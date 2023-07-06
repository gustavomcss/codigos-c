#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <Windows.h>

/* VETOR DE 1000 ELEMENTOS */

int main(int argc, char *argv[]) {
	int vetor_cresc[1000];
	int vetor[1000];     
	int vetor_decresc[1000];     
	int i, j, aux;
	srand((time)NULL);  
	
	printf("================ VETORES GERADOS ================\n\n");
	
	printf("VETOR CRESCENTE: \n");
	int num_cresc = 1;
	for (i = 0; i < 1000; i++) {
		vetor_cresc[i] = num_cresc;
		num_cresc++;
	}
	
	for (i = 0; i < 1000; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor_cresc[i]);
	}
	printf("\n\n");
	
	
	printf("VETOR ALEATORIO: \n");
	for (i = 0; i < 1000; i++) {
		vetor[i] = rand()%1000;
	}
	
	for (i = 0; i < 1000; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
	
	
	printf("VETOR DECRESCENTE: \n");
	int num_decresc = 1000;
	for (i = 0; i < 1000; i++) {
		vetor_decresc[i] = num_decresc;
		num_decresc--;
	}
	
	for (i = 0; i < 1000; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor_decresc[i]);
	}
	printf("\n\n");


	// Selection Valor Crescente
	int comp_cresc = 0;
	int troca_cresc = 0;
	for (i = 0; i < 999; i++) {
		int minIndex = i;
		int aux;

		for (j = i + 1; j < 1000; j++) {
			comp_cresc++;
			
			if (vetor_cresc[j] < vetor_cresc[minIndex]) {
				minIndex = j;
			}
		}
		
		if (minIndex != i) {
			aux = vetor_cresc[minIndex];
			vetor_cresc[minIndex] = vetor_cresc[i];
			vetor_cresc[i] = aux;
			troca_cresc++;
		}
		
	}
	
	// Selection Vetor Aleatório
	int comp = 0;  
	int troca = 0;
	for (i = 0; i < 999; i++) {
		int minIndex = i;
		int aux;
		
		for (j = i + 1; j < 1000; j++) {
			comp++;
			
			if (vetor[j] < vetor[minIndex]) {
				minIndex = j;
			}
		}
		
		if (minIndex != i) {
			aux = vetor[minIndex];
			vetor[minIndex] = vetor[i];
			vetor[i] = aux;
			troca++;
		}
		
	}
	
	// Selection Vetor Decrescente
	int comp_decresc;
	int troca_decresc = 0;
	for (i = 0; i < 999; i++) {
		int minIndex = i;
		int aux;
		
		for (j = i + 1; j < 1000; j++) {
			comp_decresc++;
			
			if (vetor_decresc[j] < vetor_decresc[minIndex]) {
				minIndex = j;
			}
		}
		
		if (minIndex != i) {
			aux = vetor_decresc[minIndex];
			vetor_decresc[minIndex] = vetor_decresc[i];
			vetor_decresc[i] = aux;
			troca_decresc++;
		}
		
	}
	
	system("pause");
	system("cls");
	printf("================ VETORES ORDENADOS ================");
	
	printf("\n\nVETOR CRESCENTE: \n");
	for (i = 0; i < 1000; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor_cresc[i]);
	}
	
	printf("\n\nVETOR ALEATORIO: \n");
	for (i = 0; i < 1000; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor[i]);
	}
	
	printf("\n\nVETOR DECRESCENTE: \n");
	for (i = 0; i < 1000; i++) {
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
	printf("\nTempo Decorrido: %.2f", (0.0001 * troca_cresc));
	
	printf("\n\nVETOR ALEATORIO: ");
	printf("\nNumero de Comparacoes: %d", comp);
	printf("\nNumero de Trocas: %d", troca);
	printf("\nTempo Decorrido: %.2f", (0.0001 * troca));
	
	printf("\n\nVETOR DECRESCENTE: ");
	printf("\nNumero de Comparacoes: %d", comp_decresc);
	printf("\nNumero de Trocas: %d", troca_decresc);
	printf("\nTempo Decorrido: %.2f", (0.0001 * troca_decresc));
	printf("\n");
	
	return 0;
}


