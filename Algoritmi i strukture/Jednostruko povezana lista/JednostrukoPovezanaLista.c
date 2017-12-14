# include <stdio.h>
# include <stdlib.h>

struct cvor *dodajNoviCvor(int vrijednost);

struct cvor{
    int vrijednost;
    struct cvor *slijedeci;
};

int main(){

    int unos, najmanji, najveci;
    unos = najmanji = najveci = 0;
    struct cvor *glava, *temp, *zadnji;
    glava = temp = zadnji = NULL;

    do{
        printf("Unesite broj: ");
        scanf("%d", &unos);

        if(unos == 0) break;
        if(glava == NULL){
            glava = dodajNoviCvor(unos);
            glava->slijedeci = NULL;
        } else if(glava->slijedeci == NULL) {
            temp = dodajNoviCvor(unos);
            glava->slijedeci = temp;
            zadnji = temp;
            zadnji->slijedeci = NULL;
        } else {
            temp = dodajNoviCvor(unos);
            zadnji->slijedeci = temp;
            zadnji = temp;
            zadnji->slijedeci = NULL;
        }
    }while(1);

    printf("\nIspis:\n");
    temp = glava;

    do{
        printf("%d\n", temp->vrijednost);
        if(temp->vrijednost > najveci) najveci = temp->vrijednost;
        if(temp->vrijednost < najmanji || najmanji == 0) najmanji = temp->vrijednost;
        temp = temp->slijedeci;
    }while(temp != NULL);

    printf("Najmanji broj: %d\n", najmanji);
    printf("Najveci broj: %d\n", najveci);

    return 0;
}

struct cvor *dodajNoviCvor(int vrijednost){

    struct cvor *noviCvor = (struct cvor*)malloc(sizeof(struct cvor));

    noviCvor->vrijednost = vrijednost;

    return noviCvor;
};
