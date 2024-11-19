#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"

/**
 * @class Transform
 * @brief Componente para gestionar la posición, rotación y escala de una entidad.
 *
 * Este componente permite manejar la transformación de una entidad en el espacio 2D, con métodos para
 * mover la entidad hacia un objetivo y actualizar su posición, rotación y escala.
 */
class
Transform: public Component{
public:
	/**
	 * @brief Constructor por defecto de la clase Transform.
	 *
	 * Inicializa un componente de transformación con posición en (0,0), rotación en (0,0)
	 * y escala en (1,1), asignándole el tipo TRANSFORM.
	 */
	Transform(): position(0.0f, 0.0f),
							 rotation(0.0f, 0.0f),
							 scale(1.0f, 1.0f),
							 Component(ComponentType::TRANSFORM){}

	/**
	 * @brief Destructor de la clase Transform.
	 */
	virtual
	~Transform() = default;

	/**
	 * @brief Actualiza el componente de transformación.
	 *
	 * Actualmente no realiza ninguna operación durante la actualización.
   *
	 * @param deltaTime Tiempo transcurrido desde el último fotograma.
	 */
	void
	update(float deltaTime) override{}

	/**
	 * @brief Renderiza el componente Transform.
	 *
	 * Este método actualmente no realiza ninguna operación de renderizado.
	 *
	 * @param window Referencia al objeto Window donde se renderizará.
	 */
	void
	render(Window window) override{}

	/**
	 * @brief Destruye el componente Transform.
	 *
	 * Métodos adicionales de destrucción específicos del componente.
	 */
	void
	destroy();

	/**
	 * @brief Mueve el objeto hacia una posición objetivo.
	 *
	 * Aplica un movimiento de "seek" hacia una posición objetivo dada a una velocidad específica,
	 * con un rango de distancia que determina cuándo debe detenerse.
	 *
	 * @param targetPosition Posición de destino hacia la cual moverse.
	 * @param speed Velocidad de movimiento.
	 * @param deltaTime Tiempo transcurrido desde el último fotograma.
	 * @param range Distancia mínima al objetivo antes de detenerse.
	 */
	void
	Seek(const sf::Vector2f& targetPosition,
		float speed,
		float deltaTime,
		float range) {
		sf::Vector2f direction = targetPosition - position;
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	if (length > range) {
			direction /= length;  // Normaliza el vector
			position += direction * speed * deltaTime;
		}
	}

	/**
	 * @brief Establece la posición del componente Transform.
	 * @param _position Nueva posición a establecer.
	 */
	void
	setPosition(const sf::Vector2f& _position) {
	position = _position;
	}

	/**
	 * @brief Establece la rotación del componente Transform.
	 * @param _rotation Nueva rotación a establecer.
	 */
	void
	setRotation(const sf::Vector2f& _rotation) {
	rotation = _rotation;
	}

	/**
	 * @brief Establece la escala del componente Transform.
	 * @param _scale Nueva escala a establecer.
	 */
	void
	setScale(const sf::Vector2f& _scale) {
	scale = _scale;
	}

	/**
	 * @brief Obtiene la posición actual del componente Transform.
	 * @return sf::Vector2f& Referencia a la posición actual.
	 */
	sf::Vector2f&
	getPosition() {
	return position;
	}

	/**
	 * @brief Obtiene la rotación actual del componente Transform.
	 * @return sf::Vector2f& Referencia a la rotación actual.
	 */
	sf::Vector2f& 
	getRotation() {
	return rotation;
	}

	/**
	 * @brief Obtiene la escala actual del componente Transform.
	 * @return sf::Vector2f& Referencia a la escala actual.
	 */
	sf::Vector2f&
	getScale() {
	return scale;
	}

private:
	sf::Vector2f position; 
	sf::Vector2f rotation;
	sf::Vector2f scale;
};

