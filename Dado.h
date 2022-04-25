#ifndef DADO_H
#define DADO_H

#include <iostream>
#include <sstream>
using namespace std;

class Dado {
private:
	char Letras[26];	// ESTA VARIABLE ALMACENA UNA LISTA DE LETRAS (A-Z)
	char Lados[6];		// ESTA VARIABLE ES PARA ALMACENAR LAS LETRAS QUE VA A TENER CADA LADO DEL DADO
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
			Lados[i] = Letras[j];		/* AQUI UTILIZO LA VARIABLE "J" PARA OBTENER UNA POSICION ALEATORIA
										   DEL VECTOR "Letras" PARA ASI OBTENER UNA LETRA ALEATORIA Y ALMACENARLA
										   EN EL VECTOR "Lados"*/
		}
	}
	~Dado() {}
	string toSring() {
		/*MEDIANTE ESTE toString HAGO QUE SE MUESTRE UNA POSICION ALEATORIA DEL VECTOR
		"Lados" CADA VEZ QUE SE LLAME A ESTE METODO*/
		stringstream s;
		srand(time(NULL));	// UTILIZO LA HORA DEL SISTEMA PARA GENERAR LOS NUMEROS ALEATORIOS
		int i = rand() % 6;	// ALMACENO EL NUMERO ALEATORIO EN LA VARIABLE "I"
		s << Lados[i];		// UTILIZO LA VARIABLE "I" PARA ACCEDER A UNA POSICION ALEATORIA DEL VECTOR Y MOSTRARLA
		return s.str();
	}

};

#endif // !DADO
