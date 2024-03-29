#include <iostream>
#include "rede.h"
#include "pacote.h"
#include "cores.h"
using namespace std;

// arquivo aonde � definido o corpo das fun��es da biblioteca pacote

// Definindo a variavel global que ser� utilizada para simular envio e recebimento de informa��es em rede dentro do nosso programa
unsigned int rede;

// Fun��o que recebe 5 valores inteiros e empacota todas as informa��es recebidas em um inteiro de 32 bits atrav�s da fun��o empacotar da biblioteca pacote
void transmitir(int passo, int cor, int pos, int vel, int oleo) {
	cout << "Transmitindo dados..." << endl;
	// Atualiza a variavel global com as informa��es recebidas
	rede = empacotar(passo, cor, pos, vel, oleo);

	// Ajustamos a cor do fundo de acordo com a cor escolhida para o caminh�o
	// A cor do fundo � sempre definida como o valor num�rica que representa a cor para a letra mais 10
	// Por isso somamos corA + 10
	ajustarCor(PRETO_LETRA, cor + 10);
	// Exibimos o valor escrito na variavel global
	cout << rede << endl;
	// Resetamos as configura��es de cor do console
	resetarCor();
}

// Fun��o usada para retornar o valor da variavel global e exibir os atribuitos do caminh�o
// Para o r�tulo do atributo, ela ser� exibida com a cor do caminh�o para a letra, j� para os valores do atributo, eles ser�o representados com a cor do caminh�o como fundo
// Para exibir os atributos do caminh�o, a fun��o utiliza as fun��es de decomposi��o da bilioteca pacote para extrair cada informa��o que est� na variavel global rede
// Para definirmos as cores de fundo, utilizamos os mesmos artificios da fun��o anterior
unsigned int receber() {
	cout << "Recebendo dados..." << endl;
	
	ajustarCor(cor(rede), PRETO_FUNDO);
	cout << "Frame ";

	ajustarCor(PRETO_LETRA, cor(rede) + 10);
	cout << passo(rede);

	ajustarCor(cor(rede), PRETO_FUNDO);
	cout << " Pos ";

	ajustarCor(PRETO_LETRA, cor(rede) + 10);
	cout << posicao(rede);

	ajustarCor(cor(rede), PRETO_FUNDO);
	cout << " Velocidade ";

	ajustarCor(PRETO_LETRA, cor(rede) + 10);
	cout << velocidade(rede);

	ajustarCor(cor(rede), PRETO_FUNDO);
	cout << " Oleo ";

	ajustarCor(PRETO_LETRA, cor(rede) + 10);

	// Caso o atributo da pista seja igual a 0, ir� ser exibido false no console, caso seja 1, ir� ser exibido true no console
	if (pista(rede) == 0){
		cout << "false";
	}
	else {
		cout << "true";
	}
	
	resetarCor();
	cout << endl;

	return rede;
}

// A fun��o recebe um inteiro de 32 bits sem sinal e, atrav�s das fun��es de decomposi��o presentes na bilioteca pacote, calcula e retorna qual ser� a pr�xima posi��o do caminh�o
unsigned int processar(unsigned int redeLocal) {
	int posicaoAtual = posicao(redeLocal);
	int vel = velocidade(redeLocal);
	int oleo = pista(redeLocal);
	unsigned int novaPosicao = posicaoAtual + vel - oleo;
	return novaPosicao;
}