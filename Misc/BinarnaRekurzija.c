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

    //Unesemo string koji cemo pretrazivati i znak koji trazimo
    printf("Unesite niz znakova: ");
    scanf("%s", niz);
    printf("Unesite trazeni znak: ");
    scanf(" %c", &trazeniZnak);

    //Izracunamo polovicu niza (ovo saljemo u rekurzivnu funkciju kako bi znali kada stati s rekurzijom)
    duzinaNiza = strlen(niz)-1;
    if(duzinaNiza%2 == 0) sredinaNiza = duzinaNiza/2;
    else sredinaNiza = (duzinaNiza/2)+1;

    printf("Ispis:\n");

    //Pozivamo rekurzivnu funkciju (brojacu predajemo 0 kao pocetnu vrijednost)
    binarnaPretraga(niz, trazeniZnak, duzinaNiza, sredinaNiza, 0);

    return 0;
}

int binarnaPretraga(char* niz, char trazeniZnak, int duzinaNiza, int sredinaNiza, int brojac){

    //Funkcija ce se rekurzivno vrtiti sve dok ne dodjemo do sredine rijeci
    if(brojac<=sredinaNiza){

        //Ispisujemo znak na pocetku niza, pocevsi od 0 (povecava se za 1 u svakom slijedecem krugu rekurzije)
        //i ako je znak jednak trazenom ispisujemo poruku i prekidamo rekurziju
        printf("Iteracija %d, pozicija %d, znak %c\n", brojac+1, brojac, *(niz+brojac));
        if(*(niz+brojac) == trazeniZnak){
            printf("Znak %c je pronadjen!", trazeniZnak);
            return 0;
        }

        //Ispisujemo znak na kraju niza, pocevsi od duzine niza -1 (smanjuje se za 1 u svakom slijedecem krugu rekurzije)
        //i ako je znak jednak trazenom ispisujemo poruku i prekidamo rekurziju
        if(duzinaNiza>sredinaNiza) printf("Iteracija %d, pozicija %d, znak %c\n", brojac+1, duzinaNiza, *(niz+duzinaNiza));
        if(*(niz+duzinaNiza) == trazeniZnak){
            printf("Znak %c je pronadjen!", trazeniZnak);
            return 0;
        }

    } else {
        //Ako nakon sto smo dosli do sredine rijeci nismo nasli znak s obje strane, ispisujemo i prekidamo
        printf("Znak %c nije pronadjen!", trazeniZnak);
        return 0;
    }

    //Povecavanje brojaca i smanjivanje duzine niza u svakom krugu rekurzije
    brojac++;
    duzinaNiza--;

    //Poziv rekurzivne funkcije
    binarnaPretraga(niz, trazeniZnak, duzinaNiza, sredinaNiza, brojac);

    return 0;
}
