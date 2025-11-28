#include "FieldManagement.h"
#include "DataStructure.h"
#include <fstream>
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

void ListaCampos::agregarCampo(ofstream& salida, const string& nombre) {
	NodoCampo* nuevo = new NodoCampo;
	nuevo->campo.ingresarCampo(salida, nombre);
	if (!cabeza) cabeza = nuevo;
	else {
		NodoCampo* aux = cabeza; while (aux->siguiente) aux = aux->siguiente;
		aux->siguiente = nuevo;
	}
}

int ListaCampos::contarCampos() {
	return 0;
}

void Campo::ingresarCampo(ofstream& salida, const string& nombre) {

	char Op;
	salida << "--- Campos del archivo " << nombre << " ---" << endl;
					
			cout << "Nombre del campo: ";
			getline(cin, nombreCampo);
			salida << nombreCampo << endl;

			cout << "Tipo de dato (Int[1]/Float[2]/Char[3]/String[4]): "<<endl;
			tipoDato = _getche();
			cout << "\n";
			salida << "Tipo: ";
			switch (tipoDato) {
			case '1':
				salida << "int" << endl;
				break;
			case '2':
				salida << "float" << endl;
				break;
			case '3':
				salida << "char" << endl;
				break;
			case '4':
				salida << "string" << endl;
				break;
			default:
				cout << "Ingrese un valor correcto por favor" << endl;
			}
		agregar_campo << "----------------------------------------------" << endl;
}