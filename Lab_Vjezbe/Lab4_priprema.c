#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{

    int i, j;
    int br_vi_o = 0, br_vi_z = 0, br_ug_o = 0, br_ug_z = 0, br_ok_o = 0, br_ok_z = 0;
    char niz[MAX] = {}, unos, tr, sl;

    for(i=0; i<MAX-1; i++){

        scanf(" %c", &unos);
        if(unos == '.'){
            break;
        } else{
        niz[i] = unos;
        }
    }

    for(i=0; i<MAX-1; i++){

        tr = niz[i];
        sl = niz[i+1];


        if((tr >= 'A' && tr <= 'Z') || (tr >= 'a' && tr <= 'z')){
            printf("NEISPRAVNO");
            return 0;
        }

        if((tr >= '0' && tr <= '9') && (sl == '{' || sl == '[' || sl =='(')){
            printf("NEISPRAVNO");
            return 0;
        }

        if((tr == '{' && sl == '}') || (tr == '[' && sl == ']') || (tr == '(' && sl == ')')){
            printf("NEISPRAVNO");
            return 0;
        }

        if(tr == '{'){
            br_vi_o++;
            if(br_vi_z != 0){
                continue;
            }
            for(j = i; j<MAX; j++){
                if(niz[j]=='}'){
                    br_vi_z++;
                }
            }
        }
        if(tr == '['){
            br_ug_o++;
            if(br_ug_z != 0){
                continue;
            }
            for(j = i; j<MAX; j++){
                if(niz[j]==']'){
                    br_ug_z++;
                }
            }
        }
        if(tr == '('){
            br_ok_o++;
            if(br_ok_z != 0){
                continue;
            }
            for(j = i; j<MAX; j++){
                if(niz[j]==')'){
                    br_ok_z++;
                }
            }
        }
        if(tr == sl){
            if ((tr >= '0' && tr <= '9') || tr == '+' || tr == '-' || tr == '*' || tr == '/') {
                printf("NEISPRAVNO");
                return 0;
            } else {
                continue;
            }
        }
    }

    if((br_vi_o == br_vi_z) && (br_ug_o == br_ug_z) && (br_ok_o == br_ok_z))
        printf("ISPRAVNO");
    else
        printf("NEISPRAVNO");

    return 0;
}
