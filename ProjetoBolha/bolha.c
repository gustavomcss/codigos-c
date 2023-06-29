#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <Windows.h>

/* VETOR DE 100 ELEMENTOS */

int main(int argc, char *argv[]) {
	int vetor_cresc[100];
	int vetor[100];     
	int vetor_decresc[100];     
	int i, j, aux;
	srand((time)NULL);  
	
	printf("================ VETORES GERADOS ================\n\n");
	
	printf("VETOR CRESCENTE: \n");
	int num_cresc = 1;
	for (i = 0; i < 100; i++) {
		vetor_cresc[i] = num_cresc;
		num_cresc++;
	}
	
	for (i = 0; i < 100; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor_cresc[i]);
	}
	printf("\n\n");
	
	
	printf("VETOR ALEATORIO: \n");
	for (i = 0; i < 100; i++) {
		vetor[i] = rand()%100;
	}
	
	for (i = 0; i < 100; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
	
	
	printf("VETOR DECRESCENTE: \n");
	int num_decresc = 100;
	for (i = 0; i < 100; i++) {
		vetor_decresc[i] = num_decresc;
		num_decresc--;
	}
	
	for (i = 0; i < 100; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor_decresc[i]);
	}
	printf("\n\n");


	// Bubble Valor Crescente
	int comp_cresc = 0;
	int troca_cresc = 0;
	for (i = 0; i < 99; i++) {
		for (j = 0; j < 99; j++) {
			comp_cresc++;
			if (vetor_cresc[j] > vetor_cresc[j+1]) {				
				aux = vetor_cresc[j];
				vetor_cresc[j] = vetor_cresc[j+1];
				vetor_cresc[j+1] = aux;
				troca_cresc++;
			}
		}
	}
	
	// Bubble Vetor Aleatório
	int comp = 0;  
	int troca = 0;
	for (i = 0; i < 99; i++) {
		for (j = 0; j < 99; j++) {
			comp++;
			if (vetor[j] > vetor[j+1]) {				
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
				troca++;
			}
		}
	}
	
	// Bubble Vetor Decrescente
	int comp_decresc;
	int troca_decresc = 0;
	for (i = 0; i < 99; i++) {
		for (j = 0; j < 99; j++) {
			comp_decresc++;
			if (vetor_decresc[j] > vetor_decresc[j+1]) {				
				aux = vetor_decresc[j];
				vetor_decresc[j] = vetor_decresc[j+1];
				vetor_decresc[j+1] = aux;
				troca_decresc++;
			}
		}
	}
	
	system("pause");
	system("cls");
	printf("================ VETORES ORDENADOS ================");
	
	printf("\n\nVETOR CRESCENTE: \n");
	for (i = 0; i < 100; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor_cresc[i]);
	}
	
	printf("\n\nVETOR ALEATORIO: \n");
	for (i = 0; i < 100; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor[i]);
	}
	
	printf("\n\nVETOR DECRESCENTE: \n");
	for (i = 0; i < 100; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor_decresc[i]);
	}
	
	printf("\n\n");
	system("pause");
	system("cls");
	printf("================ RESULTADOS ================");
	
	printf("\n\nVETOR CRESCENTE: ");
	printf("\nNumero de Comparacoes: %d", comp_cresc);
	printf("\nNumero de Trocas: %d", troca_cresc);
	printf("\nTempo Decorrido: %.2f", (0.001 * troca_cresc));
	
	printf("\n\nVETOR ALEATORIO: ");
	printf("\nNumero de Comparacoes: %d", comp);
	printf("\nNumero de Trocas: %d", troca);
	printf("\nTempo Decorrido: %.2f", (0.001 * troca));
	
	printf("\n\nVETOR DECRESCENTE: ");
	printf("\nNumero de Comparacoes: %d", comp_decresc);
	printf("\nNumero de Trocas: %d", troca_decresc);
	printf("\nTempo Decorrido: %.2f", (0.001 * troca_decresc));
	printf("\n");
	
	return 0;
}

