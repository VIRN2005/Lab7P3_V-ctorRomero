#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
#include "Cinta.h"
using namespace std;

class Estudiante {
protected:
	string nombre;
	int edad;
	Cinta* cinta;
	int fuerza;
	int resistencia;
	int overall;
	int vida;

public:
	Estudiante(string _nombre, int _edad, Cinta* _cinta);
	virtual ~Estudiante();

	string getNombre() const;
	int getVida() const;
	int getEdad() const;
	Cinta* getCinta() const;

	int getOverall() const;
	int getResistencia() const;
	void recibirAtaque(int puntos);

	void setNombre(const string&);
	void setEdad(int);
	void setCinta(Cinta*);

	void mostrar() const;
};

#endif
