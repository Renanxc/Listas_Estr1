/**************************************
* Trabalho 3 de Estrutura de Dados I
* Curso de Sistemas da informacão
* Aluno: Renan Xavier Calmon - matricula: 0050010824
* Quiz
***************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>
#include "Fila-lista.h"

void menu();

int main(){
	setlocale(LC_ALL, "Portuguese");
	menu();

	printf("Fim !!!");
	system("pause");
	return 0;
}
char* nome_jogador(){                             //função pega o que é escrito e manda para uma string
   char* nome;
   int n, ch;

   n = 0;
   while ((ch = getc( stdin)) != '\n' && n<100) {      //ch recebe um valor enquanto o que for digitado for diferente de uma quebra de linha (enter)
      nome[n++] = ch;
   }
   nome[n] = '\0';                             //finaliza a string
   return nome;
}
void menu(){
	Fila *f;
	char verif;
	char nome[100];
	int x;

	f = fila_cria();
	do{
		printf("\tInsira jogadores, digite 0 para completar\n\n");
		do{
			printf("Insira um jogador: ");
			strcpy(nome,nome_jogador());
			fflush(stdin);
			//printf("%s\n",nome);
			if(strcmp(nome,"0") != 0)
				fila_push(f,nome);
		}while(strcmp(nome,"0") != 0);                  // Se nome for igual a 0 finaliza a entrada de jogadores
		if(fila_vazia(f))
			exit(1);
		//fila_imprime(f);
		system("pause");
		system("cls");
		printf("\tResponda com s para \"Sim\" e n para \"Não\"\n");
		while(f->ini->prox != NULL){                                 // Enquanto não sobrar apenas um jogador o jogo continuará
			strcpy(nome,fila_pop(f));
			printf("\nJogador %s.",nome);
			srand(time(NULL));
			x = perguntas(rand() % 10);                       // É gerado um número aleatório de 0~9 para que seja eleita uma pergunta
			if(x)
				fila_push(f,nome);                   // Se acertar a pergunta volta para o final da fila, se errar é eliminado
			else{
				printf("\n\t%s acaba de ser eliminado!\n",nome);
				system("pause");
			}
			system("cls");
		}
		strcpy(nome,fila_pop(f));            // É retirado o nome do vencedor para que possa mostrar e ao mesmo tempo liberar fila para outra rodada
		system("cls");
		printf("\n\n\tParabéns %s, você foi o vencedor do nosso QUIZ!!!\n\n",nome);
		system("pause");
		system("cls");
		do{
			printf("\nDeseja continuar (s/n)?");
			fflush(stdin);
			scanf("%c",&verif);
			verif= toupper(verif);
		}while(verif!='S' && verif!='N');
		system("cls");

	}while(verif=='S');
	fila_libera(f);
}
int perguntas(int r){                             //De acordo com o número aleatório será feita uma pergunta diferente para o quiz
	char resp;

	while(1){
		switch(r){
			case 0:	printf(" A metade do dobro de uma dúzia é igual a 6?");
					fflush(stdin);
					scanf("%c",&resp);
					resp= toupper(resp);
					if(resp=='S')
						return 0;
					else
						if(resp=='N')
							return 1;
					break;
			case 1:	printf(" As toupeiras enchergam muito bem?");
					fflush(stdin);
					scanf("%c",&resp);
					resp= toupper(resp);
					if(resp=='S')
						return 0;
					else
						if(resp=='N')
							return 1;
					break;
			case 2:	printf(" O mar vermelho fica na china?");
					fflush(stdin);
					scanf("%c",&resp);
					resp= toupper(resp);
					if(resp=='S')
						return 0;
					else
						if(resp=='N')
							return 1;
					break;
			case 3:	printf(" Os golfinhos são mamíferos?");
					fflush(stdin);
					scanf("%c",&resp);
					resp= toupper(resp);
					if(resp=='S')
						return 1;
					else
						if(resp=='N')
							return 0;
					break;
			case 4:	printf(" O Papel foi inventado há mais de 2000 anos atrás na China?");
					fflush(stdin);
					scanf("%c",&resp);
					resp= toupper(resp);
					if(resp=='S')
						return 1;
					else
						if(resp=='N')
							return 0;
					break;
			case 5:	printf(" Famoso pensador que primeiro escreveu sobre a existência da lendária Atlântida foi Herótodo?");
					fflush(stdin);
					scanf("%c",&resp);
					resp= toupper(resp);
					if(resp=='S')
						return 0;
					else
						if(resp=='N')
							return 1;
					break;
			case 6:	printf(" O local onde nasceu a dança do Frevo foi Rio de janeiro?");
					fflush(stdin);
					scanf("%c",&resp);
					resp= toupper(resp);
					if(resp=='S')
						return 0;
					else
						if(resp=='N')
							return 1;
					break;
			case 7:	printf(" Nome do jornal do Tio Patinhas é \"A Patada\"?");
					fflush(stdin);
					scanf("%c",&resp);
					resp= toupper(resp);
					if(resp=='S')
						return 1;
					else
						if(resp=='N')
							return 0;
					break;
			case 8:	printf(" Nome do Governante brasileiro responsável pelo maior extermínio de índios durante a colonização é Mem de Sá?");
					fflush(stdin);
					scanf("%c",&resp);
					resp= toupper(resp);
					if(resp=='S')
						return 1;
					else
						if(resp=='N')
							return 0;
					break;
			case 9:	printf(" O abominável homem das neves é uma lenda do Tibet?");
					fflush(stdin);
					scanf("%c",&resp);
					resp= toupper(resp);
					if(resp=='S')
						return 1;
					else
						if(resp=='N')
							return 0;
		}
		printf("\tApenas S ou N!\n");
	}
}
