#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include <locale.h>

#define TAM 50

struct usuario{
	int idade;
	float peso;
	float alt;
	char nome[TAM];
	char senha[TAM];
	char senconf[TAM];
	char email[TAM];
	char profi[TAM];
	int sentam;
	int confirsen;
	int senTam;
};

typedef struct usuario usuario[5];

int main(){
	
	int ok = 0, ok2,i, senTam, contrlesp, contrlmai, confirsen1, escolha, p, user_select, resp;
	int u;
	char confirsen2[TAM];
	
	setlocale(LC_ALL, "Portuguese");
	
	usuario user;
	
	printf("Programa de cadastro de usuario...\n");
	printf("Quantos usuarios deseja cadastrar? (Limite de 5)\n");
	scanf("%d", &u);
	fflush(stdin);
	system("cls");
	printf("Vamos comecar os cadastros:\n\n");
	
	for(i = 0; i < u; i++){
		
		printf("\tInicio do cadastramento [%d]\n\n", i+1);
		
		printf("Digite o nome do usuario:\n");
		scanf("%49[^\n]s", &user[i].nome);
		getchar();
		
		printf("Digite o email:\n");
		scanf("%49[^\n]s", &user[i].email);
		getchar();
		
		printf("Digite a idade:\n");
		scanf("%d", &user[i].idade);
		fflush(stdin);
		
		printf("Digite a profissao:\n");
		scanf("%49[^\n]s", &user[i].profi);
		getchar();
		
		printf("Digite seu peso:\n");
		scanf("%f", &user[i].peso);
		fflush(stdin);
		
		printf("Digite sua altura:\n");
		scanf("%f", &user[i].alt);
		fflush(stdin);
		
		printf("Digite uma senha para o usuario:\n");
		printf("**Senha precisa conter 8 caracteres, letra maiuscula e caractere especial**\n");
		scanf("%49[^\n]s", user[i].senha); 
		fflush(stdin);
		
		senTam = strlen(user[i].senha) - 1;
	
		while(senTam < 7 && contrlesp == 0 && contrlmai == 0){
		
			if(senTam < 7){
				while(senTam < 7){
					printf("Sua senha não tem no mínimo 8 caracteres! Repita a senha\n");
					scanf("%49[^\n]s", user[i].senha);
					fflush(stdin);
					senTam = strlen(user[i].senha) - 1;
				}
			}
		
			for(p = 0; p < senTam+1; p++){

				if(!isalnum(user[i].senha[p])){ //Confere se há caracteres diferentes de números e letras
					contrlesp += 1;
				}
		
				if(isupper(user[i].senha[p])){ //Confere se há letras maiusculas
					contrlmai += 1;
				}
			}
			
			if(contrlmai <= 0 && contrlesp <= 0 ){
				
				while(contrlmai <= 0 && contrlesp <= 0){
					printf("Sua senha não tem caracteres especiais e / ou letra maiuscula! Repita a senha\n");
					scanf("%49[^\n]s", user[i].senha);
					fflush(stdin);
				
					senTam = strlen(user[i].senha) - 1;
				
					if(senTam < 7){
						while(senTam < 7){
							printf("Sua senha não tem no mínimo 8 caracteres! Repita a senha\n");
							scanf("%49[^\n]s", user[i].senha);
							fflush(stdin);
							senTam = strlen(user[i].senha) - 1;
						}
					}
					
					for(p = 0; p < senTam+1; p++){
						contrlesp = 0;
						contrlmai = 0;
						if(!isalnum(user[i].senha[p])){ //Confere se há caracteres diferentes de números e letras
							contrlesp += 1;
						}
		
						if(isupper(user[i].senha[p])){ //Confere se há letras maiusculas
							contrlmai += 1;
						}
					}
				}
			}
		}
		
		printf("Confirme sua senha:\n");
		scanf("%49[^\n]s", user[i].senconf);
		fflush(stdin);	
	
		user[i].confirsen = strcmp(user[i].senha, user[i].senconf);
	
		while(user[i].confirsen = 0){
			printf("Senha incorreta! Repita a senha.\n");
			scanf("%49[^\n]s", user[i].senconf);
			fflush(stdin);
			user[i].confirsen = strcmp(user[i].senha, user[i].senconf);
		}
		
		printf("Usuario cadastrado com sucesso!\n");
		getchar();
		system("cls");
	}	
	
	resp = 1;
	
	while(resp == 1){
	
		confirsen1 = 1;	
	
		printf("Deseja ver os usuarios cadastrados\n\n");
		printf("Digite: [1] Sim // [2] Não\n");
		scanf("%d", &escolha);
	
		if(escolha = 1){
			printf("Os usuarios cadastrados são:...\n\n");
			for(i = 0; i < u; i++){
				printf("usuario %d: %s\n\n", i+1, user[i].nome);
			}
		}
	
		printf("Qual deseja acessar\n");
		scanf("%d", &user_select);
		fflush(stdin);
	
		printf("Digite a senha do usuario %s!\n\n\n", user[user_select - 1].nome);
		scanf("%49[^\n]s", confirsen2);
		fflush(stdin);
	
		confirsen1 = strcmp(confirsen2, user[user_select - 1].senconf);
	
		while(confirsen1 != 0){
		
			printf("Acesso negado! Tente novamente.");
			printf("Digite a senha do usuario %s!\n\n\n", user[user_select - 1].nome);
			scanf("%49[^\n]s", confirsen2);
			fflush(stdin);
	
			confirsen1 = strcmp(confirsen2, user[user_select - 1].senconf);
			
		}
		
		system("cls");
	
		printf("----  Dados do usuario %d  ----\n", user_select);
		printf("Nome      : %s\n", user[user_select - 1].nome);
		printf("Email     : %s\n", user[user_select - 1].email);
		printf("Profissão : %s\n", user[user_select - 1].profi);
		printf("idade     : %d anos\n", user[user_select - 1].idade);
		printf("Peso      : %.2f Kg\n", user[user_select - 1].peso);
		printf("Altura    : %.2f m\n", user[user_select - 1].alt);
		printf("Senha     : %s\n\n", user[user_select - 1].senha);
		
		printf("Deseja acessar outro usuario\n");
		printf("Digite: [1] Sim // [2] Não\n");
		scanf("%d", &resp);
		fflush(stdin);
			
		system("cls");
	}
}
