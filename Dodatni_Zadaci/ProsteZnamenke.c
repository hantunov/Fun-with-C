/*
Potrebno je uèitati pozitivan broj X s tipkovnice i izraèunati mu zbroj znamenki.
Ako je zbroj znamenki prost broj onda treba ispisati sve proste brojeve manje od zbroja znamenki,
a ako nije od korisnika treba traziti unos broja Y u intervalu [11, 15]
i ispisati sve neparne brojeve djeljive sa Y u intervalu [1, X]
*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    int i, j, x, y, temp, polje[MAX] = {}, brojac = 0, suma = 0, jeProst, flag;

    do{
        scanf("%d", &x);

        if(x<=0){
            printf("Nepravilni unos!\n");
            continue;
        }
        else{
            temp = x;
            while(temp>0){
                brojac++;
                temp = temp/10;
            }

            temp = x;

            for(i = 0; i < brojac; i++){
                polje[i] = x%10;
                x = x/10;
                suma += polje[i];
            }

            x = temp;
            break;
        }

    } while(1);

    for(i = 2; i<suma; i++){

        jeProst = 1;
        if(suma%i == 0){
            jeProst = 0;
            break;
        }
    }

    if(jeProst){
        for(i=2; i<suma; i++){
            flag = 1;
            for(j=2; j<=i/2; j++){
                if(i%j==0){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                printf("%d ", i);
            }
        }
    } else if(!jeProst){
        while(1){
            scanf("%d", &y);
            if(y < 11 || y > 15){
                printf("Nepravilni unos!\n");
                continue;
            } else {
                for(i = 0; i < x; i++){
                    if((i/y>0) && (i%2!=0)){
                        if(i%y==0){
                            printf("%d ", i);
                            continue;
                        } else {
                            continue;
                        }
                    } else {
                        continue;

                    }
                }
                break;
            }
        }
    }

    return 0;
}