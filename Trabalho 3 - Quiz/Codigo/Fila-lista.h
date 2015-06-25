/**************************************
* Trabalho 3 de Estrutura de Dados I
* Curso de Sistemas da informacão
* Aluno: Renan Xavier Calmon - matricula: 0050010824
* Quiz
***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    char info[100];
    struct lista *prox;
}Lista;

typedef struct fila{
    Lista* ini;
    Lista* fim;
}Fila;

Fila* fila_cria(){
    Fila *f=(Fila*)malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	return f;
}
void fila_imprime(Fila *f){
    Lista *t;
    int n=1;
    for(t=f->ini;t!=NULL;t=t->prox){
        printf("\tJogador %d: %s\n",n,t->info);
        n++;
    }
}
void fila_push(Fila *f,char* x){
    Lista *n = (Lista*)malloc(sizeof(Lista));
    strcpy(n->info,x);
    n->prox = NULL;

    if(f->fim != NULL)
    	f->fim->prox = n;
    else
    	f->ini=n;
    f->fim = n;
}
int fila_vazia(Fila* f){
    if(f->fim==NULL)
        return 1;
    else
        return 0;
}
char* fila_pop(Fila *f){
    Lista *t;
    char *x;
    if (fila_vazia(f)){
    	printf("Pilha vazia.\n");
    	exit (1);
	}
	t = f->ini;
	strcpy(x,t->info);
	f->ini = t->prox;
	if(f->ini==NULL)
		f->fim=NULL;
	free(t);
	return x;
}

void fila_libera(Fila *f){
	Lista *q = f->ini;
	while(q!=NULL){
		Lista *t=q->prox;
		free(q);
		q=t;
	}
	free(f);
}
