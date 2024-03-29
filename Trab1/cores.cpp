#include <iostream>
#include "cores.h"
using namespace std;

// arquivo aonde � definido o corpo das fun��es da biblioteca cores


// Fun��o para ajustar o cor do texto e do fundo atrav�z de dois parametros inteiros
void ajustarCor(int texto, int fundo) {
	// Corpo de defini��o gen�rico das cores do console.
	cout << "\033[0;" << texto << ";" << fundo << "m";
}

// Fun��o definida para restaurar as configura��es padr�es de cores do console.
void resetarCor() {
	cout << "\033[m";
}