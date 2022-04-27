#ifndef TABLERO_H
#define TABLERO_H

#include <sstream>
#include "Dado.h"

class Tablero {
private:
	static const int fil = 5; // NUMERO DE FILAS
	static const int col = 5; // NUMERO DE COLUMNAS
	Dado** dados;	// ESTA ES LA MATRIZ DE DADOS PARA EL TABLERO
public:
	Tablero() {
		dados = new Dado * [fil];			// SE CREA LA MEMORIA PARA LAS FILAS
		for (int i = 0; i < fil; i++) {	
			dados[i] = new Dado[col];		// SE CREA LA MEMORIA PARA LAS COLUMNAS
		}
	}
	~Tablero() {
		/* AQUI SE ELIMINA LA MATRIZ */
		for (int i = 0; i < fil; i++) {
			delete[] dados[i];
		}
		delete[] dados;
	}
	Dado** getDados() { return dados; } // GET DE DADOS
	bool buscarPalabra(string palabra) {
		/*DESPUES DE LEER ESTA PARTE EJECUTEN EL PROGRAMA PARA QUE ENTIENDAN
		QUE HACE TODO ESTE METODO*/
		/*METODO PARA BUSCAR QUE LA PALABRA INGRESADA ESTÉ EN EL TABLERO*/
		int len = palabra.size();	// ALMACENA LA CANTIDAD DE LETRAS QUE CONTIENE LA PALABRA
		cout << len << endl;
		string palabraTmp = " ";	// VARIABLE PARA VERIFICAR QUE LA PALABRA EXISTA (YA LO VAN A VER MAS ADELANTE)
		for (int i = 0; i < fil; i++) { // CICLO PARA RECORRER LAS FILAS
			int lenTmp = palabraTmp.size();	// ALMACENA LA CANTIDAD DE LETRAS QUE CONTIENE "palabraTmp"
			int n = 0; // VARIABLE PARA RECORRER LAS LETRAS DE LA PALABRA
			while (n < len) {
				for (int j = 0; j < col; j++) { // CICLO PARA RECORRER LAS COLUMNAS
					char letra = dados[i][j].getCara();	// ALMACENA LA LETRA DEL TABLERO
					if (palabra[n] == letra && palabra[n] != palabraTmp[lenTmp-1]) {
						/*YA QUE LOS STRING SON "CADENAS" DE CARACTERES, SE PUEDE ACCEDER A
						CADA UNA DE ELLAS INDICANDO LA POSICION DESEADA. EJEMPLO:
						SI "PALABRA" ES IGUAL A "Hola", AL MOSTRAR POR PANTALLA "PALABRA[0]"
						EL RESULTADO VA A SER "H"*/
						/*EL CONDICIONAL INDICA QUE SI LA LETRA EN LA POSICION N ES IGUAL A LA
						LETRA DEL TABLERO Y, A LA VEZ, ESA LETRA ES DIFERENTE A LA ULTIMA LETRA DE
						"palabraTmp", ENTONCES SE COLOCA LA LETRA EN LA ULTIMA POSICION DE "palabraTmp"*/
						palabraTmp += palabra[n];
						cout << "PalabraTmp: " << palabraTmp << endl;
						break;
					} 
				}
				n++; // SE AUMENTA EL ITERADOR PARA CONTINUAR CON LA SIGUIENTE LETRA DE LA PALABRA
			}
		}
		/*SI LA PALABRA QUE SE FORMÓ AL VERIFICAR EL TABLERO ES IGUAL A LA PALABRA
		QUE SE ESTÁ BUSCANDO, SE VA A DEVOLVER TRUE*/
		return palabraTmp == palabra ? true : false;
	}
	string toString() {
		/* AQUI LLAMO A CADA UNO DE LOS DADOS DE LA MATRIZ */
		stringstream s;
		for (int i = 0; i < fil; i++) {
			for (int j = 0; j < col; j++) {
				s << '\t' << dados[i][j].getCara();
			}
			s << endl << endl; // CON ESTO HAGO LOS SALTOS DE LINEA PARA QUE SE VEA COMO UN TABLERO
		}
		return s.str();
	}
};

#endif // !TABLERO_H
