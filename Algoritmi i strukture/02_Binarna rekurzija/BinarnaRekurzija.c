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

void binarnoPretrazivanje(char *nizZnakova, char trazeniZnak, int duzinaNiza, int indeks);

int main()
{
    char *nizZnakova, trazeniZnak;
    int duzinaNiza;
    
    //Alociramo memoriju za 1000 znakova u nizu
    nizZnakova = (char*)malloc(1000*sizeof(char));

    printf("Unesite niz znakova: ");
    scanf("%s", nizZnakova);
    duzinaNiza = strlen(nizZnakova);
    
    //Realociramo memoriju tako da je polje dugacko tocno onoliko koliko znakova imamo + 1 za /0
    nizZnakova = realloc(nizZnakova, duzinaNiza+1);

    printf("Unesite trazeni znak: ");
    scanf(" %c", &trazeniZnak);

    printf("Ispis:\n");
    binarnoPretrazivanje(nizZnakova, trazeniZnak, duzinaNiza, 0);

    return 0;
}

void binarnoPretrazivanje(char *nizZnakova, char trazeniZnak, int duzinaNiza, int indeks){
    
    int sredinaNiza;
    
    //Racunamo sredinu niza kako bismo znali kada stati s trazenjem
    if(duzinaNiza%2 == 0){
        sredinaNiza = duzinaNiza/2;
    } else {
        sredinaNiza = (duzinaNiza/2)+1;
    }

    if(indeks==sredinaNiza){
        printf("Znak %c nije pronadjen!\n", trazeniZnak);
        return;
    }
    
    //Ovaj dio koda jednostavno gleda prvi i zadnji znak u trenutacnoj iteraciji (ovisi o indeksu)
    // i usporedjuje s trazenim znakom. Ako ga nadje, izlazi iz rekurzivne funkcije.
    printf("Iteracija %d, pozicija %d, znak %c\n", indeks+1, indeks, *(nizZnakova+indeks));
        if(*(nizZnakova+indeks) == trazeniZnak){
            printf("Znak %c je pronadjen\n", trazeniZnak);
            return;
        }
    printf("Iteracija %d, pozicija %d, znak %c\n", indeks+1, (duzinaNiza-1)-indeks, *(nizZnakova+(duzinaNiza-1)-indeks));
        if(*(nizZnakova+(duzinaNiza-1)-indeks) == trazeniZnak){
            printf("Znak %c je pronadjen\n", trazeniZnak);
            return;
        }
    indeks++;

    binarnoPretrazivanje(nizZnakova, trazeniZnak, duzinaNiza, indeks);
}
