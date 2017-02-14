/*
Ministarstvo Unutarnjih Poslova (MUP) vodi registar svih vozaèa.
Vi, kao mladi MUPovac, želite saznati neke statistièke podatke o vozaèima iz registra.

Registar se nalazi u datoteci Registar.in, i sastoji se od niza
redaka gdje svaki redak predstavlja jednog vozaèa, zajedno sa
registracijskom oznakom njegovog vozila. Primjer jednog retka datoteke:

Horvat, Ivan; ZG998PR 11.09.1976 13.08.2001
...

Prvi dio retka su prezime i ime vozaèa (odvojeno zarezom),
zatim registracijska oznaka vozila, te datum roðenja i datum izrade vozaèke dozvole.
Vaš zadatak je uèitati sve podatke iz datoteke u niz zapisa odgovarajuæe strukture,
te ispisati 5 najmlaðih vozaèa (prema datumu roðenja, poèevši od najmlaðeg).
Ispisati rezultate u datoteku Najmladji.out, u sljedeæem obliku:

Ivan Horvat (11.09.1976)
...

Napomena: programi koji ne koriste strukture ne mogu dobiti sve bodove.


U zadatku se koriste ulazne ili izlazne datoteke

Datoteka za ulaz: Registar.in
Izlazna datoteka: Najmladji.out
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct osoba{
    char prezime[50+1];
    char ime[50+1];
    char registracija[10+1];
    int dan_rod;
    int mjsc_rod;
    int god_rod;
    int dan_izd;
    int mjsc_izd;
    int god_izd;
    int rod_zbrojdana;
}registar[100];

int main()
{
    int i = 0, j, br_osoba = 0;
    struct osoba temp;

    FILE *fin, *fout;
    fin = fopen("Registar.in", "r");
    fout = fopen("Najmladji.out", "w");

    if(fin == NULL || fout == NULL){
        printf("Neuspjesno otvaranje datoteka!");
        exit(1);
    }

    while(fscanf(fin, " %[^,], %[^;]; %s %d.%d.%d. %d.%d.%d.", registar[i].prezime, registar[i].ime, registar[i].registracija, registar[i].dan_rod, registar[i].mjsc_rod, registar[i].god_rod, registar[i].dan_izd, registar[i].mjsc_izd, registar[i].god_izd)==9){
        br_osoba++;
        i++;
    }

    for(i=0; i<br_osoba; i++){
        registar[i].rod_zbrojdana = (registar[i].god_rod*365)+(registar[i].mjsc_rod*30)+registar[i].dan_rod;
    }

    for(i=0; i<br_osoba; i++){
        for(j=i+1; j<br_osoba; j++){
            if(registar[i].rod_zbrojdana < registar[j].rod_zbrojdana){
                temp = registar[i];
                registar[i] = registar[j];
                registar[j] = temp;
            }
        }
    }

    for(i=0; i<br_osoba; i++){
        printf("%s %s (%02d.%2d.%4d)\n", registar[i].ime, registar[i].prezime, registar[i].dan_rod, registar[i].mjsc_rod, registar[i].god_rod);
        fprintf(fout, "%s %s (%02d.%02d.%4d)\n", registar[i].ime, registar[i].prezime, registar[i].dan_rod, registar[i].mjsc_rod, registar[i].god_rod);
        if(i==4){
            break;
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}