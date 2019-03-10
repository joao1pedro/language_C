#include <stdio.h>
#include "calc.h"

int main(){
    int y = 5;
    int quad = quadrado(y);
    int cub = cubo(y);
    
    printf("\nQuadrado de %d é igual a %d\n", y, quad);
    printf("\nCubo de %d é igual a %d\n", y, cub);
    printf("\nValor de Pi é igual a %f", _PI);
    return 0;
}