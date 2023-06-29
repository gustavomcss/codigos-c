#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <Windows.h>

int main(int argc, char *argv[]) {
	int vetor_cresc[10000];
	int vetor[10000];     //Vetor
	int vetor_decresc[10000];
	int comp = 0;       //Variável de comparações
	int troca = 0;      //Variável de troca
	int i, j, aux;
	
	srand((time)NULL);  //Definir uma semente
	//time(NULL) é uma semente recebida pelo relógio do computador
	
	int num_cresc = 1;
	for (i = 0; i < 10000; i++) {
		vetor_cresc[i] = num_cresc;
		num_cresc++;
	}
	
	printf("VETOR CRESCENTE: \n");
	for (i = 0; i < 10000; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor_cresc[i]);
	}
	printf("\n\n");
	
	
	
	for (i = 0; i < 10000; i++) {
		vetor[i] = rand()%10000;
	}
	
	printf("VETOR ALEATORIO: \n");
	for (i = 0; i < 10000; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
	
	
	
	int num_decresc = 10000;
	for (i = 0; i < 10000; i++) {
		vetor_decresc[i] = num_decresc;
		num_decresc--;
	}
	
	printf("VETOR DECRESCENTE: \n");
	for (i = 0; i < 10000; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor_decresc[i]);
	}
	printf("\n\n");

	for (i = 0; i < 9999; i++) {
		for (j = 0; j < 9999; j++) {
			comp++;
			if (vetor_cresc[j] > vetor_cresc[j+1]) {				
				aux = vetor_cresc[j];
				vetor_cresc[j] = vetor_cresc[j+1];
				vetor_cresc[j+1] = aux;
				troca++;
			}
		}
	}
	
	for (i = 0; i < 9999; i++) {
		for (j = 0; j < 9999; j++) {
			comp++;
			if (vetor[j] > vetor[j+1]) {				
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
				troca++;
			}
		}
	}
	
	for (i = 0; i < 9999; i++) {
		for (j = 0; j < 9999; j++) {
			comp++;
			if (vetor_decresc[j] > vetor_decresc[j+1]) {				
				aux = vetor_decresc[j];
				vetor_decresc[j] = vetor_decresc[j+1];
				vetor_decresc[j+1] = aux;
				troca++;
			}
		}
	}
	
	system("pause");
	system("cls");
	printf("================ VETORES ORDENADOS ================");
	printf("\n\nVETOR CRESCENTE: \n");
	for (i = 0; i < 10000; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor_cresc[i]);
	}
	
	printf("\n\nVETOR ALEATORIO: \n");
	for (i = 0; i < 10000; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor[i]);
	}
	
	printf("\n\nVETOR DECRESC: \n");
	for (i = 0; i < 10000; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor_decresc[i]);
	}
	
	
	
	printf("\n\nNumero de Comparacoes: %d", comp);
	printf("\nNumero de Trocas: %d", troca);
	printf("\nTempo Decorrido: %.2f", (0.001 * troca));
	
	return 0;
}

