/*Korisnik unosi prvo dužinu polja, a onda elemente polja. Polje sadržava cijele brojeve (int). Na kraju korisnik
unosi broj koji se traži. Nakon toga funkcija korištenjem jednostavne linearne rekruzije pretražuje polje, od prvog
elementa polja (na poziciji nula) do kraja (do pozicije n-1, gdje je n dužina polja). Ako se element pronađe funkcija
ispisuje mjesto na kojemu se nalazi traženi cijeli broj i prestaje sa rekruzijom. Ako funkcija ne pronađe traženi cijeli
broj, onda prestaje s rekruzijom kad dođe do kraja polja. Nakon toga program prestaje s radom.
Vježba se mora realizirati u programskom jeziku C.*/

#include <stdio.h>
#include <stdlib.h>

void rekurzivnoPunjenjePolja(int *polje, int duzinaPolja, int indeks);
void rekurzivnoPretrazivanjePolja(int *polje, int duzinaPolja, int trazenaVrijednost, int indeks);

int main()
{

    int duzinaPolja, trazenaVrijednost;

    printf("Unesite duzinu polja: ");
    scanf("%d", &duzinaPolja);

    int *polje = (int*)malloc(duzinaPolja*sizeof(int));

    rekurzivnoPunjenjePolja(polje, duzinaPolja, 0);

    printf("Unesite vrijednost koju trazite: ");
    scanf("%d", &trazenaVrijednost);

    rekurzivnoPretrazivanjePolja(polje, duzinaPolja, trazenaVrijednost, 0);

    return 0;
}

void rekurzivnoPunjenjePolja(int *polje, int duzinaPolja, int indeks){

    //Testiramo da li je indeks veci od duzine polja i u tom slucaju prekidamo rekurziju jer je polje popunjeno
    if(indeks > duzinaPolja-1){
        return;
    }

    //Ucitavamo vrijednosti s tipkovnice u polje na trenutnom indeksu
    printf("Unesite %d. element (pozicija %d): ", indeks+1, indeks);
    scanf("%d", polje+indeks);
    //Povecavamo indeks za 1;
    indeks++;

    //Ponovno pozivamo funkciju i predajemo nove vrijednosti (samo je indeks drugaciji, uvecan za 1)
    rekurzivnoPunjenjePolja(polje, duzinaPolja, indeks);

};

void rekurzivnoPretrazivanjePolja(int *polje, int duzinaPolja, int trazenaVrijednost, int indeks){

    if(indeks > duzinaPolja-1){
        printf("Vrijednost nije pronadjena!\n");
        return;
    } else if (*(polje+indeks) == trazenaVrijednost){
        printf("Vrijednost je pronadjena na poziciji %d\n", indeks);
        return;
    }

    indeks++;
    rekurzivnoPretrazivanjePolja(polje, duzinaPolja, trazenaVrijednost, indeks);

}
