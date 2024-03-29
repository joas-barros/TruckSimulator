// Importando as bibliotecas utilizadas no programa
#include <iostream>
#include "cores.h"
#include "rede.h"
using namespace std;

// Arquivo principal do jogo

// Criando o protótipo das funções que serão criadas no arquivo main.cpp
void desenhar(int, int);
void whiteSpace(int);

// Iniciando a função main onde será definida toda funcionalidade do programa
int main() {

	// Iniciando a semente para a criação dos números aleatorios atraves do tempo em segundos do computador
	srand(unsigned(time(NULL)));

	// Iniciando as variaveis que serão utilizados na execução do programa
	int posicaoA, posicaoB;
	int velocidadeA, velocidadeB;
	int corA, corB;
	int oleoA, oleoB;

	// Definindo as cores de cada um dos caminhões
	// os nomes das cores foram definidos no arquivo cores.h e importados para o arquivo principal
	corA = AMARELO_LETRA;
	corB = VERDE_LETRA;

	// Definindo a posicao inicial de cada um dos caminhões
	posicaoA = 0;
	posicaoB = 0;

	// Definindo a velocidade inicial de cada um dos caminhões
	velocidadeA = 0;
	velocidadeB = 0;

	// Definindo o estado da pista de cada um dos caminhões
	oleoA = 0;
	oleoB = 0;

	// Definindo o primeiro passo do programa
	int passo = 0;

	// Estrutura que será repetida até um dos caminhões passar da posição 100, ou seja, vencer
	do
	{
		// ------------------
		// Limpa tela
		// Desenha caminhões
		// ------------------

		// comando para limpar a tela do console
		system("cls");

		// Ajustando as cores do título do programa
		ajustarCor(PRETO_LETRA, BRANCO_FUNDO);
		
		// Ajustando o posicionamento e centralizando o texto
		cout << right;
		cout.width(62);
		cout << "Truck Racing";
		cout << right;
		cout.width(61);
		// Reseta as configurações de cor para não serem passadas adiante no código
		resetarCor();
		cout << "\n\n";

		// Desenhando o primeiro caminhão de acordo com sua posição atual e sua cor definida no inicio do programa
		desenhar(posicaoA, corA);
		// Desenhando o primeiro caminhão de acordo com sua posição atual e sua cor definida no inicio do programa
		desenhar(posicaoB, corB);
		// Os valores de posição serão atualizados ao longo do programa

		// ------------------------
		// Atualiza velocidade
		// Atualiza estado da pista
		// ------------------------

		// Gerando um valor aleatório entre 1 e 10 para a velocidade de cada caminhão
		velocidadeA = 1 + rand() % 10;
		velocidadeB = 1 + rand() % 10;

		// Gerando um valor aleatório entre 0 e 1 para o estado da pista de cada caminhão
		oleoA = rand() % 2;
		oleoB = rand() % 2;

		// ----------------------------------
		// Transmite, recebe e processa dados
		// Calcula Próxima posição
		// ----------------------------------

		// Pega todos os atributos do caminhão, empacota em um inteiro de 32 bits, e depois atribui esse inteiro a uma variavel global definida em rede.cpp
		transmitir(passo, corA, posicaoA, velocidadeA, oleoA);
		
		// Recebe o valor que está no variavel global rede e exibe os atributos do caminhão como passo, posição, velocidade e estado da pista
		unsigned int redeA = receber();

		cout << "Processando dados..." << endl;
		// Recebe os atributos da variavel global e calcula a próxima posição do caminhão
		posicaoA = processar(redeA);
		ajustarCor(corA, PRETO_FUNDO);
		// Exibe a próxima posição calculada pela função processar na cor da caminhão
		cout << "Próxima posição: " << posicaoA << "\n\n";
		resetarCor();

		// Atualiza a variavel global agora com os atributos do segundo caminhão
		transmitir(passo, corB, posicaoB, velocidadeB, oleoB);
		
		// Recebe a variavel global atualizada e exibe os atributos do segundo caminhão
		unsigned int redeB = receber();
		
		cout << "Processando dados..." << endl;
		// Calcula a próxima posição do segundo caminhão
		posicaoB = processar(redeB);
		ajustarCor(corB, PRETO_FUNDO);
		// exibe a próxima posição do segundo caminhão
		cout << "Próxima posição: " << posicaoB << "\n\n";
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
		// Espera o usuario digitar qualquer tecla para continuar a execução do programa
		system("pause > nul");
		// Atualiza o passo
		passo = passo + 1;
		// Condição para sair da estrutura de repetição
	} while (posicaoA <= 100 && posicaoB <= 100);

	// Limpa o console logo após a corrida ser finalizada
	system("cls");

	// Ajuste da cor e centralização do texto do título do programa, como feito na estrutura de repetição
	ajustarCor(PRETO_LETRA, BRANCO_FUNDO);
	
	cout << right;
	cout.width(62);
	cout << "Truck Racing";
	
	cout << right;
	cout.width(61);
	resetarCor();
	cout << "\n\n";

	// Desenho dos dois caminhões logo após a finalização da corrida.
	desenhar(posicaoA, corA);
	desenhar(posicaoB, corB);

	// Ajuste da cor e centralização do texto do título de finalização da corrida
	ajustarCor(PRETO_LETRA, BRANCO_FUNDO);

	cout << right;
	cout.width(65);
	cout << "Corrida Concluída";

	cout << right;
	cout.width(58);
	resetarCor();
	cout << "\n\n\n";

	// Calcula a velocidade média em que cada caminhão finalizou a corrida
	// Devemos transformar a posicao em double através de type casting para que o resultado da divisão não seja truncado em inteiro e assim perca precisão
	double velmediaA = double(posicaoA) / passo;
	double velmediaB = double(posicaoB) / passo;

	// Exibimos quantos passos foram necessarios para que a corrida fosse finalizada
	ajustarCor(PRETO_LETRA, BRANCO_FUNDO);
	cout << "Passos: ";
	resetarCor();
	cout << passo << "\n\n";

	// Ajustamos a cor do fundo de acordo com a cor escolhida para o caminhão
	// A cor do fundo é sempre definida como o valor numérica que representa a cor para a letra mais 10
	// Por isso somamos corA + 10
	ajustarCor(PRETO_LETRA, corA + 10);
	cout << " Posição ";

	// Exibimos a posição em que o caminhão terminou a corrida na cor que foi definida no inicio do programa
	ajustarCor(corA, PRETO_FUNDO);
	cout << " " << posicaoA << " ";

	// Repetimos o processo de exibir o texto com a cor de fundo do caminhão
	ajustarCor(PRETO_LETRA, corA + 10);
	cout << " Velocidade média ";

	// exibimos a velocidade média calculada anteriormente do primeiro caminhão, com sua respectiva cor.
	ajustarCor(corA, PRETO_FUNDO);
	cout << " " << velmediaA << " ";
	cout << "\n\n";

	// Repetimos o processo de exibir o texto com a cor de fundo do caminhão
	ajustarCor(PRETO_LETRA, corB + 10);
	cout << " Posição ";

	// Exibimos a posição em que o caminhão terminou a corrida na cor que foi definida no inicio do programa
	ajustarCor(corB, PRETO_FUNDO);
	cout << " " << posicaoB << " ";

	// Repetimos o processo de exibir o texto com a cor de fundo do caminhão
	ajustarCor(PRETO_LETRA, corB + 10);
	cout << " Velocidade média ";

	// exibimos a velocidade média calculada anteriormente do segundo caminhão, com sua respectiva cor.
	ajustarCor(corB, PRETO_FUNDO);
	cout << " " << velmediaB << " ";
	resetarCor();
	cout << "\n\n";
	
	return 0;
}

// Função utilizada para exibir espaços vazios e assim deslocar o caminhão conforme interação com o usuário.
void whiteSpace(int qtd) { while (qtd-- > 0) cout << ' '; }

// Função utilizada para desenhar os caminhões no console
// Essa função deve receber quantos espaços vazios devem ser criados, ou seja os passos, e a cor do caminhão atraves de um inteiro 
void desenhar(int passos, int cor) {
	// Ajustando a cor do caminhão conforme o parametro informado
	ajustarCor(cor, PRETO_FUNDO);
	// Ajustando os espaços vazios da primeira parte do caminhão
	whiteSpace(passos);
	// Caracteres especiais para desenhar a primeira parte do caminhão
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB \xDB\xDB\xDC\n";
	// Ajustando os espaços vazios da segunda parte do caminhão
	whiteSpace(passos);
	// Caracteres especiais para desenhar a segunda parte do caminhão
	cout << "\xDFOO\xDF\xDF\xDF\xDF\xDFO\xDF\n";
	// Desenho da pista
	cout << "---------------------------------------------------------------------------------------------------";
	cout << "|";
	cout << "--------------------" << endl;
	
	// Ajeitando o espaçamento para demarcar o caractere 100, o fim da corrida
	cout << right;
	cout.width(101);
	cout << "100";
	resetarCor();
	cout << "\n\n";
}