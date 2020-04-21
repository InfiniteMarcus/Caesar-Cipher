/*
 * -------------------------------------------
 * Implementacao simples de uma cifra de Cesar
 * na linguagem C
 * 
 * UFSCar campus Sorocaba - Hackerspace - 2020
 * by: Infinitemarcus
 * -------------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "caesarCipher.h"

/*
 * Funcao main, com as chamadas de funcao para encriptar
 * e decriptar a mensagem
 * 
 * No fim, o tempo de execucacao total do programa eh mostrado
*/
int main(){
	
	char frase[200];
	int chave;
	
	printf("Digite a frase a ser encriptada: \n");
	scanf("%[^\n]", frase);
	getchar();
	
	printf("Digite a chave de referencia\n");
	scanf("%d", &chave);
	
	//Para visualizar entrada:
	//printf("Frase escolhida: %s \n", frase);
	//printf("Chave escolhida: %d \n", chave);
	
	//Tratamento de entrada da chave
	if(chave > 25 || chave < 1){
		chave %= 25;
	}
	
	clock_t agora = clock();
	
	encripta(frase, chave);
	printf("Encriptado: %s \n", frase);
	
	decripta(frase, chave);
	printf("Decriptado: %s \n", frase);
	
	clock_t depois = clock();
	
	printf("Tempo gasto (encriptar e decriptar): %.14lf \n", (( double ) ( depois - agora ) / CLOCKS_PER_SEC));
	
	return 0;
}

