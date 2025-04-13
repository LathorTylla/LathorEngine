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
  
  /**
   * @brief Actualiza el estado del actor en cada frame.
   *
   * Este método se llama en cada actualización del frame y permite actualizar el estado del actor
   * de acuerdo con el tiempo delta, lo cual es útil para cálculos dependientes del tiempo.
   *
   * @param deltaTime El tiempo transcurrido desde el último frame, en segundos.
   */
  void
  update(float deltaTime) override;
  
  /**
   * @brief Renderiza el actor en la ventana especificada.
   *
   * Dibuja el actor en la ventana proporcionada para representar su estado visual actual.
   *
   * @param window La referencia a la ventana en la cual se renderizará el actor.
   */
  void
  render(Window& window) override;
  
  /**
   * @brief Destruye el actor y libera los recursos asociados.
   *
   * Realiza las operaciones necesarias para limpiar y liberar cualquier recurso
   * que el actor haya usado antes de ser eliminado del sistema.
   */
  void
  destroy();

  /**
   * @brief Obtiene el nombre del actor.
   *
   * Devuelve el nombre del actor como una cadena, que puede ser utilizada para
   * identificar el actor en el sistema.
   *
   * @return El nombre del actor en formato std::string.
   */
  std::string 
  getName() {
  return m_name;
  }
 
  /**
   * @brief Obtiene un componente específico del actor.
   *
   * Permite acceder a un componente del actor según su tipo. Utiliza plantillas
   * para realizar una búsqueda de tipo segura.
   *
   * @tparam T El tipo del componente que se desea obtener.
   */
  template <typename T>
  EngineUtilities::TSharedPointer<T>
  getComponent();
private:
  std::string m_name = "Actor"; 
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