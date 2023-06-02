#include "Dojo.h"

Dojo::Dojo() {
}

Dojo::Dojo(string name) : nombre(name) {
}

string Dojo::getNombre() const {
	return nombre;
}

vector<Estudiante*> getEstudiantes() {
	return estudiantes;
}

void Dojo::mostrarEstudiantes() const {
	std::cout << "Estudiantes del Dojo " << nombre << ":" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (estudiantes[i] != nullptr) {
			std::cout << "Nombre: " << estudiantes[i]->getNombre() << ", Cinta: " << estudiantes[i]->getCinta()->getColorCinta() << std::endl;
		}
	}
}


void Dojo::realizarAtaque(Estudiante* attacker, Estudiante* def) {
	int attack = attacker->getOverall() * attacker->getCinta()->getPorcentaje();
	def->recibirAtaque(attack);

	cout << attacker->getNombre() << " del Dojo " << nombre << " ataca a " << def->getNombre() << " del Dojo " << nombre << endl;
	cout << "Ataque: " << attack << ", Vida restante de " << def->getNombre() << ": " << def->getVida() << endl;

	if (def->getVida() <= 0) {
		eliminarEstudiante(def);
	}
}

void Dojo::eliminarEstudiante(Estudiante* estudiante) {
	auto it = find(estudiantes.begin(), estudiantes.end(), estudiante);
	if (it != estudiantes.end()) {
		delete* it;
		estudiantes.erase(it);
	}
}