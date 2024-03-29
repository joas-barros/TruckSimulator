#include <iostream>
#include "cores.h"
using namespace std;

// arquivo aonde é definido o corpo das funções da biblioteca cores


// Função para ajustar o cor do texto e do fundo atravéz de dois parametros inteiros
void ajustarCor(int texto, int fundo) {
	// Corpo de definição genérico das cores do console.
	cout << "\033[0;" << texto << ";" << fundo << "m";
}

// Função definida para restaurar as configurações padrões de cores do console.
void resetarCor() {
	cout << "\033[m";
}