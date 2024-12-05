#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"
#include "Vectores/Vector2.h"

/*
 * @brief Clase ShapeFactory para la creación y gestión de formas.
 *
 * La clase ShapeFactory permite crear, actualizar, renderizar y manipular formas. Hereda de la clase Component
 * y está asociada al tipo de componente SHAPE.
*/

class
ShapeFactory: public Component {
public:
	ShapeFactory() = default;

	virtual	
	~ShapeFactory() = default;

  /*
	 * @brief Constructor que inicializa la fábrica de formas con un tipo específico.
	 *
	 * @param shapeType Tipo de forma que se creará, basado en la enumeración ShapeType.
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
	 * Este método es una implementación vacía, pero puede ser sobrecargado para añadir lógica de actualización.
   *
	 * @param deltaTime Tiempo transcurrido desde la última actualización.
	*/
	void
	update(float deltaTime)override {
	}

	/*
	 * @brief Renderiza la forma en la ventana.
	 *
	 * Este método es una implementación vacía, pero puede ser sobrecargado para añadir lógica de renderizado.
	 *
	 * @param window Referencia a la ventana donde se renderizará la forma.
	*/
	void
	render(Window window) override {}

	/*
	 * @brief Establece la posición de la forma mediante coordenadas.
	 *
	 * @param x Coordenada X.
	 * @param y Coordenada Y.
  */

	void
	setPosition(float x, float y);
	/*
	 * @brief Establece la posición de la forma utilizando un objeto sf::Vector2f.
	 *
	 * @param position Objeto sf::Vector2f que contiene las coordenadas de la posición.
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
	 * @brief Hace que la forma se mueva hacia una posición objetivo.
	 *
	 * @param targetPosition Posición objetivo a la que se moverá la forma.
	 * @param speed Velocidad del movimiento.
	 * @param deltaTime Tiempo transcurrido desde la última actualización.
	 * @param range Rango de alcance del movimiento.
	*/
	//void
	//Seek(const sf::Vector2f& targetPosition, float speed, float deltaTime, float range);

	/*
	 * @brief Establece la rotación de la forma.
	 *
	 * @param angle Ángulo de rotación en grados.
	 */
	void
	setRotation(float angle);
	/*
	 * @brief Escala la forma a un tamaño especificado.
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