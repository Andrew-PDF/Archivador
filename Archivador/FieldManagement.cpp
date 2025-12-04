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

		cout << "Nombre del Campo: "; getline(cin, nombreCampo);
		size_t tamano = nombreCampo.size();
		salida.write((const char*)&tamano, sizeof(tamano));
		salida.write(nombreCampo.data(), tamano);
}
bool ListaCampos::leerCampos(ifstream& entrada) {
	size_t tamano_leido;
	string Nombre_leido;

	entrada.read((char*)&tamano_leido, sizeof(tamano_leido));
	if (!entrada) return false;
	cout << "-----CAMPOS DEL ARCHIVO-----" << endl;
	if (tamano_leido > 0) {
		Nombre_leido.resize(tamano_leido);
		entrada.read(&Nombre_leido[0], tamano_leido);
		if (!entrada) return false;
	}

	return true;
}