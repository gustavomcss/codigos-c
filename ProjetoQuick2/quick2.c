#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* VETOR DE 10000 ELEMENTOS */

void swap(int vetor[], int a, int b) {
    int t = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = t;
    // printf("Troca de [%d] [%d] : (%d, %d) \n", a, b, vetor[b], vetor[a]);
}

int particiona(int vetor[], int esq, int dir, int pivot, int *comp, int *trocas) {
    
    // Se o subvetor possui tamanho > 1
	while (esq <= dir) { 
	 	
		// Comparação do lado esquerdo ao pivô
        while (vetor[esq] < pivot) {
            esq++;
            (*comp)++;
        }

		// Comparação do lado direito ao pivô
        while (vetor[dir] > pivot) {
            dir--;
            (*comp)++;
        }
	
        if (esq <= dir) {
            if (esq != dir) {
            	
            	// Troca de posições com menor que o pivo e maior que o pivo
                swap(vetor, esq, dir); 
                (*trocas)++;
            } 

			esq++;
			dir--;
        }
    }
    
    return esq; // Retorna o pivô
}

void quick(int vetor[], int esq, int dir, int *comp, int *trocas) {
    
	if (esq >= dir) {
        return;
    }

    int pivot = vetor[(esq + dir) / 2]; // Escolha do pivo (Meio)
    
	int index = particiona(vetor, esq, dir, pivot, comp, trocas); // Particiona o Vetor
    quick(vetor, esq, index - 1, comp, trocas); // Começa a ordenação da parte esquerda ao pivô
    quick(vetor, index, dir, comp, trocas); // Começa a ordenação da parte direta ao pivô
    
}

int main(int argc, char *argv[]) {
	int vetor_cresc[10000];
	int vetor[10000];     
	int vetor_decresc[10000]; 
	    
	int i, j, aux;
	srand(time(NULL));  
	
	printf("================= VETORES GERADOS =================\n\n");
	
	printf("VETOR CRESCENTE: \n");
	int num_cresc = 1;
	for (i = 0; i < 10000; i++) {
		vetor_cresc[i] = num_cresc;
		num_cresc++;
	}
	
	for (i = 0; i < 10000; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor_cresc[i]);
	}
	printf("\n\n");
	
	
	printf("VETOR ALEATORIO: \n");
	for (i = 0; i < 10000; i++) {
		vetor[i] = rand()%10000;
	}
	
	for (i = 0; i < 10000; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
	
	
	printf("VETOR DECRESCENTE: \n");
	int num_decresc = 10000;
	for (i = 0; i < 10000; i++) {
		vetor_decresc[i] = num_decresc;
		num_decresc--;
	}
	
	for (i = 0; i < 10000; i++) {
		if (i % 20 == 0) {
			printf("\n");
		}
		printf("%d ", vetor_decresc[i]);
	}
	printf("\n\n");


	// Quick Valor Crescente
	int comp_cresc = 0;
	int troca_cresc = 0;
	quick(vetor_cresc, 0, 9999, &comp_cresc, &troca_cresc);
	
	// Quick Vetor Aleatório
	int comp = 0;  
	int troca = 0;
	quick(vetor, 0, 9999, &comp, &troca);

	// Quick Vetor Decrescente
	int comp_decresc = 0;
	int troca_decresc = 0;
	quick(vetor_decresc, 0, 9999, &comp_decresc, &troca_decresc);
	
	
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
	
	printf("\n\nVETOR DECRESCENTE: \n");
	for (i = 0; i < 10000; i++) {
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

