/**************************************
* Trabalho 4 de Estrutura de Dados I
* Curso de Sistemas da informacão
* Aluno: Renan Xavier Calmon - matricula: 0050010824
* Desafio de Josephus
***************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
    struct lista *ant;
}Lista;

typedef struct circular{
    Lista* ini;
    Lista* aux;
    Lista* fim;
}Circ;

Circ* circ_cria(){                          //Inicializa círculo
    Circ *f=(Circ*)malloc(sizeof(Circ));
	f->aux = f->ini = f->fim = NULL;
	return f;
}
void circ_imprime(Circ *f){
    Lista *t;
    int n=1;
    for(t=f->ini;t!=f->fim;t=t->prox){
        printf("\tSoldado %d: %d\n",n,t->info);
        n++;
    }
    printf("\tSoldado %d: %d\n",n,t->info);
}
void circ_push(Circ *f,int x){
    Lista *n = (Lista*)malloc(sizeof(Lista)),*t;

    n->info = x;

    if(f->fim != NULL)
    	f->fim->prox = n;
    else
    	f->ini = n;
    t = f->fim;                         //variável do tipo lista segura valor anterior ao fim
    f->fim = n;
    f->fim->ant = t;
    f->ini->ant = f->fim;               //anterior do início recebe o final da lista
    f->aux = n->prox = f->ini;          //próximo valor após final da lista recebe o inicio da lista
}
int circ_vazia(Circ* f){
    if(f->fim==NULL)
        return 1;
    else
        return 0;
}
int circ_pop(Circ *f){
    Lista *t;
    int x;
    if (circ_vazia(f)){
    	printf("Lista vazia.\n");
    	exit (1);
	}
	t = f->aux;
	x = t->info;
	//printf("\n %d\n",t->prox->info);
	t->ant->prox = f->aux = t->prox;      //Valor atual é tirado da lista
	t->prox->ant = t->ant;

	if(f->fim==f->ini){                   //Se o último valor é retirado, então temos uma lista vazia
		f->aux=NULL;
		f->fim=NULL;
		f->ini=NULL;
	}
	if(t==f->fim)                         //Se o valor atual retirado for igual ao fim ou início da lista, então seu valor é
        f->fim = f->fim->ant;             //atualizado
    if(t==f->ini)
        f->ini = f->ini->prox;
	free(t);
	return x;
}

void circ_libera(Circ *f){
	Lista *q = f->ini;
	while(q!=f->fim){
		Lista *t=q->prox;
		free(q);
		q=t;
	}
	free(f->fim);
}

int mov_aux(Circ* f,int x){              //Move o auxiliar para a direita
    int i;
    for(i=0;i<x;i++)
        f->aux = f->aux->prox;
    return f->aux->info;
}
int mov_aux_rev(Circ* f,int x){          //Move o auxiliar para a esquerda
    int i;
    for(i=0;i<x;i++)
        f->aux = f->aux->ant;
    return f->aux->info;
}
