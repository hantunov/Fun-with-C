/*
Palindrom je niz znakova koji se cita jednako s lijeve kao i s desne strane - primjerice, palindrom je:
anavolimilovana

Vas zadatak je napisati funkciju koja provjerava da li je neki string palindrom.
Specificno je to sto string moze imati i interpunkcijske znakove koje je potrebno ignorirati prilikom provjere,
te treba ignorirati i razliku izmedu velikih i malih slova. Funkcija treba imati prototip:

int palindrom(char* s)

Pogledati test primjere za dodatno pojasnjenje. Svaki ulazni niz zavrsava znakom za novi red. Najveca duljina ulaznog niza ce biti 1000 znakova.

Test primjeri:

Ana voli: Milovana!                   ----> Ocekivani izlaz: Ana voli: Milovana! je palindrom.
Star? Not I! Movie. I vomit on rats.  ----> Ocekivani izlaz: Star? Not I! Movie. I vomit on rats. je palindrom.
keks                                  ----> Ocekivani izlaz: keks nije palindrom.
a N a V o l i m i l o v a na        . ----> Ocekivani izlaz: a N a V o l i m i l o v a na        . je palindrom.
palindrom                             ----> Ocekivani izlaz: palindrom nije palindrom.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrom(char* s);

int main()
{
    char unos[100+1] ="", recenica[100+1] = "", delimit[] = " ,.:!?";
    char *token;

    scanf(" %[^\n]", unos);
    printf("%s", unos);

    token = strtok(unos, delimit);

    while(token!=NULL){
        strcat(recenica, token);
        token = strtok(NULL, delimit);
    }

    strlwr(recenica);

    if(palindrom(recenica)==1) printf(" je palindrom.");
    else printf(" nije palindrom.");

    return 0;
}

int palindrom(char* s)
{
    int i;

    for(i=0; i<strlen(s)/2; i++){
        if(*(s+i)!=*(s+(strlen(s)-1-i))){
            return 0;
        }
    }
    return 1;
}
