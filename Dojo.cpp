#include "Dojo.h"

Dojo::Dojo() {
}

Dojo::Dojo(string name) : nombre(name) {
}

string Dojo::getNombre() const {
	return nombre;
}

void Dojo::addEstudiante(Estudiante* student) {

	for (int i = 0; i < 4; i++) {
		if (estudiantes[i] == nullptr) {
			estudiantes[i] = student;
			cout << "El estudiante " << student->getNombre() << " ha sido agregado al Dojo " << nombre << endl;
			return;
		}
	}
	cout << "El Dojo " << nombre << " ya tiene el máximo de estudiantes permitidos" << endl;
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
	for (int i = 0; i < 4; i++) {
		if (estudiantes[i] == estudiante) {
			delete estudiantes[i];
			estudiantes[i] = nullptr;
			cout << "El estudiante " << estudiante->getNombre() << " del Dojo " << nombre << " ha sido eliminado del torneo." << endl;
			return;
		}
	}
}
