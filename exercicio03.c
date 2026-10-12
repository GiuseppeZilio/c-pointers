#include <stdio.h>
#define TITLE_LINE "\n==============================\n"

int dividir( int dividendo, int divisor, int *quociente, int *resto );

int main(void) {

    int verify = 1;
    int numerador;
    int denominador;
    int q;
    int r;

    do {
        printf("Digite o numerador: ");
        scanf("%d", &numerador);
        printf("Digite o denominador: ");
        scanf("%d", &denominador);

        verify = dividir(numerador, denominador, &q, &r);

        if (verify == 1) {
            printf(TITLE_LINE "\n %d / %d = %d \n O resto da divisao eh %d \n" TITLE_LINE, numerador, denominador, q, r);
        }
    } while (verify != 0);

    printf("\n! FIM DO PROGRAMA !\n");
    return 0;
}

int dividir( int dividendo, int divisor, int *quociente, int *resto ) {
    
    if (divisor == 0 || quociente == NULL || resto == NULL) {
        return 0;
    }
    else {
        *quociente = dividendo / divisor;
        *resto = dividendo % divisor;
        return 1;
    }
}
