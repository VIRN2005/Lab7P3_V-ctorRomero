#ifndef DOJO_H
#define DOJO_H

#include <iostream>
#include <string>
#include <vector>
#include "Estudiante.h"
using namespace std;

class Dojo {
private:
	int numeroEstudiantes;
	string nombre;
	vector<Estudiante*> estudiantes;

public:
	Dojo();
	Dojo(string);
	string getNombre() const;
	void mostrarEstudiantes() const;
	vector<Estudiante*> getEstudiantes();
	void addEstudiante(Estudiante*);
	void enfrentamiento();
	void realizarAtaque(Estudiante*, Estudiante*);
	void eliminarEstudiante(Estudiante*);
	int getNumeroEstudiantes() const;
	void promoverEstudiante(Estudiante*);
	void degradarEstudiante(Estudiante*);
	void simulacion();

};

#endif



