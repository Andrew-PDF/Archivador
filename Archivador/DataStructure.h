#pragma once
#include "FileModel.h"
#include "FieldManagement.h"

class NodoArchivo {
public:
	ArchivoRAM archivo;
	NodoArchivo* siguiente;
	NodoArchivo() : siguiente(nullptr) {}
};
class NodoCampo {
public:
	Campo campo;
	NodoCampo* siguiente;
	NodoCampo() : siguiente(nullptr) {}
};