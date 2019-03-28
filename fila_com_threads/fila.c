#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <pthread.h>

typedef struct reg{
    char c;
} REGISTRO;

typedef struct noh{
    REGISTRO reg;
    struct noh* prox;
} NOH;

typedef struct lista{
    NOH* inicio;
    NOH* fim;
    int tamanho;
} LISTA;

LISTA* criarLista(){
    LISTA* lista = (LISTA*) malloc(sizeof(LISTA));
    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->fim = NULL;

    return lista;
}

int nElementos(LISTA lista){
    return (lista.tamanho);
}

void exibirLista(LISTA *lista){
    NOH* andador = lista->inicio;
    if(andador == NULL){
        printf("Lista vazia!\n");
    }
    while(andador != NULL){
        printf("%c ", andador->reg.c);
        andador = andador->prox;
    }
}

void inserir(LISTA *lista, REGISTRO reg){
    NOH* novo = (NOH*) malloc(sizeof(NOH));
    novo->reg = reg;
    novo->prox = NULL;
    if(lista->inicio == NULL)
        lista->inicio = novo;
    else
        lista->fim->prox = novo;
    lista->fim = novo;
    lista->tamanho++;
}

void remover(LISTA *lista, REGISTRO* reg){
    if(lista->inicio == NULL)
        printf("Lista vazia, não é possivel remover\n");
    *reg = lista->inicio->reg;
    NOH* apagar = lista->inicio;
    lista->inicio = lista->inicio->prox;
    free(apagar);
    if(lista->inicio == NULL)
        lista->fim = NULL;
}

int main()
{
    LISTA* l = criarLista();
    REGISTRO reg;
    reg.c = 'a';
    inserir(l, reg);
    reg.c = 'b';
    inserir(l, reg);
    reg.c = 'c';
    inserir(l, reg);
    reg.c = 'd';
    inserir(l, reg);
    reg.c = 'e';
    inserir(l, reg);
    remover(l, &reg);
    remover(l, &reg);
    exibirLista(l);
    printf("\n");
    return 0;
}
