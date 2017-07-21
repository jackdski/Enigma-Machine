/*

	Author: Jack Danielski

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "enigma.h"


void getMessage(char * message) {
	//char message[100];
	printf("Enter your message in ALL CAPS and NO SPACES:\n");
	scanf("%99s", message);
	printf("%s\n", message );
}


void formatMessage(char * message) {
	int length = strlen(message);
	char newMessage[length];
	for (int i = 0; i < length; i++) {
		char c = message[i];
		// If not uppercase (A=65, Z=90)
		if ( !(c > 'A' && c < 'Z') ) {
			// If lowercase make uppercase
			// a = 97, z=122
			if ( c > 'a' && c < 'z' ) {
				c = c - 32;
			}
		}

	}
	message = newMessage;
}


void setPlugboard(char * plugOption, char * plugboard) {
	if (strcmp(plugOption, "-d") == 0) {
		plugboard = "AQ SW DE FR GT HY JU KI LO MP NB VC XZ";
	}
	// If user wants default Plugboard instead of entering one
	//else (strcmp(plugOption, "-e") == 0) {
	//	plugboard = "nothing";
	//}
	// User wants to enter their own
	//else {
	//	printf("Enter each letter once with spaces between the pairs.\n");
	//	printf("For example:\nAB CD EF GH...\n");
	//	scanf("%s", plugboard);
	//}
	printf("Plugboard: %s\n", plugboard);
}


char encryptPlugBoardChar(char c, char * plugboard) {
	char returnChar;
	for (int i = 0; i < 40; i++) {
		if ( c == plugboard[i]) {
			if (plugboard[i+1] == 32) {
				returnChar = plugboard[i-1];
			}
			else {
				returnChar = plugboard[i+1];
			}
		}
	}
	return returnChar;
}


void encryptPlugboard(char * message, char * finalMsg, char * plugboard) {
	for (int i = 0; message[i]; i++) {
		char newChar;
		char c = message[i];
		printf("%c\n",c);
		for (int j = 0; plugboard[j]; j++) {
			if (c == plugboard[j]) {
				if (plugboard[j+1] == 32) {
					newChar = plugboard[j-1];
					printf("%c\n", newChar);
				}
				else {
					newChar = plugboard[j+1];
					printf("%c\n", newChar);
				}
			}
		}
		printf("Num: %i, New Char: %c\n", i, newChar);
		finalMsg[i] = newChar;
	}
	printf("After Plugboard Encryption:\n");
	printf("%s\n", finalMsg);
}

void setRingstellung(char * ringstellung){
	printf("Set a value for the ringstellung (A-Z):\n");
	scanf("%1s", ringstellung);

	if ( *ringstellung > 'a' && *ringstellung < 'z' ) {
		*ringstellung -=  32;
	}

	printf("Ringstellung: %c\n", *ringstellung);
}

void encryptRingstellung(char * finalMsg, char * ringstellung) {
	int length = strlen(finalMsg);
	printf("Length: %d\n", length);
	char ringVal = *ringstellung - 'A';
	if (ringVal > 'Z') {
		ringVal = (ringVal - 'Z') + 'A' - 1;
	}
	printf("RingVal: %d\n", ringVal );

	for (int i = 0; i < length; i++) {
		finalMsg[i] = finalMsg[i] + ringVal;
		if (finalMsg[i] > 'Z') {
			finalMsg[i] = ( finalMsg[i] - 'Z' ) + 'A' - 1;
		}
		printf("%c\n", finalMsg[i]);
	}
	printf("After Ringstellung: %s\n", finalMsg);

}

void setRotors(char * rotorsOne, char * rotorsTwo, char * rotorsThree) {
	printf("Enter character for Rotor #1 (A-Z):\n");
	scanf("%1s", rotorsOne);
	if ( !(*rotorsOne >= 'A' && *rotorsOne <= 'Z') ) {
		// If lowercase make uppercase
		if ( *rotorsOne >= 'a' && *rotorsOne <= 'z' ) {
			*rotorsOne = *rotorsOne - 32;
		}
		else {
			printf("Characters in your input are not accepted.\n");
			printf("Look at the help menu for a list of characters\n");
			printf("that are not accepted.\n");
		}
	}

	printf("Enter character for Rotor #2 (A-Z):\n");
	scanf("%1s", rotorsTwo);
	//rotors[1] = temp[0];
	if ( !(*rotorsTwo >= 'A' && *rotorsTwo <= 'Z') ) {
		// If lowercase make uppercase
		if ( *rotorsTwo>= 'a' && *rotorsTwo <= 'z' ) {
			*rotorsTwo = *rotorsTwo - 32;
		}
		else {
			printf("Characters in your input are not accepted.\n");
			printf("Look at the help menu for a list of characters\n");
			printf("that are not accepted.\n");
		}
	}
	//printf("\n");

	printf("Enter character for Rotor #3 (A-Z): \n");
	scanf("%1s", rotorsThree);
	//rotors[2] = temp[0];
	if ( !(*rotorsThree >= 'A' && *rotorsThree <= 'Z') ) {
		// If lowercase make uppercase
		if ( *rotorsThree >= 'a' && *rotorsThree <= 'z' ) {
			*rotorsThree = *rotorsThree - 32;
		}
		else {
			printf("Characters in your input are not accepted.\n");
			printf("Look at the help menu for a list of characters\n");
			printf("that are not accepted.\n");
		}
	}
	printf("Rotors are: %c, %c, %c \n", *rotorsOne, *rotorsTwo, *rotorsThree);
}


void encryptRotors( char * finalMsg, char * rotorsOne, char * rotorsTwo, char * rotorsThree) {
	int length = strlen(finalMsg);
	printf("Length: %d\n", length);
	char newLet;


	// do encryption
	for (int i = 0; i < length; i++) {
		// letValOne
		char letValOne = *rotorsOne - 'A';
		if (letValOne > 'Z') {
			letValOne = (letValOne - 'Z') + 'A' - 1;
		}
		printf("letValOne: %d\n", letValOne);

		// letValTwo
		char letValTwo = *rotorsTwo - 'A';
		if (letValTwo > 'Z') {
			letValTwo = (letValTwo - 'Z') + 'A' - 1;
		}
		printf("letValTwo: %d\n",letValTwo);

		// letValThree
		char letValThree = *rotorsThree - 'A';
		if (letValThree > 'Z') {
			letValOne = (letValThree - 'Z') + 'A' - 1;
		}
		printf("letValThree: %d\n",letValThree);


		newLet = finalMsg[i] + letValOne;
		if (newLet > 'Z') {
			newLet = ( newLet - 'Z' ) + 'A' - 1;
		}

		newLet += letValTwo;
		if (newLet > 'Z') {
			newLet = ( newLet - 'Z' ) + 'A' -1;
		}

		newLet = newLet + letValThree;
		if (newLet > 'Z') {
			newLet = ( newLet - 'Z' ) + 'A' -1;
		}

		printf("Newlet: %c\n", newLet);
		// Set the place equal to the new value
		finalMsg[i] = newLet;

		// Increment rotor one after every letter
		*rotorsOne = *rotorsOne + 1;
		if (*rotorsOne > 'Z') {
			*rotorsOne = (*rotorsOne - 'Z') + 'A' - 1;
		}
		printf("New Rotor1: %d\n", *rotorsOne);

		// Increment rotor two after every 26'th letter
		if ((i % 26) == 0 ) {
			rotorsTwo++;
		}
	}

	printf("New Message:\n%s\n", finalMsg);
}
