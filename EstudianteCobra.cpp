#include "Estudiante.h"
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

