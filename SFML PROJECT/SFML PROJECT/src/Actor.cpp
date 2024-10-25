#include "Actor.h"

/*
 * @brief Constructor que inicializa un Actor con un nombre espec�fico.
 *
 * @param actorName Nombre del actor.
*/

Actor::Actor(std::string actorName) {
	// Setup Actor Name
	m_name = actorName;
	// Setup Shape
	EngineUtilities::TSharedPointer<ShapeFactory> shape = 
	EngineUtilities::MakeShared<ShapeFactory>();
	addComponent(shape);

	// Setup Transform
	EngineUtilities::TSharedPointer<Transform>transform = 
	EngineUtilities::MakeShared<Transform>();
	addComponent(transform);
	// Setup Sprite
}

/*
 * @brief Actualiza el estado del Actor.
 *
 * Este m�todo es una implementaci�n vac�a y puede ser sobrecargado para agregar l�gica
 * de actualizaci�n espec�fica.
 *
 * @param deltaTime Tiempo transcurrido desde la �ltima actualizaci�n.
*/

void 
Actor::update(float deltaTime){
}

/*
 * @brief Renderiza el Actor en la ventana proporcionada.
 *
 * Itera sobre los componentes del Actor, y si el componente es un ShapeFactory, dibuja la forma asociada.
 *
 * @param window Referencia a la ventana donde se renderizar� el Actor.
*/
void 
Actor::render(Window& window){
	for (unsigned int i = 0; i < components.size(); i++) {
		if (components[i].dynamic_pointer_cast<ShapeFactory>()) {
			window.draw(*components[i].dynamic_pointer_cast<ShapeFactory>()->getShape());
		}
	}
}

/*
 * @brief Destruye el Actor y libera los recursos asociados.
 *
 * Este m�todo es una implementaci�n vac�a que puede ser sobrecargada para manejar la
 * destrucci�n de recursos espec�ficos.
*/
void 
Actor::destroy(){
}