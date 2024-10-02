#include <SFML/Graphics.hpp>
#include "BaseApp.h"

/*
 * @brief Funci�n principal que ejecuta la aplicaci�n.
 *
 * Crea una instancia de la clase BaseApp y llama al m�todo run para iniciar el ciclo principal
 * de la aplicaci�n.
 *
 * @return int C�digo de retorno de la aplicaci�n.
*/

sf::RenderWindow* window;
sf::CircleShape* shape;

int 
main(){
  BaseApp app;
  return app.run();
}