/*
U datoteci naziva "studenti.dat" nalaze se informacije o rezultatima kolokvija zapisani u obliku struktura: 

ime studenta - string od 30+1 znak,
prezime studenta - string od 30+1 znak,
ocjena - cijeli broj

Program mora obaviti jedno od dvije funkcije ovisno u opciji koju unosi korisnik.
Ukoliko želi izvršiti prvu funkcionalnost unosi 1, a za drugu 2.

1) Potrebno je napisati funkciju naziva prosli_sortirano koja æe u tekstualnu datoteku
naziva "rezultati.txt" upisati sve studente koji su prošli kolokvij i sortirati ih
abecedno po prezimenu (ukoliko je prezime isto po imenu) i u datoteku ih upisati u formatu:

prezime ime | ocjena


2) Takoðer, potrebno je napisati funkciju naziva pali koja æe u tekstualnu datoteku
naziva "rezultati.txt" upisati sve studente koji su pali kolokvij i u datoteku ih
upisati u formatu (isto sortirati kao pod tockom 1):

prezime ime


Neovisno o izboru 1) ili 2) u istu datoteku "rezultati.txt" potrebno je na kraj datoteke upisati statistiku prolaznosti kolokvija u obliku:

Kolokvij je proslo X% studenata, a palo Y%.

U zadatku se koriste ulazne ili izlazne datoteke

Ulazna datoteka: studenti.dat
Izlazna datoteka: rezultati.txt

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct student {
    char ime[30+1];
    char prezime[30+1];
    int ocjena;
}studenti[100];

struct pomocna{
    char ime[30+1];
    char prezime[30+1];
    int ocjena;
}pomocna[100];

void prosli_sortirano(int br_studenata, FILE *izlaz);
void pali(int br_studenata, FILE *izlaz);

int main()
{
    int i, br_studenata, unos;

    FILE *fin, *fout;

    fin = fopen("studenti.dat", "rb");
    fout = fopen("rezultati.txt", "w");

    if(fin == NULL || fout == NULL){
        printf("Neuspjelo otvaranje datoteka!");
        exit(1);
    }

    i=br_studenata=0;

    while(fread(&studenti[i], sizeof(struct student), 1, fin)!=0){
        i++;
        br_studenata++;
    }

    while(1){
        scanf("%d", &unos);
        if(unos==1){
            prosli_sortirano(br_studenata, fout);
            break;
        }
        if(unos==2){
            pali(br_studenata, fout);
            break;
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}

void prosli_sortirano(int br_studenata, FILE *izlaz){

    int i, j, br_proslih, br_palih;
    struct pomocna *temp = NULL, *sortirano[100] = {};

    br_proslih=br_palih=0;

    for(i=0; i<br_studenata; i++){
        if(studenti[i].ocjena < 2){
            br_palih++;
        }else{
            strcpy(pomocna[br_proslih].ime, studenti[i].ime);
            strcpy(pomocna[br_proslih].prezime, studenti[i].prezime);
            pomocna[br_proslih].ocjena = studenti[i].ocjena;
            br_proslih++;
        }
    }

    for(i=0; i<br_proslih; i++){
        sortirano[i] = &pomocna[i];
    }

    for(i=0; i<br_proslih; i++){
        for(j=i+1; j<br_proslih; j++){
            if(strcmp(sortirano[i]->prezime,sortirano[j]->prezime)>0){
                temp = sortirano[i];
                sortirano[i] = sortirano[j];
                sortirano[j] = temp;
            }else if(strcmp(sortirano[i]->prezime,sortirano[j]->prezime)==0){
                if(strcmp(sortirano[i]->ime,sortirano[j]->ime)>0){
                    temp = sortirano[i];
                    sortirano[i] = sortirano[j];
                    sortirano[j] = temp;
                }
            }
        }
    }

    for(i=0; i<br_proslih; i++){
        printf("%s %s | %d\n", sortirano[i]->prezime, sortirano[i]->ime, sortirano[i]->ocjena);
        fprintf(izlaz, "%s %s | %d\n", sortirano[i]->prezime, sortirano[i]->ime, sortirano[i]->ocjena);
    }

    printf("\nKolokvij je proslo %.0f%% studenata, a palo %.0f%%.", floorf((float)br_proslih/(float)br_studenata*100.00), floorf((float)br_palih/(float)br_studenata*100.00));
    fprintf(izlaz, "\nKolokvij je proslo %.0f%% studenata, a palo %.0f%%.", floorf((float)br_proslih/(float)br_studenata*100.00), floorf((float)br_palih/(float)br_studenata*100.00));

}

void pali(int br_studenata, FILE *izlaz){

    int i, j, br_proslih, br_palih;
    struct pomocna *temp = NULL, *sortirano[100] = {};

    br_proslih=br_palih=0;

    for(i=0; i<br_studenata; i++){
        if(studenti[i].ocjena < 2){
            strcpy(pomocna[br_palih].ime, studenti[i].ime);
            strcpy(pomocna[br_palih].prezime, studenti[i].prezime);
            br_palih++;
        }else{
            br_proslih++;
        }
    }

    for(i=0; i<br_palih; i++){
        sortirano[i] = &pomocna[i];
    }

    for(i=0; i<br_palih; i++){
        for(j=i+1; j<br_palih; j++){
            if(strcmp(sortirano[i]->prezime,sortirano[j]->prezime)>0){
                temp = sortirano[i];
                sortirano[i] = sortirano[j];
                sortirano[j] = temp;
            }else if(strcmp(sortirano[i]->prezime,sortirano[j]->prezime)==0){
                if(strcmp(sortirano[i]->ime,sortirano[j]->ime)>0){
                    temp = sortirano[i];
                    sortirano[i] = sortirano[j];
                    sortirano[j] = temp;
                }
            }
        }
    }

    for(i=0; i<br_palih; i++){
        printf("%s %s\n", sortirano[i]->prezime, sortirano[i]->ime);
        fprintf(izlaz, "%s %s\n", sortirano[i]->prezime, sortirano[i]->ime);
    }

    printf("\nKolokvij je proslo %.0f%% studenata, a palo %.0f%%.", floorf((float)br_proslih/(float)br_studenata*100.00), floorf((float)br_palih/(float)br_studenata*100.00));
    fprintf(izlaz, "\nKolokvij je proslo %.0f%% studenata, a palo %.0f%%.", floorf((float)br_proslih/(float)br_studenata*100.00), floorf((float)br_palih/(float)br_studenata*100.00));

}