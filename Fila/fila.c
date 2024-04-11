#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No{
    int valor;
    struct No *proximo;
}No;

typedef struct fila{
    No *inicio;
    No *fim;
}fila;


void inicializafila(fila *f){
    f->inicio = NULL;
    f->fim = NULL;
}

void enfileira(int valor, fila *f){
    No *ptr = (No*) malloc(sizeof(No));
    if(ptr == NULL){ //Caso a fila esteja vazia
        puts("ERRO AO ALOCAR MEMORIA");
        return;
    }else{
        ptr->valor = valor; //O valor passado pra função é atribuido ao novo nó
        ptr->proximo = NULL; // O proximo valor do Nó vai apontar pra nulo
        if(f->inicio == NULL){ //Caso o inicio seja nulo, ou seja, o nó a ser inserido sera o primeiro e unico elemento
            f->inicio=ptr; //O inicio da pilha vai sera o novo nó
        } else{ //Caso já tenham elementos na pilha 
            f->fim->proximo = ptr; //O proximo do fim vai apontar pro novo nó
        }
        f->fim = ptr;
    }
}

int desenfileira(fila *f){
    No *ptr = f->inicio;
    int dado;
    if(ptr != NULL){
        f->inicio = ptr->proximo; //O inicio da fila agora vai ser próximo elemento depois do inicio (o 2º passara a ser o 1º)
        ptr->proximo = NULL; //o proximo agora nó sera nulo
        dado = ptr->valor; //Uma variavel foi criada pra armazenar o valor do nó que sera apagado, aqui ela recebe o valor
        free(ptr); //O nó desenfileirado é desalocado (ele era o primeiro item da fila)
        if(f->inicio == NULL){ //Caso o inicio/primeiro da fila for nulo
            f ->fim = NULL; // O fim tambem sera nulo, ou seja, lista vazia
        }
        return dado;
    }else{
        puts("Fila vazia\n");
        return;
    }
}

void imprimefila(fila *f){
    No *ptr = f->inicio;
    if(ptr != NULL){ //se tiver elementos
        while (ptr != NULL){ //Enquanto estiver elementos ele percorre a lista
            printf("%d ", ptr->valor); //Ele imprime cada um dos valores dos nós
            ptr = ptr->proximo; //Percorre
        } 
    } else{
        printf("Fila vazia\n");
        return;
    }
}

int main(){
    fila *f1 = (fila*) malloc(sizeof(fila));
    if(f1 == NULL){
        printf("ERRO AO ALOCAR FILA\n");
        exit(-1);
    }
    else{
        inicializafila(f1);

        enfileira(10, f1);
        enfileira(20, f1);
        enfileira(30, f1);

        imprimefila(f1);
        puts("\n");

        desenfileira(f1);

        imprimefila(f1);
        puts("\n");

        enfileira(79,f1);
        imprimefila(f1);
    }
}