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

//Prototipo das funcoes
LISTA* criarLista();
int nElementos(LISTA *lista);
void exibirLista(LISTA *lista);
void inserir(LISTA *lista, REGISTRO reg);
void remover(LISTA *lista, REGISTRO* reg);
void* inserirComThread(void* ptr);
void* removerComThread(void* ptr);

// Variaveis globais
LISTA* l;
REGISTRO reg;


LISTA* criarLista(){
    LISTA* lista = (LISTA*) malloc(sizeof(LISTA));
    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->fim = NULL;

    return lista;
}

int nElementos(LISTA* lista){
    return (lista->tamanho);
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
    lista->tamanho--;
    if(lista->inicio == NULL)
        lista->fim = NULL;
}


void* inserirComThread(void* ptr){
    char* message;
    message = (char*) ptr;
    printf("%s inserindo na fila\n", message);
    reg.c = 'x';
    inserir(l, reg);
}

void* removerComThread(void* ptr){
    char* message;
    message = (char*) ptr;
    printf("%s removendo da fila\n", message);
    remover(l, &reg);
}

int main()
{
//    LISTA* l = criarLista();
//    REGISTRO reg;
//    int tam;
    l = criarLista();
    pthread_t produtor, consumidor;
    char* message1 = "Produtor ";
    char* message2 = "Consumidor ";

    pthread_create(&produtor, NULL, inserirComThread, (void*) message1);
    pthread_create(&consumidor, NULL, removerComThread, (void*) message2);
    
    pthread_join(produtor, NULL);
    pthread_join(consumidor, NULL);

    printf("Lista : ");
    exibirLista(l);
    printf("\n");
    /*
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
    tam = nElementos(l);
    printf("Tamanho da lista: %d\n", tam);
    printf("\n");
    */
    return 0;
}
