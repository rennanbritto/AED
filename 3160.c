#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[21];
    struct No* proximo;
} No;

No* criarNo(char* nome) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    strcpy(novoNo->nome, nome);
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirNoFinal(No** cabeca, char* nome) {
    No* novoNo = criarNo(nome);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        No* atual = *cabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
}

void inserirAntesDe(No** cabeca, char* nomeNovo, char* nomeReferencia) {
    No* novoNo = criarNo(nomeNovo);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
        return;
    }
    No* atual = *cabeca;
    No* anterior = NULL;
    while (atual != NULL && strcmp(atual->nome, nomeReferencia) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) {
        free(novoNo); // Não encontrou o amigo de referência, não insere
    } else {
        if (anterior == NULL) {
            novoNo->proximo = *cabeca;
            *cabeca = novoNo;
        } else {
            anterior->proximo = novoNo;
            novoNo->proximo = atual;
        }
    }
}

void imprimirLista(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        printf("%s", atual->nome);
        if (atual->proximo != NULL) {
            printf(" ");
        }
        atual = atual->proximo;
    }
    printf("\n");
}

void liberarLista(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    char linha[1001];
    No* cabeca = NULL;

    // Ler a lista atual de amigos
    fgets(linha, 1001, stdin);
    linha[strcspn(linha, "\n")] = '\0'; // Remover a nova linha
    char* token = strtok(linha, " ");
    while (token != NULL) {
        inserirNoFinal(&cabeca, token);
        token = strtok(NULL, " ");
    }

    // Ler a nova lista de amigos
    No* novaCabeca = NULL;
    fgets(linha, 1001, stdin);
    linha[strcspn(linha, "\n")] = '\0'; // Remover a nova linha
    token = strtok(linha, " ");
    while (token != NULL) {
        inserirNoFinal(&novaCabeca, token);
        token = strtok(NULL, " ");
    }

    // Ler o nome do amigo para indicação ou "nao"
    char amigoReferencia[21];
    fgets(amigoReferencia, 21, stdin);
    amigoReferencia[strcspn(amigoReferencia, "\n")] = '\0'; // Remover a nova linha

    // Inserir a nova lista de amigos na lista de Luiggy
    if (strcmp(amigoReferencia, "nao") == 0) {
        // Inserir no final da lista
        No* atual = novaCabeca;
        while (atual != NULL) {
            inserirNoFinal(&cabeca, atual->nome);
            atual = atual->proximo;
        }
    } else {
        // Inserir antes do amigo indicado
        No* atual = novaCabeca;
        while (atual != NULL) {
            inserirAntesDe(&cabeca, atual->nome, amigoReferencia);
            atual = atual->proximo;
        }
    }

    // Imprimir a lista final de amigos de Luiggy
    imprimirLista(cabeca);

    // Liberar a memória das listas
    liberarLista(cabeca);
    liberarLista(novaCabeca);

    return 0;
}
