#include <iostream>
#include <vector>
#include "Cinta.h"
#include "Dojo.h"
#include "Estudiante.h"
#include "EstudianteBlockchain.h"
#include "EstudianteCobra.h"

using namespace std;

//Intenté como 20 veces y la simulacion no sale tan bien...

/*void simularTorneo(vector<Dojo*>& dojos) {
	// Validar que haya exactamente 4 estudiantes en cada dojo
	for (Dojo* dojo : dojos) {
		if (dojo->getNumeroEstudiantes() != 4) {
			cout << "Debe haber exactamente 4 estudiantes en cada dojo para iniciar el torneo." << endl;
			return;
		}
	}

	// Inicializar vector de estudiantes en el torneo
	vector<Estudiante*> estudiantesTorneo;

	// Agregar estudiantes de cada dojo al torneo
	for (Dojo* dojo : dojos) {
		vector<Estudiante*> estudiantes = dojo->getEstudiantes();
		estudiantesTorneo.insert(estudiantesTorneo.end(), estudiantes.begin(), estudiantes.end());
	}

	// Comenzar el torneo
	while (true) {
		// Obtener cantidad de estudiantes de cada dojo en el torneo
		int estudiantesDojoCobra = 0;
		int estudiantesDojoBlockchain = 0;
		for (Estudiante* estudiante : estudiantesTorneo) {
			if (estudiante->getDojo()->getNombre() == "Cobra") {
				estudiantesDojoCobra++;
			}
			else if (estudiante->getDojo()->getNombre() == "Blockchain") {
				estudiantesDojoBlockchain++;
			}
		}

		// Verificar condiciones de finalización del torneo
		if (estudiantesDojoCobra == 0 && estudiantesDojoBlockchain > 0) {
			cout << "¡El Dojo ganador es Blockchain!" << endl;
			break;
		}
		else if (estudiantesDojoCobra > 0 && estudiantesDojoBlockchain == 0) {
			cout << "¡El Dojo ganador es Cobra!" << endl;
			break;
		}
		else if (estudiantesDojoCobra == 0 && estudiantesDojoBlockchain == 0) {
			cout << "¡El torneo terminó en empate!" << endl;
			break;
		}

		// Seleccionar estudiantes para enfrentamiento
		Estudiante* estudiante1 = nullptr;
		Estudiante* estudiante2 = nullptr;

		// Si hay más estudiantes en un dojo, se selecciona aleatoriamente un estudiante de ese dojo
		if (estudiantesDojoCobra > estudiantesDojoBlockchain) {
			while (!estudiante1 || !estudiante2 || estudiante1->getDojo() == estudiante2->getDojo()) {
				estudiante1 = dojos[0]->getEstudiantes()[rand() % 4];
				estudiante2 = dojos[1]->getEstudiantes()[rand() % 4];
			}
		}
		else if (estudiantesDojoBlockchain > estudiantesDojoCobra) {
			while (!estudiante1 || !estudiante2 || estudiante1->getDojo() == estudiante2->getDojo()) {
				estudiante1 = dojos[1]->getEstudiantes()[rand() % 4];
				estudiante2 = dojos[0]->getEstudiantes()[rand() % 4];
			}
		}
		else {
			// Si hay igual cantidad de estudiantes en ambos dojos, se selecciona aleatoriamente un estudiante de cada dojo
			while (!estudiante1 || !estudiante2 || estudiante1->getDojo() == estudiante2->getDojo()) {
				estudiante1 = dojos[0]->getEstudiantes()[rand() % 4];
				estudiante2 = dojos[1]->getEstudiantes()[rand() % 4];
			}
		}

		// Calcular ataques y defensas
		double porcentajeAtaqueEstudiante1 = estudiante1->getOverallFuerza() * estudiante1->getPorcentajeCinta();
		double porcentajeAtaqueEstudiante2 = estudiante2->getOverallFuerza() * estudiante2->getPorcentajeCinta();

		double porcentajeDefensaEstudiante1 = estudiante1->getResistencia() * estudiante1->getNivelCinta();
		double porcentajeDefensaEstudiante2 = estudiante2->getResistencia() * estudiante2->getNivelCinta();

		// Calcular daño recibido por cada estudiante
		int danoEstudiante1 = static_cast<int>(porcentajeAtaqueEstudiante2 - porcentajeDefensaEstudiante1);
		int danoEstudiante2 = static_cast<int>(porcentajeAtaqueEstudiante1 - porcentajeDefensaEstudiante2);

		// Reducir vida de los estudiantes según el daño recibido
		estudiante1->reducirVida(danoEstudiante1);
		estudiante2->reducirVida(danoEstudiante2);

		// Verificar si algún estudiante ha quedado fuera del torneo
		if (estudiante1->getVida() <= 0) {
			estudiantesTorneo.erase(std::remove(estudiantesTorneo.begin(), estudiantesTorneo.end(), estudiante1), estudiantesTorneo.end());
			delete estudiante1;
		}
		if (estudiante2->getVida() <= 0) {
			estudiantesTorneo.erase(std::remove(estudiantesTorneo.begin(), estudiantesTorneo.end(), estudiante2), estudiantesTorneo.end());
			delete estudiante2;
		}
	}

	// Liberar memoria de los estudiantes eliminados
	for (Dojo* dojo : dojos) {
		for (Estudiante* estudiante : dojo->getEstudiantes()) {
			delete estudiante;
		}
		dojo->limpiarEstudiantes();
	}
}*/


void menu() {
	int opcion;
	vector<Dojo*> dojos;
	Dojo* dojoCobra = new Dojo();
	Dojo* dojoBlockchain = new Dojo();
	dojos.push_back(dojoCobra);
	dojos.push_back(dojoBlockchain);

	do {
		cout << "---MENU---\n";
		cout << "1) Crear Estudiante \n";
		cout << "2) Modificar Estudiante \n";
		cout << "3) Eliminar Estudiante \n";
		cout << "4) Listar Estudiante \n";
		cout << "5) Promover Cinta Estudiante \n";
		cout << "6) Degradar Cinta Estudiante \n";
		cout << "7) Simulacion\n";
		cout << "8) SALIR\n\n";

		cout << "Ingrese la Opcion a escoger: ";
		cin >> opcion;
		cout << endl;

		switch (opcion) {
		case 1: { // AGREGAR
			int dojo = 0;
			cout << "--- AGREGAR ESTUDIANTE... ESCOJA EL DOJO ---\n";
			cout << "1) Dojo Cobra \n";
			cout << "2) Dojo Blockchain \n\n";
			cout << "Ingrese el Dojo a escoger: ";
			cin >> dojo;

			switch (dojo) {
			case 1: { //Dojo Cobra
				string nombre = "";
				cout << "Ingrese el Nombre: ";
				cin >> nombre;
				int edad = 0;
				cout << "Ingrese la Edad: ";
				cin >> edad;

				EstudianteCobra* cobra = new EstudianteCobra(nombre, edad, new Cinta(1));

				if (dojos.size() > 0) {
					dojos[0]->addEstudiante(cobra);
				}
				else {
					cout << "No se encontró el Dojo Cobra. Por favor, crea el Dojo primero." << endl;
				}
			}
				  break;

			case 2: {
				string nombre = "";
				cout << "Ingrese el Nombre: ";
				cin >> nombre;
				int edad = 0;
				cout << "Ingrese la Edad: ";
				cin >> edad;

				EstudianteBlockchain* blockchain = new EstudianteBlockchain(nombre, edad, new Cinta(1));

				if (dojos.size() > 1) {
					dojos[1]->addEstudiante(blockchain);
				}
				else {
					cout << "No se encontró el Dojo Blockchain. Por favor, crea el Dojo primero." << endl;
				}
			}
				  break;
			}
		}
			  break;

		case 2: { // MODIFICAR
			for (Dojo* dojo : dojos) {
				dojo->mostrarEstudiantes();
				cout << "Ingrese la posición del estudiante a modificar: ";
				int pos;
				cin >> pos;

				if (pos >= 0 && pos < dojo->getNumeroEstudiantes() && dojo->getEstudiantes()[pos] != nullptr) {
					string nuevoNombre;
					int nuevaEdad;

					cout << "Ingrese el nuevo nombre: ";
					cin >> nuevoNombre;
					cout << "Ingrese la nueva edad: ";
					cin >> nuevaEdad;

					dojo->getEstudiantes()[pos]->setNombre(nuevoNombre);
					dojo->getEstudiantes()[pos]->setEdad(nuevaEdad);
				}
				else {
					cout << "Posición inválida o estudiante no encontrado." << endl;
				}
			}
		}
			  break;

		case 3: { // Eliminar
			int dojo;
			cout << "--- ELIMINAR ESTUDIANTE... ESCOJA EL DOJO ---\n";
			cout << "1) Dojo Cobra \n";
			cout << "2) Dojo Blockchain \n\n";
			cout << "Ingrese el Dojo a escoger: ";
			cin >> dojo;

			switch (dojo) {
			case 1: {
				if (dojos.size() > 0) {
					dojos[0]->mostrarEstudiantes();
					cout << "Ingrese la posición del estudiante a eliminar: ";
					int pos;
					cin >> pos;

					if (pos >= 0 && pos < dojos[0]->getNumeroEstudiantes() && dojos[0]->getEstudiantes()[pos] != nullptr) {
						dojos[0]->eliminarEstudiante(dojos[0]->getEstudiantes()[pos]);
						cout << "Estudiante eliminado correctamente." << endl;
					}
					else {
						cout << "Posición inválida o estudiante no encontrado." << endl;
					}
				}
				else {
					cout << "No se encontró el Dojo Cobra. Por favor, crea el Dojo primero." << endl;
				}
			}
				  break;

			case 2: {
				if (dojos.size() > 1) {
					dojos[1]->mostrarEstudiantes();
					cout << "Ingrese la posición del estudiante a eliminar: ";
					int pos;
					cin >> pos;

					if (pos >= 0 && pos < dojos[1]->getNumeroEstudiantes() && dojos[1]->getEstudiantes()[pos] != nullptr) {
						dojos[1]->eliminarEstudiante(dojos[1]->getEstudiantes()[pos]);
						cout << "Estudiante eliminado correctamente." << endl;
					}
					else {
						cout << "Posición inválida o estudiante no encontrado." << endl;
					}
				}
				else {
					cout << "No se encontró el Dojo Blockchain. Por favor, crea el Dojo primero." << endl;
				}
			}
				  break;
			}
		}
			  break;

		case 4: { // Listar
			for (Dojo* dojo : dojos) {
				dojo->mostrarEstudiantes();
			}
		}
			  break;

		case 5: { // Promover Cinta
			for (Dojo* dojo : dojos) {
				dojo->mostrarEstudiantes();
				cout << "Ingrese la posición del estudiante a promover cinta: ";
				int pos;
				cin >> pos;

				if (pos >= 0 && pos < dojo->getNumeroEstudiantes() && dojo->getEstudiantes()[pos] != nullptr) {
					++(*dojo->getEstudiantes()[pos]->getCinta());
					cout << "Cinta promovida correctamente." << endl;
				}
				else {
					cout << "Posición inválida o estudiante no encontrado." << endl;
				}
			}
		}
			  break;

		case 6: { // Degradar Cinta
			for (Dojo* dojo : dojos) {
				dojo->mostrarEstudiantes();
				cout << "Ingrese la posición del estudiante a degradar cinta: ";
				int pos;
				cin >> pos;

				if (pos >= 0 && pos < dojo->getNumeroEstudiantes() && dojo->getEstudiantes()[pos] != nullptr) {
					--(*dojo->getEstudiantes()[pos]->getCinta());
					cout << "Cinta degradada correctamente." << endl;
				}
				else {
					cout << "Posición inválida o estudiante no encontrado." << endl;
				}
			}
		}
			  break;

		case 7: {
			// Simulacion
			/*if (dojos.size() > 1) {
				Dojo* dojoCobra = dojos[0];
				Dojo* dojoBlockchain = dojos[1];

				cout << "Simulación Dojo Cobra" << endl;
				cout << "----------------------------------------" << endl;
				dojoCobra->simulacion();

				cout << endl;

				cout << "Simulación Dojo Blockchain" << endl;
				cout << "----------------------------------------" << endl;
				dojoBlockchain->simulacion();
			}
			else {
				cout << "No se encontraron los Dojos Cobra y Blockchain. Por favor, crea los Dojos primero." << endl;
			}*/

		}
			  break;
		}

		cout << "-----------------------------------------------\n\n";
	} while (opcion != 8);
}

int main() {
	menu();

	return 0;
}

