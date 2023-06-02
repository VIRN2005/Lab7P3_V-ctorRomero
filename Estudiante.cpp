#include "Estudiante.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Estudiante::Estudiante(string _nombre, int _edad, Cinta* _cinta) : nombre(_nombre), edad(_edad), cinta(_cinta), vida(100) {
	srand(time(0));
	fuerza = rand() % 31;
	resistencia = rand() % 31;
	overall = fuerza + cinta->getNivel();
}

Estudiante::~Estudiante() {
	delete cinta;
}

string Estudiante::getNombre() const {
	return nombre;
}

int Estudiante::getEdad() const {
	return edad;
}

int Estudiante::getVida() const {
	return vida;
}

Cinta* Estudiante::getCinta() const {
	return cinta;
}

int Estudiante::getOverall() const {
	return overall;
}

int Estudiante::getResistencia() const {
	return resistencia;
}

void Estudiante::recibirAtaque(int puntos) {
	int defensa = resistencia * cinta->getNivel();
	int daño = puntos - defensa;
	if (daño > 0) {
		vida -= daño;
	}
}

void Estudiante::setNombre(const std::string& nombre) {
	this->nombre = nombre;
}

void Estudiante::setEdad(int edad) {
	this->edad = edad;
}
