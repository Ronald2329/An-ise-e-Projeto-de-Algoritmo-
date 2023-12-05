#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preencheTabela(char time[][40], int *pontos,int quantidadeDeTimes,int pt) {
    /*int pontosReais[] = {63, 63, 62, 60, 59, 59, 53, 52, 48, 47, 46, 45, 44, 44, 43, 42, 41, 35, 29, 21};*/
    
    //Colocando a ordem de pontos dos times de maneira crescente
	int pontosReais[] = {21, 29, 35, 41, 42, 43, 44, 45, 46, 46, 47, 48, 52, 53, 59, 59, 60, 62, 63, 63};

	
    char times[20][40] = {"Palmeiras", "Flamengo", "Botafogo", "Atletico-MG", "Gremio", "Bragantino", "Fluminense", "Athletico-PR", "Cuiaba", "Sao Paulo", "Internacional", "Fortaleza", "Cruzeiro", "Corinthians", "Santos", "Vasco", "Bahia", "Goias", "Coritiba", "America-MG"};

    /*// Copiando os times e pontos para os parâmetros da função
    for (int i = 0; i < 20; i++) {
        strcpy(time[i], times[i]);
        pontos[i] = pontosReais[i];
    }*/
    
    if(pt < quantidadeDeTimes){
    	strcpy(time[pt], times[pt]);
        pontos[pt] = pontosReais[pt];
        
        preencheTabela(time,pontos,20,pt + 1);
	}

}

void ordenarTimesPorPontos(int *pontos, int *indices){
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

void mostraTabela(char time[][40], int *pontos,int quantidadeDeTimes,int posicao) {
    int indices[20];
    ordenarTimesPorPontos(pontos, indices);

    /*printf("\nTabela Brasileirao Serie A\n");
    for (int i = 0; i < 20; i++) {
        int indice = indices[i];
        printf("\n%i. %s | P: %i", i + 1, time[i], pontos[indice]);
    }
    printf("\n");*/
    
    if(posicao < quantidadeDeTimes){
    	int indice = indices[posicao];
        printf("\n%i. %s | P: %i", posicao + 1, time[posicao], pontos[indice]);
        mostraTabela(time,pontos,20,posicao + 1);        
	}
    
}

void acharMaiores(int *pontos, char time[][40],int G5, int posicao) {
	/*
    printf("\nOs primeiros colocados (G5)):\n");
    for (int i = 0; i < 5; i++) {
        printf("Posição: %i | Pontos: %i | Time: %s\n", i + 1, pontos[i], time[i]);
    }*/
    
    if(posicao <= G5){
    	 int indices[20];
    	 ordenarTimesPorPontos(pontos, indices);

    	 printf("Posição: %i | Pontos: %i | Time: %s\n", posicao + 1, pontos[indices[posicao]], time[posicao]);
    	 acharMaiores(pontos, time,4,posicao + 1);
	}
}

void acharMenores(int *pontos, char time[][40],int Z4,int posicao,int timeRebaixado) {
   /* printf("\nOs últimos colocados na zona de rebaixamento(Z4):\n");
    for (int i = 19; i >= 16; i--) {
        printf("Posição: %i | Pontos: %i | Time: %s\n", i + 1, pontos[i], time[i]);
    }*/
    
    if(posicao <= Z4){
    	int indices[20];
    	ordenarTimesPorPontos(pontos, indices);
    	
    	int posicaoRebaixamento = 20 - posicao;
    	printf("Posição: %i | Pontos: %i | Time: %s\n", posicaoRebaixamento, pontos[posicao], time[timeRebaixado]);
    	acharMenores(pontos, time,3,posicao + 1,timeRebaixado - 1);
	}
}

int main() {
    char time[20][40];
    int pontos[20];

    preencheTabela(time, pontos,19,0);
    
    printf("\nTabela Brasileirao Serie A\n");
    mostraTabela(time, pontos,20,0);
    
    printf("\n\nOs primeiros colocados (G5)):\n");
    acharMaiores(pontos, time,4,0);
    
    printf("\nOs últimos colocados na zona de rebaixamento(Z4):\n");
    acharMenores(pontos, time,3,0,19);

    return 0;
}
