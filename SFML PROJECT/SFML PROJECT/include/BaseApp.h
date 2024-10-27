#pragma once
#include <SFML/Graphics.hpp>
#include <Window.h>
#include "ShapeFactory.h"
#include <Actor.h>
#include "Prerequisites.h"

  /*
  * @brief Clase BaseApp que representa la aplicación base del programa.
  *
  * La clase BaseApp gestiona el ciclo de vida de la aplicación, incluyendo la inicialización,
  * actualización, renderizado y limpieza de recursos. Además, gestiona el movimiento de actores
  * dentro de la ventana.
  */

class
BaseApp{
public:
  BaseApp() = default;
  ~BaseApp() = default;

  /*
   * @brief Realiza el movimiento del triángulo siguiendo los waypoints.
   *
   * Actualiza la posición del actor Triángulo basado en el deltaTime y los puntos de referencia (waypoints).
   *
   * @param deltaTime Tiempo transcurrido desde la última actualización.
   * @param Triangle Puntero compartido al actor que representa el triángulo.
  */

  void
  MovimientoTriangulo(float deltaTime, EngineUtilities::TSharedPointer<Actor> Triangle);


  int
  ActualPosition = 0; //Posicion actual de los waypoints

  std::vector<sf::Vector2f>waypoints = {
    {50.0f,50.0f},
    {400.0f,50.0f},
    {400.0f,200.0f},
    {50.0f,200.0f},

  };
  
  /*
   * @brief Ejecuta la aplicación.
   *
   * Método que contiene el bucle principal de la aplicación.
   * @return int Código de retorno de la aplicación.
  */

  int 
  run();

  /*
   * @brief Inicializa la aplicación.
   *
   * Carga los recursos y configura los objetos necesarios para el inicio de la aplicación.
   * @return bool Verdadero si la inicialización fue exitosa, falso en caso contrario.
  */ 
  
  bool
  initialize();

  /*
   * @brief Actualiza el estado de la aplicación.
   * 
   * Se llama en cada cuadro para actualizar el estado de los objetos dentro de la aplicación.
  */  
  void
  update();

  /*
   * @brief Renderiza los objetos en la ventana.
   * 
   * Se llama en cada cuadro para dibujar los objetos en la ventana.
  */ 
  void
  render();

  /*
   * @brief Limpia los recursos de la aplicación.
   *
   * Libera la memoria y otros recursos utilizados por la aplicación.
  */
  void
  cleanUp();

private:

  Window * m_window;
  //sf::RenderWindow* window;
  //sf::CircleShape* shape;
  EngineUtilities::TSharedPointer<Actor>Triangle; //Puntero compartidod al actor Triangle
  EngineUtilities::TSharedPointer<Actor> Circle;  //Puntero compartidod al actor Circle
  //ShapeFactory m_shapeFactory;
  //sf::Shape* Triangulo;
};

