/***************************************
* Trabalho 1-AV2 de Estrutura de Dados I
* Curso de Sistemas da informacão
* Aluno: Renan Xavier Calmon - matricula: 0050010824
* Listas
****************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
        int info;
        struct lista *prox;
}Lista;

Lista* lst_cria(){
      return NULL;
}
Lista* lst_insere(Lista *l1,int x){
      Lista *p=(Lista*)malloc(sizeof(Lista));
      p->info = x;
      p->prox = l1;
      return p;
}
void lst_imprime(Lista *l1){
      Lista *p;
      for(p=l1;p!=NULL;p=p->prox)
           printf("\tinfo: %d\n",p->info);
}
int lst_buscar(Lista *l1,int x){
    Lista *p;
    int indice=1;
    for(p=l1;p!=NULL;p=p->prox){
            if(x == p->info)
                return indice;
        indice++;
    }
    return -1;
}
Lista * lst_remove(Lista *l1,int x){
      Lista *p=l1,*t=l1->prox;
      if(l1->info==x){
            free(l1);
            return t;
      }
      while(t->info!=x && t->prox!=NULL){
            p=p->prox;
            t=t->prox;
            //printf("%d",t->info);
      }
      if(t->info==x){
            p->prox=t->prox;
            free(t);
      }
      return l1;
}
void lst_libera(Lista *l1){
	Lista *p;
	for(p=l1;p!=NULL;){
		Lista *t=p->prox;
		free(p);
		p=t;
	}
}
void lst_amostra(x){
    if(x>0)
         printf("\n   Achado no indice: %d\n\n",x);
    else
        printf("\n   Não foi encontrado!\n\n");
}
Lista * lst_separa(Lista *l1, int n){
    Lista *p=l1;
    Lista *t;
    while(p->info!=n && p!=NULL){
        p=p->prox;
    }
    if(p==NULL)
        return t;
    else{
        t=p->prox;
        p->prox=NULL;
        return t;
    }
}
