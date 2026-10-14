#include <stdio.h>

void inverter_array(int *valores, size_t quantidade);
void mostra_array(const int *array, size_t quantidade);

int main(void) {

    int dados [ ] = { 10, 20, 30, 40, 50};
    size_t quant = sizeof(dados) / sizeof(dados[0]);

    printf("Antes: ");
    mostra_array(dados, quant);

    inverter_array(dados, quant);
    
    printf("Depois: ");
    mostra_array(dados, quant);

    return 0;
}

void inverter_array(int *valores, size_t quantidade) {

    if (valores == NULL || quantidade < 2) {
        return; // Retorna para ponteiros nulos ou quantidade insuficiente para troca de posições;
    }

    int *left = valores; // Inicio do array;
    int *right = valores + quantidade - 1; // Final do array;

    while (left < right) {

        int temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

void mostra_array(const int *array, size_t quantidade) {

    printf("[");
    for (size_t i=0 ; i<quantidade ; i++) {
        if (i < (quantidade - 1)) {
            printf(" %d,", *(array + i));
        }
        else {
            printf(" %d ", *(array + i));
        }
    }
    printf("]\n");
}
