#include <stdio.h>
#include <stdlib.h>

/* NOTA

   Foi utilizado o mesmo código do arquivo 'ListaEncadeada.c",
feita apenas a adição do ponteiro anterior e também as operações
necessárias para que o ponteiro anterior aponte para o ponteiro
atual do elemento anterior.

*/

typedef struct lista {
	struct lista *anterior;
	int posicao;
	int elemento;
	struct lista *proximo;
} Lista;

int main() {
	Lista *ponteiroInicial;
	Lista *ponteiroAtual;
	int resp;
	
	ponteiroInicial = (Lista *)malloc(sizeof(Lista));   //A função 'malloc' irá alocar o número de bytes ocupado por Lista
	ponteiroInicial->anterior = NULL;
	ponteiroAtual = ponteiroInicial;
	
	do {
		printf("Entre com a posicao do elemento: ");
		scanf("%d", &ponteiroAtual->posicao);
		
		printf("Entre com o %do valor: ", (ponteiroAtual->posicao));
		scanf("%d", &ponteiroAtual->elemento);
		
		printf("\nDeseja continuar? \n\n[1] - Sim\n[2] - Nao\n\nSua Resposta: ");
		scanf("%d", &resp);
		system("cls");
		
		if (resp == 1) {
			ponteiroAtual->proximo = (Lista *)malloc(sizeof(Lista));
			ponteiroAtual->proximo->anterior = ponteiroAtual;   //O ponteiro anterior do próximo elemento vai referenciar o ponteiro atual do elemento anterior.
			ponteiroAtual = ponteiroAtual->proximo;   
		} else {
			break;
		}
		
	} while (resp == 1);
	
	ponteiroAtual->proximo = NULL;
	ponteiroAtual = ponteiroInicial;
	
	while (ponteiroAtual != NULL) {
		printf("Posicao Anterior: %d\n", ponteiroAtual->anterior);
        printf("POSICAO ATUAL: %d\n", ponteiroAtual);
        printf("ELEMENTO SALVO: %d\n", ponteiroAtual->elemento);
        printf("Posicao Proximo: %d\n", ponteiroAtual->proximo);
        printf("\n");
        ponteiroAtual = ponteiroAtual->proximo;
	}
	
	return 0;
}

