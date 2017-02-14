#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10

int pretvorba(int broj);

int main()
{

    int i, j, n, m, broj, br_nep = 0, tablica_prir[MAX][MAX] = {{0}}, tablica_bin[MAX][MAX] = {{0}};

    do{
        scanf("%d %d", &n, &m);

    } while(n<1 || m>8);

    for(i = 0; i<n; i++){
        for(j = 0; j<m; j++){
            scanf("%d ", &tablica_prir[i][j]);
        }
    }

    for(i = 0; i<n; i++){
        for(j = 0; j<m; j++){
            if(tablica_prir[i][j]%2==0){
                br_nep++;
            }
        }
    }

    for(i = 0; i<n; i++){
        for(j = 0; j<m; j++){
            broj = tablica_prir[i][j];
            tablica_bin[i][j] = pretvorba(broj);
        }
    }

    for(i = 0; i<n; i++){
        for(j = 0; j<m; j++){
            printf("%d ", tablica_bin[i][j]);
        }
        printf("\n");
    }

    printf("S 0 zavrsava %d brojeva.", br_nep);

    return 0;
}

int pretvorba(int broj)
{

    int i = 0, j, binarni[MAX] = {}, rezultat = 0, br_znam = 0, temp;

    temp = broj;

    do{
        broj = broj/2;
        br_znam++;
        i++;
    } while(broj > 0);

    broj = temp;

    for(i = 0; i<br_znam; i++){
        binarni[(br_znam-1)-i] = broj%2;
        broj = broj/2;
    }

    for(i = 0, j=br_znam-1; i<br_znam; i++, j--){
        rezultat += binarni[i]*round(pow(10,j));
    }

    return rezultat;
}
