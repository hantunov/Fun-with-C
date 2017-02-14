#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int jeHambi(int opseg, int promjerRupe);
int jeTrokut(int opseg, int promjerRupe);
int jeSlapica(int opseg, int promjerRupe);

int main()
{

    int i, brPeciva, promjerRupe, opseg, tezina, prolazi, H_br = 0, T_br = 0, S_br = 0, poklon = 0;
    char vrstaPeciva;

    do{
        scanf("%d", &brPeciva);

        if(brPeciva <=1 || brPeciva>= 100)
            printf("Nepravilan unos!\n");

    } while(brPeciva<=1 || brPeciva>=100);

    do{
        scanf("%d", &promjerRupe);

        if(promjerRupe<5 || promjerRupe>50)
            printf("Nepravilan unos!\n");

    } while(promjerRupe<5 || promjerRupe>50);

    for(i = 0; i<brPeciva; i++){
        scanf(" %c %d%d", &vrstaPeciva, &opseg, &tezina);

        switch(vrstaPeciva){
            case 'H':
                prolazi = jeHambi(opseg, promjerRupe);
                    if(prolazi == 1)
                        H_br++;
                    else if (prolazi == 0)
                        poklon += tezina;
                break;
            case 'T':
                prolazi = jeTrokut(opseg, promjerRupe);
                    if(prolazi == 1)
                        T_br++;
                    else if (prolazi == 0)
                        poklon += tezina;
                break;
            case 'S':
                prolazi = jeSlapica(opseg, promjerRupe);
                    if(prolazi == 1)
                        S_br++;
                    else if (prolazi == 0)
                        poklon += tezina;
                break;
            default:
                break;
        }
    }

    printf("Poklonit ce %.2f kg peciva.\n", poklon/1000.00);
    printf("U automatu ce biti %d hambi peciva, %d slapica i %d sir-trokuta.", H_br, S_br, T_br);

    return 0;
}

int jeHambi(int opseg, int promjerRupe){

    float promjerPeciva;

    promjerPeciva = opseg/M_PI;

    if(promjerPeciva <= (float)promjerRupe)
        return 1;
    else
        return 0;
}

int jeTrokut(int opseg, int promjerRupe){

    float promjerPeciva;

    promjerPeciva = opseg/3.0;

    if(promjerPeciva <= (float)promjerRupe)
        return 1;
    else
        return 0;
}

int jeSlapica(int opseg, int promjerRupe){

    float promjerPeciva;

    promjerPeciva = opseg/6.0;

    if(promjerPeciva <= (float)promjerRupe)
        return 1;
    else
        return 0;
}
