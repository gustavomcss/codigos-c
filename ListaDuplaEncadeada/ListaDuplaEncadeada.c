#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
	struct lista *anterior;
	int posicao;
	int elemento;
	struct lista *proximo;
} Lista;

int main() {
	Lista *ponteiroInicial;
	Lista *proximoPonteiro;
	int resp;
	
	ponteiroInicial = (Lista *)malloc(sizeof(Lista));   //A função 'malloc' irá alocar o número de bytes ocupado por Lista
	ponteiroInicial->anterior = NULL;
	proximoPonteiro = ponteiroInicial;
	
	do {
		printf("Entre com a posicao do elemento: ");
		scanf("%d", &proximoPonteiro->posicao);
		
		printf("Entre com o %do valor: ", (proximoPonteiro->posicao));
		scanf("%d", &proximoPonteiro->elemento);
		
		printf("\nDeseja continuar? \n\n[1] - Sim\n[2] - Nao\n\nSua Resposta: ");
		scanf("%d", &resp);
		system("cls");
		
		if (resp == 1) {
			proximoPonteiro->proximo = (Lista *)malloc(sizeof(Lista));
			proximoPonteiro->proximo->anterior = proximoPonteiro;
			proximoPonteiro = proximoPonteiro->proximo;
		} else {
			break;
		}
		
	} while (resp == 1);
	
	proximoPonteiro->proximo = NULL;
	proximoPonteiro = ponteiroInicial;
	
	while (proximoPonteiro != NULL) {
		printf("Posicao Anterior: %d\n", proximoPonteiro->anterior);
		printf("Elemento [%d]: %d\n", proximoPonteiro->posicao, proximoPonteiro->elemento);
		printf("Posicao Proximo: %d\n\n", proximoPonteiro->proximo);
		proximoPonteiro = proximoPonteiro->proximo;
	}
	
    system("pause");
	return 0;
}