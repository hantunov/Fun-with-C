/*
U programskom jeziku napi�ite aplikaciju koji u listu 1) dodaje na po�etak, 2) dodaje u sredinu, 3) dodaje na
kraj liste proizvoljan broj slu�ajno generiranih cjelobrojnih brojeva (int).

Za svaku operaciju aplikacija mjeri vrijeme koje je proteklo da bi se ta operacija izvr�ila, tj. od po�etka do kraja
operacije, te ispi�e vrijeme na ekran.

U ovom zadatku lista obavezno mora biti realizirana stati�kim poljem cijelih brojeva int[]. Nije dozvoljeno kori�tenje
slo�enih tipova podataka ugra�enih u programske jezike kao �to su List, ArrayList, Stack, Queue, Map, itd.
Za izradu vje�be obavezno konzultirajte predavanje L3_LISTA2016 objavljeno na stranicama predmeta Algoritmi i
strukture podataka na redovitom studiju ra�unarstva, te dodatnu literaturu po potrebi.

Za mjerenje vremena koristiti funkciju ctime(&time_t time1) i strukturu time_t. A za izra�un razlike
vremena (proteklo vrijeme izme�u dva intervala) koristiti funkciju double difftime(time_t time1,
time_t time2). Na po�etku programa potrebno je uklju�iti header datoteku time.h sa #include
<time.h>. Primjer: https://www.tutorialspoint.com/c_standard_library/c_function_difftime.htm

Vje�ba se mora realizirati u programskom jeziku C.


Primjer ispravnog rada:

Odaberite operaciju nad listom (1, 2 ili 3): 1
Unesite broj generiranih znakova: 100
Dodavanje na po�etak 100 slu�ajno generiranih znakova trajalo je: 0,432 s

Odaberite operaciju nad listom (1, 2 ili 3): 2
Unesite broj generiranih znakova: 10000
Dodavanje u sredinu 10000 slu�ajno generiranih znakova trajalo je: 2,191 s

Odaberite operaciju nad listom (1, 2 ili 3): 3
Unesite broj generiranih znakova: 1000
Dodavanje na kraj 1000 slu�ajno generiranih znakova trajalo je: 0,422 s
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

void punjenjeListe(int lista[], int odabir, int brojGeneriranihZnakova);

int main()
{
    int odabir = 0, brojGeneriranihZnakova = 0;
    int lista[MAX] = {};

    do{
        printf("Odaberite operaciju nad listom (1, 2 ili 3): ");
        scanf("%d", &odabir);
    }while(odabir < 1 || odabir > 3);

    do{
        printf("Unesite broj generiranih znakova: ");
        scanf("%d", &brojGeneriranihZnakova);
        if(odabir == 2 && brojGeneriranihZnakova > MAX/2){
            brojGeneriranihZnakova = MAX/2;
        }
    }while(brojGeneriranihZnakova < 1 || brojGeneriranihZnakova > MAX);

    punjenjeListe(lista, odabir, brojGeneriranihZnakova);

    return 0;
}

void punjenjeListe(int lista[], int odabir, int brojGeneriranihZnakova){

    time_t startTime, endTime;
    double diffTime;
    int i;

    if(odabir == 1){
        time(&startTime);
        for(i=0; i<brojGeneriranihZnakova; i++){
            lista[i] = rand();
        }
        time(&endTime);
        diffTime = difftime(endTime, startTime);
        printf("Dodavanje na pocetak %d slucajno generiranih znakova trajalo je: %lf s",brojGeneriranihZnakova, diffTime);
    }
    if(odabir == 2){
        time(&startTime);
        for(i=MAX/2; i<(MAX/2)+brojGeneriranihZnakova; i++){
            lista[i] = rand();
        }
        time(&endTime);
        diffTime = difftime(endTime, startTime);
        printf("Dodavanje u sredinu %d slucajno generiranih znakova trajalo je: %lf s",brojGeneriranihZnakova, diffTime);
    }
    if(odabir == 3){
        time(&startTime);
        for(i=MAX; i>=MAX-brojGeneriranihZnakova; i--){
            lista[i] = rand();
        }
        time(&endTime);
        diffTime = difftime(endTime, startTime);
        printf("Dodavanje na kraj %d slucajno generiranih znakova trajalo je: %lf s",brojGeneriranihZnakova, diffTime);
    }
}
