// Importando as bibliotecas utilizadas no programa
#include <iostream>
#include "cores.h"
#include "rede.h"
using namespace std;

// Arquivo principal do jogo

// Criando o prot�tipo das fun��es que ser�o criadas no arquivo main.cpp
void desenhar(int, int);
void whiteSpace(int);

// Iniciando a fun��o main onde ser� definida toda funcionalidade do programa
int main() {

	// Iniciando a semente para a cria��o dos n�meros aleatorios atraves do tempo em segundos do computador
	srand(unsigned(time(NULL)));

	// Iniciando as variaveis que ser�o utilizados na execu��o do programa
	int posicaoA, posicaoB;
	int velocidadeA, velocidadeB;
	int corA, corB;
	int oleoA, oleoB;

	// Definindo as cores de cada um dos caminh�es
	// os nomes das cores foram definidos no arquivo cores.h e importados para o arquivo principal
	corA = AMARELO_LETRA;
	corB = VERDE_LETRA;

	// Definindo a posicao inicial de cada um dos caminh�es
	posicaoA = 0;
	posicaoB = 0;

	// Definindo a velocidade inicial de cada um dos caminh�es
	velocidadeA = 0;
	velocidadeB = 0;

	// Definindo o estado da pista de cada um dos caminh�es
	oleoA = 0;
	oleoB = 0;

	// Definindo o primeiro passo do programa
	int passo = 0;

	// Estrutura que ser� repetida at� um dos caminh�es passar da posi��o 100, ou seja, vencer
	do
	{
		// ------------------
		// Limpa tela
		// Desenha caminh�es
		// ------------------

		// comando para limpar a tela do console
		system("cls");

		// Ajustando as cores do t�tulo do programa
		ajustarCor(PRETO_LETRA, BRANCO_FUNDO);
		
		// Ajustando o posicionamento e centralizando o texto
		cout << right;
		cout.width(62);
		cout << "Truck Racing";
		cout << right;
		cout.width(61);
		// Reseta as configura��es de cor para n�o serem passadas adiante no c�digo
		resetarCor();
		cout << "\n\n";

		// Desenhando o primeiro caminh�o de acordo com sua posi��o atual e sua cor definida no inicio do programa
		desenhar(posicaoA, corA);
		// Desenhando o primeiro caminh�o de acordo com sua posi��o atual e sua cor definida no inicio do programa
		desenhar(posicaoB, corB);
		// Os valores de posi��o ser�o atualizados ao longo do programa

		// ------------------------
		// Atualiza velocidade
		// Atualiza estado da pista
		// ------------------------

		// Gerando um valor aleat�rio entre 1 e 10 para a velocidade de cada caminh�o
		velocidadeA = 1 + rand() % 10;
		velocidadeB = 1 + rand() % 10;

		// Gerando um valor aleat�rio entre 0 e 1 para o estado da pista de cada caminh�o
		oleoA = rand() % 2;
		oleoB = rand() % 2;

		// ----------------------------------
		// Transmite, recebe e processa dados
		// Calcula Pr�xima posi��o
		// ----------------------------------

		// Pega todos os atributos do caminh�o, empacota em um inteiro de 32 bits, e depois atribui esse inteiro a uma variavel global definida em rede.cpp
		transmitir(passo, corA, posicaoA, velocidadeA, oleoA);
		
		// Recebe o valor que est� no variavel global rede e exibe os atributos do caminh�o como passo, posi��o, velocidade e estado da pista
		unsigned int redeA = receber();

		cout << "Processando dados..." << endl;
		// Recebe os atributos da variavel global e calcula a pr�xima posi��o do caminh�o
		posicaoA = processar(redeA);
		ajustarCor(corA, PRETO_FUNDO);
		// Exibe a pr�xima posi��o calculada pela fun��o processar na cor da caminh�o
		cout << "Pr�xima posi��o: " << posicaoA << "\n\n";
		resetarCor();

		// Atualiza a variavel global agora com os atributos do segundo caminh�o
		transmitir(passo, corB, posicaoB, velocidadeB, oleoB);
		
		// Recebe a variavel global atualizada e exibe os atributos do segundo caminh�o
		unsigned int redeB = receber();
		
		cout << "Processando dados..." << endl;
		// Calcula a pr�xima posi��o do segundo caminh�o
		posicaoB = processar(redeB);
		ajustarCor(corB, PRETO_FUNDO);
		// exibe a pr�xima posi��o do segundo caminh�o
		cout << "Pr�xima posi��o: " << posicaoB << "\n\n";
		resetarCor();

		// -------------------------------
		// Aguarda pressionamento de tecla
		// -------------------------------

		// Ajusta a cor e o fundo do executar passo para branco e preto
		ajustarCor(PRETO_LETRA, BRANCO_FUNDO);
		
		// Ajusta o posicionamento do texto e o centraliza
		cout << right;
		cout.width(120);
		cout << "[ENTER] Executar Passo >";
		resetarCor();
		// Espera o usuario digitar qualquer tecla para continuar a execu��o do programa
		system("pause > nul");
		// Atualiza o passo
		passo = passo + 1;
		// Condi��o para sair da estrutura de repeti��o
	} while (posicaoA <= 100 && posicaoB <= 100);

	// Limpa o console logo ap�s a corrida ser finalizada
	system("cls");

	// Ajuste da cor e centraliza��o do texto do t�tulo do programa, como feito na estrutura de repeti��o
	ajustarCor(PRETO_LETRA, BRANCO_FUNDO);
	
	cout << right;
	cout.width(62);
	cout << "Truck Racing";
	
	cout << right;
	cout.width(61);
	resetarCor();
	cout << "\n\n";

	// Desenho dos dois caminh�es logo ap�s a finaliza��o da corrida.
	desenhar(posicaoA, corA);
	desenhar(posicaoB, corB);

	// Ajuste da cor e centraliza��o do texto do t�tulo de finaliza��o da corrida
	ajustarCor(PRETO_LETRA, BRANCO_FUNDO);

	cout << right;
	cout.width(65);
	cout << "Corrida Conclu�da";

	cout << right;
	cout.width(58);
	resetarCor();
	cout << "\n\n\n";

	// Calcula a velocidade m�dia em que cada caminh�o finalizou a corrida
	// Devemos transformar a posicao em double atrav�s de type casting para que o resultado da divis�o n�o seja truncado em inteiro e assim perca precis�o
	double velmediaA = double(posicaoA) / passo;
	double velmediaB = double(posicaoB) / passo;

	// Exibimos quantos passos foram necessarios para que a corrida fosse finalizada
	ajustarCor(PRETO_LETRA, BRANCO_FUNDO);
	cout << "Passos: ";
	resetarCor();
	cout << passo << "\n\n";

	// Ajustamos a cor do fundo de acordo com a cor escolhida para o caminh�o
	// A cor do fundo � sempre definida como o valor num�rica que representa a cor para a letra mais 10
	// Por isso somamos corA + 10
	ajustarCor(PRETO_LETRA, corA + 10);
	cout << " Posi��o ";

	// Exibimos a posi��o em que o caminh�o terminou a corrida na cor que foi definida no inicio do programa
	ajustarCor(corA, PRETO_FUNDO);
	cout << " " << posicaoA << " ";

	// Repetimos o processo de exibir o texto com a cor de fundo do caminh�o
	ajustarCor(PRETO_LETRA, corA + 10);
	cout << " Velocidade m�dia ";

	// exibimos a velocidade m�dia calculada anteriormente do primeiro caminh�o, com sua respectiva cor.
	ajustarCor(corA, PRETO_FUNDO);
	cout << " " << velmediaA << " ";
	cout << "\n\n";

	// Repetimos o processo de exibir o texto com a cor de fundo do caminh�o
	ajustarCor(PRETO_LETRA, corB + 10);
	cout << " Posi��o ";

	// Exibimos a posi��o em que o caminh�o terminou a corrida na cor que foi definida no inicio do programa
	ajustarCor(corB, PRETO_FUNDO);
	cout << " " << posicaoB << " ";

	// Repetimos o processo de exibir o texto com a cor de fundo do caminh�o
	ajustarCor(PRETO_LETRA, corB + 10);
	cout << " Velocidade m�dia ";

	// exibimos a velocidade m�dia calculada anteriormente do segundo caminh�o, com sua respectiva cor.
	ajustarCor(corB, PRETO_FUNDO);
	cout << " " << velmediaB << " ";
	resetarCor();
	cout << "\n\n";
	
	return 0;
}

// Fun��o utilizada para exibir espa�os vazios e assim deslocar o caminh�o conforme intera��o com o usu�rio.
void whiteSpace(int qtd) { while (qtd-- > 0) cout << ' '; }

// Fun��o utilizada para desenhar os caminh�es no console
// Essa fun��o deve receber quantos espa�os vazios devem ser criados, ou seja os passos, e a cor do caminh�o atraves de um inteiro 
void desenhar(int passos, int cor) {
	// Ajustando a cor do caminh�o conforme o parametro informado
	ajustarCor(cor, PRETO_FUNDO);
	// Ajustando os espa�os vazios da primeira parte do caminh�o
	whiteSpace(passos);
	// Caracteres especiais para desenhar a primeira parte do caminh�o
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB \xDB\xDB\xDC\n";
	// Ajustando os espa�os vazios da segunda parte do caminh�o
	whiteSpace(passos);
	// Caracteres especiais para desenhar a segunda parte do caminh�o
	cout << "\xDFOO\xDF\xDF\xDF\xDF\xDFO\xDF\n";
	// Desenho da pista
	cout << "---------------------------------------------------------------------------------------------------";
	cout << "|";
	cout << "--------------------" << endl;
	
	// Ajeitando o espa�amento para demarcar o caractere 100, o fim da corrida
	cout << right;
	cout.width(101);
	cout << "100";
	resetarCor();
	cout << "\n\n";
}