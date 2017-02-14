#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    int n = 0, i, j, segment = 0, br = 0;
    char unos;
    char put[MAX] = {};


    scanf(" %d", &n);

    for(i=0; i<n; i++){
        scanf(" %c", &unos);
        if(unos == '.'|| unos == 'v'|| unos == 'x'){
            put[i] = unos;
        } else {
            continue;
        }
    }

    scanf(" %d", &n);

    for(i=0; i<n; i++){
        scanf(" %d", &segment);
        for(j=0; j<segment; j++){
            if(put[j]=='.'){
                br += 1;
            } else if(put[j]=='v'){
                br += 2;
            } else if(put[j]=='x'){
                br += 4;
            }
        }

        printf("%d. segment: Nakon %d dana\n", segment, br);
        br = 0;
    }

    return 0;
}
