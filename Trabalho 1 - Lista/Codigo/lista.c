/***************************************
* Trabalho 1-AV2 de Estrutura de Dados I
* Curso de Sistemas da informacão
* Aluno: Renan Xavier Calmon - matricula: 0050010824
* Listas
****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    int x;
    Lista *l1=(Lista*)malloc(sizeof(Lista));   //Aloca dinâmicamente um espaço para o tipo Lista
    Lista *l2=(Lista*)malloc(sizeof(Lista));

    printf("\tBem-Vindo!\n\n");
    l1 = lst_cria();                           //Inicializa o primeiro valor da lista com NULL
    l2 = lst_cria();
    l1 = lst_insere(l1,10);                    //Insere valores a lista
    l1 = lst_insere(l1,20);
    l1 = lst_insere(l1,30);
    l1 = lst_insere(l1,40);
    l1 = lst_insere(l1,50);
    l1 = lst_insere(l1,60);
    l1 = lst_insere(l1,70);
    l1 = lst_insere(l1,80);
    l1 = lst_insere(l1,90);
    l1 = lst_insere(l1,100);
    //printf("\n\tLista Original:\n");
    //lst_imprime(l1);

    l2 = lst_separa(l1,20);                    //Separa a lista em duas, criando outra lista que receberá a segunda parte

    printf("\tLista 1:\n");
    lst_imprime(l1);                            //Mostra na tela os valores das listas

    printf("\n\tLista 2:\n");
    lst_imprime(l2);

	lst_libera(l1);           //Libera o espaço alocado
	lst_libera(l2);

    system("pause");
    return 0;
}
