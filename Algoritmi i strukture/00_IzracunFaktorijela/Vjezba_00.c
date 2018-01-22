#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, i, faktorijel = 1;

    scanf("%d", &n);

    for(i = 1; i<=n; i++){

        faktorijel *= i;
        printf("%d! = %d\n", i, faktorijel);

        if(i>=10){
            printf("Nemoguce racunati faktorijele vece od 10!\n");
            break;
        }
    }

    return 0;
}
