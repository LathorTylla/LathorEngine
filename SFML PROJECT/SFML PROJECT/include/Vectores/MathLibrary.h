#pragma once
/**
 * Calcula la raíz cuadrada de un número utilizando el método de Newton-Raphson.
 * Este algoritmo aproxima la raíz cuadrada de un valor mediante iteraciones.
 * Si el valor es negativo, devuelve 0.
 *
 * @param valor: El número del cual se quiere calcular la raíz cuadrada.
 * @return La aproximación de la raíz cuadrada del valor dado.
 */

inline float MraizNewton(float valor) {
  if (valor < 0) {
    return 0; //Regresa si el valor no es positivo
  }
  float x = valor;            //Estimacion inicial para poder calcular la raiz
  float y = 1.0f;             //Valor de y
  float epsilon = 0.000001f;  //Margen de error o aproximacion

  // Bucle while hasta que la diferencia entre x e y sea menor que epsilon.
  while (x-y>epsilon){
    x = (x + y) / 2.0f; //Formula para poder sacar la aproximacion de x
    y = valor / x;   //Nuevo valor de y
  }
  return x;  //Regresa la aproximacion de la raiz cuadrada
}

//Funciones trigonometricas, coseno, seno y tangente

/**
 * Calcula el coseno de un ángulo en radianes utilizando la serie de Taylor.
 * La serie de Taylor aproxima el coseno mediante una suma infinita de términos.
 *
 * @param angle Ángulo en radianes del cual se quiere calcular el coseno.
 * @return La aproximación del coseno del ángulo dado.
 */
inline float Mcos(float angle) {
  float result = 1.0f;                  // Primer término de la serie (cos(0) = 1)
  float term = 1.0f;                    // Término actual de la serie
  float angle_squared = angle * angle;  // Precalcular el ángulo al cuadrado
  int n = 1;                            // Índice de la serie de Taylor
  while (term > 1e-6f || term < -1e-6f) {
    term *= -angle_squared / ((2 * n - 1) * (2 * n)); // Calcular el siguiente término
    result += term;                     // Sumar el término al resultado
    ++n;                                // Incrementar el índice de la serie
  }
  return result;                        // Regresa el resultado aproximado
}

/**
 * Calcula el seno de un ángulo en radianes utilizando la serie de Taylor.
 * La serie de Taylor aproxima el seno mediante una suma infinita de términos.
 *
 * @param angle Ángulo en radianes del cual se quiere calcular el seno.
 * @return La aproximación del seno del ángulo dado.
 */

inline float Msin(float angle) {
  float result = 0.0f;                  // El seno de 0 es 0
  float term = angle;                   // Primer término de la serie
  float angle_squared = angle * angle;  // Calcular el ángulo al cuadrado
  int n = 1;                            // Índice de la serie de Taylor

  while (term > 1e-6f || term < -1e-6f) {
    result += term;                     // Sumar el término al resultado
    term *= -angle_squared / ((2 * n) * (2 * n + 1)); // Calcular el siguiente término
    ++n;                                // Incrementar el índice de la serie
  }
  return result;                        // Regresa el resultado aproximado
}

/**
 * Calcula la tangente de un ángulo en radianes.
 * La tangente se calcula como la división entre el seno y el coseno.
 *
 * @param angle Ángulo en radianes del cual se quiere calcular la tangente.
 * @return La aproximación de la tangente del ángulo dado, o 0 si el coseno es 0.
 */

inline float Mtan(float angle) {
  float sinVal = Msin(angle);            // Calcular el seno del ángulo
  float cosVal = Mcos(angle);            // Calcular el coseno del ángulo
  if (cosVal == 0) {
    return 0; // Evitar divisiones por 0
  }
  return sinVal / cosVal;               // Regresa el valor de la tangete (seno/coseno)
}

/**
 * Convierte un ángulo de grados a radianes.
 * Para mejores practicas y se hace uso de los radianes
 *
 * @param degrees Ángulo en grados.
 * @return El ángulo convertido a radianes.
 */
inline float MdegToRad(float degrees) {
  return degrees * (3.1416f / 180.0f);
}

/**
 * Convierte un ángulo de radianes a grados.
 * Los ángulos en radianes se pueden convertir a grados para facilitar la interpretación.
 *
 * @param radians Ángulo en radianes.
 * @return El ángulo convertido a grados.
 */
inline float MradToGrad(float radians) {
  return radians * (180.0f / 3.1416f);
}



