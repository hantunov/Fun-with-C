#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, odabir, br_par, br_prij, temp;
    int poljeA[10] = {}, poljeB [10] = {}, poljeC[10] = {};

    for(i=0; i<10; i++){

        scanf(" %d", &poljeA[i]);
    }

    scanf(" %d", &odabir);

    switch(odabir){
        case 1:
            br_par = 0;
            for(i=0; i<10; i++){
                if(poljeA[i]%2 == 0)
                    br_par++;
            }
            printf("U polju poljeA parnih brojeva ima: %d.", br_par);
            break;
        case 2:
            printf("PoljeA (nesortirano):");
            for(i=0; i<10; i++){
                poljeB[i]=poljeA[i];
                printf(" %d", poljeA[i]);
            }
            printf("\nPoljeB (sortirano):");
            for(i=0; i<10; i++){
                for(j=i+1; j<10; j++){
                    if(poljeB[i]<poljeB[j]){
                        temp = poljeB[i];
                        poljeB[i] = poljeB[j];
                        poljeB[j] = temp;
                    }
                }
            }
            for(i=0; i<10; i++){
                printf(" %d", poljeB[i]);
            }
            break;
        case 3:
            br_prij=0;
            for(i=0; i<10; i++){
                if(poljeA[i]%3 == 1){
                    poljeC[br_prij]=poljeA[i];
                    br_prij++;
                }
            }
            printf("PoljeA:");
            for(i=0; i<10; i++){
                printf(" %d", poljeA[i]);
            }
            printf("\nPoljeC:");
            for(i=0; i<10; i++){
                if(poljeC[i] != 0)
                    printf(" %d", poljeC[i]);
                else
                    continue;
            }
            break;
        default:
            break;

    }

    return 0;
}
