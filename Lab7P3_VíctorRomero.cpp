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
	vector <EstudianteCobra*> Est_Cobra;
	vector <EstudianteBlockchain*> Est_Blockchain;

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
			case 1: { //DojoCobra
				string nombre = "";
				cout << "Ingrese el Nombre: ";
				cin >> nombre;
				int edad = 0;
				cout << "Ingrese la Edad: ";
				cin >> edad;

				EstudianteCobra* cobra = new EstudianteCobra(nombre, edad, new Cinta(1));
				Est_Cobra.push_back(cobra);
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
				Est_Blockchain.push_back(blockchain);
			}
				  break;
			}
		}
			  break;

		case 2: { // MODIFICAR
			cout << "Estudiantes Dojo Cobra\n";
			int i = 0;
			for (const auto& estudiante : Est_Cobra) {
				cout << i++ << ")  Nombre: " << estudiante->getNombre() << ", Edad: " << estudiante->getEdad() << "\n";
			}


			cout << "Estudiantes Dojo BlockChain\n";
			int i = 0;
			for (const auto& estudiante : Est_Blockchain) {
				cout << i++ << ")  Nombre: " << estudiante->getNombre() << ", Edad: " << estudiante->getEdad() << "\n";
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
				cout << "Estudiantes Dojo Cobra\n";
				int i = 0;
				for (const auto& estudiante : Est_Cobra) {
					cout << i++ << ")  Nombre: " << estudiante->getNombre() << ", Edad: " << estudiante->getEdad() << "\n";
				}

			}
				  break;

			case 2: {
				cout << "Estudiantes Dojo BlockChain\n";
				int i = 0;
				for (const auto& estudiante : Est_Blockchain) {
					cout << i++ << ")  Nombre: " << estudiante->getNombre() << ", Edad: " << estudiante->getEdad() << "\n";
				}

			}
				  break;
			}
		}
		}
		cout << "-----------------------------------------------\n\n";
	} while (opcion != 8);
}

int main() {
	menu();
}