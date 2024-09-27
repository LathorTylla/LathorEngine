#include "BaseApp.h"

int BaseApp::run(){
  initialize();  // Inicializa la ventana y la forma
  while (m_window->isOpen())
  {
    m_window->handleEvents();  // Maneja eventos
    update();        // Actualiza la l�gica
    render();        // Dibuja en la pantalla
  }

  cleanUp();  
  return 0; 
}

// Implementaci�n de initialize 
void 
BaseApp::initialize(){
  m_window = new Window(800, 600, "LathorEngine");
  shape = new sf::CircleShape(100.0f);
  shape->setFillColor(sf::Color::Magenta);
}

// Implementaci�n de update
void BaseApp::update()
{
}

// Implementaci�n de render 
void BaseApp::render()
{
  m_window->clear();
  m_window->draw(*shape);
  m_window->display();
}

// Implementaci�n de cleanUp
void BaseApp::cleanUp()
{
  m_window->destroy();
  delete m_window;
  delete shape;
}
