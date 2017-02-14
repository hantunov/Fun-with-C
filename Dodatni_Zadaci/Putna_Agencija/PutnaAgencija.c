/*Napisati C program koji æe ispisati sva putovanja koja zadovoljavaju traženi budžet. Datoteka agencija.dat sadrži podatke o putovanjima u sljedeæem obliku:
naziv destinacije: 30+1 znakova
dan polaska: int (pretpostaviti da svaki mjesec ima tocno 31 dan)
mjesec polaska: int
broj dana: int
cijena: double
popust: int (postotak)

Potrebno je uèitati koliki je budžet (od-do), te ispisati sva putovanja koja su unutar budžeta, poredano po ukupnoj cijeni, u datoteku dostupno.txt.

Napomena: treba uzeti u obzir i postotak popusta kod izraèuna cijene.

U zadatku se koriste ulazne ili izlazne datoteke

Ulazna datoteka: agencija.dat
Izlazna datoteka: dostupno.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct dest{
    char naziv[30+1];
    int dan_polaska;
    int mjsc_polaska;
    int br_dana;
    double cijena;
    int popust;
};

int main()
{
    int i, j, br_dest, br_odgovarajucih;
    double izracun, min, max;
    struct dest *d, *dsort;
    struct dest temp;

    d = (struct dest*)malloc(sizeof(struct dest));
    dsort = (struct dest*)malloc(sizeof(struct dest));

    FILE *fin, *fout;
    fin = fopen("agencija.dat", "rb");
    fout = fopen("dostupno.txt", "w");

    if(fin == NULL || fout == NULL){
        printf("Neuspjelo otvaranje datoteka!");
        exit(0);
    }

    fseek(fin, 0, SEEK_END);
    d = (struct dest*)realloc(d, ftell(fin));
    dsort = (struct dest*)realloc(d, ftell(fin));
    rewind(fin);

    i=br_dest=br_odgovarajucih=0;

    while(fread(&d[i], sizeof(struct dest), 1, fin)==1){
        i++;
        br_dest++;
    }

    scanf("%lf%lf", &min, &max);

    for(i = 0; i<br_dest; i++){
        izracun = d[i].cijena - (d[i].popust*(d[i].cijena/100));
        if(izracun >= min && izracun <= max){
            dsort[br_odgovarajucih] = d[i];
            br_odgovarajucih++;
        }
    }

    dsort = (struct dest*)realloc(dsort, br_odgovarajucih*sizeof(struct dest));

    for(i=0; i<br_odgovarajucih; i++){
        for(j=i+1; j<br_odgovarajucih; j++){
            if(dsort[i].cijena - (dsort[i].popust*(dsort[i].cijena/100)) > dsort[j].cijena - (dsort[j].popust*(dsort[j].cijena/100))){
                temp = dsort[i];
                dsort[i] = dsort[j];
                dsort[j] = temp;
            }
        }
    }

    for(i = 0; i<br_odgovarajucih; i++){
        fprintf(fout, "%s %d.%d. (%d dana) %.2f\n", dsort[i].naziv, dsort[i].dan_polaska, dsort[i].mjsc_polaska, dsort[i].br_dana, dsort[i].cijena - dsort[i].popust*(dsort[i].cijena/100));
    }

    free(d);
    free(dsort);
    fclose(fin);
    fclose(fout);

    return 0;
}