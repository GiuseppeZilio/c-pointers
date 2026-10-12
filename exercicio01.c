#include <stdio.h>
#define LINE "=================================\n"

int main(void) {

    int x = 10;
    int y = 20;
    int *p;

    p = &x;

    printf(LINE);
    printf("Valor de x: %d \n", x);
    printf("Valor acessado por *p: %d \n", *p);
    printf("Endereco de x: %p \n", (void *)&x);
    printf("conteudo de p: %p \n", ( void *)p);

    *p = 15;

    p = &y;
    *p = 25;

    printf(LINE);
    printf("Valor de x: %d \n", x);
    printf("Valor de y: %d \n", y);
    printf(LINE);
    printf("sizeof(int) = %zu bytes\n", sizeof(int));
    printf("sizeof(int *) = %zu bytes\n", sizeof(int *));
}
