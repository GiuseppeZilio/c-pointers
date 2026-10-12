#include <stdio.h>

int calcular_estatisticas(
 const int *valores,
 size_t quantidade,
 int *menor,
 int *maior,
 int *soma
);

int main(void) {

    int dados[ ] = {18, -4, 27, 9, 31, 2};
    int menor;
    int maior;
    int soma;
    size_t quant = sizeof(dados) / sizeof(dados[0]);

    if (calcular_estatisticas(dados, quant, &menor, &maior, &soma) == 0) {
        printf("Erro ao calcular estatisticas.\n");
        return 1;
    }

    printf("\nDados: [");
    for (size_t i = 0; i < quant; i++) {
        printf("%d", *(dados + i));

        if (i < quant - 1) {
            printf(" , ");
        }
    }
    printf("]\n");

    printf("\nTamanho do array: %zu;\n"
            "Menor valor: %d;\n"
            "Maior valor: %d;\n"
            "Soma total: %d.\n",
            quant, menor, maior, soma
    );

    return 0;
}

int calcular_estatisticas( const int *valores, size_t quantidade, int *menor, int *maior, int *soma ) {
    
    if (quantidade == 0 || valores == NULL || menor == NULL ||
        maior == NULL || soma == NULL ) {
        return 0;
    }

    *menor = *valores;
    *maior = *valores;
    *soma = 0;
    
    for (size_t i=0 ; i<quantidade ; i++) {
        int atual = *(valores + i);
        if (atual > *maior) {
            *maior = atual;
        }
        if (atual < *menor) {
            *menor = atual;
        }
        *soma += atual; 
    }
    return 1;
}
