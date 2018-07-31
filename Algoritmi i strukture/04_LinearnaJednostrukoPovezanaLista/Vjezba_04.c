#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct cvor{
    int vrijednost;
    struct cvor *slijedeci;
} Cvor;

Cvor *noviCvor(int Vrijednost);
void rekurzivniIspis(Cvor *cvor, int *min, int *max);

int main()
{
    int unos, min, max;
    unos=max=0;
    min=INT_MAX;
    Cvor *head, *tail, *temp;
    head=tail=temp=NULL;

    do{
        printf("Unesite broj: ");
        scanf("%d", &unos);

        if(unos != 0){
            if(head == NULL){
                head = noviCvor(unos);
            } else if (head->slijedeci == NULL) {
                tail = noviCvor(unos);
                head->slijedeci = tail;
            } else {
                temp = noviCvor(unos);
                tail->slijedeci = temp;
                tail = temp;
            }
        }

    }while(unos);

    printf("\nIspis: \n");
    rekurzivniIspis(head, &min, &max);
    printf("Najmanji broj: %d\nNajveci broj: %d\n", min, max);

    return 0;
}

Cvor *noviCvor(int vrijednost){

     Cvor *novi = (Cvor*)malloc(sizeof(Cvor));
     novi->vrijednost = vrijednost;
     novi->slijedeci = NULL;

     return novi;
}

void rekurzivniIspis(Cvor *cvor, int *min, int *max){

    if(cvor == NULL) return;

    rekurzivniIspis(cvor->slijedeci, min, max);

    if(*max < cvor->vrijednost) *max = cvor->vrijednost;
    if(*min > cvor->vrijednost) *min = cvor->vrijednost;
    printf("%d\n", cvor->vrijednost);
}
