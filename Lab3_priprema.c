#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

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
