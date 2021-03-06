/*
Napisati C program koji će zamijeniti prve dvije riječi u rečenici.
Program od korisnika tražiti učitavanje rečenice (koja može sadržavati i prazna mjesta),
sve dok se ne učita string koji nema praznih mjesta. Zatim se unutar funkcije prototipa
void zamijeni (char *recenica) u rečenici moraju zamijeniti mjesta prve dvije riječi,
vodeći računa o tome da rečenica mora počinjati velikim početnim slovom. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

void zamijeni (char *recenica);

int main()
{
    char *recenica;

    while(1){
        recenica = (char*)malloc((200+1)*sizeof(char));
        scanf(" %[^\n]", recenica);
        zamijeni(recenica);
    }

    return 0;
}

void zamijeni (char *recenica)
{
    int i;
    char *prva, *druga, *ostatak, *ispis;
    char zadnjiznak;
    char delimit[] = " ?!.";

    ispis = (char*)malloc((strlen(recenica)+1)*sizeof(char));
    for (i = 0; i < strlen(ispis); i++) *(ispis+i) = '\0';

    if(strstr(recenica, " ")==NULL) exit(0);

    zadnjiznak = *(recenica+(strlen(recenica)-1));
    prva = strtok(recenica, delimit);
    druga = strtok(NULL, delimit);
    ostatak = strtok(NULL, "\0");

    *druga = toupper(*druga);
    *prva = tolower(*prva);

    if(ostatak!=NULL){
        strcat(ispis, druga);
        strcat(ispis, " ");
        strcat(ispis, prva);
        strcat(ispis, " ");
        strcat(ispis, ostatak);
    } else {
        strcat(ispis, druga);
        strcat(ispis, " ");
        strcat(ispis, prva);
        strcat(ispis, &zadnjiznak);
    }

    printf("%s\n", ispis);
    free(recenica);
    free(ispis);
}
