#include "EstudianteCobra.h"
#include <cstdlib>
#include <ctime>

EstudianteCobra::EstudianteCobra(string _nombre, int _edad, Cinta* _cinta) : Estudiante(_nombre, _edad, _cinta) {
	srand(time(0));
	fuerzaPiernas = rand() % 11;
	overall += fuerzaPiernas;
}

int EstudianteCobra::getFuerzaPiernas() const {
	return fuerzaPiernas;
}

void EstudianteCobra::operator++() {
	// Ascenso de nivel
	if (cinta->getNivel() < 7) {
		++(*cinta);
		overall = fuerza + cinta->getNivel();
	}
}

void EstudianteCobra::operator--() {
	// Descenso de nivel
	if (cinta->getNivel() > 1) {
		--(*cinta);
		overall = fuerza + cinta->getNivel();
	}
}

