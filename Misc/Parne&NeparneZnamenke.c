/*
Napisati funkciju "prebroji" koja za zadani nenegativni cijeli broj u pozivajuci
program vraca dva cijela broja: zbroj parnih znamenki i zbroj neparnih znamenki.
Napisati glavni program koji ucitava broj, poziva funkciju, te ispisuje spomenute
brojeve.
*/

#include <stdio.h>
#include <stdlib.h>

void prebroji(int a, int *ptrP, int *ptrN);

int main()
{
    int a = 0, zbrP = 0, zbrN = 0;
    int *ptrP = &zbrP;
    int *ptrN = &zbrN;

    printf("Unesite neki cijeli broj (do 9 znamenki): ");
    //Ako prihvacamo brojeve vece od 8 znamenki moze doci do krivih rezultata (najveci int je 2,147,483,647)
    scanf("%9d", &a);
    printf("\n");
    if(a<0) a = abs(a);
    prebroji(a, ptrP, ptrN);
    printf("Zbroj parnih: %d\nZbroj neparnih: %d\n", zbrP, zbrN);

    return 0;
}

void prebroji(int a, int *ptrP, int *ptrN){

    int i, brZnam = 0, temp;
    temp = a;

    //prebrojimo koliko znamenki uneseni broj ima

    while(a>0){
        a /= 10;
        brZnam++;
    }

    a = temp;

    //dinamicki alociramo int polje velicine broja znamenki
    int* znamenke = (int*)malloc(brZnam*sizeof(int));

    //spremimo broj znamenki u privremenu varijablu
    i = brZnam;

    //napunimo polje sa znamenkama, obrnutim redom (tako da ako citamo polje po redu izgleda kao nas izvorni broj)
    while(a>0){
        temp = a%10;
        znamenke[brZnam-1]=temp;
        brZnam--;
        a /= 10;
    }

    brZnam = i;

    //redom testiramo svaki broj u polju i azuriramo zbrojeve u glavnoj funkciji preko pointera

    for(i=0; i<brZnam; i++){
        printf("%d. znamenka: %d, ", i+1, znamenke[i]);
        if(znamenke[i]%2==0){
            *ptrP += znamenke[i];
            printf("PARNA");
        }else {
            *ptrN += znamenke[i];
            printf("NEPARNA");
        }
        printf("\n");
    }
    
    //oslobodimo alociranu memoriju (izbjegavamo "visece" pointere)
    free(znamenke);
}
