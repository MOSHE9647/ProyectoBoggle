#include <iostream>
#include "Tablero.h"
#include "Juego.h"
using namespace std;

int main() {
	
	/*Tablero* t1 = new Tablero();

	cout << t1->toString();*/

	/*char Matriz[5][5]{};
	char letra = 'A';
	srand(time(NULL));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			char salida = letra + rand() % 15;
			Matriz[i][j] = salida;
			cout << '\t' << Matriz[i][j];
		}
		cout << endl << endl;
	}*/

	/*Jugador* j1 = new Jugador("Isaac Herrera");*/

	/*fstream archivo("Puntuaciones.txt", ios::out | ios::app);
	if (archivo.good()) {
		srand(time(NULL));
		for (int i = 0; i < 10; i++) {
			int j = rand() % 100;
			j1->setPuntaje(j);
			archivo << j1->getNombre() << '\t';
			archivo << j1->getPuntaje() << '\n';
		}
	}*/
	/*Juego* p1 = new Juego();
	fstream archivo("Puntuaciones.txt", ios::in);
	fstream temp("temp.txt", ios::out | ios::trunc);
	Jugador* vector[50]{};
	int cantidad = 0;

	if (archivo.good() && temp.good()) {
		Jugador* aux;
		while (!archivo.eof()) {
			string nombre, puntaje;
			int i = 0;
			getline(archivo, nombre, '\t');
			getline(archivo, puntaje, '\n');
			int puntos = p1->convertirInt(puntaje);
			aux = new Jugador(nombre);
			aux->setPuntaje(puntos);
			vector[i] = aux;
			cantidad++;
			i++;
		}
		for (int i = 0; i < cantidad; i++) {

		}
	}
	archivo.close();
	temp.close();

	cout << cantidad << endl;
	system("pause");*/

	string cadena = "Hola mundo!";
	string palabra = "Hola mundo!";
	string aux_cadena = "";

	for (int i = cadena.size(); i >= 0; i--)
		aux_cadena += cadena[i];

	cout << "El texto normal es: " << cadena << endl;
	cout << "El texto invertido es: " << aux_cadena << endl;

	for (int i = palabra.size(); i >= 0; i--) {
		if (cadena[i] = palabra[i]) {
			cout << "Coincide..." << endl;
		}
	}

	return 0;
}