#include "EstudianteBlockchain.h"
#include <cstdlib>
#include <ctime>

EstudianteBlockchain::EstudianteBlockchain(string _nombre, int _edad, Cinta* _cinta) : Estudiante(_nombre, _edad, _cinta) {
	srand(time(0));
	fuerzaBrazos = rand() % 11;
	overall += fuerzaBrazos;
}

int EstudianteBlockchain::getFuerzaBrazos() const {
	return fuerzaBrazos;
}

void EstudianteBlockchain::operator++() {
	// Ascenso de nivel
	if (cinta->getNivel() < 7) {
		++(*cinta);
		overall = fuerza + cinta->getNivel();
	}
}

void EstudianteBlockchain::operator--() {
	// Descenso de nivel
	if (cinta->getNivel() > 1) {
		--(*cinta);
		overall = fuerza + cinta->getNivel();
	}
}

