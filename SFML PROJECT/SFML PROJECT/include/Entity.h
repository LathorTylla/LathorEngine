#pragma once
#include "Prerequisites.h"
#include "Component.h"

class 
Window;

/**
 * @class Entity
 * @brief Clase base para todas las entidades en el motor.
 *
 * La clase Entity representa un objeto en el juego que puede poseer m�ltiples componentes,
 * permitiendo as� comportamientos y caracter�sticas espec�ficas mediante un sistema de entidad-componente.
 */
class
Entity {
public:

  /**
  * @brief Destructor virtual de la clase Entity.
  *
  * Permite la destrucci�n correcta de las entidades derivadas.
  */
  virtual
  ~Entity() = default;
  
  /**
   * @brief M�todo virtual puro para actualizar la entidad.
   *
   * Este m�todo es sobrescrito por clases derivadas para implementar la l�gica de actualizaci�n
   * espec�fica de la entidad.
   *
   * @param deltaTime Tiempo transcurrido desde el �ltimo cuadro, usado para c�lculos dependientes del tiempo.
   */
  virtual 
  void
  update(float deltaTime) = 0;
  
  /**
   * @brief M�todo virtual puro para renderizar la entidad.
   *
   * Este m�todo es sobrescrito por clases derivadas para implementar la l�gica de renderizado espec�fica de la entidad.
   *
   * @param window Referencia a la ventana en la que se renderizar� la entidad.
   */
  virtual 
  void
  render(Window& window) = 0;
 
  /*
   * @brief A�ade un componente a la entidad.
   *
   * El componente debe ser derivado de la clase Component.
   *
   * @tparam T Tipo del componente a a�adir.
   * @param component Puntero compartido al componente a a�adir.
  */

  template <typename T>
  void 
  addComponent(EngineUtilities::TSharedPointer<T> component) {
    static_assert(std::is_base_of<Component, T>::value, "T must be derived from Component");
    components.push_back(component.template dynamic_pointer_cast<Component>());
  }
  /*
   * @brief Obtiene un componente de la entidad.
   *
   * Busca un componente del tipo especificado que est� asociado a la entidad.
   *
   * @tparam T Tipo del componente a buscar.
   * @return EngineUtilities::TSharedPointer<T> Puntero compartido al componente si existe,
   * o un puntero compartido vac�o si no se encuentra.
  */
  
  template<typename T>
  EngineUtilities::TSharedPointer<T>
    getComponent() {
    for (auto& component : components) {
      EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
      if (specificComponent) {
        return specificComponent;
      }
    }
    return EngineUtilities::TSharedPointer<T>();
  }
protected:

  bool 
  isActive;
  int 
  id;
  std::vector<EngineUtilities::TSharedPointer<Component>> components;
};