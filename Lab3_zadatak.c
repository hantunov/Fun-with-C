#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10


int main(){

    int i, N = 0, domaci, gosti, golrazlika, grmax = 0, krug = 0, dp = 0, gp = 0;

    do{
        scanf(" %d", &N);
    } while(N<1 || N>MAX);

    for(i=0; i<N; i++){

        scanf(" %d %d", &domaci, &gosti);
        golrazlika = abs(domaci-gosti);

        if(grmax == 0){
            grmax = golrazlika;
        }

        if(golrazlika>=grmax){
            grmax = golrazlika;
            krug = i+1;
        }

        if(domaci>gosti){
            dp++;
        } else if(domaci<gosti){
            gp++;
        }
    }

    if(grmax == 0){
        krug = 1;
    }

    if(dp>gp){
        printf("Najveca gol razlika %d postignuta je u %d. krugu, a ukupni pobjednik je 1. tim.", grmax, krug);
    } else if(dp<gp){
        printf("Najveca gol razlika %d postignuta je u %d. krugu, a ukupni pobjednik je 2. tim.", grmax, krug);
    } else if (dp==gp) {
        printf("Najveca gol razlika %d postignuta je u %d. krugu. Timovi imaju jednake bodove.", grmax, krug);
    }

    return 0;
}