#include <stdio.h>

float soma_elementos(float *vetor){   
    float soma = 0;
    int i;
	int p;

    for (i=0; i<5; i++){
        printf("\nDigite o valor [%i]:",i+1);
        scanf("%f",&vetor[i]);
        soma += vetor[i];
    }
    printf("Digite a posicao que deseja descobrir o valor: ");
    scanf("%i",&p);
    printf("\nA posicao %i tem valor %.1f",p,vetor[p-1]);
    return soma;
}

void existe(float *vetor){
    int i;
	int x;
    float v;
    printf("\nDigite o valor que deseja saber se esta no vetor: ");
    scanf("%f",&v);
    for(i=0;i<5;i++){
        if(v==vetor[i]){
        	printf("\n%1.f existe no vetor e esta na posicao %i",v,i+1);
        	x= 1;
        }
    }
    if(x !=1)
    	printf("\n%1.f nao existe no vetor !!",v);
   
}
int main(){
    float vetor[5];
    float soma = soma_elementos(&vetor);
    printf("\n Soma: %.1f",soma);
    existe(&vetor);
    return 0;
}
