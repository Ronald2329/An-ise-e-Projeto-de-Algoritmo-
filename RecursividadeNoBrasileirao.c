#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preencheTabela(char time[][40], int *pontos) {
    /*int pontosReais[] = {63, 63, 62, 60, 59, 59, 53, 52, 48, 47, 46, 45, 44, 44, 43, 42, 41, 35, 29, 21};*/
    
    //Colocando a ordem de pontos dos times de maneira crescente
	int pontosReais[] = {21, 29, 35, 41, 42, 43, 44, 45, 46, 46, 47, 48, 52, 53, 59, 59, 60, 62, 63, 63};

	
    char times[20][40] = {"Palmeiras", "Flamengo", "Botafogo", "Atletico-MG", "Gremio", "Bragantino", "Fluminense", "Athletico-PR", "Cuiaba", "Sao Paulo", "Internacional", "Fortaleza", "Cruzeiro", "Corinthians", "Santos", "Vasco", "Bahia", "Goias", "Coritiba", "America-MG"};

    // Copiando os times e pontos para os parâmetros da função
    for (int i = 0; i < 20; i++) {
        strcpy(time[i], times[i]);
        pontos[i] = pontosReais[i];
    }

}

void ordenarTimesPorPontos(int *pontos, int *indices) {
    for (int i = 0; i < 20; i++) {
        indices[i] = i;
    }

    for (int i = 0; i < 19; i++) {
        for (int j = i + 1; j < 20; j++) {
            if (pontos[indices[j]] > pontos[indices[i]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }
}

void mostraTabela(char time[][40], int *pontos) {
    int indices[20];
    ordenarTimesPorPontos(pontos, indices);

    printf("\nTabela Brasileirao Serie A\n");
    for (int i = 0; i < 20; i++) {
        int indice = indices[i];
        printf("\n%i. %s | P: %i", i + 1, time[i], pontos[indice]);
    }
    printf("\n");
}

void acharMaiores(int *pontos, char time[][40]) {
    printf("\nOs primeiros colocados (G5)):\n");
    for (int i = 0; i < 5; i++) {
        printf("Posição: %i | Pontos: %i | Time: %s\n", i + 1, pontos[i], time[i]);
    }
}

void acharMenores(int *pontos, char time[][40]) {
    printf("\nOs últimos colocados na zona de rebaixamento(Z4):\n");
    for (int i = 19; i >= 16; i--) {
        printf("Posição: %i | Pontos: %i | Time: %s\n", i + 1, pontos[i], time[i]);
    }
}

int main() {
    char time[20][40];
    int pontos[20];

    preencheTabela(time, pontos);
    mostraTabela(time, pontos);
    acharMaiores(pontos, time);
    acharMenores(pontos, time);

    return 0;
}
