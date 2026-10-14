#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define TITLELINE "\n===========================\n"

typedef struct { 
    int id; 
    float temperatura; 
    char status; 
} Sensor;

void atualizar_sensor(Sensor *sensor, float nova_temperatura);
void mostra_sensor(Sensor *dados_atualizados);
char pergunta(void);

int main(void) {

    char resposta = 'S';
    srand((unsigned int)time(NULL));
    Sensor dados;

    do {
        float nova_temp = rand() % 40 ;
        
        atualizar_sensor(&dados, nova_temp);
        mostra_sensor(&dados);
        
        resposta = pergunta();
    
    } while (resposta == 'S');

    return 0;
}

void atualizar_sensor(Sensor *sensor, float nova_temperatura) {

    if (sensor == NULL) {
        return;
    }

    // ATRIBUIÇÃO DE ID;
    sensor -> id = 1000;

    // ATUALIZAÇÃO DA NOVA TEMPERATURA ALEATÓRIA;
    sensor -> temperatura = nova_temperatura;
    
    // ATUALIZAÇÃO DE STATUS
    if (nova_temperatura < 15.0) {
        sensor -> status = 'B'; // Temperatura Baixa;
    }
    else if (nova_temperatura < 30.0) {
        sensor -> status = 'N'; // Temperatura Normal;
    }
    else {
        sensor -> status = 'A'; // Temperatura Alta;
    }   
}

void mostra_sensor(Sensor *dados_atualizados) {
    printf(TITLELINE);
    printf("ID: %d\n", dados_atualizados -> id);
    printf("Temperatura: %.1f\n", dados_atualizados -> temperatura);
    printf("Status: %c\n", dados_atualizados -> status);
}

char pergunta(void) {
    
    char keep_doing;
    do {
        printf("Quer continuar? [S/N]\n");
        scanf(" %c", &keep_doing);
        keep_doing = (char)toupper((unsigned char)keep_doing);
    } while (keep_doing != 'S' && keep_doing != 'N');

    return keep_doing;
}
