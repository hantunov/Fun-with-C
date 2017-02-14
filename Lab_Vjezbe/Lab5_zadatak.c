#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int main()
{
    int i, j, studenti;
    double postotak, tablica[MAX][4] = {{0}}, prolaznost[4] = {}, pomocna[4] = {};

    for(i=0; i<MAX; i++){
        scanf("%d", &studenti);
        if(studenti<2 || studenti>10){
            printf("Pogresan unos broja. Unesite ponovno broj studenata:\n");
            continue;
        } else {
            break;
        }
    }



    for(i = 0; i<studenti; i++){
        for(j = 0; j<4; j++){
            scanf("%lf", &postotak);
            tablica[i][j] = postotak;
        }
    }

    for(i = 0; i<studenti; i++){
        for(j = 0; j<4; j++){
            if(tablica[i][j]>=50 && tablica[i][j]<= 100){
                prolaznost[j]++;
            }
        }
    }

    for(i = 0; i<4; i++){
            pomocna[i] = (100.00/studenti)*prolaznost[i];
    }

    printf("Prolaznost:\n");

    for(i = 0; i<studenti; i++){
        for(j = 0; j<4; j++){
            if(j<=2){
                printf("%.0lf\t", tablica[i][j]);}
            else{
                printf("%.0lf", tablica[i][j]);
            }
        }
        printf("\n");
    }

    for(i = 0; i<4; i++){
        if(i<=2){
            printf("%.0lf\t", pomocna[i]);
        } else{
            printf("%.0lf", pomocna[i]);
        }

    }

    return 0;
}
