#pragma once

/*
 * @file Prerequisites.h
 * @brief Archivo de cabecera que incluye las bibliotecas estándar, bibliotecas de terceros y macros utilizadas en el proyecto.
*/

//Lbrerias STD

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <thread>
#include <map>
#include <fstream> 

//Third Parties

#include <SFML/Graphics.hpp>
#include <Memory/TSharedPointer.h> 
#include <Memory/TStaticPtr.h>
#include <Memory/TUniquePtr.h>
#include <Memory/TWeakPointer.h>

//IMGUI
#include <imgui.h>
#include <imgui-SFML.h>


/*
 * @brief Enumeración ShapeType para definir los diferentes tipos de formas.
 *
 * Los valores incluyen formas como CIRCLE, RECTANGLE, y TRIANGLE.
*/

enum
ShapeType {
  EMPTY=0,
  CIRCLE = 1,
  RECTANGLE = 2,
  TRIANGLE = 3
};

enum
ConsolErrorType {
  NORMAL = 0,
  WARNING= 1,
  ERROR= 2

};


// MACRO for safe release of resources
#define SAFE_PTR_RELEASE(x) if(x != nullptr) { delete x; x = nullptr; }

/*
 * @brief Macro para mostrar un mensaje de creación de recursos.
 *
 * Muestra un mensaje en la consola con el nombre de la clase, método y el estado de la creación del recurso.
 * @param classObj Nombre de la clase.
 * @param method Nombre del método.
 * @param state Estado del recurso creado.
*/

#define MESSAGE(classObj, method, state)                      \
{                                                             \
    std::ostringstream os_;                                   \
    os_ << classObj << "::" << method << " : "                \
        << "[CREATION OF RESOURCE" << ": " << state << "] \n";\
    std::cerr << os_.str();                                   \
}

/*
 * @brief Macro para mostrar un mensaje de error.
 *
 * Muestra un mensaje de error en la consola con el nombre de la clase, método y el mensaje de error. Luego, finaliza el programa.
 * @param classObj Nombre de la clase.
 * @param method Nombre del método.
 * @param errorMSG Mensaje de error a mostrar.
*/

#define ERROR(classObj, method, errorMSG)                         \
{                                                                 \
    std::ostringstream os_;                                       \
    os_ << "ERROR : " << classObj << "::" << method << " : "      \
        << "  Error in data from params [" << errorMSG << "] \n"; \
    std::cerr << os_.str();                                       \
    exit(1);                                                      \
}
