#pragma once
class Window;

enum
	ComponentType {
	NONE = 0,				//Componente sin tipo
	TRANSFORM = 1,  //Componente de transformaci�m
	SPRITE = 2,			//Componente de sprie
	RENDERER = 3,		//Componente de render
	PHYSICS = 4,		//Componente de fisicas
	AUDIOSOURCE = 5,//Componente de audio
	SHAPE = 6,			//Componente de forma
};

class
Component {
public:
	
	Component() = default;

 /*
	* @brief Constructor que inicializa un componente con un tipo espec�fico.
	* @param type Tipo del componente basado en la enumeraci�n ComponentType.
 */
	
	Component(const ComponentType type) : m_type(type) {}
	
	virtual
	~Component() = default;
	
	virtual void
	update(float deltaTime) = 0;

	virtual void
	render(Window window) = 0;
	
	ComponentType
	getType() const { return m_type; }

protected:
	ComponentType m_type; // Tipo de Componente.
};