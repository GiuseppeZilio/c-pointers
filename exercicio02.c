#include <stdio.h>
#include <stdbool.h>
#define TITLE_LINE "==============="

void trocar(int *a, int *b, bool *verify);

int main(void) {

    int x = 25;
    int y = 50;
    int contagem = 0;
    bool verify = true;

    do {
        contagem++;
        printf("\n" TITLE_LINE " CONTAGEM %d " TITLE_LINE "\n", contagem);
        trocar(&x, &y, &verify);
        if (contagem == 3) {
            trocar(&x, NULL, &verify);
        }
        printf("\n Valor de X: %d \n Valor de Y: %d \n", x, y);
        x += 5;
        y += 5;
    } while (verify == true);

    printf("\n Foi digitado um valor nulo como entrada. \n");
    
    return 0;
}

void trocar(int *a, int *b, bool *verify) {

    if (a == NULL || b == NULL) {
        *verify = false;
        return;
    }

    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
