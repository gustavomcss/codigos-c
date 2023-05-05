#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
	int posicao;
	int elemento;
	struct lista *proximo;
} Lista;

int main() {
	Lista *ponteiroInicial;
	Lista *proximoPonteiro;
	int i = 1, resp;
	
	ponteiroInicial = (Lista *)malloc(sizeof(Lista));   //A função 'malloc' irá alocar o número de bytes ocupado por Lista
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
			proximoPonteiro = proximoPonteiro->proximo;
			i++;
		} else {
			break;
		}
		
	} while (resp == 1);
	
	proximoPonteiro->proximo = NULL;
	proximoPonteiro = ponteiroInicial;
	
	while (proximoPonteiro != NULL) {
		printf("Elemento [%d]: %d\n", proximoPonteiro->posicao, proximoPonteiro->elemento);
		proximoPonteiro = proximoPonteiro->proximo;
	}
	
	return 0;
}