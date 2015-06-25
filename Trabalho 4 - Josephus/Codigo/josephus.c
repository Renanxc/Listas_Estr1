/**************************************
* Trabalho 4 de Estrutura de Dados I
* Curso de Sistemas da informac�o
* Aluno: Renan Xavier Calmon - matricula: 0050010824
* Desafio de Josephus
***************************************/

#include <locale.h>
#include <time.h>
#include "ListaCircular.h"

#define cap 10

void insere_soldados(Circ* f);
int sorteio_chapeu();
void retira_soldado(Circ* f, int s);
void display(Circ* f){                                //Fun��o para mostrar a parte visual do programa
    printf("\n\t Bem Vindo ao Problema de Josephus!");
    printf("\n\n  Um grupo de soldados est� cercado e n�o h� esperan�a de vit�ria,\n");
    printf(" por�m existe somente um cavalo dispon�vel para escapar e buscar por refor�os.\n");
    printf(" Para determinar qual soldado deve escapar para encontrar ajuda, eles formam um\n");
    printf(" c�rculo e sorteiam um n�mero de um chap�u.\n\n");
    if(f->aux->prox!=f->aux)                          //Se houver mais de um soldado imprime os restantes, do contr�rio apenas
        circ_imprime(f);                              //o vencedor
    else
        printf("\n\tVencedor: %d\n\n",circ_pop(f));
    printf("\n");
}
int main(){
    int soldado, sorteado;
    Circ *f;

    system("COLOR F0");                               //Deixa o fundo branco
	setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    f = circ_cria();                                  //Cria lista circular
    insere_soldados(f);                               //Insere 10 soldados, cada um com identificador �nico
    soldado = mov_aux(f, rand() % 11);                //� selecionado o primeiro soldado aleatoriamente

    display(f);
    printf("\n Soldado Selecionado: %d\n\n",soldado);
    system("pause");
    system("cls");                                    //Limpa a tela para uma melhor experi�ncia
    do{
        display(f);

        sorteado = sorteio_chapeu();
        retira_soldado(f,sorteado);
        system("pause");
        system("cls");
    }while(f->aux->prox!=f->aux);                    //Enquanto n�o restar apenas um soldado, continuar� retirando

    display(f);
    circ_libera(f);
    system("pause");
    return 0;
}
void insere_soldados(Circ* f){
    int i,n;

    circ_push(f,(rand()%4)+1);                       //Inicia a lista de soldados com um id de 1 a 4
    for(i=1;i<cap;i++){
        do{
            n = rand()%(10+i*2);                     //Para que cada soldado tenha uma id aleat�ria sem repeti��o em
        }while(f->aux->ant->info >= n);              //ordem crescente, � gerado sempre um n�mero maior que o anterior
        circ_push(f,n);
    }
}
int sorteio_chapeu(){
    int s;
    do{
        s = (rand()%19)-9;                           //� gerado um n�mero aleat�rio de 0~18, e subtra�do por 9, para assim
    }while(s==0);                                    //termos -9~9 e diferente de 0
    printf(" N�mero Sorteado: %d\n",s);
    return s;
}
void retira_soldado(Circ* f, int s){
    if(s>0)                                          //n�mero positivo anda para direita
        mov_aux(f,s);
    else{                                            //negativo para a esquerda
        s *=(-1);
        mov_aux_rev(f,s);
    }
    printf("\n Soldado Retirado: %d\n\n",circ_pop(f));
}
