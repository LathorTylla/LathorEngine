#include "BaseApp.h"
#include "Services/NotificationSystem.h"
#include "Services/ResourceManager.h"

BaseApp::~BaseApp() {
  NotificationService& notifier = NotificationService::getInstance();
  notifier.saveMessagesToFile("LogData.txt");
}

int 
BaseApp::run() {
  NotificationService& notifier = NotificationService::getInstance();

  if (!initialize()) {
    notifier.addMessage(ConsolErrorType::ERROR, "Initialization failed, check method validations");
    notifier.saveMessagesToFile("LogData.txt");
    ERROR("BaseApp", "run", "Initialization failed, check method validations");
  }
  else {
    notifier.addMessage(ConsolErrorType::INF, "All programs were initialized correctly");
  }
  m_GUI.init();

  while (m_window->isOpen()) {
    m_window->handleEvents();
    update();
    render();
  }

  cleanUp();
  return 0;
}

bool 
BaseApp::initialize() {
  NotificationService& notifier = NotificationService::getInstance();
  ResourceManager& resourceManager = ResourceManager::getInstance();

  m_window = new Window(1920, 1080, "LathorEngine");
  if (!m_window) {
    ERROR("BaseApp", "initialize", "Error on window creation, var is null");
    return false;
  }

  // Track Actor
  Track = EngineUtilities::MakeShared<Actor>("Track");
  if (!Track.isNull()) {
    Track->getComponent<ShapeFactory>()->createShape(ShapeType::RECTANGLE);
    Track->getComponent<Transform>()->setTransform(Vector2(0.0f, 0.0f), 
                                                   Vector2(0.0f, 0.0f), 
                                                   Vector2(8.2f, 12.0f));

    // Cargar textura usando ResourceManager
    if (!resourceManager.loadTexture("CircuitoRainbow", "png")) {
      notifier.addMessage(ConsolErrorType::ERROR, "Error al cargar la textura del mapa");
      return false;
    }
    auto texture = resourceManager.getTexture("CircuitoRainbow");
    if (texture) {
      Track->getComponent<ShapeFactory>()->getShape()->setTexture(&texture->getTexture());
    }
    m_actors.push_back(Track);
  }

  // Circle Actor
  Circle = EngineUtilities::MakeShared<Actor>("Circle");
  if (!Circle.isNull()) {
    Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);

    //Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Blue);
    Circle->getComponent<Transform>()->setTransform(Vector2(200.0f, 200.0f), 
                                                    Vector2(0.0f, 0.0f), 
                                                    Vector2(1.0f, 1.0f));
    m_actors.push_back(Circle);
  }

  // Triangle Actor
  Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
  if (!Triangle.isNull()) {
    Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
    Triangle->getComponent<Transform>()-> setTransform(Vector2(200.0f, 200.0f), 
                                                       Vector2(0.0f, 0.0f), 
                                                       Vector2(0.5f, 0.5f));


    // Cargar textura usando ResourceManager
    if (!resourceManager.loadTexture("Toad", "png")) {
      notifier.addMessage(ConsolErrorType::ERROR, "Error al cargar la textura Toad");
      return false;
    }
    auto texture = resourceManager.getTexture("Toad");
    if (texture) {
      Triangle->getComponent<ShapeFactory>()->getShape()->setTexture(&texture->getTexture());
    }
    m_actors.push_back(Triangle);
  }
  return true;
}

void 
BaseApp::update() {
  m_window->update();

  for (auto& actor : m_actors) {
    if (!actor.isNull()) {
      actor->update(m_window->deltaTime.asSeconds());
      if (actor->getName() == "Triangle") {
        MovimientoTriangulo(m_window->deltaTime.asSeconds(), actor);
      }
    }
  }
}

void 
BaseApp::MovimientoTriangulo(float deltaTime, EngineUtilities::TSharedPointer<Actor> Triangle) {
  if (Triangle.isNull()) return;

  auto transform = Triangle->getComponent<Transform>();
  if (transform.isNull()) return;

  Vector2 targetPos = waypoints[ActualPosition];
  transform->Seek(targetPos, 200.0f, deltaTime, 10.0f);
  Vector2 currentPos = transform->getPosition();
  float distanceToTarget = std::sqrt(std::pow(targetPos.x - currentPos.x, 2) + std::pow(targetPos.y - currentPos.y, 2));

  if (distanceToTarget < 10.0f) {
    ActualPosition = (ActualPosition + 1) % waypoints.size();
  }
}

int selectedActorID = -1;

void 
BaseApp::render() {
  NotificationService& notifier = NotificationService::getInstance();
  m_window->clear();

  for (auto& actor : m_actors) {
    if (!actor.isNull()) {
      actor->render(*m_window);
    }
  }

  m_window->renderToTexture();
  m_window->showInImGui();
  m_GUI.console(notifier.getNotifications());
  m_GUI.hierarchy(m_actors, selectedActorID);
  if (selectedActorID >= 0 && selectedActorID < m_actors.size()) {
    m_GUI.inspector(m_actors[selectedActorID]);
  }

  m_GUI.actorCreationMenu(m_actors);
  m_window->render();
  m_window->display();
}

void 
BaseApp::cleanUp() {
  m_window->destroy();
  delete m_window;
}
