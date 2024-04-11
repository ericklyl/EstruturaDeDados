//Implemente uma função que ordena uma lista de inteiros. A assinatura da função deve ser:

//void ordena_lista(List *l)

//Dica: utilize uam lista auxiliar e as funções de inserir e remover elementos da lista.

#include <stdlib.h>
#include <stdio.h>

typedef struct No{
  int valor;
  struct No *proximo;
  struct No *anterior;
}No;

void botainicio(No **lista, int num){
  No* novo = malloc(sizeof(No));
  if(novo){ //CASO TENHA SIDO ALOCADO
      puts("ALOCADO COM SUCESSO!");
      novo->valor = num; //É O VALOR QUE QUERO INSERIR
      novo->proximo = *lista;
      novo->anterior = NULL;
      *lista = novo;
    if(*lista){
      (*lista)->anterior = novo;
      puts("O ELEMENTO FOI INSERIDO COM SUCESSO NA LISTA!");
    }
    *lista = novo;
  }
  else{
  puts("ERRO AO ALOCAR ELEMENTO");}
}

void botafim(No **lista, int num){
    No* novo, *aux =malloc(sizeof(No));
    if(novo){
        puts("ALOCADO COM SUCESSO!");
        novo->valor = num;
        novo->proximo = NULL;
        if(*lista == NULL){
            *lista = novo;
            puts("ULTIMO E UNICO ELEMENTO INSERIDO!");
            novo->anterior = NULL;
        }        
        else{
            aux = *lista; //UMA LISTA AUXILIAR É CRIADA, SENDO ELA UMA CÓPIA DA LISTA ORIGINAL
            while(aux->proximo){ //Percorre a lista auxiliar
                aux->proximo;
            }
            aux ->proximo = novo; //Ao chegar ao fim da lista (o proximo é nulo) o proóximo elemetno vai se tornar o novo elemento
            novo -> anterior = aux; //E os elementos anteriores a ele vão ser o resto da lista
            puts("ULTIMO ELEMENTO INSERIDO COM SUCESSO!");
            {
                /* code */
            }
            
        }
    }
}

botanomeio(No **lista, int num, int ant){
    No *novo, *aux = malloc(sizeof(No));

    if(novo){
        puts("ALOCADO COM SUCESSO!");
        novo->valor = num;
        if(*lista == NULL){
            novo ->proximo = NULL;
            novo ->anterior = NULL;
            *lista = novo;
            puts("ALOCADO NO MEIO COM SUCESSO SENDO O UNICO ELEMENTO!");
        }
        else{
            aux = *lista;
            while (aux-> valor != ant && aux ->proximo){
                aux = aux->proximo;
            }
            novo ->proximo = aux->proximo;
            aux->proximo = novo;
            novo->anterior = aux;
            aux ->proximo = novo; //ESTRANHO, REPETE O MESMO COMANDO DA LINHA 79
            puts("ALOCADO COM SUCESSO!");
            
                /* code */
            
            
        }
    }
}

removerdalista(No **lista, int num){
    No *aux, *remover = NULL;

    if(*lista){
        if((*lista)->valor == num){
            remover = *lista; //uma copia da lista é criada
            *lista = remover->proximo;// Alista começa depois do primeiro elemento caso ele for o que eu quero remover
            if(*lista){
                (*lista)->anterior = NULL;
            }
            else{
                aux = *lista; //Aux é uma cópia da lista
                while(aux ->proximo && aux->proximo ->valor != num){
                    aux = aux->proximo;
                }
                if(aux->proximo){
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                    if(aux->proximo){
                        aux->proximo->anterior = aux;
                    }
                }
            }
        }
    }
}


int main(void) {
    int opcao, valor, ant;
    No* remover, * lista = NULL;
    int encerrar = 0;

    while (!encerrar) {
        printf("ESCOLHA UMA OPÇÃO:\n");
        printf("1- Quer adicionar um elemento ao início da lista? ");
        printf("\n2- Quer adicionar um elemento ao fim da lista? ");
        printf("\n3- Quer adicionar um elemento ao meio da lista? ");
        printf("\n4- Quer remover um elemento da lista? ");
        printf("\n5- Encerrar o programa\n");

        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 4) {
            printf("\nDigite um valor: ");
            scanf("%d", &valor);
        }

        switch (opcao) {
            case 1:
                botainicio(&lista, valor);
                break;
            case 2:
                botafim(&lista, valor);
                break;
            case 3:
                printf("Antes de qual valor você quer inserir o novo valor? ");
                scanf("%d", &ant);
                botanomeio(&lista, valor, ant);
                break;
            case 4:
                removerdalista(&lista, valor);
                break;
            case 5:
                encerrar = 1;
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }


        // Imprimir a lista ordenada
        No* atual = lista;
        while (atual != NULL) {
            printf("%d ", atual->valor);
            atual = atual->proximo;
        }

        printf("\n\n");
    }

    return 0;
}
//Nesse código, adicionei um loop while ao redor do bloco do main. O programa exibirá um menu de opções, onde você pode escolher entre várias operações na lista. Ao digitar a opção 5, o valor da variável encerrar é definido como 1, e o loop do main é encerrado, finalizando o programa.

//Certifique-se de compilar e executar o código em um ambiente apropriado para a linguagem C, pois o código fornecido é escrito nessa linguagem.






