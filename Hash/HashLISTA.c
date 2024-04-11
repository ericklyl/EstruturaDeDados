#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TABELA HASH COM LISTA ENCADEADA

typedef struct No{
    int chave;
    struct No *proximo;
}No;

typedef struct Lista{
    No *inicio;
    int tam;
}Lista;


void inicializaLista(Lista *l){
    l->inicio = NULL;
    l->tam = 0;
}
void inserir_na_lista(Lista *l, int valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->chave = valor;
        novo->proximo = l->inicio;
        l->inicio = novo;
        l->tam++; // Incrementa o tamanho da lista
    }
    else{
        puts("\nFalha ao alocar memoria");
    }
}

void imprimir_lista(Lista *l){
    No *aux = l->inicio;
    printf("Tam: %d: ", l->tam); // Exibe o tamanho da lista corretamente
    while (aux){
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }
}

int buscar_na_lista(Lista *l, int valor){
    No *aux = l->inicio; //é criado um nó com o inicio da lista
    while (aux && aux->chave != valor){ //Enquanto o nó de busca, for diferente do valor que quero encontrar
        aux = aux->proximo; //Ele passa pro proximo e assim em diante
    }
    if(aux){ //Se  o aux tiver algum valor
        return aux->chave; //retornamos sua chave/valor
    }
    return 0;
    
}


//2 * 15 = 31(primo mais proximo)
#define TAM 31

void inicializarTabela(Lista t[]){
    int i;
    
    for(i = 0; i < TAM; i++){
        inicializaLista(&t[i]); // Preendchemos todas as posições da tabela com 0
    }
}

int funcaoHash(int chave){
    return chave % TAM; //Calcula o resto da divisão
}

void inserir(Lista t[], int valor){
    int id = funcaoHash(valor); //"id" é local/indice de qual posição o valor sera inserido na tabela
    inserir_na_lista(&t[id], valor);
}

int busca(Lista t[], int chave){
    int id = funcaoHash(chave); //geramos uma posição pro valor buscado
    printf("\nIndice gerado: %d\n", id);
    
    return buscar_na_lista(&t[id],chave);
}

void imprimir(int t[]){
    int i;
    for(i = 0; i < TAM; i++){
        printf("%2d = ", i);
        imprimir_lista(&t[i]);
        printf("\n");
    }
}



int main(){
    Lista tabela[TAM];
    int opcao, valor, retorno;
    inicializarTabela(tabela);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            printf("\tQual valor deseja inserir? ");
            scanf("%d", &valor);
            inserir(tabela, valor);
            break;
        case 2:
            printf("\tQual valor deseja buscar? ");
            scanf("%d", &valor);
            retorno = busca(tabela,valor);
            if(retorno != 0){
                printf("\tValor encontrado: %d\n", retorno);
            }
            else{
                printf("\tValor não encontrado!\n");
            }
            break;
        case 3:
            imprimir(tabela);
            break;
        default:
            printf("Opção invalida!\n");
        }
    }while(opcao != 0);
    

    return 0;
}