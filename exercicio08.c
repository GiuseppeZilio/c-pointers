#include <stdio.h>

#define COLUNAS 4 

void somar_linhas( const int (*matriz)[COLUNAS], size_t quantidade_linhas, int *resultados );
void mostra_resultado( const int *resultados, size_t quantidade_linhas);

int main(void) {

    const int matriz[][COLUNAS] = { 
        { 1,  2,  3,  4}, 
        { 5,  6,  7,  8}, 
        { 9, 10, 11, 12} 
    };
    size_t quant_linhas = sizeof(matriz) / sizeof(matriz[0]);
    int resultados[quant_linhas];

    somar_linhas(matriz, quant_linhas, resultados);
    mostra_resultado(resultados, quant_linhas);

    return 0;
}

void somar_linhas( const int (*matriz)[COLUNAS], size_t quantidade_linhas, int *resultados ) {

    for (size_t i=0 ; i<quantidade_linhas ; i++) {
        int soma = 0;
        
        for (size_t j=0 ; j<COLUNAS ; j++) {
            soma += *( *(matriz + i) + j); // Acessa conteúdo da linha i e coluna j.
        }
        *(resultados + i) = soma;
    }
}

void mostra_resultado( const int *resultados, size_t quantidade_linhas) {
    for (size_t i=0 ; i<quantidade_linhas ; i++) {
        printf("Soma da linha %zu: %d\n", i, *(resultados + i));
    }
}
