#include <stdio.h>

#define TAM 2

typedef struct {
    char estado;                
    char codigoCarta[4];        
    char nomeCidade[100];       
    unsigned long int populacao;
    float area;                 
    float pib;                  
    int pontosTuristicos;       
    float densidadePopulacional;
    float pibPerCapita;         
    float superPoder;           
} Carta;

void lerCarta(Carta *carta, int indice) {
    printf("\n--- Inserindo dados da carta %d ---\n", indice + 1);
    
    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%3s", carta->codigoCarta);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("População: ");
    scanf("%lu", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB: ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculos adicionais
    if (carta->area > 0) {
        carta->densidadePopulacional = carta->populacao / carta->area;
    } else {
        carta->densidadePopulacional = 0;
    }

    if (carta->populacao > 0) {
        carta->pibPerCapita = carta->pib / carta->populacao;
    } else {
        carta->pibPerCapita = 0;
    }

    // Cálculo do Super Poder
    float inversoDensidade = (carta->densidadePopulacional > 0) ? (1.0f / carta->densidadePopulacional) : 0;
    carta->superPoder = (float)carta->populacao + carta->area + carta->pib + 
                        carta->pontosTuristicos + carta->pibPerCapita + inversoDensidade;
}

void exibirCarta(Carta carta, int indice) {
    printf("\n--- Carta %d ---\n", indice + 1);
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigoCarta);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

void compararCartas(Carta c1, Carta c2) {
    printf("\n--- Comparações ---\n");

    printf("População - Carta 1 vence? %d\n", c1.populacao > c2.populacao);
    printf("Área - Carta 1 vence? %d\n", c1.area > c2.area);
    printf("PIB - Carta 1 vence? %d\n", c1.pib > c2.pib);
    printf("Pontos Turísticos - Carta 1 vence? %d\n", c1.pontosTuristicos > c2.pontosTuristicos);
    printf("PIB per Capita - Carta 1 vence? %d\n", c1.pibPerCapita > c2.pibPerCapita);
    printf("Densidade Populacional - Carta 1 vence? %d (menor é melhor)\n", c1.densidadePopulacional < c2.densidadePopulacional);
    printf("Super Poder - Carta 1 vence? %d\n", c1.superPoder > c2.superPoder);
}

int main() {
    Carta cartas[TAM];

    for (int i = 0; i < TAM; i++) {
        lerCarta(&cartas[i], i);
    }

    for (int i = 0; i < TAM; i++) {
        exibirCarta(cartas[i], i);
    }

    compararCartas(cartas[0], cartas[1]);

    return 0;
}