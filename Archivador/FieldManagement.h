#pragma once
#include <string>
#include <fstream>
class NodoCampo;

class ListaCampos {
private:
	NodoCampo* cabeza;
public:
	void agregarCampo(std::ofstream&, const std::string&);
	bool leerCampos(std::ifstream&);
	int contarCampos();
};
class Campo {
public:
	std::ofstream agregar_campo;
	std::string nombreCampo;
	int tipoDato;
	int tamano;
	Campo() : nombreCampo(""), tipoDato(0), tamano(0) {}
	void ingresarCampo(std::ofstream& , const std::string&);
};
