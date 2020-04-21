/*
 * --------------------------------------------
 * Implementacao simples de um algoritmo de
 * forca bruta de cifra de Cesar na linguagem C
 * 
 * UFSCar campus Sorocaba - Hackerspace - 2020
 * by: Infinitemarcus
 * --------------------------------------------
 */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "caesarCipher.h"

/*
 * Funcao que decodifica a frase fornecida, ate encontrar
 * a mesma frase original, antes de aplicar a cifra de cesar
 * 
 * Uma variavel temporaria eh usada pois a funcao de decriptar, fornecida
 * em "cesar.c" altera o valor original da string fornecida
 * 
 * Um loop eh executado ateh que ou a frase original seja encontrada a partir
 * da funcao de decriptar, ou ateh que o algoritmo chegue na chave 26
 * 
 * Caso a frase tenha sido encontrada, a chave usada eh impressa na tela
 * 
 * Os tempos antes e depois da execucao do loop sao anotados e retornados para a main
*/ 
double decodifica(char * frase, char * outraFrase){
	
	int chave = 1;
	char temp[200];
	
	strcpy(temp, frase);
	
	clock_t agora = clock();
	
	while(strcmp(temp, outraFrase) && chave < 26){
		decripta(temp, chave);
		
		printf("Chave usada: %d \n", chave);
		printf("%s \n", temp);
		
		if(strcmp(temp, outraFrase))
			strcpy(temp, frase);
		else
			strcpy(frase, temp);
		
		chave++;
	}

	clock_t depois = clock();
	
	if(strcmp(temp,outraFrase) == 0)
		printf("Chave de criptografia encontrada: %d\n", chave-1);

	return (( double ) ( depois - agora ) / CLOCKS_PER_SEC);
}


/*
 * Funcao main, com a chamada da funcao de decodificacao e
 * a apresentacao do tempo de execucao do loop da mesma,
 * alem da frase decriptada
*/
int main(){
	
	char frase[200];
	char outraFrase[200];
	
	printf("Digite a frase criptografada: ");
	scanf("%[^\n]", frase);
	getchar();
	
	printf("Digite a frase desejada: ");
	scanf("%[^\n]", outraFrase);
	getchar();
	
	double timer = decodifica(frase, outraFrase);
	
	printf("Tempo gasto: %.14lf \n", timer);
	
	printf("Frase decodificada: %s \n", frase);
	
	return 0;
}

