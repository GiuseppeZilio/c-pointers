#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define TITLELINE printf("\n============================================\n")
#define TAMANHO_NOME 16
#define MAX_AMOSTRAS 5

typedef struct { 
    int id; 
    char nome[TAMANHO_NOME]; // Cria um vetor de char's -> String de 16 letras - 1 caractere '\0' que marca o fim da string.
    float amostras[MAX_AMOSTRAS]; 
    size_t quantidade_amostras; 
} Sensor;

Sensor *buscar_sensor( Sensor *sensores, size_t quantidade, int id );
int adicionar_amostra( Sensor *sensor, float nova_amostra ); 
void apresentar_sensor( const Sensor *sensor , float media );
void pergunta_ini(bool *continua);
float pergunta_nova(void);
float calcular_media( const Sensor *sensor ); 

int main(void) {
    Sensor sensores[ 3 ] = {
        {101, "Temp_01", {10.0, 20.0}, 2},
        {102, "Temp_02", {20.0, 30.0, 40.0, 30.0}, 4},
        {103, "Temp_03", {30.0}, 1}
    };

    size_t quantidade_sensores = sizeof(sensores) / sizeof(sensores[0]);
    bool continua = true;

    while (continua) {

        int id;
        printf("ID do sensor: ");
        scanf(" %d", &id);

        Sensor *address = buscar_sensor( sensores, quantidade_sensores, id );
        if (address == NULL) {
            TITLELINE;
            printf("\nO sensor nao consta no banco de dados.\n");
            TITLELINE;
        }
        else if (address -> quantidade_amostras >= MAX_AMOSTRAS) {
            TITLELINE;
            printf("\nSensor %d esta com o armazenamento lotado.\n", address->id);
            TITLELINE;
        }
        else {
            float nova_amostra = pergunta_nova();
            adicionar_amostra( address, nova_amostra );
            apresentar_sensor( address , calcular_media( address ) );
        }
        pergunta_ini(&continua);
    }
    return 0;
}

Sensor *buscar_sensor( Sensor *sensores, size_t quantidade, int id_procurado ) {
    for (size_t i=0 ; i<quantidade ; i++) {
        if ( (sensores + i) -> id == id_procurado) {
            return sensores + i;
        }
    }
    return NULL;
}

int adicionar_amostra( Sensor *sensor, float nova_amostra ) {

    if (sensor == NULL || sensor -> quantidade_amostras >= MAX_AMOSTRAS) {
        return 0;
    }
    *(sensor -> amostras + (sensor -> quantidade_amostras)) = nova_amostra;
    (sensor -> quantidade_amostras) ++;
    return 1;
}

float calcular_media( const Sensor *sensor ) {
    float soma = 0;
    for (size_t i=0 ; i< (sensor -> quantidade_amostras) ; i++) {
        soma += *((sensor -> amostras) + i);
    }
    return soma / (sensor -> quantidade_amostras); 
}

void apresentar_sensor( const Sensor *sensor ,  const float media ) {
    
    TITLELINE;
    printf("\nIdentificador: %d \n", sensor -> id);
    printf("Nome: %s \n", sensor -> nome);
    printf("Amostras: [");
    for (size_t i=0 ; i<sensor -> quantidade_amostras ; i++) {
        if (i < sensor -> quantidade_amostras - 1) {
            printf(" %.2f,", *((sensor -> amostras) + i));
        }
        else {
            printf(" %.2f", *((sensor -> amostras) + i));
        }
    }
    printf(" ] \n");
    printf("Media: %.2f\n", media);
    TITLELINE;

}

float pergunta_nova(void) {

    float novo_valor;

    printf("Qual o valor da nova amostra? ");
    scanf(" %f", &novo_valor);
    return novo_valor;
}

void pergunta_ini(bool *continua) {
    char resposta;
    do {
        printf("[S/N] Quer adicionar uma nova amostra? ");
        scanf(" %c", &resposta);
        resposta = (char)toupper((unsigned char)resposta);
    } while (resposta != 'S' && resposta != 'N');
    *continua = (resposta == 'S'); // Retorna true se resposta == 'S' ou false se resposta == 'N'.
}
