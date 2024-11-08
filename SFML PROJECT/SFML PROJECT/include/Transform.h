#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"

/**
 * @class Transform
 * @brief Componente para gestionar la posici�n, rotaci�n y escala de una entidad.
 *
 * Este componente permite manejar la transformaci�n de una entidad en el espacio 2D, con m�todos para
 * mover la entidad hacia un objetivo y actualizar su posici�n, rotaci�n y escala.
 */
class
Transform: public Component{
public:
	/**
	 * @brief Constructor por defecto de la clase Transform.
	 *
	 * Inicializa un componente de transformaci�n con posici�n en (0,0), rotaci�n en (0,0)
	 * y escala en (1,1), asign�ndole el tipo TRANSFORM.
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
	 * @brief Actualiza el componente de transformaci�n.
	 *
	 * Actualmente no realiza ninguna operaci�n durante la actualizaci�n.
   *
	 * @param deltaTime Tiempo transcurrido desde el �ltimo fotograma.
	 */
	void
	update(float deltaTime) override{}

	/**
	 * @brief Renderiza el componente Transform.
	 *
	 * Este m�todo actualmente no realiza ninguna operaci�n de renderizado.
	 *
	 * @param window Referencia al objeto Window donde se renderizar�.
	 */
	void
	render(Window window) override{}

	/**
	 * @brief Destruye el componente Transform.
	 *
	 * M�todos adicionales de destrucci�n espec�ficos del componente.
	 */
	void
	destroy();

	/**
	 * @brief Mueve el objeto hacia una posici�n objetivo.
	 *
	 * Aplica un movimiento de "seek" hacia una posici�n objetivo dada a una velocidad espec�fica,
	 * con un rango de distancia que determina cu�ndo debe detenerse.
	 *
	 * @param targetPosition Posici�n de destino hacia la cual moverse.
	 * @param speed Velocidad de movimiento.
	 * @param deltaTime Tiempo transcurrido desde el �ltimo fotograma.
	 * @param range Distancia m�nima al objetivo antes de detenerse.
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
	 * @brief Establece la posici�n del componente Transform.
	 * @param _position Nueva posici�n a establecer.
	 */
	void
	setPosition(const sf::Vector2f& _position) {
	position = _position;
	}

	/**
	 * @brief Establece la rotaci�n del componente Transform.
	 * @param _rotation Nueva rotaci�n a establecer.
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
	 * @brief Obtiene la posici�n actual del componente Transform.
	 * @return sf::Vector2f& Referencia a la posici�n actual.
	 */
	sf::Vector2f&
	getPosition() {
	return position;
	}

	/**
	 * @brief Obtiene la rotaci�n actual del componente Transform.
	 * @return sf::Vector2f& Referencia a la rotaci�n actual.
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

