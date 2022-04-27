#ifndef DADO_H
#define DADO_H

#include <iostream>
using namespace std;

class Dado {
private:
	char Letras[26];	// ESTA VARIABLE ALMACENA UNA LISTA DE LETRAS (A-Z)
	char Cara;		// ESTA VARIABLE ES PARA ALMACENAR LAS LETRAS QUE VA A TENER CADA LADO DEL DADO
public:
	Dado() {
		char letra = 'A';	// ESTA VARIABLE ES LA QUE NOS VA A DAR LAS DIFERENTES LETRAS
		for (int i = 0; i < 26; i++) {
			/* MEDIANTE ESTE CICLO SE PONEN LAS LETRAS EN CADA POSICION DEL VECTOR "Letras" */
			Letras[i] = letra;	// AQUI SE ALMACENA
			letra++;			// ESTO HACE QUE SE CAMBIE DE LA LETRA "A" A LA "B", Y ASI SUCESIVAMENTE
		}
		for (int i = 0; i < 6; i++) {
			/* ESTE CICLO ES PARA CREAR LOS LADOS DEL DADO*/
			int j = rand() % 26 - 1;	// AQUI SE ALMACENA UN NUMERO ALEATORIO DEL 1 AL 26 EN LA VARIABLE "J"
			Cara = Letras[j];		/* LUEGO UTILIZO LA VARIABLE "J" PARA OBTENER UNA POSICION ALEATORIA
										   DEL VECTOR "Letras" PARA ASI OBTENER UNA LETRA ALEATORIA Y ALMACENARLA
										   EN EL VECTOR "Lados"*/
		}
	}
	~Dado() {}
	char getCara() { return Cara; }
};

#endif // !DADO
