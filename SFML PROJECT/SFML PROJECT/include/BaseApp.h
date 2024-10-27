#pragma once
#include <SFML/Graphics.hpp>
#include <Window.h>
#include "ShapeFactory.h"
#include <Actor.h>
#include "Prerequisites.h"

  /*
  * @brief Clase BaseApp que representa la aplicaci�n base del programa.
  *
  * La clase BaseApp gestiona el ciclo de vida de la aplicaci�n, incluyendo la inicializaci�n,
  * actualizaci�n, renderizado y limpieza de recursos. Adem�s, gestiona el movimiento de actores
  * dentro de la ventana.
  */

class
BaseApp{
public:
  BaseApp() = default;
  ~BaseApp() = default;

  /*
   * @brief Realiza el movimiento del tri�ngulo siguiendo los waypoints.
   *
   * Actualiza la posici�n del actor Tri�ngulo basado en el deltaTime y los puntos de referencia (waypoints).
   *
   * @param deltaTime Tiempo transcurrido desde la �ltima actualizaci�n.
   * @param Triangle Puntero compartido al actor que representa el tri�ngulo.
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
   * @brief Ejecuta la aplicaci�n.
   *
   * M�todo que contiene el bucle principal de la aplicaci�n.
   * @return int C�digo de retorno de la aplicaci�n.
  */

  int 
  run();

  /*
   * @brief Inicializa la aplicaci�n.
   *
   * Carga los recursos y configura los objetos necesarios para el inicio de la aplicaci�n.
   * @return bool Verdadero si la inicializaci�n fue exitosa, falso en caso contrario.
  */ 
  
  bool
  initialize();

  /*
   * @brief Actualiza el estado de la aplicaci�n.
   * 
   * Se llama en cada cuadro para actualizar el estado de los objetos dentro de la aplicaci�n.
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
   * @brief Limpia los recursos de la aplicaci�n.
   *
   * Libera la memoria y otros recursos utilizados por la aplicaci�n.
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

