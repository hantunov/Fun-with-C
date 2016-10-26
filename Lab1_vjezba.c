/*"HexInt"

Potrebno je učitati 3 znamenke u HEX formatu, i ispisati koji je to broj u dekadskom formatu.

Napomena: zadatak riješiti "pješke", ne unosom broja pomoću %x specifikatora.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    char x, y, z;
    int xd, yd, zd, rezultat;

    scanf("%c %c %c", &x, &y, &z);

    if(x >= 65 && x <= 70){
        xd = x - 55;
    }
    else if (x >=97 && x <=102) {
        xd = x - 87;
    }
    else{
        xd = x - 48;
    }



    if(y >= 65 && y <= 70){
        yd = y - 55;
    }
    else if (y >=97 && y <=102) {
        yd = y - 87;
    }
    else{
        yd = y - 48;
    }


    if(z >= 65 && z <= 70){
        zd = z - 55;
    }
    else if (z >=97 && z <=102) {
        zd = z - 87;
    }
    else{
        zd = z - 48;
    }

    rezultat = (xd*16*16)+(yd*16)+zd;


    printf("%d", rezultat);
    return 0;
}
