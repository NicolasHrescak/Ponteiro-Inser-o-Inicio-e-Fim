#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int valor;
    struct No* proximo;
}No;

typedef struct ListaEncadeada{
    struct No* inicio;
    struct No* fim;
}ListaEncadeada;


void adicionarNoInicio( ListaEncadeada *lista, int valor){
    struct No* novo_no = (struct No*)malloc(sizeof(struct No));
    novo_no->valor = valor;
    novo_no->proximo = lista->inicio;
    
    if(lista->inicio == NULL){
        lista->fim = novo_no;
    }
        
    lista->inicio = novo_no; 
}

void adicionarNoFim(ListaEncadeada *lista, int valor){
    struct No* novo_no = (struct No *)malloc(sizeof(struct No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    
    if(lista->inicio == NULL){
        lista->inicio = novo_no;
    }
    else{
        lista->fim->proximo = novo_no;
    }
    
    lista->fim = novo_no;
}

void imprimelista(ListaEncadeada *lista){
    struct No* atual = lista->inicio;
    while(atual != NULL){
        printf("%d ->", atual->valor);
        atual = atual->proximo;
    }
    printf(" NULL");
}

int main(){
    ListaEncadeada lista;
    lista.inicio = NULL;
    lista.fim = NULL;
    
      adicionarNoInicio(&lista, 1);
    adicionarNoInicio(&lista, 2);
    adicionarNoInicio(&lista, 3);
    adicionarNoFim(&lista, 4);
    adicionarNoFim(&lista, 5);

    // Imprime a lista resultante
    imprimelista(&lista);
    
    return 0;
}

