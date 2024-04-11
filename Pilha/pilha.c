//Insere e remove elmentos pelo topo

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Criando um nó que nele vai conter um valor e vai apontar pro proximo nó
typedef struct No{
     int dado;
     struct No *proximo; 
}No;

//Criando uma estrutura de pilha
typedef struct pilha{
    No *topo;
}pilha;

//Aqui estou criando uma pilha vazia (aponta pra nulo)
void inicializaPilha(pilha *p){
    p->topo = NULL;
}

//Função que empilha elementos na pilha
void empilha(int dado, pilha *p){
    No *ptr = (No*) malloc(sizeof(No));

    if(ptr){
        puts("ALOCADO COM SUCESSO!");
        ptr->dado = dado; //o valor no meu novo nó é o elemento que foi passado pra função
        ptr->proximo = p->topo; //O proximo elemento desse novo Nó é o elemento que estava no topo
        p->topo = ptr;  //O Topo agora aponta pro novo elemento inserido
    }
    else{
        puts("ERRO AO ALOCAR MEMORIA!");
    }
    puts("Empilhado com sucesso!");
}

//Função que desempilha/remove elementos da pilha
int desempilha(pilha *p){
    No *ptr = p->topo;
    int dado;
    if(ptr == NULL){
        puts("Pilha vazia\n");
        return -1;
    }
    else{
        p->topo = ptr->proximo; // O topo vai apontar pro proximo elemento
        ptr->proximo = NULL; //Proximo elemento do nó a ser removido vai ser nulo
        dado = ptr->dado; //O meu dado vai ser igual ao valor a ser removido
        free(ptr); //Como o elemento foi removido, não tem mais utilidade, então eu desaloco ele da memória
        return dado; //retorno o valor que foi removido
    }
}

void imprimirpilha(pilha *p){
    No *ptr= p->topo;
    if(ptr){
        
        while(ptr != NULL){
            printf("%d ", ptr->dado);
            ptr = ptr-> proximo;
        }
        printf("\n");
    }
    else{
        puts("Pilha vazia!\n");
    }
}
int main() {
    pilha *p1 = (pilha*) malloc(sizeof(pilha));
    int op, val;
    if (p1) {
        inicializaPilha(p1);

        do {
            printf("Quer empilhar ou desempilhar um valor da pilha ou sair do programa [1/2/3]? ");
            scanf("%d", &op);

            if (op == 1) {
                printf("Insira o valor a ser empilhado: ");
                scanf("%d", &val);
                empilha(val, p1);
                imprimirpilha(p1);
            } else if (op == 2) {
                desempilha(p1);
                imprimirpilha(p1);
            } else if (op == 3) {
                puts("Encerrando o programa...");
                break;  // Sai do loop e encerra o programa
            } else {
                puts("Opção inválida!");
            }
        } while (1);  // Loop infinito (só será encerrado quando o usuário escolher a opção 3)
    } else {
        puts("Erro ao alocar pilha!");
    }
}
