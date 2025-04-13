#pragma once
#include "MathLibrary.h"

class 
Vector3{
public:

	float x; //Componente x del vector
 	float y; //Componente y del vector
	float z; //Componente z del vector

	/*
	* Constructor por defecto
	* Inicializa el vector con los valores (0, 0, 0)
	*/
	Vector3() : x(0), y(0), z(0) {};

	/**
	 * Constructor que inicializa un vector con valores específicos.
	 * @param valX: Valor para el componente x.
	 * @param valY: Valor para el componente y.
	 * @param valZ: Valor para el componente z.
	 */
	Vector3(float valX, float valY, float valZ) :x(valX), y(valY), z(valZ) {};
	/**
	 * Sobrecarga del operador + para sumar dos vectores.
	 * @param other: El vector con el que se va a sumar el vector actual.
	 * @return Un nuevo vector que es la suma del actual y el otro vector.
	 */
	Vector3 operator+(const Vector3& other)const {
		float new_valX = x + other.x;
		float new_valY = y + other.y;
		float new_valZ = z+ other.z;
		return Vector3(new_valX, new_valY, new_valZ);
	}
	/**
	 * Sobrecarga del operador - para restar dos vectores.
	 * @param other: El vector que se va a restar del vector actual.
	 * @return Un nuevo vector que es la resta del actual y el otro vector.
	 */
	Vector3 operator-(const Vector3& other)const {
		float new_valX = x - other.x;
		float new_valY = y - other.y;
		float new_valZ = z - other.z;
		return Vector3(new_valX, new_valY, new_valZ);
	}
	/**
	 * Sobrecarga del operador * para multiplicar el vector por un escalar.
	 * @param escalar: El valor escalar por el que se multiplicará el vector.
	 * @return Un nuevo vector resultante de la multiplicación por el escalar.
	 */
	Vector3 operator*(float escalar)const {
		float new_valX = x * escalar;
		float new_valY = y * escalar;
		float new_valZ = z * escalar;
		return Vector3(new_valX, new_valY, new_valZ);
	}
	/**
	 * Calcula la magnitud (longitud) del vector.
	 * @return La magnitud del vector.
	 */
	float 
	magnitud() const {
		return MraizNewton(x * x + y * y + z * z);
	}
	/**
	 * Devuelve el vector normalizado (unidad), es decir,con magnitud 1.
	 * @return Un nuevo vector que es la versión normalizada del vector actual.
	 */
	Vector3 normalizar() const {
		float mag = magnitud();
		if (mag == 0) {
			return Vector3(0, 0, 0);
		}
		return Vector3(x / mag, y / mag, z/mag);
	}
	/**
	 * Devuelve un puntero a los datos del vector (para acceso no constante).
	 * @return Un puntero a la componente x del vector.
	 */
	float*data() {
		return &x;
	}

	/**
	 * Devuelve un puntero a los datos del vector (para acceso constante).
	 * @return Un puntero constante a la componente x del vector.
	 */
	const float* data() const {
		return &x;
	}

private:

};

