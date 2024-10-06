#include "item.h"
#include "lista.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct no_ NO;

struct no_ {
    ITEM* valor;
    NO* proximo;
    NO* anterior;
};

struct lista_ {
    int tamanho;
    NO* inicio;
    NO* fim;
    bool ordenada;
};

//Utilidades
NO* _criar_no(ITEM* item) {
    NO* no = (NO*) malloc(sizeof(no));

    if (no != NULL) {
        no->anterior = NULL;
        no->valor = item;
        no->proximo = NULL;
    }

    return(no);
}

void _apagar_no(NO* no) {
    if (no == NULL) {
        return;
    }

    _apagar_no(no->proximo);
    no->anterior = NULL;
    item_apagar(&no->valor);
    free(no);
}


LISTA* lista_criar(bool ordenada) {
    LISTA* lista = (LISTA*) malloc(sizeof(LISTA));

    if (lista == NULL) {
        lista->tamanho = 0;
        lista->inicio = NULL;
        lista->fim = NULL;
    }

    return(lista);
}

bool lista_apagar(LISTA** lista) {
    if (*lista == NULL) {
        return(false);
    }

    _apagar_no((*lista)->inicio);

    free(*lista);
    *lista = NULL;

    return(true);
}

bool lista_inserir(LISTA* lista, ITEM* item) {
    if (lista_cheia(lista)) {
        return(NULL);
    }

    NO* no = _criar_no(item);
    if (no == NULL) {
        return(false);
    }

    if (lista->tamanho == 0) {
        lista->inicio = no;
        lista->fim = no;
        lista->tamanho++;

        return(true);
    }

    if (!lista->ordenada) {
        //inserir no fim (mais facil?)
        lista->fim->proximo = no; //coloca no fim
        no->anterior = lista->fim; //conecta com o atual fim
        lista->fim = no; //se torna o atual fim
        lista->tamanho++;

        return(true);
    }

    //aqui deu ruim! é ordenada

    //verificar se insere no incio ou no fim!

    NO* aux = lista->inicio;
    while (aux != NULL) {
        if (item_get_chave(aux->valor) < item_get_chave(item)) {
            //achou a posição
            //conectar ao proximo (aux->proximo)
            no->proximo = aux->proximo; 
            aux->proximo->anterior = no;

            //conectar ao anterior (aux)
            aux->proximo = no;
            no->anterior = aux;
        }
    }

    return(true);
}

ITEM* lista_remover(LISTA* lista, int chave) {
    if (lista_vazia(lista)) {
        return(NULL);
    }

    ITEM* item = NULL;
    NO* aux = lista->inicio;

    while (aux != NULL) {
        if (item_get_chave(aux->valor) == chave) {
            item = aux->valor;

            //verifica se é o primeiro (se não for, há um anterior)
            if (aux == lista->inicio) {
                lista->inicio = aux->proximo; //ele é o primeiro e o lista->inicio é o proximo
            } else {
                aux->anterior->proximo = aux->proximo;
            }

            //verifica se é o último (se não for, há um próximo) 
            if (aux == lista->fim) {
                lista->fim = aux->anterior //ele é o ultimo e o lista->fim é o anterior
            } else {
                aux->proximo->anterior = aux->anterior; 
            }

            break;
        }

        if (lista->ordenada && item_get_chave(aux->valor) > chave) {
            //já passou da chave e não achou então ela não existe!
            break;
        }

        aux = aux->proximo;
    }

    if (aux != NULL) {
        aux->proximo = NULL;
        aux->anterior = NULL;
        free(aux);
    }

    return(item);
}

bool lista_cheia(LISTA* lista) {
    if (lista == NULL) {
        return(true);
    }

    //alocar nó e ver se é null (se for, não tem espaço)
    NO* no = (NO*) malloc(sizeof(NO));
    if (no == NULL) {
        return(true); //heap cheia
    }

    free(no);
    return(false);
}

bool lista_vazia(LISTA* lista) {
    if (lista == NULL) {
        return(false);
    }

    return(lista->tamanho == 0);
}

int lista_tamanho(LISTA* lista) {
    if (lista == NULL) {
        return(-1);
    }

    return(lista->tamanho);
}

void lista_imprimir(LISTA* lista) {
    if (lista == NULL) {
        return;
    }

    NO* aux = lista->inicio;
    while (aux != NULL) {
        printf("%d\n", item_get_chave(aux->valor));
        aux = aux->proximo;
    }

    free(aux);
}