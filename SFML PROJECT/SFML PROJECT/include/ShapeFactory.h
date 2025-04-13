#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"
#include "Vectores/Vector2.h"

/*
 * @brief Clase ShapeFactory para la creaci�n y gesti�n de formas.
 *
 * La clase ShapeFactory permite crear, actualizar, renderizar y manipular formas. Hereda de la clase Component
 * y est� asociada al tipo de componente SHAPE.
*/

class
ShapeFactory: public Component {
public:
	ShapeFactory() = default;

	virtual	
	~ShapeFactory() = default;

  /*
	 * @brief Constructor que inicializa la f�brica de formas con un tipo espec�fico.
	 *
	 * @param shapeType Tipo de forma que se crear�, basado en la enumeraci�n ShapeType.
	*/
	ShapeFactory(ShapeType shapeType) : 
	m_shape(nullptr), m_shapeType(ShapeType::EMPTY), 
	Component(ComponentType::SHAPE) {}

	/*
	 * @brief Crea una forma basada en el tipo especificado.
	 *
	 * @param shapeType Tipo de forma a crear.
	 * @return sf::Shape* Puntero a la forma creada.
	*/
	sf::Shape*
	createShape(ShapeType shapeType);

	/*
	 * @brief Actualiza el estado de la forma.
	 *
	 * Este m�todo es una implementaci�n vac�a, pero puede ser sobrecargado para a�adir l�gica de actualizaci�n.
   *
	 * @param deltaTime Tiempo transcurrido desde la �ltima actualizaci�n.
	*/
	void
	update(float deltaTime)override {
	}

	/*
	 * @brief Renderiza la forma en la ventana.
	 *
	 * Este m�todo es una implementaci�n vac�a, pero puede ser sobrecargado para a�adir l�gica de renderizado.
	 *
	 * @param window Referencia a la ventana donde se renderizar� la forma.
	*/
	void
	render(Window window) override {}

	/*
	 * @brief Establece la posici�n de la forma mediante coordenadas.
	 *
	 * @param x Coordenada X.
	 * @param y Coordenada Y.
  */

	void
	setPosition(float x, float y);
	/*
	 * @brief Establece la posici�n de la forma utilizando un objeto sf::Vector2f.
	 *
	 * @param position Objeto sf::Vector2f que contiene las coordenadas de la posici�n.
	*/
	void
	setPosition(const Vector2& position);
	/*
	 * @brief Establece el color de relleno de la forma.
	 *
	 * @param color Color de relleno en formato sf::Color.
	*/
	void
	setFillColor(const sf::Color& color);

	/*
	 * @brief Hace que la forma se mueva hacia una posici�n objetivo.
	 *
	 * @param targetPosition Posici�n objetivo a la que se mover� la forma.
	 * @param speed Velocidad del movimiento.
	 * @param deltaTime Tiempo transcurrido desde la �ltima actualizaci�n.
	 * @param range Rango de alcance del movimiento.
	*/
	//void
	//Seek(const sf::Vector2f& targetPosition, float speed, float deltaTime, float range);

	/*
	 * @brief Establece la rotaci�n de la forma.
	 *
	 * @param angle �ngulo de rotaci�n en grados.
	 */
	void
	setRotation(float angle);
	/*
	 * @brief Escala la forma a un tama�o especificado.
	 *
	 * @param scl Objeto sf::Vector2f que define el factor de escala en los ejes X e Y.
	 */
	void
	setScale(const Vector2& scl);

	sf::Shape*
		getShape() {
		return m_shape;
	}

private:
	sf::Shape* m_shape;		 //Puntero a la forma
	ShapeType m_shapeType; //Puntero al tipo de forma
 }; 