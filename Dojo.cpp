#include "Dojo.h"
#include <algorithm>

Dojo::Dojo() {
	numeroEstudiantes = 0;
}

Dojo::Dojo(string name) : nombre(name) {
	numeroEstudiantes = 0;
}

string Dojo::getNombre() const {
	return nombre;
}

vector<Estudiante*> Dojo::getEstudiantes() {
	return estudiantes;
}

int Dojo::getNumeroEstudiantes() const {
	return numeroEstudiantes;
}

void Dojo::mostrarEstudiantes() const {
	cout << "Estudiantes del Dojo " << nombre << ":" << endl;
	for (int i = 0; i < numeroEstudiantes; i++) {
		cout << "Nombre: " << estudiantes[i]->getNombre() << ", Cinta: " << estudiantes[i]->getCinta()->getColorCinta() << endl;
	}
}

void Dojo::addEstudiante(Estudiante* estudiante) {
	estudiantes.push_back(estudiante);
	numeroEstudiantes++;
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
		estudiantes.erase(it);
		numeroEstudiantes--;
		delete estudiante;
	}
}

void Dojo::enfrentamiento() {
	cout << "Comienza el enfrentamiento en el Dojo " << nombre << "!" << endl;

	while (true) {
		int estudiantesRestantes = numeroEstudiantes;
		if (estudiantesRestantes <= 1) {
			break;
		}

		for (int i = 0; i < numeroEstudiantes; i += 2) {
			if (i + 1 < numeroEstudiantes) {
				realizarAtaque(estudiantes[i], estudiantes[i + 1]);
			}
		}
	}

	Estudiante* ganador = nullptr;
	if (!estudiantes.empty()) {
		ganador = estudiantes[0];
	}

	if (ganador != nullptr) {
		cout << "El estudiante " << ganador->getNombre() << " del Dojo " << nombre << " es el ganador del torneo!" << endl;
	}
	else {
		cout << "El Dojo " << nombre << " ha sido eliminado del torneo." << endl;
	}
}
