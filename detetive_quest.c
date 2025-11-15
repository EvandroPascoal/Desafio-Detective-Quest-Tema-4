#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sala {
    char nome[50];           
    char pista[100];         
    struct Sala *esquerda;   
    struct Sala *direita;    
} Sala;

typedef struct PistaNode {
    char pista[100];              
    struct PistaNode *esquerda;   
    struct PistaNode *direita;    
} PistaNode;


Sala* criarSala(const char *nome, const char *pista) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    if (pista != NULL)
        strcpy(nova->pista, pista);
    else
        strcpy(nova->pista, "");
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}


PistaNode* inserirPista(PistaNode *raiz, const char *pista) {
    if (raiz == NULL) {
        PistaNode *novo = (PistaNode*) malloc(sizeof(PistaNode));
        strcpy(novo->pista, pista);
        novo->esquerda = novo->direita = NULL;
        return novo;
    }
    if (strcmp(pista, raiz->pista) < 0)
        raiz->esquerda = inserirPista(raiz->esquerda, pista);
    else if (strcmp(pista, raiz->pista) > 0)
        raiz->direita = inserirPista(raiz->direita, pista);
    return raiz;
}


void exibirPistas(PistaNode *raiz) {
    if (raiz != NULL) {
        exibirPistas(raiz->esquerda);
        printf("- %s\n", raiz->pista);
        exibirPistas(raiz->direita);
    }
}


// ======================
// Exploração da Mansão
// ======================

void explorarSalasComPistas(Sala *atual, PistaNode **pistas) {
    char escolha;
    while (1) {
        printf("\nVocê está no(a): %s\n", atual->nome);

        if (strlen(atual->pista) > 0) {
            printf(">> Pista encontrada: %s\n", atual->pista);
            *pistas = inserirPista(*pistas, atual->pista);
        } else {
            printf(">> Nenhuma pista aqui.\n");
        }

        printf("Escolha seu caminho:\n");
        if (atual->esquerda != NULL) printf("[e] Ir para a esquerda: %s\n", atual->esquerda->nome);
        if (atual->direita != NULL) printf("[d] Ir para a direita: %s\n", atual->direita->nome);
        printf("[s] Sair da exploração\n");
        printf("Opção: ");
        scanf(" %c", &escolha);

        if (escolha == 's') break;
        else if (escolha == 'e' && atual->esquerda != NULL)
            atual = atual->esquerda;
        else if (escolha == 'd' && atual->direita != NULL)
            atual = atual->direita;
        else
            printf("Opção inválida!\n");
    }
}


int main() {
    // mapa da mansão
    Sala *hall = criarSala("Hall de Entrada", "Pegada misteriosa no tapete");
    Sala *salaEstar = criarSala("Sala de Estar", "Caderno rasgado no sofá");
    Sala *cozinha = criarSala("Cozinha", "Copo quebrado no chão");
    Sala *biblioteca = criarSala("Biblioteca", "Página arrancada de um diário");
    Sala *quarto = criarSala("Quarto Principal", "");
    Sala *porao = criarSala("Porão", "Chave enferrujada");

    // Ligando as salas manualmente
    hall->esquerda = salaEstar;
    hall->direita = cozinha;
    salaEstar->esquerda = biblioteca;
    salaEstar->direita = quarto;
    cozinha->direita = porao;

    // Árvore de pistas coletadas
    PistaNode *pistas = NULL;

    printf("=== Detective Quest: Exploração da Mansão ===\n");
    explorarSalasComPistas(hall, &pistas);

    printf("\n=== Pistas coletadas (em ordem alfabética) ===\n");
    if (pistas == NULL)
        printf("Nenhuma pista foi coletada.\n");
    else
        exibirPistas(pistas);

    return 0;
}
