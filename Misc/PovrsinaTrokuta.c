//Napisi funkciju trokut koja na temelju duljine stranica a, b i c u pozivajuci program vraca izracunatu
//povrsinu i opseg trokuta.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void trokut(float a, float b, float c, float *povrsina, float *opseg);

int main()
{
    float a, b, c, povrsina, opseg;
    float *pPovrsina = &povrsina, *pOpseg = &opseg;

    scanf("%f%f%f", &a, &b, &c);

    trokut(a, b, c, pPovrsina, pOpseg);

    printf("Opseg trokuta je: %.2f\n", opseg);
    printf("Povrsina trokuta je: %.2f", povrsina);

    return 0;
}

void trokut(float a, float b, float c, float *povrsina, float *opseg){

    *opseg = a+b+c;
    float s = *opseg/2;

    *povrsina = sqrt(s*(s-a)*(s-b)*(s-c));
}
