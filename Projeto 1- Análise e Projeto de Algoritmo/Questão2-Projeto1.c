#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct lista {
    int id;
    char produto[32];
    struct lista *prox;
};
typedef struct lista lista;

// Função para inserir mantendo a ordem alfabética
void inserirOrdenado(int id, char *nome, lista **prod) {
    lista *novoproduto = (lista *)malloc(sizeof(lista));
    novoproduto->id = id;
    strcpy(novoproduto->produto, nome);

    // Inserir o novo produto mantendo a lista ordenada por ordem alfabética
    lista *atual = *prod;
    lista *anterior = NULL;

    while (atual != NULL && strcmp(nome, atual->produto) > 0) {
        anterior = atual;
        atual = atual->prox;
    }

    novoproduto->prox = atual;

    if (anterior == NULL) {
        *prod = novoproduto; // Novo produto é o primeiro da lista
        id = 0;
    } else {
        anterior->prox = novoproduto; // Inserir entre dois produtos
    }
}

void procurar(lista *prod) {
    char nomeProd[32];
    int ach = 0;
    printf("Digite o nome do produto que deseja procurar: ");
    scanf("%s", nomeProd);
    while (prod != NULL) {
        if (strcmp(nomeProd, prod->produto) == 0) {
            printf("\nProduto encontrado!\n");
            printf("Produto: %s\n", prod->produto);
            printf("ID: %i\n", prod->id);
            ach = 1;
            break;
        }
        prod = prod->prox;
    }

    if (ach == 0) {
        printf("O produto %s nao esta na lista de produtos!!\n", nomeProd);
    }
}

void imprimir(lista *prod) {
    printf("---------------------Lista dos produtos:---------------------\n");
    while (prod != NULL) {
        printf("ID: %i, Produto: %s\n", prod->id, prod->produto);
        prod = prod->prox;
    }
    printf("\n---------------------Fim da lista dos produtos---------------------\n");
}

int main() {
    lista *produtos;
    produtos = NULL;
    int n;
    int resp;

    do {
        printf("Informe a quantidade de produtos a serem adicionados: \n");
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            char nome[32];
            printf("Digite o nome do produto: ");
            scanf("%s", nome);
            inserirOrdenado(i, nome, &produtos);
            imprimir(produtos);
        }

        procurar(produtos);
        imprimir(produtos);

        printf("Para continuar adicionando novos produtos à lista, digite qualquer numero\n");
        printf("Se nao, digite 0 para sair:\n");
        scanf("%d", &resp);

    } while (resp != 0);

    return 0;
}
