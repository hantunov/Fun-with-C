#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stm{
    char word[15+1];
    char pozneg[3+1];
}sentiment[50];

int main()
{
    int i = 0, br_poz = 0, br_neg = 0, br_krijeci = 0;
    char recenica[200+1] = "";
    char delimit[] = " .,!";
    char *rijec;
    FILE *fin, *fout;

    fin = fopen("Sentiment.txt", "r");
    fout = fopen("RezultatAnalize.txt", "w");

    if(fin == NULL || fout == NULL){
        printf("Greska pri otvaranju datoteka!");
        exit(1);
    }

    while(fscanf(fin, " %[^:]: %[^\n]", sentiment[i].word, sentiment[i].pozneg)==2){
        i++;
        br_krijeci++;
    }

    scanf(" %[^\n]", recenica);
    fprintf(fout, "%s\n", recenica);
    strlwr(recenica);

    rijec = strtok(recenica, delimit);

    while(rijec!=NULL){
        for(i=0; i<br_krijeci; i++){
            if(strcmp(rijec, sentiment[i].word)==0){
                if(strcmp(sentiment[i].pozneg, "POZ")==0) br_poz++;
                else br_neg++;
                fprintf(fout, "%s\n", rijec);
            }
        }
        rijec = strtok(NULL, delimit);
    }

    if(br_poz>br_neg) fprintf(fout, "Analiza: pozitivna");
    else if(br_poz<br_neg) fprintf(fout, "Analiza: negativna");
    else fprintf(fout, "Analiza: neutralna");

    fclose(fin);
    fclose(fout);

    return 0;
}
