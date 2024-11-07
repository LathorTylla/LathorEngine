#include "BaseApp.h"

int
BaseApp::run() {
	if (!initialize()) {
		ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");
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
	m_window = new Window(1920, 1080, "LathorEngine");
	if (!m_window) {
		ERROR("BaseApp", "initialize", "Error on window creation, var is null");
		return false;
	}
	//track
	Track = EngineUtilities::MakeShared<Actor>("Track");
	if (!Track.isNull()) {
		Track->getComponent<ShapeFactory>()->createShape(ShapeType::RECTANGLE);
		//Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Blue);

		Track->getComponent<Transform>()->setPosition(sf::Vector2f(0.0f, 0.0f));
		Track->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
		Track->getComponent<Transform>()->setScale(sf::Vector2f(8.2f, 12.0f));

		if (!texture.loadFromFile("CircuitoRainbow.png")) {
			std::cout << "Error de carga de textura" << std::endl;
			return -1; //Manejar error de carga
		}
		Track->getComponent<ShapeFactory>()->getShape()->setTexture(&texture);
	}

		// Circle Actor
		Circle = EngineUtilities::MakeShared<Actor>("Circle");
		if (!Circle.isNull()) {
			Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);
			Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Blue);

			Circle->getComponent<Transform>()->setPosition(sf::Vector2f(200.0f, 200.0f));
			Circle->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
			Circle->getComponent<Transform>()->setScale(sf::Vector2f(1.0f, 1.0f));


		}

		
		// Triangle Actor
		Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
		if (!Triangle.isNull()) {
			Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);

			Triangle->getComponent<Transform>()->setPosition(sf::Vector2f(200.0f, 200.0f));
			Triangle->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
			Triangle->getComponent<Transform>()->setScale(sf::Vector2f(0.5f, 0.5f));

			if (!Toad.loadFromFile("Toad.png")) {
				std::cout << "Error de carga de textura" << std::endl;
				return -1; //Manejar error de carga
			}
			Triangle->getComponent<ShapeFactory>()->getShape()->setTexture(&Toad);
		}

		return true;
	}

	void
	BaseApp::update() {
		//Update window
		m_window->update();
		// Mouse Position
		sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->getWindow());
		sf::Vector2f mousePosF(static_cast<float>(mousePosition.x),
			static_cast<float>(mousePosition.y));

		if (!Track.isNull()) {
			Track->update(m_window->deltaTime.asSeconds());
		}
		if (!Triangle.isNull()) {
			Triangle->update(m_window->deltaTime.asSeconds());
		}

		if (!Circle.isNull()) {
			Circle->update(m_window->deltaTime.asSeconds());
			//Circle->getComponent<ShapeFactory>()->Seek(mousePosF,
			//300.0f, //velocidad
			//deltaTime.asSeconds(),
			//10.0f);
		}
		// Mover el triángulo entre los waypoints
		MovimientoTriangulo(m_window->deltaTime.asSeconds(), Triangle);
	}

	void
	BaseApp::MovimientoTriangulo(float deltaTime, EngineUtilities::TSharedPointer<Actor> Triangle) {
		if (Triangle.isNull()) return;

		auto transform = Triangle->getComponent<Transform>();
		if (transform.isNull()) return;

		// Posición del siguiente waypoint
		sf::Vector2f targetPos = waypoints[ActualPosition];

		// Llamar al Seek del Transform
		transform->Seek(targetPos, 200.0f, deltaTime, 10.0f);

		// Obtener la posición actual del triángulo
		sf::Vector2f currentPos = transform->getPosition();

		// Calcular la distancia al waypoint
		float distanceToTarget = std::sqrt(std::pow(targetPos.x - currentPos.x, 2) + std::pow(targetPos.y - currentPos.y, 2));

		// Si estamos cerca del waypoint, pasar al siguiente
		if (distanceToTarget < 10.0f) {
			ActualPosition = (ActualPosition + 1) % waypoints.size(); // Ciclar entre los waypoints
		}
	}

	void
	BaseApp::render() {
		m_window->clear();
		if (!Track.isNull()) {
			Track->render(*m_window);
		}
		if (!Triangle.isNull()) {
			Triangle->render(*m_window);
		}
		m_window->renderToTexture();  // Finaliza el render a la textura
		m_window->showInImGui();      // Muestra la textura en ImGui

		m_window->render();
		m_window->display();
	}

	void
	BaseApp::cleanUp() {
		m_window->destroy();
		delete m_window;
	}