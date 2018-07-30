#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binarnoPretrazivanje(char *nizZnakova, char trazeniZnak, int duzinaNiza, int indeks);

int main()
{
    char *nizZnakova, trazeniZnak;
    int duzinaNiza;

    nizZnakova = (char*)malloc(1000*sizeof(char));

    printf("Unesite niz znakova: ");
    scanf("%s", nizZnakova);
    duzinaNiza = strlen(nizZnakova);

    nizZnakova = realloc(nizZnakova, duzinaNiza+1);

    printf("Unesite trazeni znak: ");
    scanf(" %c", &trazeniZnak);

    printf("Ispis:\n");
    binarnoPretrazivanje(nizZnakova, trazeniZnak, duzinaNiza, 0);

    return 0;
}

void binarnoPretrazivanje(char *nizZnakova, char trazeniZnak, int duzinaNiza, int indeks){

    int sredinaNiza;

    if(duzinaNiza%2 == 0){
        sredinaNiza = duzinaNiza/2;
    } else {
        sredinaNiza = (duzinaNiza/2)+1;
    }

    if(indeks==sredinaNiza){
        printf("Znak %c nije pronadjen!\n", trazeniZnak);
        return;
    }

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
