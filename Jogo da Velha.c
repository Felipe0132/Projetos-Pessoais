#include <stdio.h>
#include <stdlib.h>

#define TAM 50

int main(){
	
	char velha[3][3];
	int c, l, vencedor = 0, resp = 0, vezesjogadas = 0;
	int jog[3] = {0, 'X', 'O'};
	int vez[2] = {1, 2};

		do{
			vencedor = 0;
			vezesjogadas = 0;
		
			for(l = 0;l < 3;l++){
				for(c = 0;c < 3;c++){
					velha[l][c] = 0;
				}
			}
	
		while(vencedor == 0){
			
			printf("[]    1    2    3\n");
			printf("  ------------------\n");
			for(l = 0; l < 3; l++){
				printf("%d ", l+1);
				printf("| ");
				for(c = 0; c < 3; c++){
					if(velha[l][c] == 0){
						printf("     ");
					}else{
						printf("  %c  ", velha[l][c]);
					}
				
				}	
				printf("| ");
				printf("\n\n");
			}
	
			printf("Vez do jogador %d\n", vez[0]);
		
		do{
			printf("Digite uma posicao vazia:\n");
			printf("Linha:\n");
			scanf("%d", &l);
			fflush(stdin);
			printf("Coluna:\n");
			scanf("%d", &c);
			fflush(stdin);
		}while((velha[l-1][c-1] == 'X' || velha[l-1][c-1] == 'O') || (l > 4 || c > 4));
		
			velha[l-1][c-1] = jog[1];
	 
			system("cls");
				
			if(velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2] && velha[0][0] != 0 && velha[1][1] != 0 && velha[2][2]){
				printf("O jogador %d ganhou!\n\n", vez[0]);
				break;
			}
			
			if(velha[0][2] == velha[1][1] && velha[1][1] == velha[2][0] && velha[0][2] != 0 && velha[1][1] != 0 && velha[2][0]){
				printf("O jogador %d ganhou!\n\n", vez[0]);
				vencedor = 1;
				break;
			}			
		
			for(l = 0;l < 3;l++){
				if((velha[l][0] == 'O' || velha[l][0] == 'X') && (velha[l][1] == 'O' || velha[l][1] == 'X') && (velha[l][2] == 'O' || velha[l][2] == 'X')){
					if(velha[l][0] == velha[l][1] && velha[l][1] == velha[l][2] && velha[l][0] != 0 && velha[l][1] != 0 && velha[l][2]){
					printf("O jogador %d ganhou!\n\n", vez[0]);
					vencedor = 1;
					break;	
					}
				}
			}	
		
			for(c = 0;c < 3;c++){
				if((velha[0][c] == 'O' || velha[0][c] == 'X') && (velha[1][c] == 'O' || velha[1][c] == 'X') && (velha[2][c] == 'O' || velha[2][c] == 'X')){
					if(velha[0][c] == velha[1][c] && velha[1][c] == velha[2][c] && velha[0][c] != 0 && velha[1][c] != 0 && velha[2][c]){
					printf("O jogador %d ganhou!\n\n", vez[0]);
					vencedor = 1;
					break;	
					}
				}
			}
			
			if(vezesjogadas >= 8){
				printf("Deu velha!\n");
				vencedor = 1;
				break;
			}
			
			vezesjogadas++;
			
				
			jog[0] = jog[1];
			jog[1] = jog[2];
			jog[2] = jog[0];
			
			vez[0] = vez[0] + vez[1];
			vez[1] = vez[0] - vez[1];
			vez[0] = vez[0] - vez[1];
		
		}
	
		printf("[]    1    2    3\n");
		printf("  ------------------\n");
		for(l = 0; l < 3; l++){
			printf("%d", l+1);
			printf("| ");
			for(c = 0; c < 3; c++){
				printf("  %c  ", velha[l][c]);			
			}
			printf("| ");
			printf("\n\n");
		}
		
		printf("\nDeseja jogar de novo?\n");
		printf("[0] --> SIM\n");
		printf("[1] --> NAO\n");
		scanf("%d", &resp);
		system("cls");
		
	}while(resp == 0);
}

