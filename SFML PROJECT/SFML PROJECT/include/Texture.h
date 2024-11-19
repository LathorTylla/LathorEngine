#pragma once
#include "Prerequisites.h"
#include "Component.h"

/**
 * @class Texture
 * @brief Componente para cargar y almacenar texturas en la entidad.
 *
 * Este componente permite cargar una textura desde un archivo y asociarla a una entidad.
 */
class 
Texture:public Component{
public:

	/**
	 * @brief Constructor por defecto de la clase Texture.
	 *
   * Inicializa un componente de textura sin cargar ninguna textura específica.
	 */
	Texture() = default;
	/**
	 * @brief Constructor parametrizado para cargar una textura desde un archivo.
	 *
	 * Intenta cargar la textura desde el archivo especificado. Si falla, intenta cargar una textura predeterminada.
	 *
	 * @param textureName Nombre del archivo de la textura sin extensión.
	 * @param extension Extensión del archivo de la textura.
	 */

	Texture(std::string textureName, std::string extension) : m_textureName(textureName),
																														m_extension(extension),
																														Component(ComponentType::TEXTURE) {
		if (!m_texture.loadFromFile(m_textureName+ "." + m_extension)) {
			std::cout << "Error de carga de textura" << std::endl;
		}
		else {
			m_textureName = "texturaDefault";
			m_extension = "png";
			if (!m_texture.loadFromFile(m_textureName + "." + m_extension)) {
				std::cout << "Error de carga de textura" << std::endl;
			}
		}
	}

	/**
	 * @brief Destructor de la clase Texture.
	 *
	 * Libera cualquier recurso asociado con la textura.
	 */
	virtual
	~Texture() = default;

	/**
	 * @brief Obtiene una referencia a la textura cargada.
	 *
	 * @return sf::Texture& Referencia a la textura cargada en este componente.
	 */
	sf::Texture& getTexture() {
		return m_texture;
	}
private:
	std::string m_textureName; //Nombre del archivo de la textura sin la extensión
	std::string m_extension;	 //Extensión del archivo de la textura (por ejemplo, "png")
	sf::Texture m_texture;		 //Objeto que almacena la textura cargada

};
