/*

	Author: Jack Danielski

*/

#ifndef ENIGMA_H
#define ENIGMA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Gets message input
void getMessage(char * message);

// Get rid of spaces and punctuation
// Capitalize lowercase letters
//void formatMessage(char * message);

// Set enigma.plugboard
void setPlugboard(char * plugOption, char * plugboard);

// Encrypts a letter according to its paired
// value on the Plugboard
char encryptPlugboardChar(char c, char * plugboard);

// Encrypt according to the plugboard
// using encryptPlugBoardChar function
void encryptPlugboard(char * message, char * finalMsg, char * plugboard);

// Set enigma.ringstellung
void setRingstellung(char * ringstellung);

// Encrypt message according to ringstellung
void encryptRingstellung(char * finalMsg, char * ringstellung);

// Set rotors in enigma
void setRotors(char * rotorsOne, char * rotorsTwo, char * rotorsThree);

// Encrypt a character according to the first rotor
void encryptRotors( char * finalMsg, char * rotorsOne, char * rotorsTwo, char * rotorsThree);

// Decrypt a message using the rotors
char decryptRotors(char * message, char rotorOne, char rotorTwo, char rotorThree);

// Display help menu
void help();

// Displays Menu 1
int menuOne();

// Sets off the process to encrypt
void encrypt();

// Sets off the process ot decrypt
void decrypt();

#endif
