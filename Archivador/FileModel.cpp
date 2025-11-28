#define _CRT_SECURE_NO_WARNINGS
#include "FileModel.h"
#include "DataStructure.h"
#include "FieldManagement.h"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

void Cabecera::ingresarCabecera(ofstream& crear, const string& nombre) {
		cout << "Descripcion breve: "; getline(cin, descripcion);

		crear << "--- Contenido del archivo " << nombre << " ---" << endl;
		crear << descripcion << endl;
		time_t now = time(0);
		fechaCreacion = ctime(&now);
		crear << fechaCreacion << endl;
		crear << "----------------------------------------------" << endl;

}
void ListaArchivos::crearNuevoArchivo() {
	NodoArchivo* nuevo = new NodoArchivo();
	nuevo->archivo.crearArchivo();
	if (!cabeza) cabeza = nuevo;
	else {
		NodoArchivo* aux = cabeza; while (aux->siguiente) aux = aux->siguiente;
		aux->siguiente = nuevo;
	}
	std::cout << "\n Archivo creado exitosamente.\n";
}
void ListaArchivos::mostrarArchivos() {
    const string ruta_carpeta = "prueba";
    filesystem::path ruta(ruta_carpeta);
    if (!filesystem::exists(ruta)) {
        cout << "\nERROR: La carpeta '" << ruta_carpeta << "' no existe.\n";
        cout << " Asegurate de crear la carpeta en la raiz de tu proyecto.\n";
        return;
    }
    std::cout << "\n=============================================\n";
    std::cout << "          ARCHIVOS .TXT EN LA CARPETA '" << ruta << "'\n";
    std::cout << "=============================================\n";

    int contador = 0;

    for (const auto& entrada : filesystem::directory_iterator(ruta)) 
    {
        const auto& pa = entrada.path();

        if (filesystem::is_regular_file(pa) && pa.extension() == ".txt") {
            string nombre_archivo = pa.filename().string();

            cout << "    - " << nombre_archivo << "\n";
            contador++;
        }
    }

    if (contador == 0) {
        std::cout << "No se encontraron archivos.txt en la carpeta.\n";
    }

    std::cout << "=============================================\n";
}
ListaArchivos::~ListaArchivos() {
	while (cabeza != nullptr) {
		NodoArchivo* temp = cabeza; cabeza =
			cabeza->siguiente; delete temp;
	}
}

//Se encarga de la apertura del archivo, otorgandole el flujo a las demas clases para que realicen el registro de informacion o la lectura de la misma
void ArchivoRAM::crearArchivo() {
    ofstream salida;
    char resp;

     cout << "Nombre del archivo: ";

     getline(std::cin, nombre);

     ruta = "prueba\\" + nombre + ".txt";
     cout << "Ruta de archivo: " << ruta << std::endl;

     salida.open(ruta);
     if (!salida.is_open()) {
         std::cout << "Error al abrir el archivo. Verifique si la carpeta 'prueba' existe." << std::endl;
         return;
     }

     cabecera.ingresarCabecera(salida, nombre);
     salida.close();

     cout << "\n--- Ingresar CAMPOS ---\n";
     do {
         salida.open(ruta, std::ios::app);
         if (!salida.is_open()) {
             cout << "Error al reabrir el archivo para Campos." << std::endl;
             return;
         }

         listaCampos.agregarCampo(salida, nombre);

         salida.close();

         cout << "¿Agregar otro campo? (s/n): ";
         cin >> resp;
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         resp = std::toupper(resp);
     } while (resp == 'S');

        cabecera.numCampos = listaCampos.contarCampos();
}
bool Cabecera::leerCabecera(std::ifstream& entrada) {
    char cadena[100];
    while (entrada.getline(cadena, 100)) {
        cout << cadena << endl;
    }

    return true;
}
ArchivoRAM* ListaArchivos::buscarArchivoExistente(const string& nombre) {

    NodoArchivo* aux = cabeza;
    NodoArchivo* nuevo = new NodoArchivo();
    while (aux) {
        if (aux->archivo.nombre == nombre) {
            std::cout << "El archivo '" << nombre << "' ya estaba cargado.\n";
            nuevo->archivo.cargarDesdeDisco(nombre);
            return &(aux->archivo);
        }
        aux = aux->siguiente;
    }

    std::cout << "Cargando archivo '" << nombre << "' desde el disco...\n";

    
    if (nuevo->archivo.cargarDesdeDisco(nombre)) {
        if (!cabeza) cabeza = nuevo;
        else {
            NodoArchivo* temp = cabeza;
            while (temp->siguiente) temp = temp->siguiente;
            temp->siguiente = nuevo;
        }
        return &(nuevo->archivo);
    }
    else {

        delete nuevo;
        return nullptr;
    }
}
bool ArchivoRAM::cargarDesdeDisco(const string& nombre) {
    string ruta_completa = "prueba\\" + nombre + ".txt";
    ifstream entrada(ruta_completa);
    if (!entrada.is_open()) {
        std::cout << "Error: No se pudo abrir el archivo en la ruta: " << ruta_completa << std::endl;
        return false;
    }

    if (!cabecera.leerCabecera(entrada)) {
        std::cout << "Error al leer la Cabecera.\n";
        entrada.close();
        return false;
    }
    this->nombre = nombre;
    ruta = ruta_completa;
    cabecera.nombreArchivo = nombre;

    entrada.close();
    return true;
}