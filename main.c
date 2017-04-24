#include "enigma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	createEnigma(); 
	char choice[2] = menuOne();
	char plugOption[2];

	printf("Enter an option for the Plugboard settings:\n");
	printf("Default Values: -d\nOwn Values: -e\n");
	printf("Enter an option:\n");
	scanf("%s", plugOption);

	setPlugboard(enigma, plugOption);
	setRotors(enigma);


	// Print tests to see what is held inside these variables
	printf("Choice: %s\n", choice);
	printf("PlugOption: %s\n",plugOption);


	/******************************************************
	
	After getting the plugboard settings and gettting a
	message to encrypt/decrypt, start encrypting/decrypting

	*******************************************************/
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

	deleteEnigma(enigma);
	
	return 0;
}
