#include <stdio.h>
#include <stdlib.h>

void menu();
void escrever();
void ler();

typedef struct
{
    char nome[30];
    int idade;
} Pessoa;

void menu(){
    int op;
    Pessoa p;

    system("clear");
    printf("\n1 - Escrever\n2 - Ler\n0 - Sair\n");
    scanf("%d", &op);
    setbuf(stdin, NULL); // limpa buffer de teclado

    switch (op)
    {
        case 1:
            escrever(p);
            break;
        case 2:
            ler(p);
            break;
        case 0:
            exit(1);
        default:
            printf("\nOpção inválida\n");
            break;
    }
}

void escrever(Pessoa p){
    printf("Digite seu nome: ");
    /*setbuf(stdin, NULL);
    scanf("%[^\n]s", p.nome);*/
    fgets(p.nome, 30, stdin);

    printf("Digite sua idade: ");
    scanf("%d", &p.idade);

    FILE *f;
    f = fopen("data.bin", "ab"); //abre arquivo binario em modo de escrita
    
    fwrite(&p, sizeof(Pessoa), 1, f); // salva o arquivo
    fclose(f); // fecha o arquivo
}

void ler(Pessoa p){

    FILE *f = fopen("data.bin", "rb"); // abre o arquivo em modo de leitura

    if (!f) { // verifica se conseguiu abrir o arquivo
        printf("Erro ao tentar ler o arquivo.\n");
        exit(1);
    }

    while(fread(&p, sizeof(Pessoa), 1, f)) { // enquanto conseguir ler, ler e mostrar printf
        printf("Olá %s, você tem %d anos.\n", p.nome, p.idade);
    }

    fclose(f);
}

int main(){
    menu();
    return 0;
}