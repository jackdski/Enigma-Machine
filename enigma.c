#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Enigmas {
	char message[100];
	int rotorOne;
	int rotorTwo;
	int rotorThree;
	int ringstellung;
	char plugboard[39]; // 26 letters plus 13 spaces
} Engima;


Enigma createEnigma(char name) {
	Enigma name; 
	//name.message = "";
	name.rotorOne = 0;
	name.rotorTwo = 0; 
	name.rotorThree = 0; 
	name.ringstellung = 0; 
	//name.plugboard = "";
}

int deleteEnigma(Enigma enigma) {
	if (!enigma) return -1;
	free(enigma);
	return 0; 
}

int printEnigma(Enigma enigma) {
	if (!n) return -1; 
	printf("Message: %s\n", enigma.message);
	printf("Rotor One: %i\n", enigma.rotorOne);
	printf("Rotor Two: %i\n", enigma.rotorTwo);
	printf("Rotor Three: %i\n", enigma.rotorThree);
	printf("Ringstellung: %i\n", enigma.ringstellung);
	printf("Plugboard: %s\n", enigma.plugboard);
	return 0; 
}

void getMessage(Enigma enigma) {
	char c; 
	while (c != EOF) {
		scanf("%c", c);
		strcat(enigma.message, c);
	}
}

void formatMessage(Enigma enigma) {
	int length = strlen(enigma.message);
	char newMessage[length]; 
	for (int i = 0; i < length; i++) {
		char c = enigma.message[i];
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
	enigma.message = newMessage;

}

void setPlugboard(Enigma enigma, char plugOption) {
	// If user wants default Plugboard instead of entering one
	if (strcmp(plugOption, "-d") == 0) {
		enigma.message = "AQ SW DE FR GT HY JU KI LO MP NB VC XZ";
	}
	// User wants to enter their own
	else if (strcmp(plugOption, "-e") == 0) {
		printf("Enter each letter once with spaces between the pairs.\n");
		printf("For example:\nAB CD EF GH...\n");
		scanf("%s", enigma.message);
	}
}

char encryptPlugBoardChar(char c) {
	int returnChar;
	for (i = 0; i < 39; i++) {
		if (strcmp(c, enigma.plugboard[i]) == 0) {
			if (strcmp(enigma.plugboard[i+1] == 32) == 0) {
				returnChar = enigma.plugboard[i-1]; 
			}
			else {
				returnChar = enigma.plugboard[i+1];
			}
		}
	}
	return returnChar;
}

void encryptPlugBoard(Enigma enigma) {
	for (int i = 0; i < 39; i++) {
		char c = enigma.message[i];
		enigma.message[i] = encryptPlugBoardChar(c);
		// Print test to see what enigma.message[i] is now; 
		printf("%c", enigma.message([i]));
	}
}

void setRingstellung();


void setRotors(Enigma enigma) {
	printf("\nEnter character for Rotor #1: ");
	sscanf("%i", enigma.rotorOne);
	if ( !(enigma.rotorOne > 64 && enigma.rotorOne < 91) ) {
		// If lowercase make uppercase
		if ( enigma.rotorOne > 96 && enigma.rotorOne < 122 ) {
			enigma.rotorOne = enigma.rotorOne - 32;
		}
		else {
			printf("Characters in your input are not accepted.\
				Look at the help menu for a list of characters \
				that are not accepted.\n");
		}
	}

	printf("\nEnter character for Rotor #2: ");
	sscanf("%i", enigma.rotorTwo);
	if ( !(enigma.rotorTwo > 64 && enigma.rotorTwo < 91) ) {
		// If lowercase make uppercase
		if ( enigma.rotorTwo > 96 && enigma.rotorTwo < 122 ) {
			enigma.rotorTwo = enigma.rotorTwo - 32;
		}
		else {
			printf("Characters in your input are not accepted.\
				Look at the help menu for a list of characters 
				that are not accepted.\n");
		}
	}

	printf("\nEnter character for Rotor #3: ");
	sscanf("%i", enigma.rotorThree);
	if ( !(enigma.rotorThree > 64 && enigma.rotorThree < 91) ) {
		// If lowercase make uppercase
		if ( enigma.rotorThree > 96 && enigma.rotorThree < 122 ) {
			enigma.rotorThree = enigma.rotorThree - 32;
		}
		else {
			printf("Characters in your input are not accepted.\
				Look at the help menu for a list of characters 
				that are not accepted.\n");
		}
	}

	printf("Rotors are: %i, %i, %i \n", enigma.rotorOne, enigma.rotorTwo, enigma.rotorThree);

}

void incrementRotor(Enigma enigma, int number) {
	if ( number == 1 ) {
		enigma.rotorOne = enigma.rotorOne + 1; 
	}
	if ( number == 2 ) {
		enigma.rotorTwo = enigma.rotorTwo + 1:
	}
	if ( number == 3 ) {
		enigma.rotorThree = enigma.rotorThree + 1; 
	}
}

char encryptRotors(Enigma enigma, int number, char c);

void help() {
	printf("HELP MENU\n\
		This program allows you to replicate the German WWII Enigma Machine\ 
		on your computer.  There are three main parts to the Enigma Machine: \ 
		the Rotors, the Ringstellung, and the Plugboard.\n\
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

void encrypt(Enigma enigma) {
	getMessage(enigma);
	formatMessage(enigma);
	setRotors(enigma);
	setRingstellung(enigma); 

	encryptPlugBoard(enigma);

	encryptRingstellung(enigma);

	int length = strlen(enigma.message);
	// Go through third rotor encryption
	for (int i = 0; i < length; i++) {
		incrementRotor(enigma, 3); 
		char c = encryptRotor(enigma, 3, enigma.message[i]);
		enigma.message[i] = c;
	}

	// Go through second rotor encryption
	for (int i = 0; i < length; i++) {
		incrementRotor(enigma, 2);
		char c = encryptRotor(enigma, 2, enigma.message[i]);
		enigma.message[i] = c; 
	}

	// Go through third rotor encryption
	for (int i = 0; i < length; i++) {
		incrementRotor(enigma, 1); 
		char c = encryptRotor(enigma, 1, enigma.message[i]);
		enigma.message[i] = c; 
	}

	// Encryption is complete
	printEnigma(enigma);


}

void decrypt() {
	getMessage(enigma);
	formatMessage(enigma);
	setRotors(enigma);
	setRingstellung(enigma);

	// Go through third rotor encryption
	for (int i = 0; i < length; i++) {
		incrementRotor(enigma, 1); 
		char c = encryptRotor(enigma, 1, enigma.message[i]);
		enigma.message[i] = c; 
	}

	// Go through second rotor encryption
	for (int i = 0; i < length; i++) {
		incrementRotor(enigma, 2);
		char c = encryptRotor(enigma, 2, enigma.message[i]);
		enigma.message[i] = c; 
	}

	encryptRingstellung(enigma);

	int length = strlen(enigma.message);
	// Go through third rotor encryption
	for (int i = 0; i < length; i++) {
		incrementRotor(enigma, 3); 
		char c = encryptRotor(enigma, 3, enigma.message[i]);
		enigma.message[i] = c;
	}

	encryptPlugBoard(enigma);

	// Decryption is complete
	printEnigma(enigma);
}
