#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "FieldManagement.h"
class NodoArchivo;

class Cabecera {
public:
	std::ofstream crear;
	std::string nombreArchivo;
	std::string descripcion;
	std::string fechaCreacion;
	int numCampos;
	int numRegistros;
	Cabecera() : nombreArchivo(""), descripcion(""), fechaCreacion(""), numCampos(0),
		numRegistros(0) {
	}
	void ingresarCabecera(std::ofstream&, const std::string&);
	bool leerCabecera(std::ifstream&);
};
//-----------------------------------------------------//
class ArchivoRAM {
public:
	std::string nombre, ruta;
	Cabecera cabecera;
	ListaCampos listaCampos;
	void crearArchivo();
	bool cargarDesdeDisco(const std::string&);
};
//-----------------------------------------------------//
class ListaArchivos {
private:
	NodoArchivo* cabeza;
public:
	ListaArchivos() : cabeza(nullptr) {}
	~ListaArchivos();
	void crearNuevoArchivo();
	void mostrarArchivos();
	ArchivoRAM* buscarArchivoExistente(const std::string& nombre);
	
};