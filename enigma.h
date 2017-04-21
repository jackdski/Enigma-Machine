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

typedef struct Enigmas; 

// Creates an Enigma type with name "name"
Engima createEnigma(char name);

// Delete an Enigma type
// Returns -1 if Enigma n DNE
// Returns 0 is successful
int deleteEnigma(Enigma n); 

// Print the values of Enigma n
// Returns -1 if Enigma n DNE
// Returns 0 if successful 
int printEnigma(Enigma n);

// Set enigma.message 
void getMessage(Enigma enigma);

// Get rid of spaces and punctuation 
// Capitalize lowercase letters
void formatMessage(Enigma enigma);

// Set enigma.plugboard
void setPlugboard(Enigma enigma, char plugOption);

// Encrypts a letter according to its paired 
// value on the Plugboard
char encryptPlugboardChar(char c);

// Encrypt according to the plugboard
// using encryptPlugBoardChar function
void encryptPlugboard(Enigma enigma);

// Set enigma.ringstellung
void setRingstellung(Engima enigma); 

// Encrypt message according to ringstellung 
void encryptRingstellung(Enigma enigma);

// Set rotors in enigma 
void setRotors(Enigma enigma);

// Increment the proper rotors
void incrementRotor(Enigma enigma, int number);

// Encrypt a character according to the first rotor
char encryptRotor(Enigma enigma, int number, char c);

// Display help menu
void help();

// Displays Menu 1
char menuOne();

// Displays Menu 2
// char menuTwo(); 

// Sets off the process to encrypt
void encrypt(); 

// Sets off the process ot decrypt
void decrypt();

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
