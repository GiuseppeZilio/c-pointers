#include <stdio.h>

#define TITLELINE printf("\n=============================================\n")

typedef struct {
    int id; 
    float temperatura; 
    char status; 
} Sensor;

void mostra_sensor(const Sensor *dados_atualizados, size_t quantidade);
Sensor *buscar_sensor(Sensor *sensores, size_t quantidade, int id_procurado);

int main(void) {

    Sensor sensores[ ] = {
        {101, 22.5, 'N'}, 
        {102, 35.8, 'A'}, 
        {103, 18.2, 'N'}, 
        {104, 12.7, 'B'} 
    };
    size_t quant = sizeof(sensores) / sizeof(sensores[0]);
    int id_procurado;

    printf("Qual sensor devemos mudar? ");
    scanf(" %d", &id_procurado);
    Sensor *address = buscar_sensor(sensores, quant, id_procurado);

    if (address == NULL) {
        TITLELINE;
        printf("O sensor nao consta no banco de dados.");
        TITLELINE;
        return 1;
    }

    address -> temperatura = 0.0f;
    address -> status = 'B';

    TITLELINE;
    printf("Sensores: ");
    TITLELINE;
    mostra_sensor(sensores, quant);
    TITLELINE;
    printf("Sensor modificado: ");
    TITLELINE;
    mostra_sensor(address, 1);
    TITLELINE;

    return 0;
}

Sensor *buscar_sensor( Sensor *sensores, size_t quantidade, int id_procurado) {
    for (size_t i=0 ; i<quantidade ; i++) {
        if ( (sensores + i) -> id == id_procurado ) {
            return sensores + i;
        }
    }
    return NULL;
}

void mostra_sensor(const Sensor *dados_atualizados, size_t quantidade) {
    if (dados_atualizados == NULL) {
        return;
    }
    for (size_t i=0; i<quantidade; i++) {
        printf("ID: %d, ", (dados_atualizados + i) -> id);
        printf("Temperatura: %.1f, ", (dados_atualizados + i) -> temperatura);
        printf("Status: %c\n", (dados_atualizados + i) -> status);
    }
}
