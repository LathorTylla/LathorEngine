#pragma once
#include "Prerequisites.h"
#include "Entity.h"
#include "ShapeFactory.h"
#include "Transform.h"
class
Actor : Entity {
public:

  /*
   * @brief Constructor por defecto de la clase Actor.
   *
   * Inicializa un Actor sin nombre definido.
  */
  Actor() = default;

  /*
   * @brief Constructor que inicializa un Actor con un nombre específico.
   * @param actorName Nombre del actor.
  */
  Actor(std::string actorName);
  
  /*
   * @brief Destructor virtual por defecto.
  */
  virtual
  ~Actor() = default;
  
  void
  update(float deltaTime) override;
  
  void
  render(Window& window) override;
  
  void
  destroy();
 
  template <typename T>
  EngineUtilities::TSharedPointer<T>
  getComponent();
private:
  std::string m_name = "Actor"; ///< Nombre del actor.
};

/*
 * @brief Implementación de la plantilla getComponent para obtener un componente del Actor.
 *
 * Recorre la lista de componentes y devuelve el componente que coincide con el tipo especificado.
 *
 * @tparam T Tipo del componente a buscar.
 * @return EngineUtilities::TSharedPointer<T> Puntero compartido al componente si existe,
 * o un puntero compartido vacío si no se encuentra.
*/
template<typename T>
inline EngineUtilities::TSharedPointer<T>
Actor::getComponent() {
  for (auto& component : components) {
    EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
    if (specificComponent) {
      return specificComponent;
    }
  }
  // Devuelve un TSharedPointer vacío si no se encuentra el componente
  return EngineUtilities::TSharedPointer<T>();
}