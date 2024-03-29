#include <iostream>
#include "rede.h"
#include "pacote.h"
#include "cores.h"
using namespace std;

// arquivo aonde é definido o corpo das funções da biblioteca pacote

// Definindo a variavel global que será utilizada para simular envio e recebimento de informações em rede dentro do nosso programa
unsigned int rede;

// Função que recebe 5 valores inteiros e empacota todas as informações recebidas em um inteiro de 32 bits através da função empacotar da biblioteca pacote
void transmitir(int passo, int cor, int pos, int vel, int oleo) {
	cout << "Transmitindo dados..." << endl;
	// Atualiza a variavel global com as informações recebidas
	rede = empacotar(passo, cor, pos, vel, oleo);

	// Ajustamos a cor do fundo de acordo com a cor escolhida para o caminhão
	// A cor do fundo é sempre definida como o valor numérica que representa a cor para a letra mais 10
	// Por isso somamos corA + 10
	ajustarCor(PRETO_LETRA, cor + 10);
	// Exibimos o valor escrito na variavel global
	cout << rede << endl;
	// Resetamos as configurações de cor do console
	resetarCor();
}

// Função usada para retornar o valor da variavel global e exibir os atribuitos do caminhão
// Para o rótulo do atributo, ela será exibida com a cor do caminhão para a letra, já para os valores do atributo, eles serão representados com a cor do caminhão como fundo
// Para exibir os atributos do caminhão, a função utiliza as funções de decomposição da bilioteca pacote para extrair cada informação que está na variavel global rede
// Para definirmos as cores de fundo, utilizamos os mesmos artificios da função anterior
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

	// Caso o atributo da pista seja igual a 0, irá ser exibido false no console, caso seja 1, irá ser exibido true no console
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

// A função recebe um inteiro de 32 bits sem sinal e, através das funções de decomposição presentes na bilioteca pacote, calcula e retorna qual será a próxima posição do caminhão
unsigned int processar(unsigned int redeLocal) {
	int posicaoAtual = posicao(redeLocal);
	int vel = velocidade(redeLocal);
	int oleo = pista(redeLocal);
	unsigned int novaPosicao = posicaoAtual + vel - oleo;
	return novaPosicao;
}