**LathorEngine**

LathorEngine es un motor gráfico básico diseñado en C++ que utiliza SFML para el renderizado 2D y ImGui para la interfaz de usuario. Este proyecto tiene como objetivo proporcionar una base para desarrollar simulaciones y videojuegos sencillos, explorando funcionalidades comunes en motores de videojuegos.


**Características Principales**

**Consola de Mensajes:** Una consola en ImGui que permite mostrar mensajes en tiempo real. Puede mostrar distintos tipos de mensajes como errores, advertencias e información, facilitando la depuración y el seguimiento del estado de la aplicación.

**Jerarquía de Objetos:** Un sistema de jerarquía similar a Unity, donde se pueden ver y seleccionar los diferentes actores que forman parte de la escena actual. Este sistema facilita la organización de elementos y la edición de sus propiedades.

**Inspector de Propiedades:** Herramienta que permite modificar propiedades de los actores seleccionados, como su posición y escala. El inspector es ideal para realizar ajustes de manera visual y en tiempo real.

**Creación de Actores**: Menú de creación para añadir actores en la escena, como círculos, triángulos o rectángulos, con opciones de personalización como nombres y dimensiones iniciales.


**Tecnologías Utilizadas**

**SFML (Simple and Fast Multimedia Library):** Utilizada para el renderizado gráfico y manejo de eventos. SFML proporciona una interfaz amigable y eficiente para gráficos 2D, entrada y otros elementos multimedia.

**ImGui:** Biblioteca de interfaz de usuario que permite crear paneles interactivos, controles y menús con facilidad. Se utiliza para mostrar la consola, la jerarquía de objetos y el inspector de propiedades en este proyecto.

**C++:** Lenguaje de programación base, elegido por su eficiencia y flexibilidad para manejar sistemas en tiempo real.


**Estructura del Proyecto**

**Actor**: Clase que representa un objeto dentro de la escena. Los actores pueden tener distintos componentes y ser manipulados a través de la jerarquía y el inspector.

**Window**: Clase para manejar la ventana de renderizado y la integración con SFML. Permite actualizar, renderizar y gestionar el ciclo de vida de la ventana.

**GUI**: Clase para gestionar todos los aspectos de la interfaz de usuario de ImGui, incluyendo la consola, la jerarquía y el inspector.

**Componentes**: Cada actor tiene componentes que definen su comportamiento y características, como Transform (posición y escala) y ShapeFactory (gestión de forma).
