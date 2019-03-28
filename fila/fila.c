#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX 200

typedef struct produto{
    char nome[30];
}PRODUTO;

typedef struct{
    int nElem;
    PRODUTO vet[MAX];
}LISTA;

void criaLista(LISTA *lista){
    lista->nElem = 0;
}

void inserirFinal(LISTA *lista, PRODUTO prod){
    lista->vet[lista->nElem] = prod;
    lista->nElem +=1;
}

void inserirPos(LISTA *lista, PRODUTO prod, int pos){
    if(pos >=lista->nElem)
        inserirFinal(lista, prod);
    else{
        for (int i = lista->nElem; i < pos; i--) {
            lista->vet[i] = lista->vet[i-1];
        }
        lista->vet[pos] = prod;
        lista->nElem +=1;
    }
}

void inserirInicio(LISTA *lista, PRODUTO prod){
    inserirPos(lista, prod, 0);
}

void listar(LISTA *lista){
    PRODUTO prod;
    for (int i = 0; i < lista->nElem; i++) {
        prod = lista->vet[i];
        printf("%s ", prod.nome);
    }
}

int verificarTamanho(LISTA lista){
    return lista.nElem;
}   

void destruir(LISTA *lista){
    lista->nElem = 0;
}

void excluirPos(LISTA *lista, int pos){
    int i;
    if(pos < lista->nElem-1){
        if(pos == lista->nElem-1)
            lista->nElem = lista->nElem-1;
        else{
            for (i = pos; i < lista->nElem-1; i++) {
                lista->vet[i] = lista->vet[i+1];
            }
            lista->nElem -=1;
        }
    }
}

void excluirInicio(LISTA *lista){
    excluirPos(lista, 0);
}

PRODUTO *buscarEndereco(LISTA *lista, char nome[]){
    int i;
    for (i = 0; i < lista->nElem; i++) {
        if(strcmp (nome, lista->vet[i].nome) == 0)
            return &lista->vet[i];
    }
    return NULL;
}

int buscarPos(LISTA *lista, char nome[]){
   int i;
   for (i = 0; i < lista->nElem; i++) {
       if(strcmp(nome, lista->vet[i].nome) == 0)
           return i;
   }
   return -1;
}

int main(int argc, char *argv[])
{
    LISTA lista;
    PRODUTO prod;
    PRODUTO *pr;
    int op=0, pos=0, tam=0;
    char nome[30];
    do
    {
        printf("1 - Criar Lista\n");
        printf("2 - Inserir no final\n");
        printf("3 - Inserir na posição\n");
        printf("4 - Inserir no inicio\n");
        printf("5 - Listar\n");
        printf("6 - Verificar tamanho\n");
        printf("7 - Excluir posição\n");
        printf("8 - Excluir inicio\n");
        printf("9 - Destruir\n");
        printf("10 - Buscar nome retornar endereço\n");
        printf("11 - Buscar nome retornar posição\n");
        printf("12 - Sair\n");
        printf("opção: ");
        scanf("%d", &op);
        printf("\n\n");

        switch (op) {
            case 1:
                criaLista(&lista);
                break;
            case 2:
                printf("Digite o produto que deseja inserir: \n");
                scanf("%s", prod.nome);
                inserirFinal(&lista, prod);
                break;   
            case 3:
                printf("Digite o produto que deseja inserir: \n");
                scanf("%s", prod.nome);
                inserirInicio(&lista, prod);
                break;
            case 4:
                printf("Digite o produto que deseja inserir: \n");
                scanf("%s", prod.nome);
                printf("Digite a posição que deseja inserir: \n");
                scanf("%d", &pos);
                inserirPos(&lista, prod, pos);
                break;
            case 5:
                printf("Os elementos na lista são: \n");
                listar(&lista);
                printf("\n");
                break;
            case 6:
                tam = verificarTamanho(lista);
                printf("O tamanho da lista é: %d\n", tam);
                break;
            case 7:
                printf("Digite a posição que deseja excluir da lista: \n");
                scanf("%d", &pos);
                excluirPos(&lista, pos);
                break;
            case 8:
                excluirInicio(&lista);
                printf("Primeiro elemento da lista excluido!\n");
                break;
            case 9:
                destruir(&lista);
                printf("Lista destruida!\n");
                break;
            case 10:
                printf("Digite o nome do produto que deseja buscar o endereço: \n");
                scanf("%s", nome);
                pr = buscarEndereco(&lista, nome);
                if(pr != NULL)
                    printf("Produto: %s\n", pr->nome);
                else
                    printf("O produto buscado não existe na lista!\n");
                break;
            case 11:
                
                printf("Digite o nome do produto que deseja buscar a posição: \n");
                scanf("%s", nome);
                pos = buscarPos(&lista, nome);
                if(pos >= 0)
                    printf("posição: %d\n", pos);
                else
                    printf("O produto buscado não existe na lista!\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    }while(op != 12);
    return 0;
}
