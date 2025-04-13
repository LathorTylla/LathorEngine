#pragma once
#include "MathLibrary.h"

class 
Vector4{
public:
	float x; //Componente x del vector
	float y; //Componente y del vector
	float z; //Componente z del vector
	float w; //Componente w del vector

	/**
	 * Constructor por defecto.
	 * Inicializa el vector con los valores (0, 0, 0, 0).
	 */

	Vector4() : x(0), y(0), z(0), w(0) {};
	/**
	 * Constructor que inicializa un vector con valores específicos.
	 * @param valX: Valor para el componente x.
	 * @param valY: Valor para el componente y.
	 * @param valZ: Valor para el componente z.
	 * @param valZ: Valor para el componente w.
	 */
	Vector4(float valX, float valY, float valZ, float valW) :x(valX), y(valY), z(valZ), w(valW) {};
	/**
	 * Sobrecarga del operador + para sumar dos vectores.
	 * @param other: El vector con el que se va a sumar el vector actual.
	 * @return Un nuevo vector que es la suma del actual y el otro vector.
	 */
	Vector4 operator+(const Vector4& other)const {
		float new_valX = x + other.x;
		float new_valY = y + other.y;
		float new_valZ = z + other.z;
		float new_valW = w + other.w;
		return Vector4(new_valX, new_valY, new_valZ, new_valW);
	}
	/**
	 * Sobrecarga del operador - para restar dos vectores.
	 * @param other: El vector que se va a restar del vector actual.
	 * @return Un nuevo vector que es la resta del actual y el otro vector.
	 */
	Vector4 operator-(const Vector4& other)const {
		float new_valX = x + other.x;
		float new_valY = y + other.y;
		float new_valZ = z + other.z;
		float new_valW = w + other.w;
		return Vector4(new_valX, new_valY, new_valZ, new_valW);
	}
	/**
	 * Sobrecarga del operador * para multiplicar el vector por un escalar.
	 * @param escalar: El valor escalar por el que se multiplicará el vector.
	 * @return Un nuevo vector resultante de la multiplicación por el escalar.
	 */
	Vector4 operator*(float escalar)const {
		float new_valX = x * escalar;
		float new_valY = y * escalar;
		float new_valZ = z * escalar;
		float new_valW = w * escalar;
		return Vector4(new_valX, new_valY, new_valZ, new_valW);
	}
	/**
	 * Calcula la magnitud (longitud) del vector.
	 * @return La magnitud del vector.
	 */
	float
	magnitud() const {
		return MraizNewton(x * x + y * y + z * z + w * w);
	}
	/**
	 * Devuelve el vector normalizado (unidad), es decir,con magnitud 1.
	 * @return Un nuevo vector que es la versión normalizada del vector actual.
	 */
	Vector4 normalizar() const {
		float mag = magnitud();
		if (mag == 0) {
			return Vector4(0, 0, 0, 0);
		}
		return Vector4(x / mag, y / mag, z / mag, w/mag);
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
private:

};
