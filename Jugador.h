#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
using namespace std;

class Jugador {
private:
	string nombre;
	int puntaje;
public:
	Jugador(string nom) {
		nombre = nom;
		puntaje = 0;
	}
	~Jugador() { }
	void setNombre(string nom) { this->nombre = nom; }
	void setPuntaje(int _ganes) { this->puntaje = _ganes; }
	string getNombre() { return this->nombre; }
	int getPuntaje() { return this->puntaje; }
};

#endif // !JUGADOR_H
