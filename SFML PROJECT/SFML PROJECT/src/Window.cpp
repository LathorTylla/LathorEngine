#include "Window.h"
#include "Prerequisites.h"
#include <SFML/Graphics.hpp>

/*
 * @brief Constructor que inicializa una ventana con las dimensiones y el t�tulo especificados.
 *
 * @param width Ancho de la ventana.
 * @param height Alto de la ventana.
 * @param tittle T�tulo de la ventana.
*/

Window::Window(int width, int height, const std::string& tittle) {
  m_window = new sf::RenderWindow(sf::VideoMode(width, height), tittle);

  if (!m_window) {
    ERROR("Window", "Window", "CHECK CONSTRUCTOR");
  }
  else {
    MESSAGE("Window", "Window", "OK");
  }
}

/*
 * @brief Destructor que libera los recursos asociados a la ventana.
*/
Window::~Window() {
  ImGui::SFML::Shutdown();
  delete m_window;
}

/*
 * @brief Maneja los eventos de la ventana, como el cierre de la misma.
*/
void
Window::handleEvents() {
  sf::Event event;
  //initialize the InGui Resource
  ImGui::SFML::Init(*m_window);

  while (m_window->pollEvent(event)){
    ImGui::SFML::ProcessEvent(event);

    if (event.type == sf::Event::Closed)
      m_window->close();
  }
  // Manejar el evento de redimensionar
  if (event.type == sf::Event::Resized) {
    // Obtener el nuevo tama�o de la ventana
    unsigned int newWidth = event.size.width;
    unsigned int newHeight = event.size.height;
    // Opcional: Redefinir el tama�o de la vista para ajustarse al nuevo tama�o de la ventana
    sf::View view = m_window->getView();
    view.setSize(static_cast<float>(newWidth), static_cast<float>(newHeight));
    m_window->setView(view);
  }
}

/*
 * @brief Limpia la ventana antes de renderizar.
*/
void
Window::clear() {
  if (m_window != nullptr) {
    m_window->clear();
  }
  else
  {
    ERROR("Window", "clear", "CHECK FOR WINDOW POINTER DATA");
  }
}

/*
 * @brief Muestra el contenido renderizado en la ventana.
*/
void
Window::display() {
  if (m_window != nullptr) {
    m_window->display();
  }
  else
  {
    ERROR("Window", "display", "CHECK FOR WINDOW POINTER DATA");
  }
}

/*
 * @brief Verifica si la ventana est� abierta.
 *
 * @return bool Verdadero si la ventana est� abierta, falso en caso contrario.
*/
bool
Window::isOpen() const{
  if (m_window != nullptr) {
    return m_window->isOpen();
  }
  else {
    ERROR("Window", "isOpen", "CHECK FOR WINDOW POINTER DATA");
    return false;
  }
}

/*
 * @brief Dibuja un objeto en la ventana.
 *
 * @param drawable Objeto dibujable que ser� renderizado en la ventana.
*/
void
Window::draw(const sf:: Drawable& drawable) {
  if (m_window != nullptr) {
    m_window->draw(drawable);
  }
  else {
    ERROR("Window", "draw", "CHECK FOR WINDOW POINTER DATA");
  }
}

/*
 * @brief Obtiene el puntero a la ventana de SFML.
 *
 * @return sf::RenderWindow* Puntero a la ventana, o nullptr si no existe.
*/
sf::RenderWindow*
Window::getWindow() {
  if (m_window != nullptr) {
    return m_window;
  }
  else {
    ERROR("Window", "getWindow", "CHECK FOR WINDOW POINTER DATA");
    return nullptr;
  }
}

void
Window::update() {
  deltaTime = clock.restart();
  ImGui::SFML::Update(*m_window, deltaTime);
}

void 
Window::render(){
  ImGui::SFML::Render(*m_window);
}

/*
 * @brief Destruye la ventana y libera los recursos asociados.
*/
void
Window::destroy()
{
  ImGui::SFML::Shutdown();
  SAFE_PTR_RELEASE(m_window);
}