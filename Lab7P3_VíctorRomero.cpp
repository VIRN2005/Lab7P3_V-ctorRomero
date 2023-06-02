#include <iostream>
#include <vector>
#include "Cinta.h"
#include "Dojo.h"
#include "Estudiante.h"
#include "EstudianteBlockchain.h"
#include "EstudianteCobra.h"

using namespace std;

void menu() {
	int opcion;
	vector<Dojo*> dojos;

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
			if (dojos.size() > 0) {
				dojos[0]->mostrarEstudiantes();
				cout << "Ingrese la posición del estudiante a modificar: ";
				int pos;
				cin >> pos;

				if (pos >= 0 && pos < dojos[0]->getNumeroEstudiantes() && dojos[0]->getEstudiantes()[pos] != nullptr) {
					string nuevoNombre;
					int nuevaEdad;

					cout << "Ingrese el nuevo nombre: ";
					cin >> nuevoNombre;
					cout << "Ingrese la nueva edad: ";
					cin >> nuevaEdad;

					dojos[0]->getEstudiantes()[pos]->setNombre(nuevoNombre);
					dojos[0]->getEstudiantes()[pos]->setEdad(nuevaEdad);
				}
				else {
					cout << "Posición inválida o estudiante no encontrado." << endl;
				}
			}

			if (dojos.size() > 1) {
				dojos[1]->mostrarEstudiantes();
				cout << "Ingrese la posición del estudiante a modificar: ";
				int pos;
				cin >> pos;

				if (pos >= 0 && pos < dojos[1]->getNumeroEstudiantes() && dojos[1]->getEstudiantes()[pos] != nullptr) {
					string nuevoNombre;
					int nuevaEdad;

					cout << "Ingrese el nuevo nombre: ";
					cin >> nuevoNombre;
					cout << "Ingrese la nueva edad: ";
					cin >> nuevaEdad;

					dojos[1]->getEstudiantes()[pos]->setNombre(nuevoNombre);
					dojos[1]->getEstudiantes()[pos]->setEdad(nuevaEdad);
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
			if (dojos.size() > 0) {
				dojos[0]->mostrarEstudiantes();
			}

			if (dojos.size() > 1) {
				dojos[1]->mostrarEstudiantes();
			}
		}
			  break;

		case 5: { // Promover Cinta
			if (dojos.size() > 0) {
				dojos[0]->mostrarEstudiantes();
			}

			if (dojos.size() > 1) {
				dojos[1]->mostrarEstudiantes();
			}

			/*cout << "Nivel inicial de la cinta: " << Cinta.getNivel() << endl;
			++cinta;
			cout << "Nivel de la cinta después de incrementar: " << cinta.getNivel() << endl;*/
		}
			  break;

		case 6: { // Degradar Cinta
			if (dojos.size() > 0) {
				dojos[0]->mostrarEstudiantes();
			}

			if (dojos.size() > 1) {
				dojos[1]->mostrarEstudiantes();
			}

			/*cout << "Nivel inicial de la cinta: " << Cinta.getNivel() << endl;
			--cinta;
			std::cout << "Nivel de la cinta después de decrementar: " << cinta.getNivel() << endl;*/
		}
			  break;

		case 7: {
			// Simulacion
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
