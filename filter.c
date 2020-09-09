#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 1000

int main() {

	// aici creezi un handler
	FILE* file;

	// aici creezi un buffer ( un spatiu de stocare )
	char buffer[BUFFER_SIZE];

	// aici deschizi un fisier
	file = fopen("emailuri.txt","r");

	// aici cei 1000 de bytes sunt inlocuiti mereu pana cand citeste tot documentul
	while (fgets(buffer,BUFFER_SIZE,file) != NULL) {
		char *token;
		token = strtok(buffer," "); // aici delimiteaza propozitia in bucati
		while (token != NULL) {

			// ia toate cuvintele impartite si verifica daca contin @
			if (strstr(token,"@")) {
				printf("%s",token);
			}

			// trece la urmatorul token
			token = strtok(NULL," ");
		}
 	}
	return 0;
}
