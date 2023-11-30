/*Algoritmo pior caso para inserção e deleção de produtos na lista O(n)
 Neste caso por estarmos com uma lista simplesmente encadeada do modo pilha, estamos sempre adicionando o próximo elemento da lista após o último
isso significa que para buscar um elemento na lista simplesmente percorrendo a lista fica mais fácil procurar o último elemento adicionado e mais difícil 
ao se aproximar ao último elemento adicionado
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct lista{
	int id;
	char produto[32];
	struct lista *prox;
};typedef struct lista lista;

void inserir(int id, lista **prod){
	lista *novoproduto = (lista*)malloc(sizeof(lista));
	(*novoproduto).id = id;
	printf("Digite o nome do produto: ");
	scanf("%s", (*novoproduto).produto);
	(*novoproduto).prox = *prod;
	(*prod) = novoproduto;
}

void procurar(lista *prod){
	char nomeProd[32];
	int ach;
	printf("Digite o nome do produto que deseja procurar: ");
	scanf("%s", nomeProd);
	while(prod != NULL){
		if(strcmp(nomeProd,(*prod).produto) == 0){
			printf("\nProduto encontrado!\n");
			printf("Produto: %s\n",(*prod).produto);
			printf("ID: %i\n",(*prod).id);
			ach = 1;
			break;
		}
		prod = (*prod).prox;
		ach = 0;
	}
	ach == 0 ? 	printf("O produto %s nao esta na lista de produtos!!\n",nomeProd): 0;

}

void imprimir(lista *prod){
	printf("---------------------Lista dos produtos:---------------------\n");
	while(prod != NULL){
		printf("%s\n", (*prod).produto);
		prod = (*prod).prox;
	}
	printf("\n---------------------Fim da lista dos produtos---------------------\n");
}
int main(){
	lista *produtos;
	//int reg = 0;
	produtos = NULL;
	int n;
	int resp;
	
	do{
		
		printf("INforme a quantidade de produtros a ser adicionados: \n");
		scanf("%d",&n);
	
			for(int i = 0; i < n; i++){
				inserir(i,&produtos);
				imprimir(produtos);
			}
			procurar(produtos);
			imprimir(produtos);
			
			printf("Para continuar adicionando novos produtos a lista digite qualqeur numero\n");
			printf("Se nao digite 0 para sair:\n");
			scanf("%d",&resp);
	
	}while(resp != 0);
	
}
