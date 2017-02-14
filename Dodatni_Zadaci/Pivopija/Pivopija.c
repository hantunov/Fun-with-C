/*
Napišite C program koji učitava podatke o pivima iz datoteke pivo.in. Podaci o svakom pivu se sastoje od sljedećeg:
naziv_piva -  string od max 50 znakova
kolicina -  količina piva u jednoj boci u litrama  - pozitivni realni broj
cijena - cijena jedne boce u kunama - pozitivni realni broj
Napišite funkciju koja će pronaći i kao rezultat vratiti koje pivo je najisplativije (najjeftinije po litri).
U main programu zapisati rezultat u datoteku pivo.out.

U zadatku se koriste ulazne ili izlazne datoteke

Datoteka za ulaz: pivo.in
Izlazna datoteka: pivo.out
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void isplativost(char *naziv_piva, float kolicina, float cijena, char *najboljePivo, float *najboljaCijena);

struct pivo{
    char naziv_piva[50+1];
    float kolicina;
    float cijena;
};

int main()
{
    FILE *inputFile, *outputFile;

    struct pivo P, najboljeP;
    najboljeP.cijena = 1000;
    float* pNC = &najboljeP.cijena;
    char* pNP = najboljeP.naziv_piva;

    inputFile = fopen("pivo.in", "r");
    outputFile = fopen("pivo.out", "w");

    if(inputFile == NULL || outputFile == NULL){
        printf("Neuspjelo otvaranje fajlova!");
        exit(0);
    }

    while(!feof(inputFile)){
        fscanf(inputFile, " %[^:]: %fL %fkn[^\n]", P.naziv_piva, &P.kolicina, &P.cijena);
        isplativost(P.naziv_piva, P.kolicina, P.cijena, pNP, pNC);
    }

    fprintf(outputFile, "Najisplativije je %s: %.2f kn/L", najboljeP.naziv_piva, najboljeP.cijena);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

void isplativost(char *naziv_piva, float kolicina, float cijena, char *najboljePivo, float *najboljaCijena)
{
    float cijenaPoLitri = cijena/kolicina;

    if(cijenaPoLitri < *najboljaCijena){
        strcpy(najboljePivo, naziv_piva);
        *najboljaCijena = cijenaPoLitri;
    }
}
