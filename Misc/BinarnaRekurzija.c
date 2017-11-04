/*
Napisite algoritam koji pomocu binarne rekurzije pretrazuje niz znakova pocevsi s
prvim i posljednjim znakom u nizu. Tijekom rada algoritam ispisuje trenutacni korak (tj. iteraciju), znak koji se
usporedjuje i poziciju znaka koji se usporedjuje. Nakon pronalaska trazenog znaka algoritam zaustavlja rekurziju i
ispisuje poziciju trazenog znaka u zadanom nizu.
Pretrazivanje je osjetljivo na velika i mala slova (engl. case sensitive).

Primjer ispravnog unosa #1:

Unesite niz znakova: abC123
Unesite trazeni znak: C
Ispis:
Iteracija 1, pozicija 0, znak a
Iteracija 1, pozicija 5, znak 3
Iteracija 2, pozicija 1, znak b
Iteracija 2, pozicija 4, znak 2
Iteracija 3, pozicija 2, znak C
Znak C je pronadjen!

Primjer ispravnog unosa #2:

Unesite niz znakova: IvAnA
Unesite trazeni znak: m
Ispis:
Iteracija 1, pozicija 0, znak I
Iteracija 1, pozicija 4, znak A
Iteracija 2, pozicija 1, znak v
Iteracija 2, pozicija 3, znak n
Iteracija 3, pozicija 2, znak A
Znak m nije pronadjen!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarnaPretraga(char* niz, char trazeniZnak, int duzinaNiza, int sredinaNiza, int brojac);

int main()
{
    char niz[100];
    char trazeniZnak;
    int duzinaNiza;
    int sredinaNiza;

    printf("Unesite niz znakova: ");
    scanf("%s", niz);
    printf("Unesite trazeni znak: ");
    scanf(" %c", &trazeniZnak);

    duzinaNiza = strlen(niz)-1;
    if(duzinaNiza%2 == 0) sredinaNiza = duzinaNiza/2;
    else sredinaNiza = (duzinaNiza/2)+1;

    printf("Ispis:\n");

    binarnaPretraga(niz, trazeniZnak, duzinaNiza, sredinaNiza, 0);

    return 0;
}

int binarnaPretraga(char* niz, char trazeniZnak, int duzinaNiza, int sredinaNiza, int brojac){

    if(brojac<=sredinaNiza){

        printf("Iteracija %d, pozicija %d, znak %c\n", brojac+1, brojac, *(niz+brojac));
        if(*(niz+brojac) == trazeniZnak){
            printf("Znak %c je pronadjen!", trazeniZnak);
            return 0;
        }

        if(duzinaNiza>sredinaNiza) printf("Iteracija %d, pozicija %d, znak %c\n", brojac+1, duzinaNiza, *(niz+duzinaNiza));
        if(*(niz+duzinaNiza) == trazeniZnak){
            printf("Znak %c je pronadjen!", trazeniZnak);
            return 0;
        }

    } else {
        printf("Znak %c nije pronadjen!", trazeniZnak);
        return 0;
    }

    brojac++;
    duzinaNiza--;

    binarnaPretraga(niz, trazeniZnak, duzinaNiza, sredinaNiza, brojac);

    return 0;
}
