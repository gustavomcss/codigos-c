#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
	int topo;
	int itens[5];
} Pilha;

void inicializar(Pilha *p) {
	p -> topo = -1;
//	(*p).topo = -1;	
}

int mostrarMenu() {
	int opc;
	
	printf("--------------- MENU ---------------\n\n");
	printf("[1] - Inserir um elemento na Pilha\n");
	printf("[2] - Remover um elemento da Pilha\n");
	printf("[3] - Verificar condicao da Pilha\n");
	printf("[0] - Encerrar o Programa\n\n");
	printf("------------------------------------\n\n");
	printf("Digite sua escolha: ");
	scanf("%d",&opc);
	system("cls");
	
	return opc;
}

void inserirPilha(int e, Pilha *p) {

	if (p -> topo == 4) {
		printf("\n!!! A PILHA ESTA CHEIA !!!\n\nNao eh possivel inserir mais elementos.");
	}
	
	else {
		p -> topo++;
		p -> itens[p -> topo] = e;
        printf("\nElemento %d foi inserido na pilha.", e);
	}
}

void removerPilha(Pilha *p) {
	int elementoRemovido;
	
	if (p -> topo == -1) {
		printf("!!! A PILHA ESTA VAZIA !!!\n\nNao eh possivel remover mais elementos.");
	}
	
	else {
		elementoRemovido = p -> itens[p -> topo];
		p -> topo--;
		printf ("O elemento %d foi removido da pilha.", elementoRemovido);
	}
}

void verificarCondicaoPilha(Pilha *p) {
	int i;
	
	if (p -> topo == 4) {
		printf("!!! A PILHA ESTA CHEIA !!!\n\n");
	}
	
	else if (p -> topo == -1) {
		printf("!!! A PILHA ESTA VAZIA !!!");
	}
	
	if (p -> topo != -1) {
		printf ("A sua pilha atual eh: \n\n");
		printf ("PILHA = ");
		for(i = 0; i <= p -> topo; i++) {
			printf ("- [ %d ] ", p -> itens[i]);
		}
	}
}


int main() {
	int opc;   //Variavel que atribuira a opcao do usuario
	int elemento;   //Numero que vai ser inserido na pilha
	Pilha p;

	inicializar(&p);
	
	do {
		opc = mostrarMenu();
		
		if (opc >= 4 || opc < 0) {
			printf("OPCAO INVALIDA - Escolha uma nova opcao. \n\n");
		}
		
		if (opc == 1) {
			printf("--------------- ENTRADA ---------------\n\n");
			printf("Digite um elemento para entrar na pilha: ");
			scanf("%d",&elemento);

			inserirPilha(elemento, &p);
            
			printf("\n\n");
			printf("---------------------------------------\n\n");
			system("pause");
			system("cls");
		}
		
		if (opc == 2) {
			printf("--------------- REMOCAO ---------------\n\n");

			removerPilha(&p);

			printf("\n\n");
			printf("---------------------------------------\n\n");
			system("pause");
			system("cls");	
		}
		
		if( opc == 3) {
			printf("--------------- CONDICAO ---------------\n\n");

			verificarCondicaoPilha(&p);

			printf("\n\n");
			printf("----------------------------------------\n\n");
			system("pause");
			system("cls");
		}
		
		if (opc == 0) {
			printf("--------------- SAIDA ---------------\n\n");
	        printf("Encerrando o Programa...\n\n");
            printf("-------------------------------------\n\n");

            system("pause");
		}
	
	} while (opc != 0);
	
	return 0;
}
