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


Enigma createEngima() {
	Enigma enimga; 
	//enimga.message = "";
	enimga.rotorOne = 0;
	enimga.rotorTwo = 0; 
	enimga.rotorThree = 0; 
	enimga.ringstellung = 0; 
	//enimga.plugboard = "";
}

int deleteEngima(Enigma n) {
	if (!n) return -1;
	free(n);
	return 0; 
}

void printEnigma(Enigma n) {
	if (!n) return -1; 
	printf("Message: %s\n", n.message);
	printf("Rotor One: %i\n", n.rotorOne);
	printf("Rotor Two: %i\n", n.rotorTwo);
	printf("Rotor Three: %i\n", n.rotorThree);
	printf("Ringstellung: %i\n", n.ringstellung);
	printf("Plugboard: %s\n", n.plugboard);
}


void setRotors() {
	printf("\nEnter character for Rotor #1: ");
	sscanf("%i", enigma.rotorOne);
	if ( !(enigma.rotorOne > 64 && enigma.rotorOne < 91) ) {
		// If lowercase make uppercase
		if ( enigma.rotorOne > 96 && enigma.rotorOne < 122 ) {
			enigma.rotorOne = enigma.rotorOne - 32;
		}
		else {
			printf("Characters in your input are not accepted.\
				Look at the help menu for a list of characters\ 
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

void setRingstellung();

void setPlugboard();

void help() {
	printf("HELP MENU\n\
		This program allows you to replicate the German WWII Enigma Machine\ 
		on your computer.  There are three main parts to the Enigma Machine: \ 
		the Rotors, the Ringstellung, and the Plugboard.\n\
		");

}

void menuOne() {
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

	if ( strcmp(choice,"-e") == 0 ) {
		encrypt();
	}
	else if ( strcmp(choice, "-d") == 0) {
		decrypt();
	}
	else if ( strcmp(choice,"-h") == 0) {
		help();
	}
	else {
		printf("Not a valid choice. Try again\n");
		menuOne();
	}
}


void menuTwo() {
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
}

void encrypt() {
	createEngima();
	setRotors();
}

void decrypt() {
	createEngima();
	setRotors();
}
