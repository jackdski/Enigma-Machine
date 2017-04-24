#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "enigma.h"

struct _enigma {
	char message[100];
	int rotorOne;
	int rotorTwo;
	int rotorThree;
	int ringstellung;
	char plugboard[39]; // 26 letters plus 13 spaces
} Engima;


enigma createEnigma() {
	enigma e; 
	enigma.message = "";
	enigma.rotorOne = 0;
	enigma.rotorTwo = 0; 
	enigma.rotorThree = 0; 
	enigma.ringstellung = 0; 
	enigma.plugboard = "";
}

int deleteEnigma(enigma e) {
	if (!e) return -1;
	free(e);
	return 0; 
}

int printEnigma(enigma e) {
	if (!n) return -1; 
	printf("Message: %s\n", e.message);
	printf("Rotor One: %i\n", e.rotorOne);
	printf("Rotor Two: %i\n", e.rotorTwo);
	printf("Rotor Three: %i\n", e.rotorThree);
	printf("Ringstellung: %i\n", e.ringstellung);
	printf("Plugboard: %s\n", e.plugboard);
	return 0; 
}

void getMessage(enigma e) {
	char c; 
	while (c != EOF) {
		scanf("%c", c);
		strcat(e.message, c);
	}
}

void formatMessage(enigma e) {
	int length = strlen(e.message);
	char newMessage[length]; 
	for (int i = 0; i < length; i++) {
		char c = e.message[i];
		// If not uppercase (A=65, Z=90)
		if ( !(c > 64 && c < 91) ) {
			// If lowercase make uppercase
			// a = 97, z=122
			if ( c > 96 && c < 123 ) {
				c = c - 32;
			}
		}
		strcat(newMessage, c);
	}
	e.message = newMessage;

}

void setPlugboard(enigma e, char plugOption) {
	// If user wants default Plugboard instead of entering one
	if (strcmp(plugOption, "-d") == 0) {
		e.message = "AQ SW DE FR GT HY JU KI LO MP NB VC XZ";
	}
	// User wants to enter their own
	else if (strcmp(plugOption, "-e") == 0) {
		printf("Enter each letter once with spaces between the pairs.\n");
		printf("For example:\nAB CD EF GH...\n");
		scanf("%s", e.message);
	}
}

char encryptPlugBoardChar(enigma e, char c) {
	int returnChar;
	for (int i = 0; i < 39; i++) {
		if (strcmp(c, e.plugboard[i]) == 0) {
			if (strcmp(e.plugboard[i+1] == 32) == 0) {
				returnChar = e.plugboard[i-1]; 
			}
			else {
				returnChar = e.plugboard[i+1];
			}
		}
	}
	return returnChar;
}

void encryptPlugBoard(enigma e) {
	for (int i = 0; i < 39; i++) {
		char c = e.message[i];
		e.message[i] = encryptPlugBoardChar(c);
		// Print test to see what enigma.message[i] is now; 
		printf("%c", e.message([i]));
	}
}

void setRingstellung(enigma e);


void setRotors(enigma e) {
	printf("\nEnter character for Rotor #1: ");
	sscanf("%i", e.rotorOne);
	if ( !(e.rotorOne > 64 && e.rotorOne < 91) ) {
		// If lowercase make uppercase
		if ( e.rotorOne > 96 && e.rotorOne < 122 ) {
			e.rotorOne = e.rotorOne - 32;
		}
		else {
			printf("Characters in your input are not accepted.
				Look at the help menu for a list of characters 
				that are not accepted.\n");
		}
	}

	printf("\nEnter character for Rotor #2: ");
	sscanf("%i", e.rotorTwo);
	if ( !(e.rotorTwo > 64 && e.rotorTwo < 91) ) {
		// If lowercase make uppercase
		if ( e.rotorTwo > 96 && e.rotorTwo < 122 ) {
			e.rotorTwo = e.rotorTwo - 32;
		}
		else {
			printf("Characters in your input are not accepted.
				Look at the help menu for a list of characters 
				that are not accepted.\n");
		}
	}

	printf("\nEnter character for Rotor #3: ");
	sscanf("%i", e.rotorThree);
	if ( !(e.rotorThree > 64 && e.rotorThree < 91) ) {
		// If lowercase make uppercase
		if ( e.rotorThree > 96 && e.rotorThree < 122 ) {
			e.rotorThree = e.rotorThree - 32;
		}
		else {
			printf("Characters in your input are not accepted.
				Look at the help menu for a list of characters 
				that are not accepted.\n");
		}
	}

	printf("Rotors are: %i, %i, %i \n", e.rotorOne, e.rotorTwo, e.rotorThree);

}

void incrementRotor(enigma e, int number) {
	if ( number == 1 ) {
		e.rotorOne = e.rotorOne + 1; 
	}
	if ( number == 2 ) {
		e.rotorTwo = e.rotorTwo + 1:
	}
	if ( number == 3 ) {
		e.rotorThree = e.rotorThree + 1; 
	}
}

char encryptRotors(enigma e, int number, char c);

void help() {
	printf("HELP MENU\n\
		This program allows you to replicate the German WWII Enigma Machine 
		on your computer.  There are three main parts to the Enigma Machine:  
		the Rotors, the Ringstellung, and the Plugboard.\n
		");

}

char menuOne() {
	char option[2];

	printf("Choose to encrypt, decrypt, or see help menu:\n");
	printf("
		Encryption: -e\n
		Decryption: -d\n
		Help: -h\n
		Enter an option: 
		");

	scanf("%s", option);
	// Prints the option chosen as a test
	//printf("%s\n", option);

	return option;
}

// Optional 
/*
char menuTwo() {
	char option[2];
	printf("Choose an option:\n\
		-h -> help menu and how the Enigma Machine works\n\
		-e -> encrypt a message\n\
		-d -> decrypt a message\n\
		-t -> enter text via a file from the same directory\
		 as the program\n\
		-k -> enter text from stdin/keyboard\n\
		-r -> modify rotor characters\n\
		-rs -> modify Ringstellung number/character\n\
		-p -> modify plugboard settings\n\
		");
	return option;
}
*/

void encrypt(enigma e) {
	getMessage(e);
	formatMessage(e);
	setRotors(e);
	setRingstellung(e); 

	encryptPlugBoard(e);

	encryptRingstellung(e);

	int length = strlen(e.message);
	// Go through third rotor encryption
	for (int i = 0; i < length; i++) {
		incrementRotor(e, 3); 
		char c = encryptRotor(e, 3, e.message[i]);
		e.message[i] = c;
	}

	// Go through second rotor encryption
	for (int i = 0; i < length; i++) {
		incrementRotor(e, 2);
		char c = encryptRotor(e, 2, e.message[i]);
		e.message[i] = c; 
	}

	// Go through third rotor encryption
	for (int i = 0; i < length; i++) {
		incrementRotor(e, 1); 
		char c = encryptRotor(e, 1, e.message[i]);
		e.message[i] = c; 
	}

	// Encryption is complete
	printEnigma(e);


}

void decrypt() {
	getMessage(e);
	formatMessage(e);
	setRotors(e);
	setRingstellung(e);

	// Go through third rotor encryption
	for (int i = 0; i < length; i++) {
		incrementRotor(e, 1); 
		char c = encryptRotor(e, 1, e.message[i]);
		e.message[i] = c; 
	}

	// Go through second rotor encryption
	for (int i = 0; i < length; i++) {
		incrementRotor(e, 2);
		char c = encryptRotor(e, 2, e.message[i]);
		e.message[i] = c; 
	}

	encryptRingstellung(e);

	int length = strlen(e.message);
	// Go through third rotor encryption
	for (int i = 0; i < length; i++) {
		incrementRotor(e, 3); 
		char c = encryptRotor(e, 3, e.message[i]);
		e.message[i] = c;
	}

	encryptPlugBoard(e);

	// Decryption is complete
	printEnigma(e);
}
