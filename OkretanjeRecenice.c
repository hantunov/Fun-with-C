//Ucitaj recenicu sa tipkovnice. Ispisi rijeci u obrnutom redoslijedu, izbaci interpunkcije.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char recenica[200+1] ="";
    char *token[30] = {};

    scanf(" %[^\n]", recenica);

    token[0] = strtok(recenica, " -;,.?!");
    int i = 0;
    int br_rijeci = 0;

    do{
        br_rijeci++;
        i++;
        token[i] = strtok(NULL, " -;,.?!");
    }while(token[i]);

    for(i=br_rijeci-1; i>=0; i--){
        printf("%s ", token[i]);
    }

    return 0;
}
