// Calculadora.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <ctime>
using namespace std;

// Instancias dos prototipos

double operacaoporcento(double num, double porcentagem);
bool numeroehpar(int numero);
double operacaoprimeirograu(double a, double b);
double* operacaosegundograu(double a, double b, double c);
string replaceChar(string str, char ch1, char ch2);
long fibonacci(long posicao, bool mostrarsequencia);
bool ehnumero(string item);
int fatorial(int numero);
// Main
int main()
{
	cout << "Bem-vindo a calculadora de opera��es! \n";
	string TentouQuebrar[] = { "Bela tentativa! Mas acho que isso n�o � uma op��o! Tente novamente! ;-)", "Voc� se sente bem quebrando o programa dos outros? Tente novamente!", "N�o nessa calculadora! Tente novamente!", "Tudo isso?! Acho que n�o! Tente novamente!" };
	string SemTexto[] = { "Tente novamente! Desta vez um numeral!", "Eu sou de exatas, n�o de gram�tica! Tente novamente!", "Lindo texto! Mas onde est�o os n�meros que eu pedi? Tente novamente!", "Textos n�o ir�o te ajudar a achar a solu��o! Tente novamente!", "Uma vez um s�bio me disse:\"Voc� deve colocar um n�mero, gafanhoto! Tente novamente!\"" };
	string OperacaoDesconhecida[] = { "Opera��o desconhecida! Tente novamente!", "Acho que essa op��o n�o est� disponivel...! Tente novamente!", "Leia o menu de opera��es atentamente e selcione uma v�lida! Tente novamente!" };
	// Variaveis de menu
	bool continuar = true;
	string input = "";
	int escolha = 0;
	// Variaveis de opera��o
	double num = 0.0;
	double porcentagem = 0.0;
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	// Prepara a sequencia aleatoria
	srand(time(NULL));
	// Programa roda at� o usu�rio n�o querer mais
	do 
	{
		cout << "Selecione uma das opera��es abaixo:\n";
		cout << "1. Calcular 10% de um n�mero\n";
		cout << "2. Calcular X% de um n�mero\n";
		cout << "3. Identificar se um n�mero � par ou �mpar\n";
		cout << "4. Calcular a raiz de uma fun��o de primeiro grau\n";
		cout << "5. Calcular a raiz de uma fun��o de segundo grau\n";
		cout << "6. Calcular o fatorial de um n�mero\n";
		cout << "7. Capturar um n�mero da sequ�ncia de Fibonacci\n";
		getline(cin, input);
		while (input.length() >= 18)
		{
			cout << TentouQuebrar[rand() % (sizeof(TentouQuebrar) / sizeof(*TentouQuebrar))];
			getline(cin, input);
		}
		// Checa se o input passado n�o contem letras
		while (!ehnumero(input)) 
		{
			cout << SemTexto[rand() % (sizeof(SemTexto) / sizeof(*SemTexto))];
			getline(cin, input);
		}
		// Checa s� pra ter certeza se o input � um numero inteiro
		if (ehnumero(input)) 
		{
			escolha = stoi(input);
			// Pede nova escolha caso a escolha feita n�o esteja no menu
			while (true) 
			{
				if (escolha == 1 || escolha == 2 || escolha == 3 || escolha == 4 || escolha == 5 || escolha == 6 || escolha == 7) break;
				// Caso n�o, repita todo procedimento anterior at� sair um input v�lido
				cout << OperacaoDesconhecida[rand() % (sizeof(OperacaoDesconhecida) / sizeof(*OperacaoDesconhecida))];
				getline(cin, input);
				while ((unsigned int)input.length() >= 18)
				{
					cout << TentouQuebrar[rand() % (sizeof(TentouQuebrar) / sizeof(*TentouQuebrar))];
					getline(cin, input);
				}
				// Checa se o input passado n�o contem letras
				while (!ehnumero(input))
				{
					cout << SemTexto[rand() % (sizeof(SemTexto) / sizeof(*SemTexto))];
					getline(cin, input);
				}
				if (ehnumero(input))
					escolha = stoi(input);
			}
			// Escolha 1: Calcular 10% de um n�mero
			if (escolha == 1)
			{
				cout << "Digite um valor\n";
				getline(cin, input);
				// Checa se o usu�rio passou um n�mero v�lido
				// Caso o usu�rio passe um n�mero invalido, pede-se uma nova entrada
				while (!ehnumero(input)) 
				{
					cout << SemTexto[rand() % (sizeof(SemTexto) / sizeof(*SemTexto))];
					getline(cin, input);
				}
				input = replaceChar(input, '.', ',');
				num = stod(input);
				// Computando resultados
				cout << "10% de " << num << " � igual a: " << operacaoporcento(num, 10) << "\n";
			}
			// Escolha 2: Calcular x% de um n�mero
			else if (escolha == 2)
			{
				cout << "Digite um valor\n";
				getline(cin, input);
				// Checa se o usu�rio passou um n�mero v�lido
				// Caso o usu�rio passe um n�mero invalido, pede-se uma nova entrada
				while (!ehnumero(input))
				{
					cout << SemTexto[rand() % (sizeof(SemTexto) / sizeof(*SemTexto))];
					getline(cin, input);
				}
				input = replaceChar(input, '.', ',');
				num = stod(input);
				cout << "Digite a porcentagem em %(Exemplo: 50%)\n";
				getline(cin, input);
				// Checa se fora passado uma porcentagem v�lida
				while (input.find("%") == string::npos) {
					cout << "Tente novamente! Desta vez uma porcentagem!\n";
					getline(cin, input);
					// Remove o % para checar se o input � um n�mero v�lido
					// Caso o usu�rio passe um n�mero invalido, pede-se uma nova entrada
					input = replaceChar(input, '%', '\0');
					while (!ehnumero(input)) 
					{
						cout << SemTexto[rand() % (sizeof(SemTexto) / sizeof(*SemTexto))];
						getline(cin, input);
					}
				}
				// Computando resultados
				input = replaceChar(input, '.', ',') = replaceChar(input, '%', '\0');
				porcentagem = stod(input);
				cout << porcentagem << "% de " << num << " � igual a: " << operacaoporcento(num, porcentagem) << "\n";
			}
			// Escolha 3: Identificar se o n�mero � par ou impar
			else if (escolha == 3)
			{
				cout << "Digite um valor inteiro\n";
				getline(cin, input);
				// Checa se o usu�rio passou um n�mero v�lido
				// Caso o usu�rio passe um n�mero invalido, pede-se uma nova entrada
				while (!ehnumero(input) || input.find(".") != string::npos || input.find(",") != string::npos)
				{
					cout << SemTexto[rand() % (sizeof(SemTexto) / sizeof(*SemTexto))];
					getline(cin, input);
				}
				num = stod(input);
				if (numeroehpar(num)) 
				{
					if ((unsigned int)input.length() < 18)
					{
						cout << "O n�mero " << num << " � Par!\n";
					}
					else
					{
						cout << "Este n�mero gigante � Par!\n";
					}
				}
				else
				{
					if ((unsigned int)input.length() < 18)
					{
						cout << "O n�mero " << num << " � �mpar!\n";
					}
					else
					{
						cout << "Este n�mero gigante � �mpar!\n";
					}
				}
			}
			// Escolha 4: Calcular a raiz de uma fun��o de primeiro grau
			else if (escolha == 4)
			{
				cout << "Digite o valor de A\n";
				getline(cin, input);
				// Checa se o usu�rio passou um n�mero v�lido
				// Caso o usu�rio passe um n�mero invalido, pede-se uma nova entrada
				while (!ehnumero(input))
				{
					cout << SemTexto[rand() % (sizeof(SemTexto) / sizeof(*SemTexto))];
					getline(cin, input);
				}
				a = stod(input);
				while (a == 0)
				{
					cout << "A n�o pode ter valor de 0! Tente novamente!" << endl;
					getline(cin, input);
					// Checa se o usu�rio passou um n�mero v�lido
					// Caso o usu�rio passe um n�mero invalido, pede-se uma nova entrada
					while (!ehnumero(input))
					{
						cout << SemTexto[rand() % (sizeof(SemTexto) / sizeof(*SemTexto))];
						getline(cin, input);
					}
					a = stod(input);
				}
				cout << "Digite o valor de B\n";
				getline(cin, input);
				// Checa se o usu�rio passou um n�mero v�lido
				// Caso o usu�rio passe um n�mero invalido, pede-se uma nova entrada
				while (!ehnumero(input))
				{
					cout << SemTexto[rand() % (sizeof(SemTexto) / sizeof(*SemTexto))];
					getline(cin, input);
				}
				b = stod(input);
				cout << "O resultado da fun��o para A = " << a << " e B = " << b << " �: " << operacaoprimeirograu(a, b) << endl;
			}
			else if (escolha == 5)
			{
				cout << "Digite o valor de A\n";
				getline(cin, input);
				// Checa se o usu�rio passou um n�mero v�lido
				// Caso o usu�rio passe um n�mero invalido, pede-se uma nova entrada
				while (!ehnumero(input))
				{
					cout << SemTexto[rand() % (sizeof(SemTexto) / sizeof(*SemTexto))];
					getline(cin, input);
				}
				a = stod(input);
				while (a == 0)
				{
					cout << "A n�o pode ter valor de 0! Tente novamente!" << endl;
					getline(cin, input);
					// Checa se o usu�rio passou um n�mero v�lido
					// Caso o usu�rio passe um n�mero invalido, pede-se uma nova entrada
					while (!ehnumero(input))
					{
						cout << SemTexto[rand() % (sizeof(SemTexto) / sizeof(*SemTexto))];
						getline(cin, input);
					}
					a = stod(input);
				}
				cout << "Digite o valor de B\n";
				getline(cin, input);
				// Checa se o usu�rio passou um n�mero v�lido
				// Caso o usu�rio passe um n�mero invalido, pede-se uma nova entrada
				while (!ehnumero(input))
				{
					cout << SemTexto[rand() % (sizeof(SemTexto) / sizeof(*SemTexto))];
					getline(cin, input);
				}
				b = stod(input);
				cout << "Digite o valor de C\n";
				getline(cin, input);
				// Checa se o usu�rio passou um n�mero v�lido
				// Caso o usu�rio passe um n�mero invalido, pede-se uma nova entrada
				while (!ehnumero(input))
				{
					cout << SemTexto[rand() % (sizeof(SemTexto) / sizeof(*SemTexto))];
					getline(cin, input);
				}
				c = stod(input);
				bool be = true;
				double* x;
				try {
					x = operacaosegundograu(a, b, c);
				}
				catch (exception e) {
					be = false;
				}
				if (!be)
					cout << "A fun��o A = " << a << ", B = " << b << " e C = " << c << " n�o apresenta raiz!" << endl;
				else
				{
					if (x[0] == x[1])
						cout << "A fun��o A = " << a << ", B = " << b << " e C = " << c << " � X = "<< x[0] << endl;
					else
						cout << "A fun��o A = " << a << ", B = " << b << " e C = " << c << " � X1 = " << x[0] << " e X2 = "<< x[1] << endl;
				}
			}
			else if (escolha == 6) 
			{
				cout << "Digite um valor inteiro\n";
				getline(cin, input);
				// Checa se o usu�rio passou um n�mero v�lido
				// Caso o usu�rio passe um n�mero invalido, pede-se uma nova entrada
				while (!ehnumero(input) || input.find(".") != string::npos || input.find(",") != string::npos)
				{
					cout << SemTexto[rand() % (sizeof(SemTexto) / sizeof(*SemTexto))];
					getline(cin, input);
				}
				num = stol(input);
				cout << "Fatorial de " << num << ":" << fatorial(num) << endl;
			}
			else if (escolha == 7)
			{
				cout << "Digite um valor inteiro\n";
				getline(cin, input);
				// Checa se o usu�rio passou um n�mero v�lido
				// Caso o usu�rio passe um n�mero invalido, pede-se uma nova entrada
				while (!ehnumero(input) || input.find(".") != string::npos || input.find(",") != string::npos)
				{
					cout << SemTexto[rand() % (sizeof(SemTexto) / sizeof(*SemTexto))];
					getline(cin, input);
				}
				num = stol(input);
				cout << "N�mero " << num << " da sequ�ncia de Fibonacci: " << fibonacci((long)num, false) << endl;
			}
			// Zona de escolha do usu�rio entre continuar ou n�o
			cout << "Deseja continuar? Y/N" << endl;
			getline(cin, input);
			while (true)
			{
				if (input == "Y" || input == "y" || input == "N" || input == "n") break;
				cout << OperacaoDesconhecida[rand() % (sizeof(OperacaoDesconhecida) / sizeof(*OperacaoDesconhecida))];
				getline(cin, input);
			}
			// Caso opte por n�o continuar, o programa sair� do loop e encerrar�
			if (input == "N" || input == "n") 
			{
				continuar = false;
				break;
			}
		}
	} while (continuar);
    return 0;
}
double operacaoporcento(double num, double porcentagem) 
{
	return num * (porcentagem / 100);
}
string replaceChar(string str, char ch1, char ch2) {
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ch1)
			str[i] = ch2;
	}

	return str;
}
double operacaoprimeirograu(double a, double b) 
{
	if (a == 0)
		throw new invalid_argument("A n�o pode ser 0!");
	return -b / a;
}
bool ehnumero(string item) 
{
	try {
		stod(item);
	}
	catch (exception e) {
		return false;
	}
	return true;
}
double* operacaosegundograu(double a, double b, double c) 
{
	if (a == 0)
		throw new invalid_argument("A n�o pode ser 0!");
	// Possiveis valores para X
	double x1 = 0.0;
	double x2 = 0.0;
	// Fun��o delta = b� - 4ac
	double delta = (b * b) - 4 * a * c;
	double raiz;
	if (delta >= 0)
		raiz = sqrt(delta);
	else
		throw new exception("Sem x");
	double valores[2];
	valores[0] = (-b + raiz) / (2 * a);
	valores[1] = (-b - raiz) / (2 * a);
	return valores;
}
bool numeroehpar(int numero) 
{
	return numero % 2 == 0;
}
int fatorial(int numero) 
{
	if (numero == 1)
		return numero;
	return numero * fatorial(numero - 1);
}
long fibonacci(long posicao, bool mostrarsequencia) 
{
	// Sequencia inicia nessa variavel
	long temp = 1;
	// Variavel que armazena o resultado em potencial
	long temp2 = 1;
	long num = 1;
	// Caso seje as primeiras posi��es, o valor ser� sempre 1
	if (posicao == 1 || posicao == 2) 
	{
		num = temp;
	}
	else
	{
		// Fica fazendo o c�lculo at� chegar na posi��o
		for (long x = 1; x <= posicao; x++) 
		{
			// Mostra sequencia no console
			if (mostrarsequencia) 
			{
				cout << temp2 << "\n";
			}
			// Caso chegue na posi��o, o resultado potencial � atribuido ao retorno
			if (x == posicao) 
			{
				num = temp2;
			}
			else
			{
				temp = temp2 + temp;
				temp2 = temp - temp2;
			}
		}
	}
	return num;
}

