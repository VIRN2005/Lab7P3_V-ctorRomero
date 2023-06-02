#ifndef ESTUDIANTEBLOCKCHAIN_H
#define ESTUDIANTEBLOCKCHAIN_H

#include <iostream>
#include <string>
#include "Estudiante.h"
using namespace std;

class EstudianteBlockchain : public Estudiante {
private:
	int fuerzaBrazos;

public:
	EstudianteBlockchain(string _nombre, int _edad, Cinta* _cinta);
	int getFuerzaBrazos() const;
	void operator++();
	void operator--();
};

#endif
