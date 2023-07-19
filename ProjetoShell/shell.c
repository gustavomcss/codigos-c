#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* VETOR DE 100 ELEMENTOS */

void shell(int vetor[], int tamanho, int *comp, int *trocas) {
	int i, intervalo = tamanho;
	float h = tamanho;
	
	// Enquanto intervalo != 0, continua dividindo e ordenando o vetor
	while (intervalo != 1) {
		h = intervalo;
		
		h = h / 2.0;
		intervalo = intervalo / 2;
		
		if (h > intervalo) {
			intervalo = intervalo + 1;
		}
		
		// Aplica a inserção direta com o intervalo atual
		for (i = intervalo; i < tamanho; i++) {
			int temp = vetor[i];
			int j = i - intervalo;
			
			// Move os elementos de cada intervalo para frente enquanto fora de ordem
			while (j >= 0 && temp < vetor[j]) {
				vetor[j + intervalo] = vetor[j];
				j = j - intervalo;
				(*trocas)++;
			}
			(*comp)++;
			
			// Se houve troca anteriormente, realiza a troca para ajeitar as coisas
			if ((j + intervalo) != i) {
				vetor[j + intervalo] = temp;
				
			}
			
		}
	}
}

int main(int argc, char *argv[]) {
	int vetor_cresc[100];
	int vetor[100];     
	int vetor_decresc[100];     
	int i, j, aux;
	srand(time(NULL));  
	
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


	// Shell Valor Crescente
	int comp_cresc = 0;
	int troca_cresc = 0;
	shell(vetor_cresc, 100, &comp_cresc, &troca_cresc);
	
	// Shell Vetor Aleatório
	int comp = 0;  
	int troca = 0;
	shell(vetor, 100, &comp, &troca);
	
	// Shell Vetor Decrescente
	int comp_decresc = 0;
	int troca_decresc = 0;
	shell(vetor_decresc, 100, &comp_decresc, &troca_decresc);
	
	
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


