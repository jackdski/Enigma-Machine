/*
	<enigma.h> Library for Jack Danielski and Thomas Wintenburg's 
	ECEN 1310 WWII Engima Machine Project

	Authors: Jack Danielski and Thomas Wintenburg
*/

#ifndef ENIGMA_H
#define ENIGMA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "enigma.c"


/* 
*
*	Function Prototypes
*
*/

typedef struct _enigma enigma; 

// Creates an Enigma type
engima createEnigma();

// Delete an Enigma type
// Returns -1 if Enigma n DNE
// Returns 0 is successful
int deleteEnigma(enigma e); 

// Print the values of Enigma n
// Returns -1 if Enigma n DNE
// Returns 0 if successful 
int printEnigma(enigma e);

// Set enigma.message 
void getMessage(enigma e);

// Get rid of spaces and punctuation 
// Capitalize lowercase letters
void formatMessage(enigma e);

// Set enigma.plugboard
void setPlugboard(enigma e, char plugOption);

// Encrypts a letter according to its paired 
// value on the Plugboard
char encryptPlugboardChar(enigma e, char c);

// Encrypt according to the plugboard
// using encryptPlugBoardChar function
void encryptPlugboard(enigma e);

// Set enigma.ringstellung
void setRingstellung(enigma e); 

// Encrypt message according to ringstellung 
void encryptRingstellung(enigma e);

// Set rotors in enigma 
void setRotors(enigma e);

// Increment the proper rotors
void incrementRotor(enigma e, int number);

// Encrypt a character according to the first rotor
char encryptRotor(enigma e, int number, char c);

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

#endif 
