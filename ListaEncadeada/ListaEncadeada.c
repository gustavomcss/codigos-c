#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
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
		printf("Entre com o %do valor: ", (i));
		scanf("%d", &proximoPonteiro -> elemento);
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
	
	int j = 1;
	while (proximoPonteiro != NULL) {
		printf("Elemento [%d]: %d\n", j, proximoPonteiro->elemento);
		proximoPonteiro = proximoPonteiro->proximo;
		j++;
	}
	
	return 0;
}