#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float h1, d1, r1;
    float h2, d2, r2;
    float V1, V2;
    float pi = 3.14;

    scanf("%f %f", &h1, &d1);
    scanf("%f %f", &h2, &d2);

    r1 = d1/2.0;
    r2 = d2/2.0;

    V1 = ((pow(r1,2)*pi)*h1)/100;
    V2 = ((pow(r2,2)*pi)*h2)/100;

    if(V1 == 0){
        printf("U drugu casu stane manje soka. (V=%.2f dl)", V2);
    }
    else if(V2 == 0){
        printf("U prvu casu stane manje soka. (V=%.2f dl)", V1);
    }
    else if(V2>V1){
        printf("U prvu casu stane manje soka. (V=%.2f dl)", V1);
    }
    else if(V2==V1){
        printf("U obje case stane jednako soka. (V=%.2f dl)", V2);
    }
    else if(V2<V1){
        printf("U drugu casu stane manje soka. (V=%.2f dl)", V2);
    }
    else{
        return 0;
    }

    return 0;
}
