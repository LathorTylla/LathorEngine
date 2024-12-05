#include "ShapeFactory.h"

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

void
ShapeFactory::setPosition(float x, float y) {
	if (m_shape) {
		m_shape->setPosition(x, y);
	}
}

void
ShapeFactory::setPosition(const Vector2& position) {
	if (m_shape) {
		m_shape->setPosition(position.x, position.y);
	}
}

void
ShapeFactory::setRotation(float angle){
	if (m_shape) {
		m_shape->setRotation(angle);
	}
}

void
ShapeFactory::setScale(const Vector2& scl) {
	if (m_shape) {
		m_shape->setScale(scl.x, scl.y);
	}
}


void
ShapeFactory::setFillColor(const sf::Color& color) {
	m_shape->setFillColor(color);
}

