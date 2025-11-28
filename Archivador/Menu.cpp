#include "Menu.h"
#include <string>
#include <cstring>

using namespace std;

void SubMenuArchivo::mostrarSubMenu(ArchivoRAM* archivo) {
	if (!archivo) return;
	int sub;
	string nombre = archivo->cabecera.nombreArchivo;
	do {
		cout << "\n--- SUBMENU (" << nombre << ") ---\n";
		cout << "1. Mostrar cabecera\n";
		cout << "2. Mostrar lista de campos\n";
		cout << "6. Volver al menu principal\n";
		cout << "Opcion: ";
		cin >> sub;
		switch (sub) {
		case 1:  break; //por revisar
		case 2:  break;
		//case 3: break;
		//case 4: break;
		//case 5: break;
		case 6: break;
		default: cout << "Opcion invalida.\n";
		}
	} while (sub != 6);
}
void MenuPrincipal::opcionListarArchivos() {
	listaArchivos.mostrarArchivos();
	system("Pause");
}
void MenuPrincipal::opcionSeleccionarArchivo() {
	string nombre;
	listaArchivos.mostrarArchivos();
	cout << "Ingrese Nombre del Archivo que quiera abrir :"; getline(cin, nombre);
	listaArchivos.buscarArchivoExistente(nombre);
	system("Pause");

}
void MenuPrincipal::ejecutar() {
	int opcion;
	do {
		cout << "\n=== MENU PRINCIPAL ===\n";
		cout << "1. Crear nuevo archivo\n";
		cout << "2. Seleccionar archivo existente\n";
		cout << "3. Listar archivos\n";
		cout << "4. Salir\n";
		cout << "Opcion: ";
		cin >> opcion; 
		cin.ignore();
		switch (opcion) {
		case 1:
			opcionCrearArchivo();
			break;
		case 2:
			opcionSeleccionarArchivo();
			system("cls");
			break;
		case 3:
			opcionListarArchivos();
			system("cls");
			break;
		case 4:
			cout << "\nSaliendo y liberando la memoria.\n";
			break;
		default:
			cout << "\nOpcion invalida.\n";
		}
	} while (opcion != 4);
}