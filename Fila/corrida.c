#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct fila {
    No* inicio;
    No* fim;
} fila;

void inicializaFila(fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void enfileira(int valor, fila* f) {
    No* ptr = (No*)malloc(sizeof(No));
    if (ptr == NULL) {
        puts("ERRO AO ALOCAR MEMÓRIA");
        return;
    }
    else {
        ptr->valor = valor;
        ptr->proximo = NULL;
        if (f->inicio == NULL) {
            f->inicio = ptr;
        }
        else {
            f->fim->proximo = ptr;
        }
        f->fim = ptr;
    }
}

int desenfileira(fila* f) {
    No* ptr = f->inicio;
    int dado;
    if (ptr != NULL) {
        f->inicio = ptr->proximo;
        ptr->proximo = NULL;
        dado = ptr->valor;
        free(ptr);
        if (f->inicio == NULL) {
            f->fim = NULL;
        }
        return dado;
    }
    else {
        puts("Fila vazia\n");
        return -1; // Valor de erro
    }
}

void imprimeFila(fila* f) {
    No* ptr = f->inicio;
    if (ptr != NULL) {
        while (ptr != NULL) {
            printf("%d ", ptr->valor);
            ptr = ptr->proximo;
        }
        printf("\n");
    }
    else {
        printf("Fila vazia\n");
    }
}

int tamanhoFila(fila* f) {
    int contador = 0;
    No* p = f->inicio;
    while (p != NULL) {
        contador++;
        p = p->proximo;
    }
    return contador;
}

int filaVazia(fila* f) {
    return f->inicio == NULL;
}

int main() {
    setlocale(LC_ALL, "");

    fila f1, f2; //Duas filas são criadas
    inicializaFila(&f1); //Fila 1 é inicializada
    inicializaFila(&f2); //Fila 2 é inicializada

    int numCorredores, numRodadas; //As variaveis que vão receber a quantidade de corredores e rodadas são inicializadas
    printf("Qual o número de corredores e de rodadas? ");
    scanf("%d %d", &numCorredores, &numRodadas); //Aqui elas recebem os valores passados pelo usuario

    for (int i = 0; i < numCorredores; i++) { //Zeros são adicionados a fila 1 e fila 2
        enfileira(0, &f1);
        enfileira(0, &f2);
    }

    int equipe, drop;
    int rodadasF1 = numRodadas; //As rodadas são passadas pra novas variaveis
    int rodadasF2 = numRodadas;
    int contFila1 = 0, contFila2 = 0; //Aqui as variaveis que vão contar quantos elementos tem na fila são inicializadas com 0

    while (scanf("%d", &equipe) != EOF) { //O programa entra em um loop que lê o valor da equipe até o final da entrada.
        if (equipe == 1) {
            if (rodadasF1 > 1) { //O programa verifica se ainda há rodadas restantes para a equipe 1
                drop = desenfileira(&f1); // se sim, o primeiro elmeneto da fila1 é desenfileirado  
                enfileira(drop, &f1); // e adicionado novamente ao fim da fila 
                if (++contFila1 == numCorredores) { //Se o numero de elementos removidos da f1 for igual ao numero de corredores
                    rodadasF1--; //O numero de rodadas restantes é decrementado
                    contFila1 = 0; //e o contador é reiniciado
                }
            }
            else {
                desenfileira(&f1);
            }
        }
        else if (equipe == 2) { //Se a equipe for 2 o programa realiza as mesmas operações
            if (rodadasF2 > 1) {
                drop = desenfileira(&f2);
                enfileira(drop, &f2);
                if (++contFila2 == numCorredores) {
                    rodadasF2--;
                    contFila2 = 0;
                }
            }
            else {
                desenfileira(&f2);
            }
        }

        if (filaVazia(&f1) || filaVazia(&f2)) { //Caso as filas estiverem vazias ele sai do loop
            break;
        }
    }

    printf("%d %d\n", tamanhoFila(&f1), tamanhoFila(&f2)); //O tamanho das filas é imprimido

    // Liberar memória alocada
    No* ptr = f1.inicio;
    while (ptr != NULL) {
        No* temp = ptr;
        ptr = ptr->proximo;
        free(temp);
    }

    ptr = f2.inicio;
    while (ptr != NULL) {
        No* temp = ptr;
        ptr = ptr->proximo;
        free(temp);
    }

    return 0; //O programa retorna 0, indicando que foi executado com sucesso
}
