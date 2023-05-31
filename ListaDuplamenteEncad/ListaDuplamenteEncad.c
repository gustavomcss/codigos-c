#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    struct lista *anterior;
    int posicao;
    int elemento;
    struct lista *proximo;
} Lista;

int main () {
    Lista *ponteiroInicial;
    Lista *ponteiroAtual;
    int resp;

    ponteiroInicial = (Lista *)malloc(sizeof(Lista));
    ponteiroInicial->anterior = NULL;
    ponteiroAtual = ponteiroInicial;

    do {
        printf("Entre com a posicao do elemento: ");
        scanf("%d", &ponteiroAtual->posicao);

        printf("Entre com o valor da posicao [%d]: ", ponteiroAtual->posicao);
        scanf("%d", &ponteiroAtual->elemento);

        printf("\nDeseja continuar? \n\n[1] - Sim\n[2] - Nao\n\nSua Resposta: ");
        scanf("%d", &resp);
        system("cls");

        if (resp == 1) {
            ponteiroAtual->proximo = (Lista *)malloc(sizeof(Lista));
            ponteiroAtual->proximo->anterior = ponteiroAtual->posicao;
            ponteiroAtual = ponteiroAtual->proximo;
        } else {
            break;
        }

    } while (resp != 2);

    ponteiroAtual->proximo = NULL;

    while (ponteiroInicial != NULL) {
        printf("Posicao Anterior: %d\n", ponteiroInicial->anterior);
        printf("POSICAO ATUAL: %d\n", ponteiroInicial->posicao);
        printf("ELEMENTO SALVO: %d\n", ponteiroInicial->elemento);
        
        if (ponteiroInicial->proximo == NULL) {
            printf("Posicao Proximo: %d\n", 0);
        } else {
            printf("Posicao Proximo: %d\n", ponteiroInicial->proximo->posicao);
        }
            
        printf("\n");
        ponteiroInicial = ponteiroInicial->proximo;
    }

    system("pause");
    return 0;
}
