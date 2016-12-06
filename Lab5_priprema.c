#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, br_vremena = 0, br_kukuruza = 0, br_reda = 0, pravi_red = 0, tablica[3][3], temp[3][3], max_kuk = 0;
    char unos, kukuruziste[3][20];

    for(i=0; i<3; i++){
        for(j=0; j<20;j++){
            scanf(" %c", &unos);
            if(unos=='.' || unos==',' || unos=='I'){
                kukuruziste[i][j] = unos;
            } else {
                continue;
            }
        }
    }

    for(i=0; i<3; i++){
        for(j=0; j<20;j++){
            if(kukuruziste[i][j]=='.'){
                br_vremena += 1;
            } else if(kukuruziste[i][j]==','){
                br_vremena += 2;
            } else if(kukuruziste[i][j]=='I'){
                br_vremena += 5;
                br_kukuruza += 1;
            }
        }
        br_reda++;
        tablica[i][0]=br_reda;
        tablica[i][1]=br_vremena;
        tablica[i][2]=br_kukuruza;
        br_vremena = 0;
        br_kukuruza = 0;
    }

    for(i = 2; i>=0; i--){
        if(tablica[i][2]>=max_kuk){
            max_kuk=tablica[i][2];
        }
    }

    for(i=0; i<3; i++){
        for(j=i+1; j<3; j++){
            if(tablica[i][1]>tablica[j][1]){
                temp[i][0] = tablica[j][0];
                temp[i][1] = tablica[j][1];
                temp[i][2] = tablica[j][2];
                tablica[j][0] = tablica[i][0];
                tablica[j][1] = tablica[i][1];
                tablica[j][2] = tablica[i][2];
                tablica[i][0] = temp[i][0];
                tablica[i][1] = temp[i][1];
                tablica[i][2] = temp[i][2];
            }
        }
    }

    for(i = 0; i<3; i++){
        if(tablica[i][2]>=max_kuk-3){
            printf("Pozicioniraj se u %d. red!", tablica[i][0]);
            break;
        } else if(tablica[i][2]>=max_kuk-2){
            printf("Pozicioniraj se u %d. red!", tablica[i][0]);
            break;
        } else if(tablica[i][2]>=max_kuk-1){
            printf("Pozicioniraj se u %d. red!", tablica[i][0]);
            break;
        } else if(tablica[i][2]>=max_kuk){
            printf("Pozicioniraj se u %d. red!", tablica[i][0]);
            break;
        } else if(tablica[i][2]>=max_kuk+1){
            printf("Pozicioniraj se u %d. red!", tablica[i][0]);
            break;
        } else if(tablica[i][2]>=max_kuk+2){
            printf("Pozicioniraj se u %d. red!", tablica[i][0]);
            break;
        } else if(tablica[i][2]>=max_kuk+3){
            printf("Pozicioniraj se u %d. red!", tablica[i][0]);
            break;
        }
    }

    return 0;
}