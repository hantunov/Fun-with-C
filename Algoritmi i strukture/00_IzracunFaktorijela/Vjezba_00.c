/*
Napisati potpuno funkcionalni program u programskom jeziku C koji računa faktorijel broja n (n!).

Npr.
n=1 → 1! = 1
n=2 → 2! = 1 * 2 = 2
n=3 → 3! = 1 * 2 * 3 = 6
Itd.

Korisnik mora unijeti cijeli broj n, te se potom fatorijel računa u petlji. Ispisuje se iznos faktorijela u svakom koraku
petlje. Ako je broj koraka petlje već od 10 petlja se prekida i ispisuje se odgovarajuća poruka.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, result = 1;

    do{
        printf("Unesite broj:\n");
        scanf("%d", &n);
    }while(n<1);

    for(i=1; i<=n; i++){
        if(i>10){
            printf("Broj je prevelik, prekidam!\n");
            break;
        }
        printf("%d! = ", i);
        result *= i;
        printf("%d\n", result);
    }
}
