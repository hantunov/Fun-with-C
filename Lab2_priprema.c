/*"Binarni brojevi s predznakom"

Napišite program koji učitava 5 znakova (5 podataka tipa char) koje interpretiramo kao binarni prikaz
cijelog broja s predznakom (signed int). Ako ulazni niz sadrži samo binarne znamenke (0 ili 1),
program treba ispisati dekadski zapis tog broja, prema pravilu da prvi učitani znak označava predznak broja (0 je +, a 1 je −).

Ostatak niza interpretiramo ovisno o predznaku:

 nenegativni (uključena je i 0) brojevi imaju uobičajeni prikaz
 negativni brojevi se prikazuju dvojnim komplementom
 

Ako ulazni niz sadrži barem jedan znak koji nije binarna znamenka, treba ispisati poruku „Pogresan unos!“
i prekinuti izvođenje programa. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a,b,c,d,e;
    int a_bin, b_bin, c_bin, d_bin, e_bin;
    int rezultat;

    scanf("%c %c %c %c %c", &a,&b,&c,&d,&e);

    if(a == '0'){
        if(b == '1'){
            b_bin=8;
        }
        else if(b == '0'){
            b_bin=0;
        }
        else{
            printf("Pogresan unos!");
            return 0;
        }
        if(c == '1'){
            c_bin=4;
        }
        else if(c == '0'){
            c_bin=0;
        }
        else{
            printf("Pogresan unos!");
            return 0;
        }
        if(d == '1'){
            d_bin=2;
        }
        else if(d == '0'){
            d_bin=0;
        }
        else{
            printf("Pogresan unos!");
            return 0;
        }
        if(e == '1'){
            e_bin=1;
        }
        else if(e == '0'){
            e_bin=0;
        }
        else{
            printf("Pogresan unos!");
            return 0;
        }

        rezultat = b_bin+c_bin+d_bin+e_bin;
        printf("%d", rezultat);
    }
    else if (a == '1'){
        if(b == '0'){
            b_bin=8;
        }
        else if(b == '1'){
            b_bin=0;
        }
        else{
            printf("Pogresan unos!");
            return 0;
        }
        if(c == '0'){
            c_bin=4;
        }
        else if(c == '1'){
            c_bin=0;
        }
        else{
            printf("Pogresan unos!");
            return 0;
        }
        if(d == '0'){
            d_bin=2;
        }
        else if(d == '1'){
            d_bin=0;
        }
        else{
            printf("Pogresan unos!");
            return 0;
        }
        if(e == '0'){
            e_bin=1;
        }
        else if(e == '1'){
            e_bin=0;
        }
        else{
            printf("Pogresan unos!");
            return 0;
        }

        rezultat = (b_bin+c_bin+d_bin+e_bin+1)*(-1);
        printf("%d", rezultat);
    }
    else{
        printf("Pogresan unos!");
        }

    return 0;
}
