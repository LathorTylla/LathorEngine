#include "ShapeFactory.h"

/*
 * @brief Crea una forma basada en el tipo especificado.
 *
 * Crea una forma de tipo círculo, rectángulo o triángulo y la almacena en el miembro m_shape.
 *
 * @param shapeType Tipo de forma a crear, basado en la enumeración ShapeType.
 * @return sf::Shape* Puntero a la forma creada, o nullptr si el tipo es EMPTY.
*/

sf::Shape*
ShapeFactory::createShape(ShapeType shapeType) {
	m_shapeType = shapeType;
	switch (shapeType) {
	case EMPTY: {
		return nullptr;
	}
	case CIRCLE: {
		sf::CircleShape* circle = new sf::CircleShape(10.0f);
		circle->setFillColor(sf::Color::White);
		m_shape = circle;
		return circle;
	}
	case RECTANGLE: {
		sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2(100.0f, 50.0f));
		rectangle->setFillColor(sf::Color::White);
		m_shape = rectangle;
		return rectangle;
	}
	case TRIANGLE: {
		sf::CircleShape* triangle = new sf::CircleShape(50.0f, 3);
		triangle->setFillColor(sf::Color::White);
		m_shape = triangle;
		return triangle;
	}
	default:
		return nullptr;
	}
}

/*
 * @brief Establece la posición de la forma.
 *
 * @param x Coordenada X de la posición.
 * @param y Coordenada Y de la posición.
*/
void
ShapeFactory::setPosition(float x, float y) {
	if (m_shape){
		m_shape->setPosition(x, y);
	}
}
/*
 * @brief Establece la posición de la forma utilizando un objeto sf::Vector2f.
 *
 * @param position Objeto sf::Vector2f que contiene las coordenadas de la posición.
*/
void
ShapeFactory::setPosition(const sf::Vector2f& position) {
	if (m_shape) {
		m_shape->setPosition(position);
	}
}

void
ShapeFactory::setRotation(float angle){
	if (m_shape) {
		m_shape->setRotation(angle);
	}
}

void
ShapeFactory::setScale(const sf::Vector2f& scl) {
	if (m_shape) {
		m_shape->setScale(scl);
	}
}

/*
 * @brief Establece el color de relleno de la forma.
 *
 * @param color Color de relleno en formato sf::Color.
*/
void
ShapeFactory::setFillColor(const sf::Color& color) {
	m_shape->setFillColor(color);
}
/*
 * @brief Mueve la forma hacia una posición objetivo.
 *
 * La forma se moverá hacia la posición objetivo a una velocidad específica y se detendrá si está dentro del rango especificado.
 *
 * @param targetPosition Posición objetivo a la que se moverá la forma.
 * @param speed Velocidad del movimiento.
 * @param deltaTime Tiempo transcurrido desde la última actualización.
 * @param range Distancia mínima para detenerse cerca del objetivo.
*/
