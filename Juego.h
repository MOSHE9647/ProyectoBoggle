#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include "Jugador.h"

/*ESTA CLASE NO ESTÁ TERMINADA Y POR LO TANTO NO ESTÁ FUNCIONANDO*/

class Juego {
private:
	fstream archivo;
	int rondas;
public:
	// CONSTRUCTORES //
	Juego(int _rondas) { rondas = _rondas; }
	Juego() { rondas = 0; }
	// DESTRUCTOR //
	~Juego() {	}
	// SET y GET //
	void setRondas(int _rondas) { this->rondas = _rondas; }
	int getRondas() { return rondas; }
	// METODOS //
	void puntuaciones(int mode) {
		if (mode) { // VISUALIZAR PUNTUACIONES
			archivo.open("Puntuaciones.txt", ios::in);
			if (archivo.good()) {
				while (!archivo.eof()) {
					string jugador;
					getline(archivo, jugador, '\n');
					cout << jugador << endl;
				}
			}
			else {
				cout << "ERROR AL REALIZAR LA OPERACION SOLICITADA..." << endl;
			}
			archivo.close();
			system("pause"); system("cls");
		}
		else { // ELIMINAR PUNTUACIONES
			archivo.open("Puntuaciones.txt", ios::out | ios::trunc);
			if (archivo.good()) {
				archivo << "\n     TABLA DE PUNTUACIONES" << endl;
				archivo << "********************************" << endl;
				archivo << "NOMBRE		PARTIDAS GANADAS" << endl;
				archivo << "--------------------------------" << endl;
				cout << "LAS PUNTUACIONES SE ELIMINARON CON EXITO..." << endl;
			}
			else {
				cout << "ERROR AL REALIZAR LA OPERACION SOLICITADA..." << endl;
			}
			archivo.close();
			system("pause"); system("cls");
		}
	}
	void agregar(Jugador* Obj) {
		fstream archivo("Puntuaciones.txt", ios::in | ios::out);
		fstream temp("temp.txt", ios::out, ios::trunc);

		if (archivo.good() && temp.good()) {
			if (isEmpty("Puntuaciones.txt")) {
				cout << "Esta vacio..." << endl;
				archivo << Obj->getNombre() << '\t';
				archivo << Obj->getPuntaje() << '\n';
			}
			else {
				while (!archivo.eof()) {
					string nombre, puntaje;
					int contador = 0;
					getline(archivo, nombre, '\t');
					getline(archivo, puntaje, '\n');
					int puntos = convertirInt(puntaje);
					if (Obj->getPuntaje() > puntos && contador == 0) {
						temp << Obj->getNombre() << '\t';
						temp << Obj->getPuntaje() << '\n';
						temp << nombre << '\t';
						temp << puntos << '\n';
						contador++;
					}
					else {
						temp << nombre << '\t';
						temp << puntos << '\n';
					}
				}
				remove("Puntuaciones.txt");
				if (rename("temp.txt", "Puntuaciones.txt") == NULL) {
					return;
				}
			}
		} else { cout << "Ha ocurrido un error..." << endl; }
		archivo.close();
		temp.close();
	}
	int convertirInt(string Obj) {
		stringstream r(Obj);
		int v;
		r >> v;
		return v;
	}
	void iniciarJuego() {

	}
	bool isEmpty(string archivo) {
		fstream evaluando(archivo.c_str(), ios::in);
		if (evaluando.good()) {
			while (!evaluando.eof()) {
				string contador;
				getline(evaluando, contador, '\n');
				evaluando.close();
				return contador == "" ? true : false;
			}
		}
		else return -1;
	}
};

#endif // !JUEGO_H