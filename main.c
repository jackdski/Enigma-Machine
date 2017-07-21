/*

	Author: Jack Danielski

*/

#include "enigma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*

	Encryption Process:
	--Plugboard
	--Rotors
	--Ringstellung

*/

int main() {

  char finalMsg[100];
  char message[100];
  char ringstellung;
  char rotorsOne;
  char rotorsTwo;
  char rotorsThree;
  char plugboard[40] = "AQ SW DE FR GT HY JU KI LO MP NB VC XZ";
  char plugOption[3];


  getMessage(message);
  //formatMessage(message);

  printf("Enter -d for default or -e for personal plugboard\n");
  scanf("%2s", plugOption);
  setPlugboard(plugOption, plugboard);

  setRingstellung(&ringstellung);
  setRotors(&rotorsOne, &rotorsTwo, &rotorsThree);

  // Encryption process
  encryptPlugboard(message, finalMsg, plugboard);
  encryptRingstellung(finalMsg, &ringstellung);
  encryptRotors(finalMsg, &rotorsOne, &rotorsTwo, &rotorsThree);

  printf("Original Message:\n%s\n", message);

  return 0;
}
