#pragma once
#include <string>
#include <cstring>
#include "FileModel.h"

class SubMenuArchivo {
public:
	void mostrarSubMenu(ArchivoRAM* archivo);
};

class MenuPrincipal {
private:
	ListaArchivos listaArchivos;
	SubMenuArchivo subMenu;
	void opcionCrearArchivo() {
		listaArchivos.crearNuevoArchivo();
	}
	void opcionSeleccionarArchivo();
	void opcionListarArchivos();
public:
	void ejecutar();
};

