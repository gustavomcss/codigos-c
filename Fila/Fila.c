#include <stdio.h>
#include <stdlib.h>

int fila[5]; //fila[0], fila[1], fila[2], fila[3], fila[4]
int inicio = 0;
int fim = -1;

int mostrarMenu() { //Mostra o Menu na Tela
	int opc;
	
	printf("--------------- MENU ---------------\n\n");
	printf("[1] - Inserir um elemento na Fila\n");
	printf("[2] - Remover um elemento na Fila\n");
	printf("[3] - Verificar condicao da Fila\n");
	printf("[0] - Encerrar o Programa\n\n");
	printf("------------------------------------\n\n");
	printf("Digite sua escolha: ");
	scanf("%d",&opc);
	system("cls");
	
	return opc;
}

void inserirFila(int e) { //Insere um Elemento na Fila
	if (fim == 4) {
		printf("\n!!! A FILA ESTA CHEIA !!!\n\nNao eh possivel inserir mais elementos.");
	}
	else {
		fim = fim + 1; //fim++
		fila[fim] = e;
		printf("\nElemento %d foi inserido na fila.", e);
	}
	
}

void removerFila() { //Remove um Elemento na FIla
	int elementoRemovido, i;
	//int aux;
	
	if (fim == -1){
		printf("!!! A FILA ESTA VAZIA !!!\n\nNao eh possivel remover mais elementos.");
	}
	else {
		elementoRemovido = fila[inicio];
		for (i = 1 ; i <= fim ; i++){
			 //aux = fila[i];
			 //fila[i] = fila[i+1];
			 //fila[i-1] = aux;
			 fila[i-1] = fila[i];
		}
		fim = fim - 1;
		
		printf("O elemento %d foi removido da fila.", elementoRemovido);
	}
}

void verificarCondicaoFila() { //Imprime a Fila atual
	int i;
	
	if (fim == 4){
		printf("!!! A FILA ESTA CHEIA !!!\n\n");
	}
	if (fim == -1){
		printf("!!! A FILA ESTA VAZIA !!!");
	}
	if (fim != -1){
		printf("A sua fila atual eh: \n\n");
		printf("FILA = ");
		for (i = 0 ; i < fim+1 ; i++){
			printf("- [ %d ] ", fila[i]);
		}
	}
} 

void sairPrograma() { //Mostra a Saída na Tela
	printf("--------------- SAIDA ---------------\n\n");
	printf("Encerrando o Programa...\n\n");
    printf("-------------------------------------\n\n");

    system("pause");
}

int main(int argc, char *argv[]) {
	int opc, elemento;

	do {
		opc = mostrarMenu();
		
		if (opc >= 4 || opc < 0) {
			printf("OPCAO INVALIDA - Escolha uma nova opcao. \n\n");
		}
		
		if (opc == 1){
			printf("--------------- ENTRADA ---------------\n\n");
			printf("Digite um elemento para entrar na fila: ");
			scanf("%d",&elemento);

			inserirFila(elemento);

			printf("\n\n");
			printf("---------------------------------------\n\n");
			system("pause");
			system("cls");
		}
		
		if (opc == 2){
			printf("--------------- REMOCAO ---------------\n\n");

			removerFila();

			printf("\n\n");
			printf("---------------------------------------\n\n");
			system("pause");
			system("cls");	
		}
		
		if (opc == 3){
			printf("--------------- CONDICAO ---------------\n\n");

			verificarCondicaoFila();

			printf("\n\n");
			printf("----------------------------------------\n\n");
			system("pause");
			system("cls");
		}
		
		if (opc == 0) {
			sairPrograma();
		}
	} while(opc != 0);	
	return 0;
}