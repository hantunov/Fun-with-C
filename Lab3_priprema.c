#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

/*Jedan vaš prijatelj, popularno zvan "Giza", odlučio je probati zaraditi na pretvaranju valuta. Inicijalno, on raspolaže
sa 100,00 kn. Svaki dan, pogleda tečaj za promjenu EUR <-> KN, i ako je tečaj najpovoljniji (za njega) koji je on do sad vidio,
pretvorit će sve novce jedne valute u drugu. 

Vaš zadatak je napisati program koji će simulirati ponašanje našeg Gize, i nakon što prođe N dana ispisati koliko
kuna ili eura ima Giza.

Učitava se prirodni broj N, koji označava koliko dana Giza mijenja novce, a u svakom retku nalaze se dva decimalna broja
k i p sa 5 decimala koji označavaju kupovni i prodajni tečaj za EUR:
Ukoliko Giza ima 100,00 kn, a kupovni tečaj za EUR je 7,50000; Giza će taj dan završiti s 13,33 €
(ukoliko, prema pravilima zadatka, odluči promijeniti novce). Primjerice, kad idući put bude imao kune,
promijenit će samo ako je kupovni tečaj manji od 7,50000 (tada je tečaj povoljniji)
Ukoliko Giza ima 20,00 €, a prodajni tečaj za EUR je 7,40000; Giza će taj dan završiti sa 148,00 kn
(uvijek se zaokružuje na 2 decimale). Primjerice, kad idući put bude imao eure, promijenit će samo ako je
prodajni tečaj veći od 7,40000 (tada mu je tečaj povoljniji)*/


int main()
{
    int i, N, br = 0;
    double kune = 100.00, euri = 0.00;
    double k, p;
    double kmin = 0, pmax = 0;
    char imaKune = 'd', imaEure ='n';

    scanf(" %d", &N);

    for(i = 1; i<=N; i++){

        scanf(" %lf %lf", &k, &p);

        if(k<kmin){
            kmin = k;
        }

        if(p>pmax){
            pmax = p;
        }

        if(imaKune == 'd'){
            if(kmin == 0){
                kmin = k;
            }

            if(k<=kmin){
                euri = round((kune/k)*100)/100;
                kune = 0.00;
                imaKune = 'n';
                imaEure = 'd';
                br++;
            } else{
                continue;
            }

        } else if(imaEure == 'd'){

            if(p>=pmax){
                kune = round((euri*p)*100)/100;
                euri = 0.00;
                imaKune = 'd';
                imaEure = 'n';
                br++;
            } else{
                continue;
            }
        }
    }

    if(imaKune == 'd'){
        printf("Nakon %d promjena, ostaje mu %.2lf kn.", br, kune);
    }

    else{
        printf("Nakon %d promjena, ostaje mu %.2lf EUR.", br, euri);
    }

    return 0;
}
