#include <SFML/Graphics.hpp>
#include "BaseApp.h"

/*
 * @brief Función principal que ejecuta la aplicación.
 *
 * Crea una instancia de la clase BaseApp y llama al método run para iniciar el ciclo principal
 * de la aplicación.
 *
 * @return int Código de retorno de la aplicación.
*/

sf::RenderWindow* window;
sf::CircleShape* shape;

int 
main(){
  BaseApp app;
  return app.run();
}