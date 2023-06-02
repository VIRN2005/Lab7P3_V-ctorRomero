#include "EstudianteBlockchain.h"
#include <cstdlib>
#include <ctime>

EstudianteBlockchain::EstudianteBlockchain(std::string _nombre, int _edad, Cinta* _cinta) : Estudiante(_nombre, _edad, _cinta) {
	srand(time(0));
	fuerzaBrazos = rand() % 11;
	overall += fuerzaBrazos;
}

int EstudianteBlockchain::getFuerzaBrazos() const {
	return fuerzaBrazos;
}

