#pragma once
#include "MathLibrary.h"

class
Vector2 {
public:
	float x; //Componente x del vector
	float y; //Componente y del vector

	/**
   * Constructor por defecto.
   * Inicializa el vector con los valores (0, 0).
	 */
	Vector2() : x(0), y(0) {};

	/**
	 * Constructor que inicializa un vector con valores específicos.
	 * @param valX: Valor para el componente x.
	 * @param valY: Valor para el componente y.
	 */
	Vector2(float valX, float valY) : x(valX), y(valY) {};

	/**
	 * Sobrecarga del operador + para sumar dos vectores.
	 * @param other: El vector con el que se va a sumar el vector actual.
	 * @return Un nuevo vector que es la suma del actual y el otro vector.
   */
	Vector2
	operator+(const Vector2& other)const {
		float new_valX = x + other.x;
		float new_valY = y + other.y;
		return Vector2(new_valX, new_valY);
	}

	/**
	 * Sobrecarga del operador - para restar dos vectores.
	 * @param other: El vector que se va a restar del vector actual.
	 * @return Un nuevo vector que es la resta del actual y el otro vector.
	 */
	Vector2
	operator-(const Vector2& other)const {
		float new_valX = x - other.x;
		float new_valY = y - other.y;
		return Vector2(new_valX, new_valY);
	}

	/**
	 * Sobrecarga del operador * para multiplicar el vector por un escalar.
	 * @param escalar: El valor escalar por el que se multiplicará el vector.
	 * @return Un nuevo vector resultante de la multiplicación por el escalar.
	 */
	Vector2
	operator*(float escalar)const {
		float new_valX = x * escalar;
		float new_valY = y * escalar;
		return Vector2(new_valX, new_valY);
	}

	/**
	 * Calcula la magnitud (longitud) del vector.
	 * @return La magnitud del vector.
	 */
	float
	magnitud() const {
		return MraizNewton(x * x + y * y);
	}

	/**
	 * Devuelve el vector normalizado (unidad), es decir, con magnitud 1.
	 * @return Un nuevo vector que es la versión normalizada del vector actual.
	 */
	Vector2 
	normalizar() const {
		float mag = magnitud();
		if (mag == 0) {
			return Vector2(0, 0);
		}
		return Vector2(x / mag, y / mag);
	}

	/**
	 * Devuelve un puntero a los datos del vector (para acceso no constante).
	 * @return Un puntero a la componente x del vector.
	 */
	float*
	data() {
		return &x;
	}

	/**
	 * Devuelve un puntero a los datos del vector (para acceso constante).
	 * @return Un puntero constante a la componente x del vector.
	 */
	const float*
	data() const {
		return &x;
	}

	/**
 * Sobrecarga del operador += para sumar otro vector al vector actual.
 * @param other: El vector a sumar al vector actual.
 * @return Una referencia al vector actual después de la operación.
 */
	Vector2& 
	operator+=(const Vector2& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	/**
	 * Sobrecarga del operador /= para dividir el vector actual por un escalar.
	 * @param escalar: El escalar por el que se dividirá el vector actual.
	 * @return Una referencia al vector actual después de la operación.
	 * @throws std::invalid_argument si el escalar es 0.
	 */
	Vector2& 
	operator/=(float escalar) {
		if (escalar == 0) {
			throw std::invalid_argument("Division by zero is not allowed.");
		}
		x /= escalar;
		y /= escalar;
		return *this;
	}
};

