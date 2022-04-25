#ifndef TABLERO_H
#define TABLERO_H

#include "Dado.h"

class Tablero {
private:
	Dado** dados;	// ESTA ES LA MATRIZ DE DADOS PARA EL TABLERO
public:
	Tablero() {
		dados = new Dado * [5];			// SE CREA LA MEMORIA PARA LAS FILAS
		for (int i = 0; i < 5; i++) {	
			dados[i] = new Dado[5];		// SE CREA LA MEMORIA PARA LAS COLUMNAS
		}
	}
	~Tablero() {
		/* AQUI SE ELIMINA LA MATRIZ */
		for (int i = 0; i < 5; i++) {
			delete[] dados[i];
		}
		delete[] dados;
	}
	string toString() {
		/* AQUI LLAMO AL toString DE CADA UNO DE LOS DADOS DE LA MATRIZ */
		stringstream s;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				s << '\t' << dados[i][j].toSring();
			}
			s << endl << endl; // CON ESTO HAGO LOS SALTOS DE LINEA PARA QUE SE VEA COMO UN TABLERO
		}
		return s.str();
	}
};

#endif // !TABLERO_H
