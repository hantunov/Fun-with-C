#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct model {
    int ID;
    char naziv[100];
    char kategorija[50];
    float duljina;
    int br_lezajeva;
    int br_soba;
    int cijena;
}modeli[150];

struct jahta {
    char reg[6+1];
    int model;
    char naziv[100+1];
    char luka[3+1];
}jahte[500];

struct luka {
    char kod[3+1];
    char naziv[100+1];
    double lat;
    double lon;
}luke[60];

struct pom{
    char reg[6+1];
    char kategorija[50];
    char naziv[100+1];
    float duljina;
    int cijena;
    int model;
}pomocna[500];

void pretraga(char *kod_luke, int donja_cijena, int gornja_cijena, int broj_modela, int broj_jahti, int broj_luka, FILE *ispis);

int main()
{
    int i = 0, br_modela = 0, br_jahti = 0, br_luka = 0;
    char trazena_luka[3+1] = "";
    int donja_cijena, gornja_cijena;

    FILE *modeli_in, *jahte_in, *luke_in, *ispis;

    modeli_in = fopen("modeli.dat", "rb");
    jahte_in = fopen("mojejahte.txt", "r");
    luke_in = fopen("luke.txt", "r");
    ispis = fopen("rezultat.out", "w");

    if(modeli_in == NULL || jahte_in == NULL || luke_in == NULL || ispis == NULL){
        printf("Neuspjelo otvaranje datoteka!");
        exit(1);
    }

    while(fread(&modeli[i], sizeof(struct model), 1, modeli_in)!=0){
        i++;
        br_modela++;
    }

    i=0;

    while(fscanf(jahte_in, " %[^ ] %d %[^#]#%[^\n]", jahte[i].reg, &jahte[i].model, jahte[i].naziv, jahte[i].luka)==4){
        i++;
        br_jahti++;
    }

    i=0;

    while(fscanf(luke_in, " %[^ ] %[^(](%lf, %lf)", luke[i].kod, luke[i].naziv, &luke[i].lat, &luke[i].lon)==4){
        i++;
        br_luka++;
    }

    scanf(" %s %d %d", trazena_luka, &donja_cijena, &gornja_cijena);

    pretraga(trazena_luka, donja_cijena, gornja_cijena, br_modela, br_jahti, br_luka, ispis);

    fclose(modeli_in);
    fclose(jahte_in);
    fclose(luke_in);
    fclose(ispis);

    return 0;
}

void pretraga(char *kod_luke, int donja_cijena, int gornja_cijena, int broj_modela, int broj_jahti, int broj_luka, FILE *ispis)
{
    int i, j, br_pronadjenih = 0, br_printanih = 0;
    char *ptrLuka = NULL;
    struct pom *temp = NULL, *sortirano[500] = {};

    for(i=0; i<broj_luka; i++){
        if(strstr(luke[i].kod, kod_luke)!=NULL){
            printf("%s(%f, %f)\n", luke[i].naziv, luke[i].lat, luke[i].lon);
            fprintf(ispis, "%s(%f, %f)\n", luke[i].naziv, luke[i].lat, luke[i].lon);
            ptrLuka = luke[i].kod;
        }
    }
    if(ptrLuka == NULL){
        printf("Nepoznata marina.");
        fprintf(ispis, "Nepoznata marina.");
        exit(0);
    }

    for(i=0; i<broj_jahti; i++){
        if(strstr(jahte[i].luka, kod_luke)!=NULL){
            strcpy(pomocna[br_pronadjenih].reg, jahte[i].reg);
            strcpy(pomocna[br_pronadjenih].naziv, jahte[i].naziv);
            pomocna[br_pronadjenih].model = jahte[i].model;
            br_pronadjenih++;
        }
    }

    for(i=0; i<br_pronadjenih; i++){
        for(j=0; j<broj_modela; j++){
            if(pomocna[i].model == modeli[j].ID){
                strcpy(pomocna[i].kategorija, modeli[j].kategorija);
                pomocna[i].cijena = modeli[j].cijena;
                pomocna[i].duljina = modeli[j].duljina;
            }
        }
    }

    for(i=0; i<br_pronadjenih; i++){
        sortirano[i] = &pomocna[i];
    }

    for(i=0; i<br_pronadjenih; i++){
        for(j=i+1; j<br_pronadjenih; j++){
            if((sortirano[i]->cijena)>(sortirano[j]->cijena)){
                temp = sortirano[i];
                sortirano[i] = sortirano[j];
                sortirano[j] = temp;
            }
        }
    }

    for(i=0; i<br_pronadjenih; i++){
        if((sortirano[i]->cijena)>= donja_cijena && (sortirano[i]->cijena) <= gornja_cijena){
            printf("%s %s %s %.2fft EUR%d\n", sortirano[i]->reg, sortirano[i]->kategorija, sortirano[i]->naziv, sortirano[i]->duljina, sortirano[i]->cijena);
            fprintf(ispis, "%s %s %s %.2fft EUR%d\n", sortirano[i]->reg, sortirano[i]->kategorija, sortirano[i]->naziv, sortirano[i]->duljina, sortirano[i]->cijena);
            br_printanih++;
        }
    }

    if(br_printanih == 0){
        printf("Nema brodova za danu pretragu.");
        fprintf(ispis, "Nema brodova za danu pretragu.");
    }
}