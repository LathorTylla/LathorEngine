#pragma once
#include <SFML/Graphics.hpp>
/*
 * @brief Clase Window que gestiona la ventana de renderizado.
 *
 * La clase Window proporciona métodos para manejar eventos, actualizar, renderizar y gestionar
 * una ventana utilizando la biblioteca SFML.
*/
class 
Window{

public:
  Window() = default;

  /*
   * @brief Constructor que inicializa una ventana con dimensiones y título específicos.
   *
   * @param width Ancho de la ventana.
   * @param height Alto de la ventana.
   * @param tittle Título de la ventana.
  */
  Window(int width, int height, const std::string& tittle);

  ~Window();
 
  /*
   * @brief Maneja los eventos de la ventana.
   *
   * Captura y procesa los eventos generados por la ventana, como el cierre o la interacción del usuario.
   */  
  void
  handleEvents();
  /*
   * @brief Limpia la ventana antes de renderizar.
   *
   * Borra el contenido actual de la ventana, preparándola para el próximo cuadro.
  */

  void
  clear();
  /*
   * @brief Muestra el contenido renderizado en la ventana.
   *
   * Intercambia el búfer y muestra lo que ha sido dibujado en la ventana.
  */

  void
  display();

  /*
   * @brief Verifica si la ventana está abierta.
   *
   * @return bool Verdadero si la ventana está abierta, falso si está cerrada.
  */

  bool
  isOpen() const;

  /*
   * @brief Dibuja un objeto en la ventana.
   *
   * @param drawable Objeto dibujable (como un sprite o forma) que será renderizado en la ventana.
  */

  void
  draw(const sf::Drawable & drawable);

  /*
   * @brief Obtiene el puntero a la ventana de SFML.
   *
   * @return sf::RenderWindow* Puntero a la ventana SFML utilizada para el renderizado.
  */

  sf::RenderWindow*
  getWindow();
 
  /*
   * @brief Inicializa la ventana.
   *
   * Crea y configura la ventana de SFML con los parámetros especificados.
   */

  void
  renderToTexture();
  void
  showInImGui();

  void 
  init();

  /*
  * @brief Actualiza el estado de la ventana.
  *
  * Método que se llama en cada cuadro para actualizar el estado de la ventana.
  */
  void
  update();

  /*
   * @brief Renderiza el contenido de la ventana.
   *
   * Método que se llama en cada cuadro para renderizar los objetos en la ventana.
  */
  void
  render();

  /*
   * @brief Destruye la ventana y libera los recursos asociados.
  */
  void
  destroy(); 
  
private:
  sf::RenderWindow* m_window; //Puntero a la ventana
  sf::View m_view;
  

public:
  sf::RenderTexture m_renderTexture;
  sf::Time deltaTime;
  sf::Clock clock;
};