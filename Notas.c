#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main(){
	
	FILE *arq;
	int notas[TAM], notas2[TAM], i;
	
	arq = fopen("notas.txt", "wb");
	
	for(i = 0; i < TAM;){
		printf("Digite o numero %d\n", i+1);
		scanf("%d", notas[TAM]);
		fputs(notas[TAM], arq);
	}
	
	fclose(arq);
	
	printf("Notas salvadas!\n");
	printf("-----------------\n");
	printf("\nImprimindo dados salvados:\n"):
		
	fp = fopen("notas.txt", "rb");
	
	for(i = 0; i < TAM; i++){
		fscanf(arq, "%d", &notas2[i]);
		printf("%d", notas2[i]);
	}
	
	fclose(arq);
	return 0;
}
