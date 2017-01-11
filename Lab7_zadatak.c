/*
Igra Spoji 4. Vidljivo je stanje igrace ploce, treba odrediti pobjednika. Unos su dva broja koja oznacavaju dimenzije 2D polja, a zatim i stanje 2D polja.
Moguce situacije - "Pobjednik: x", "Pobjednik: o", "Nema pobjednika", "Nemoguca situacija"(ako su oba pobjednici).

Primjeri:

5 8
......x.
......x.
......o.	----> Ocekivani izlaz:  Nema pobjednika
...x..x.
xooxoox.


6 8
........
........
....x...	----> Ocekivani izlaz:  Pobjednik: x
x..xx.oo
x..xxxxx
xxoooxxx


8 10
..........
..........
....x.....
....xx....	----> Ocekivani izlaz:  Nemoguca situacija
....xo....
..x.xo...x
.xxxxo..xx
xxxxxo.xxx


4 1
o
o			----> Ocekivani izlaz:  Pobjednik: o
o
o

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int pobjednik(char ploca[][MAX], int redovi, int stupci);

int main()
{
    int i, j, redovi, stupci, rezultat;
    char ploca[MAX][MAX]={{}};

    scanf("%d%d", &redovi, &stupci);

    for(i = 0; i<redovi; i++){
        for(j = 0; j<stupci; j++){
            scanf(" %c", &ploca[i][j]);
        }
    }

    rezultat = pobjednik(ploca, redovi, stupci);

    if(rezultat == 0)printf("Nema pobjednika");
    if(rezultat == 1)printf("Pobjednik: x");
    if(rezultat == 2)printf("Pobjednik: o");
    if(rezultat == 3)printf("Nemoguca situacija");

    return 0;
}

int pobjednik(char ploca[][MAX], int redovi, int stupci){

    int i, j, igracX = 0, igracO = 0;

    for(i = 0; i<redovi; i++){
        for(j = 0; j<stupci; j++){
            if(ploca[i][j] == 'x' && ploca[i][j+1] == 'x' && ploca[i][j+2] == 'x' && ploca[i][j+3] == 'x'){
                igracX = 1;
            }
            if(ploca[i][j] == 'o' && ploca[i][j+1] == 'o' && ploca[i][j+2] == 'o' && ploca[i][j+3] == 'o'){
                igracO = 1;
            }
        }
    }
    for(i = 0; i<stupci; i++){
        for(j = 0; j<redovi; j++){
            if(ploca[j][i] == 'x' && ploca[j+1][i] == 'x' && ploca[j+2][i] == 'x' && ploca[j+3][i] == 'x'){
                igracX = 1;
            }
            if(ploca[j][i] == 'o' && ploca[j+1][i] == 'o' && ploca[j+2][i] == 'o' && ploca[j+3][i] == 'o'){
                igracO = 1;
            }
        }
    }

    if(igracX==0 && igracO==0)return 0;
    if(igracX>igracO)return 1;
    if(igracX<igracO)return 2;
    if(igracX==1 && igracO==1)return 3;
}