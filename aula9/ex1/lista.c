#include "item.h"
#include "lista.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct no_ NO;

struct no_ {
    ITEM* valor;
    NO* proximo;
};

struct lista_ {
    int tamanho;
    NO* inicio;
    NO* fim;
    bool ordenada;
};

//Utilidades
NO* _criar_no(ITEM* item) {
    NO* no = (NO*) malloc(sizeof(NO));

    if (no != NULL) {
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
    item_apagar(&no->valor);
    free(no);
}

bool _inserir_fim(LISTA* lista, ITEM* item) {
    NO* no = _criar_no(item);
    if (no == NULL) {
        return(false);
    }

    lista->fim->proximo = no;
    lista->fim = no;
    lista->tamanho++;

    return(true);
}

bool _inserir_posicao(LISTA* lista, ITEM* item) {
    NO* no = _criar_no(item);
    if (no == NULL) {
        return(false);
    }

    //caso especial (tamanho = 1)
    if (lista->tamanho == 1) {
        if (item_get_chave(lista->inicio->valor) > item_get_chave(item)) {
            no->proximo = lista->inicio;
            lista->inicio = no;
            lista->tamanho++;

            return(true);
        }
    }

    //caso especial (maior que o fim->valor)
    if (item_get_chave(lista->fim->valor) < item_get_chave(item)) {
        return(_inserir_fim(lista, item));
    }

    //se chegou aqui, então será inserido no meio!!
    NO* aux = lista->inicio;
    while (aux != NULL && aux->proximo != NULL) {
        if (item_get_chave(aux->proximo->valor) > item_get_chave(item)) {
            no->proximo = aux->proximo;
            aux->proximo = no;
            lista->tamanho++;

            return(true);
        }
    }
}


ITEM* _busca_sequencial(LISTA* lista, int chave) {
    NO* aux = lista->inicio;
    ITEM* item = NULL;

    while (aux != NULL && aux->proximo != NULL) {
        if (item_get_chave(aux->valor) == chave) {
            item = aux->valor;
            free(aux);

            return(item);
        }

        aux = aux->proximo;
    }

    free(item);
    return(NULL);
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

    //se vazia, inicio = fim
    if (lista->tamanho == 0) {
        NO* no = _criar_no(item);
        if (no == NULL) {
            return(false);
        }

        lista->inicio = no;
        lista->fim = no;
        lista->tamanho++;

        return(true);
    }
 
    if (lista->ordenada) {
        //inserir na posição correta
        return(_inserir_posicao(lista, item));
    } else {
        //inserir fim
        return(_inserir_fim(lista, item));
    }
   
}

ITEM* lista_remover(LISTA* lista, int chave) {
    if (lista_vazia(lista)) {
        return(NULL);
    }

    ITEM* item = NULL;
    NO* aux = NULL;
    NO* aux2 = NULL;

    //caso especial (item esta no inicio)
    if (item_get_chave(lista->inicio->valor) == chave) {
        aux = lista->inicio;
        item = aux->valor;

        lista->inicio = aux->proximo;
        lista->tamanho--;

        free(aux);
        return(item);
    }

    aux = lista->inicio;
    while (aux != NULL && aux->proximo != NULL) {
        aux2 = aux->proximo;
        if (item_get_chave(aux2->valor) == chave) {
            item = aux2->valor;

            aux->proximo = aux2->proximo; //tá certo isso?
            lista->tamanho--;

            free(aux2);
            return(item);
        }

        aux = aux->proximo;
    }

    if (aux != NULL) {
        free(aux);
    }

    if (aux2 != NULL) {
        free(aux2);
    }

    return(NULL);
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