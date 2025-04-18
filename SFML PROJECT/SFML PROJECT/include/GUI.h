#pragma once
#include "Prerequisites.h"
#include <vector>
#include "Actor.h"

class Window;
class actor;

/**
 * @class GUI
 * @brief Clase para gestionar la interfaz gr�fica de usuario (GUI).
 *
 * Esta clase maneja la creaci�n, actualizaci�n, renderizado y destrucci�n
 * de la interfaz gr�fica del programa. Proporciona herramientas para interactuar
 * con los actores de la escena y visualizar informaci�n relevante.
 */
class 
GUI {
public:
  /**
   * @brief Constructor por defecto de la clase GUI.
   */
	GUI() = default;
  /**
   * @brief Destructor por defecto de la clase GUI.
   */
	~GUI() = default;

  /*
   * @brief Inicializa los elementos de la GUI.
   *
   * Configura los par�metros iniciales y prepara la interfaz gr�fica
   * para ser usada durante la ejecuci�n del programa.
   */
  void
  init();

  /*
   * @brief Actualiza el estado de la GUI en cada ciclo de actualizaci�n.
   *
   * Refleja los cambios recientes y reacciona a las interacciones
   * del usuario, manteniendo la interfaz actualizada.
   */
  void
  update();

  /*
   * @brief Renderiza los elementos de la GUI en pantalla.
   *
   * Dibuja los componentes gr�ficos en la ventana, asegurando
   * que los elementos se muestren correctamente al usuario.
   */
  void
  render();

  /*
   * @brief Libera los recursos utilizados por la GUI.
   *
   * Limpia la memoria asignada y cierra cualquier recurso
   * que haya sido utilizado por la interfaz.
   */
  void
  destroy();

  /*
   * @brief Configura el estilo visual de la GUI.
   *
   * Define la apariencia de la interfaz gr�fica, incluyendo
   * colores, tama�os y temas personalizados.
   */
	void 
  setupGUIStye();

  /*
   * @brief Muestra los mensajes de la consola en la GUI.
   *
   * Presenta los mensajes de error, advertencias o informaci�n
   * generados por el sistema en un formato legible para el usuario.
   *
   * @param programMessages Mapa que contiene los mensajes de error
   * clasificados por su tipo (error, advertencia, informaci�n).
   */
  void 
  console(const std::map<ConsolErrorType, std::vector<std::string>>& programMessages);


  /*
   * @brief Despliega la jerarqu�a de actores en la escena.
   *
   * Presenta una lista de los actores actuales en la escena, permitiendo
   * la selecci�n de uno de ellos para su edici�n o inspecci�n.
   *
   * @param actors Vector de actores en la escena.
   * @param selectedActorID ID del actor seleccionado por el usuario.
   */
  void 
  hierarchy(const std::vector<EngineUtilities::TSharedPointer<Actor>>& actors, int& selectedActorID);


  /*
   * @brief Despliega un men� para la creaci�n de nuevos actores.
   *
   * Permite al usuario a�adir nuevos actores a la escena seleccionando
   * el tipo y el nombre del actor.
   *
   * @param actors Vector de actores en la escena, donde se a�adir� el nuevo actor.
   */
   
  void 
  actorCreationMenu(std::vector<EngineUtilities::TSharedPointer<Actor>>& actors);

   /*
   * @brief Despliega el inspector de propiedades para el actor seleccionado.
   *
   * Permite la modificaci�n de propiedades del actor, como posici�n,
   * rotaci�n y escala, en una interfaz gr�fica.
   *
   * @param selectedActor Actor seleccionado actualmente para su edici�n.
   */
  void 
  inspector(EngineUtilities::TSharedPointer<Actor> selectedActor);

  /**
   * @brief Control de vectores 2D en la GUI.
   *
   * Proporciona controles interactivos para modificar propiedades de vectores
   * como posici�n, rotaci�n o escala en el inspector.
   *
   * @param label Etiqueta que describe el vector mostrado.
   * @param values Puntero a los valores del vector (X, Y).
   * @param resetValues Valores predeterminados para el vector.
   * @param columnWidth Ancho de columna para el dise�o de la GUI.
   */
  void
  vec2Control(const std::string& label,
      float* values,
      float resetValues = 0.0f,
      float columnWidth = 100.0f);

private:
  std::map<int, std::string> m_programMessages;
};

