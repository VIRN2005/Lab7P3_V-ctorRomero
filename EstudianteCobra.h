#ifndef ESTUDIANTECOBRA_H
#define ESTUDIANTECOBRA_H

#include <iostream>
#include <string>
#include "Estudiante.h"
using namespace std;

class EstudianteCobra : public Estudiante {
private:
	int fuerzaPiernas;

public:
	EstudianteCobra(string _nombre, int _edad, Cinta* _cinta);
	int getFuerzaPiernas() const;
};

#endif

