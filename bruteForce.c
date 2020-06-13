/*
 * ----------------------------------------------
 * Simple implementation of a Caesar cipher brute
 * force algoritm in C language
 * 
 * UFSCar campus Sorocaba - Hackerspace - 2020
 * by: Infinitemarcus
 * ----------------------------------------------
 */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "caesarCipher.h"

/*
 * Function decripting the message with brute force, calling
 * decript() from "caesarCipher.h" multiple times
*/ 
double forcingDecode(char * message){
	
	int key = 1;
	char temporary[200];
	
	
	//Using a temporary string because decript() overwrite the string
	strcpy(temporary, message);
	
	clock_t before = clock();
	
	/*
	 * Loop calculating and printing every
	 * possible decripted message, with keys
	 * 1-25 
	*/
	while(key < 26){
		decript(temporary, key);
		
		printf("Using key: %d \n", key);
		printf("%s\n", temporary);
		
		strcpy(temporary, message);
		
		key++;
	}

	clock_t after = clock();
	
	//Calculating and returning the execution time
	return ((( double ) after - before) / CLOCKS_PER_SEC);
}


/*
 * main(), calling forcingDecore function
*/
int main(){
	
	char message[200];
	
	printf("Type the encripted message: ");
	scanf("%[^\n]", message);
	getchar();
	
	double timer = forcingDecode(message);
	
	// In the end, the algorithm total execution time is shown
	printf("Time spend: %.14lf \n", timer);
	
	return 0;
}

