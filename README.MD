# Exercicio de Mini Calculadora
Um programa feito para base de estudos, uma mini calculadora que realiza alguns calculos, desta vez em C++.

## Opera��es

1. Calcular 10% de um n�mero
2. Calcular X% de um n�mero
3. Identificar se um n�mero � par ou �mpar
4. Calcular a raiz de uma fun��o de primeiro grau
5. Calcular a raiz de uma fun��o de segundo grau
6. Calcular o fatorial de um n�mero
7. Capturar um n�mero da sequ�ncia de Fibonacci

## Descri��o das Opera��es

1. **Calcular 10% de um n�mero**
   - Recebe um determinado *n�mero* digitado pelo usu�rio e retorna *10%* desse *n�mero*.
2. **Calcular X% de um n�mero**
   - Recebe um determinado *n�mero* digitado pelo usu�rio, mas tamb�m recebe outro n�mero *X%* que equivale a porcentagem a ser calculada, e retorna *X%* desse *n�mero*.
3. **Identificar se um n�mero � par ou �mpar**
   - Recebe um determinado *n�mero inteiro* digitado pelo usu�rio e retorna se o *n�mero inteiro* � *par* ou *�mpar*
4. **Calcular a raiz de uma fun��o de primeiro grau**
   - Recebe dois valores *A* e *B*, sendo *A* diferente de *0*, e retorna a raiz da fun��o de primeiro grau seguindo a equa��o:
   
   > f(x) = ax + b onde f(x) = 0
   
5. **Calcular a raiz de uma fun��o de segundo grau**
   - Recebe tr�s valores *A*, *B* e *C*, sendo *A* diferente de *0*, e retorna nenhuma, uma ou mais raizes dependendo do resultado da fun��o seguindo as equa��es:
  
   >f(x) = ax� + bx + c onde f(x) = 0, 
   >? = b� - 4ac, e
   >x = -b +- v? / 2a
   
6. **Calcular o fatorial de um n�mero**
   - Recebe um determinado *n�mero inteiro* digitado pelo usu�rio e retorna o fatorial desse n�mero.
   
   >n!
   
7. **Capturar um n�mero da sequ�ncia de Fibonacci**
   - Recebe um determinado *n�mero inteiro* digitado pelo usu�rio e retorna um n�mero da sequ�ncia de Fibonacci na posi��o determinada pelo usu�rio
   
## Exemplos de Testes

***Menu Principal***
```
Bem-vindo a calculadora de opera��es!
Selecione uma das opera��es abaixo: 
1. Calcular 10% de um n�mero
2. Calcular x% de um n�mero
3. Identificar se o n�mero � par ou �mpar
4. Calcular a raiz de uma fun��o de primeiro grau
5. Calcular a raiz de uma fun��o de segundo grau
6. Calcular o fatorial de um n�mero
7. Capturar um n�mero da sequ�ncia de Fibonacci
```
***Testando Opera��es***
1. **Calcular 10% de um n�mero**
	```
	>> 1
	Digite um Valor
	>> 50
	10% de 50 � igual a: 5
	Deseja continuar? Y/N
	>> N
	```
2. **Calcular x% de um n�mero**
	```
	>> 2
	Digite um Valor
	>> 50
	Digite a porcentagem em %(Exemplo:50%)
	>> 25%
	25% de 52 � igual a: 13
	Deseja continuar? Y/N
	>> N
	```
3. **Identificar se o n�mero � par ou �mpar** <br />
	*teste 1 - n�mero inteiro normal*
	```
	>> 3
	Digite um valor inteiro
	>> 29
	O N�mero 29 � �mpar!
	Deseja continuar? Y/N
	>> N
	```
	*teste 2 - n�mero inteiro enorme*
	```
	>> 3
	Digite um valor inteiro
	>> 99999999999999999999999999999999999999999999999999999999999
	Este n�mero gigante � �mpar!
	Deseja continuar? Y/N
	>> N
	```
4. **Calcular a raiz de uma fun��o de primeiro grau**
	```
	>> 4
	Digite o valor de A
	>> 0
	A n�o pode ter o valor de 0! Tente novamente!
	>> 5
	Digite o valor de B
	>> -9
	O resultado da fun��o para A = 5 e B = -9 �: 1,800
	```
5. **Calcular a raiz de uma fun��o de segundo grau** <br />
	*teste 1 - resultado 2 raizes*
    ```
	>> 5
	Digite o valor de A
	>> 9
	Digite o valor de B
	>> 4
	Digite o valor de C
	>> -6
	O resultado da fun��o para A = 9, B = 4 e C = -6 �: X1 = 0,624 X2 = -1,068
	Deseja continuar? Y/N
	>> N
	```
	*teste 2 - resultado 1 raiz*
	```
	>> 5
	Digite o valor de A
	>> 8
	Digite o valor de B
	>> 8 
	Digite o valor de C
	>> 2
	O resultado da fun��o para A = 8, B = 8 e C = 2 �: X = -0,500
	Deseja continuar? Y/N
	>> N
	```
	*teste 3 - resultado nenhuma raiz*
	```
	>> 5
	Digite o valor de A
	>> 10
	Digite o valor de B
	>> -4
	Digite o valor de C
	>> 8
	A fun��o A = 10, B = -4 e C = 8, n�o apresenta raiz!
	Deseja continuar? Y/N
	>> N
	```
6. **Calcular o fatorial de um n�mero**
	```
	>> 6
	Digite um n�mero inteiro(at� 20)
	>> 7
	Fatorial de 7: 5040
	Deseja continuar? Y/N
	>> N
	```

7. **Capturar um n�mero da sequ�ncia de Fibonacci**
	```
	>> 7
	Digite um valor inteiro(Entre 1 e 46)
	>> 10
	N�mero 10 da sequ�ncia de Fibonacci: 55
	Deseja continuar? Y/N
	```