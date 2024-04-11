#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TABELA HASH COM VETOR LINEAR

//2 * 15 = 31(primo mais proximo)
#define TAM 31

void inicializarTabela(int t[]){
    int i;
    
    for(i = 0; i < TAM; i++){
        t[i] = 0; // Preendchemos todas as posições da tabela com 0
    }
}

int funcaoHash(int chave){
    return chave % TAM; //Calcula o resto da divisão
}

//Função que insere na tabela hash (linear)
void inserir(int t[], int valor){
    int id = funcaoHash(valor); //"id" é local/indice de qual posição o valor sera inserido na tabela
    while (t[id] != 0){ //Enquanto a determinada posição da tabela estiver com 0, é pq tem valor lá (colisão)
        id = funcaoHash(id + 1); //Então ele passa pra proxima posição pra colocar um valor lá 
    }
    t[id] = valor; //Quando ele sair do while, é pq achou uma posição vazia, então ele coloca o valor lá
}

//Função que busca na tabela hash (linear)
int busca(int t[], int chave){
    int id = funcaoHash(chave); //geramos uma posição pro valor buscado
    printf("\nIndice gerado: %d\n", id);
    while (t[id] != 0){ //Verificamos se há algum valor naquela posição
        if(t[id] == chave){ //Caso haja, verificamos se é igual ao valor que buscamos
            return t[id];//Caso for o valor retornado
        }
        else{
            id = funcaoHash(id + 1); //Se não for ele, passamos pra prosição seguinte pra realizar o mesmo processo
        }
    }
    return 0;
}

void imprimir(int t[]){
    int i;
    for(i = 0; i < TAM; i++){
        printf("%d = %d\n", i, t[i]);
    }
}



int main(){
    int tabela[TAM], opcao, valor, retorno;
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