#ifndef DOJO_H
#define DOJO_H

#include <iostream>
#include <string>
#include "Estudiante.h"
using namespace std;

class Dojo {
private:
	string nombre;
	Estudiante* estudiantes[4];

public:
	Dojo();
	Dojo(string);
	string getNombre() const;
	void mostrarRegistros();
	void addEstudiante(Estudiante*);
	void enfrentamiento();

private:
	void realizarAtaque(Estudiante*, Estudiante*);
	void eliminarEstudiante(Estudiante*);
};

#endif


