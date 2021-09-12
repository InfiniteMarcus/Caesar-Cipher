/*
 * -------------------------------------------
 * Simple implementation of Caesar cipher in C
 * language
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
 * main(), calling encription and decript functions
 * from "caesarCipher.h"
*/
int main(){
	
	char message[200];
	int key;
	
	printf("Type you message: \n");
	scanf("%[^\n]", message);
	getchar();
	
	printf("Type the encription key\n");
	scanf("%d", &key);
	
	/*
     * To prevent bugs, key needs to be >= 1 and <= 25,
     * So there is a key validation
	*/ 
	if(key > 25 || key < 1){
		key %= 25;
		//printf("New key: %d \n", key);
	}
	
	clock_t before = clock();
	
	/*
	 * Both encript() and decript() overwrite the message string
	 * with the new value
	*/
	
	encript(message, key);
	printf("Encripted: %s \n", message);
	
	decript(message, key);
	printf("Decripted: %s \n", message);
	
	clock_t after = clock();
	
	// In the end, the algorithms total execution time is calculated and shown
	double diff = ( double ) ( after - before ) / CLOCKS_PER_SEC;
	
	printf("Time spend (encript and decript): %.15lf \n", diff);
	
	return 0;
}

