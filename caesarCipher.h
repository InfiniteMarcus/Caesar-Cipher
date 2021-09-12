  /*
 * ------------------------------------------------------
 * Header for simple encript and decript functions
 * of Caesar Cipher in C language
 * 
 * UFSCar campus Sorocaba - Hackerspace - 2020
 * by: Infinitemarcus
 * ------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>

/*
 * Encript function for Caesar Cipher, using ASCII letters
 * 
 * Non-ASCII chars are preserved
*/ 
void encript(char * message, int key);

/*
 * Decript function for Caesar Cipher, using ASCII letters
 * 
 * Non-ASCII chars are preserved
*/ 
void decript(char * message, int key);
