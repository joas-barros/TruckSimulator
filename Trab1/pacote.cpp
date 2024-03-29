#include <iostream>
#include "pacote.h"
using namespace std;

// arquivo aonde � definido o corpo das fun��es da biblioteca pacote

// Fun��o que recebe os 5 atributos do caminh�o em formato de inteiro e empacota eles em um inteiro de 32 bits
unsigned int empacotar(int passo, int cor, int pos, int vel, int oleo) {

	// Criando um inteiro de 32 bis sem sinal com valor 0 que ser� a m�scara da nossa fun��o
	unsigned int pacote = 0;

	// Deslocamos os bits do parametro passo em 24 bits para a esquerda, de modo que os 8 primeiro bits sejam os ultimos para serem postos na variavel pacote
	passo = passo << (32 - 8);
    
	// Atualizando a variavel pacote com a opera��o OR para que os bits de passo sejam gravados nos 8 ultimos bits de pacote
	pacote = pacote | passo;

	// Deslocamos os bits do parametro cor em 16 bits para a esquerda, para que as informa��es sejam gravadas nos 8 bits subsequentes
	cor = cor << (32 - 16);

	// Atualizando a variavel pacote com a opera��o OR para que os bits de cor sejam gravados nos pr�ximos 8 bits de pacote
	pacote = pacote | cor;

	// Deslocamos os bits do parametro pos em 9 bits para a esquerda, para que as informa��es sejam gravadas nos 7 bits subsequentes
	pos = pos << (32 - 23);

	// Atualizando a variavel pacote com a opera��o OR para que os bits de pos sejam gravados nos pr�ximos 7 bits de pacote
	pacote = pacote | pos;

	// Deslocamos os bits do parametro vel em 5 bits para a esquerda, para que as informa��es sejam gravadas nos 4 bits subsequentes
	vel = vel << (32 - 27);

	// Atualizando a variavel pacote com a opera��o OR para que os bits de vel sejam gravados nos pr�ximos 4 bits de pacote
	pacote = pacote | vel;

	// Deslocamos os bits do parametro oleo em 4 bits para a esquerda, para que as informa��es sejam gravadas no bit subsequente
	oleo = oleo << (32 - 28);

	// Atualizando a variavel pacote com a opera��o OR para que os bits de pacote sejam gravados nos pr�ximo bit de pacote
	pacote = pacote | oleo;

	// Retornamos o pacote com todas as informa��es dos atributos ddo caminh�o
	return pacote;
}

// As Pr�ximas fun��es foram definidas para desempacotar cada informa��o de um inteiro de 32 bits sem sinal que ser� passada como par�metro da fun��o
// Para fazer isso, deslocamos os bits do parametro para a direita de modo que a informa��o que queremos extrair esteja agora localizado nos bits de menor ordem, logo ap�s extraimos esses bits
// Para extrair os bits de menor ordem, criamos uma m�scara em que todos os bits menos significativos que desejamos s�o iguais a 1.
// Fazemos isso deslocando o bit 1 para a esquerda a quantidade de bits que queremos extrair e logo ap�s subtraimos por 1
// Por fim, pegamos o inteiro passado de parametro e aplicamos o operador AND com a m�scara que acabamos de criar, isso far� com que os bits que queremos sejam extra�dos e o resto seja zero.

int passo(unsigned int pacote) {
	// tornando passos os digitos de menor ordem
	pacote = pacote >> 24;
	// pegando os bits de menor ordem
	int passo = pacote & ((1 << 8) - 1);

	return passo;
}

int cor(unsigned int pacote) {
	// tornando cor os digitos de menor ordem
	pacote = pacote >> 16;
	// pegando os bits de menor ordem
	int cor = pacote & ((1 << 8) - 1);

	return cor;
}

int posicao(unsigned int pacote) {
	// tornando pos os digitos de menor ordem
	pacote = pacote >> 9;
	// pegando os bits de menor ordem
	int pos = pacote & ((1 << 7) - 1);

	return pos;
}

int velocidade(unsigned int pacote) {
	// tornando velocidade os digitos de menor ordem
	pacote = pacote >> 5;
	// pegando os bits de menor ordem
	int vel = pacote & ((1 << 4) - 1);

	return vel;
}

int pista(unsigned int pacote) {
	// tornando pista os digitos de menor ordem
	pacote = pacote >> 4;
	// pegando os bits de menor ordem
	int oleo = pacote & ((1 << 1) - 1);

	return oleo;
}