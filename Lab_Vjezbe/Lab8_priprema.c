#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 160+1

char *trazi(char *sms);

int main()
{
    char sms[MAX], kontrolni[1+1];
    int i, brPoruka;
    char *ime;

    scanf(" %[^\n]", kontrolni);
    brPoruka = atoi(kontrolni);

    for(i=0; i<brPoruka; i++){
        scanf(" %160[^#\n]", sms);
        ime = trazi(sms);
        if(ime != NULL){
            printf("%s\n", ime);
        }
    }

    return 0;
}

char *trazi(char *sms)
{
    char copy[MAX];
    int dob;

    strcpy(copy, sms);
    strlwr(copy);

    char *ime=NULL, *godine=NULL;
    char delimit[] = "()";

    ime = strtok(copy, delimit);
    godine = strtok(NULL, delimit);
    dob = atoi(godine);

    char *crn=NULL, *bogat=NULL, *visok=NULL;

    crn = strstr(copy, "crn");
    bogat = strstr(copy, "bogat");
    visok = strstr(copy, "visok");

    if((crn != NULL || bogat != NULL || visok != NULL) || (dob <= 45)){
        return ime;
    } else {
        return NULL;
    }
}
