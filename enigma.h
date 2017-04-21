/*
	<enigma.h> Library for Jack Danielski and Thomas Wintenburg's 
	ECEN 1310 WWII Engima Machine Project

	Authors: Jack Danielski and Thomas Wintenburg
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* 
*
*	Function Prototypes
*
*/

// Takes text from a file and uses it as the message being encrypted 
// or decrypted. 
void textEnter(); 

// Takes text from stdin/keyboard and uses it as the message being 
// encrypted or decrypted. 
void stdinEnter();

// Sets off the process to encrypt
void encrypt(); 

// Sets off the process ot decrypt
void decrypt();

// Displays Menu 1
void menuOne();

// Displays Menu 2
void menuTwo(); 

// Display help menu
void help();

//Give the rotors values
void setRotors(void);

void menuOne() ;


void menuTwo();

/*
void encrypt() {
	printf("Encrypt was choses\n");
	setRotors();
}

void decrypt() {
	printf("Decrypt was chosen\n");
	setRotors();
}
*/

void help();

void setRotors(void);
