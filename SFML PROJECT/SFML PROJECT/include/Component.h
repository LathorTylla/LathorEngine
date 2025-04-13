#pragma once
class Window;

/**
 * @enum ComponentType
 * @brief Enumeraci�n para definir los diferentes tipos de componentes.
 *
 * Este enum proporciona una lista de tipos de componentes que un objeto puede tener, como TRANSFORM, SPRITE,
 * RENDERER, PHYSICS, entre otros.
 */
enum
	ComponentType {
	NONE = 0,				//Componente sin tipo
	TRANSFORM = 1,  //Componente de transformaci�m
	SPRITE = 2,			//Componente de sprie
	RENDERER = 3,		//Componente de render
	PHYSICS = 4,		//Componente de fisicas
	AUDIOSOURCE = 5,//Componente de audio
	SHAPE = 6,			//Componente de forma
	TEXTURE = 7
};

/**
 * @class Component
 * @brief Clase base para todos los componentes.
 *
 * La clase Component representa un componente gen�rico que puede ser usado dentro de un sistema
 * de entidad-componente. Proporciona una estructura base para implementar diferentes tipos de
 * componentes especializados.
 */
class
Component {
public:
	/**
	 * @brief Constructor por defecto de la clase Component.
	 *
	 * Inicializa un componente sin asignarle un tipo espec�fico.
	 */
	Component() = default;

 /**
	* @brief Constructor que inicializa un componente con un tipo espec�fico.
	* @param type Tipo del componente basado en la enumeraci�n ComponentType.
  */
	
	Component(const ComponentType type) : m_type(type) {}
	
	/**
	 * @brief Destructor virtual de la clase Component.
	 *
   * Permite la destrucci�n correcta de los componentes derivados.
	 */
	virtual
	~Component() = default;
	/**
	 * @brief M�todo virtual puro para actualizar el componente.
	 *
	 * Este m�todo es sobrescrito por clases derivadas para implementar la l�gica de actualizaci�n
	 * espec�fica del componente.
	 *
	 * @param deltaTime Tiempo transcurrido desde el �ltimo cuadro, usado para c�lculos dependientes del tiempo.
	 */
	virtual void
	update(float deltaTime) = 0;

	/**
	 * @brief M�todo virtual puro para renderizar el componente.
	 *
	 * Este m�todo es sobrescrito por clases derivadas para implementar la l�gica de renderizado
	 * espec�fica del componente.
	 *
	 * @param window Referencia a la ventana en la que se renderizar� el componente.
	 */
	virtual void
	render(Window window) = 0;
	
	/**
	 * @brief Obtiene el tipo del componente.
	 *
	 * Devuelve el tipo del componente basado en la enumeraci�n ComponentType.
	 *
	 * @return El tipo del componente como un valor de ComponentType.
	 */
	ComponentType
	getType() const { return m_type; }

protected:
	ComponentType m_type; // Tipo de Componente.
};