/*Imanje je pravokutnog oblika, i potrebno ga je podijeliti na pola kako bi i Alejandro i Rico Suave dobili jednak broj maslenika (M), pasnjaka (P) i gradjevina (G).
Imanje se moze podijeliti samo pravocrtno, okomito ili vodoravno. Potrebno je napraviti funkciju koja za neku predlozenu podjelu vraca informaciju je li podjela
korektna ili nije (funkciji je potrebno proslijediti matricu), a u main programu isprobati sve moguce podjele te ispisati, kao konacni rezultat, na koliko je nacina
moguce podijeliti imanje i gdje je sve moguce povuci granicu. Imanje nece biti vece od 100m u sirinu niti duzinu. Ukoliko je imanje nemoguce ispravno podijeliti,
potrebno je ispisati "Nemoguce podijeliti 50-50.".*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void izracun(char orijentacija, char imanje[][MAX], int visina, int sirina, int *br_podjela, int M, int P, int G);

int main()
{
    int i, j, sirina, visina, M = 0, P = 0, G = 0, tmpM = 0, tmpP = 0, tmpG = 0, br_ukupno = 0, br_podjela = 0;
    char imanje[MAX][MAX] = {{0}};

    //unos dimenzija polja

    scanf("%d%d", &visina, &sirina);

    //ucitavanje sadrzaja polja

    for(i = 0; i<visina; i++){
        for(j = 0; j<sirina; j++){
            scanf(" %c", &imanje[i][j]);
        }
    }

    //brojanje ukupne kolicine "maslenika","pasnjaka" i "gradjevina" na imanju

    for(i = 0; i<visina; i++){
        for(j = 0; j<sirina; j++){
            if(imanje[i][j]=='M')M++;
            if(imanje[i][j]=='P')P++;
            if(imanje[i][j]=='G')G++;
        }
    }

    //izracun ukupnog broja mogucih podjela

    for(i = 0; i<visina; i++){
        for(j = 0; j<sirina; j++){
            if(imanje[i][j]=='M')tmpM++;
            if(imanje[i][j]=='P')tmpP++;
            if(imanje[i][j]=='G')tmpG++;
        }
        if(tmpM == M/2 && tmpP == P/2 && tmpG == G/2){
            br_ukupno++;
        }
    }

    tmpM = tmpP = tmpG = 0;

    for(i = 0; i<sirina; i++){
        for(j = 0; j<visina; j++){
            if(imanje[j][i]=='M')tmpM++;
            if(imanje[j][i]=='P')tmpP++;
            if(imanje[j][i]=='G')tmpG++;
        }
        if(tmpM == M/2 && tmpP == P/2 && tmpG == G/2){
            br_ukupno++;
        }
    }

    // ispis

    if(br_ukupno == 0){
        printf("Nemoguce podijeliti 50-50.");
        return 0;
    } else {
        printf("Broj mogucih podjela: %d\n", br_ukupno);
        izracun('V',imanje, visina, sirina, &br_podjela, M, P, G);
        izracun('O',imanje, visina, sirina, &br_podjela, M, P, G);
    }

    return 0;
}

void izracun(char orijentacija, char imanje[][MAX], int visina, int sirina, int *br_podjela, int M, int P, int G){

    int i, j, tmpM = 0, tmpP = 0, tmpG = 0, granica = 0;

    if(orijentacija=='V'){
        for(i = 0; i<visina; i++){
            for(j = 0; j<sirina; j++){
                if(imanje[i][j]=='M')tmpM++;
                if(imanje[i][j]=='P')tmpP++;
                if(imanje[i][j]=='G')tmpG++;
            }
            granica++;
            if(tmpM == M/2 && tmpP == P/2 && tmpG == G/2){
                (*br_podjela)++;
                printf("%d. Vodoravno, izmedju retka br. %d i br. %d\n", *br_podjela, granica, granica+1);
            }
        }
    } else if(orijentacija=='O'){
        for(i = 0; i<sirina; i++){
            for(j = 0; j<visina; j++){
                if(imanje[j][i]=='M')tmpM++;
                if(imanje[j][i]=='P')tmpP++;
                if(imanje[j][i]=='G')tmpG++;
            }
            granica++;
            if(tmpM == M/2 && tmpP == P/2 && tmpG == G/2){
                (*br_podjela)++;
                printf("%d. Okomito, izmedju stupca br. %d i br. %d\n", *br_podjela, granica, granica+1);
            }
        }
    }
}
