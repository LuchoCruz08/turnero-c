#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "turno.h"

typedef struct nodo {
    Turno vipd;
    struct nodo *sig;
} Nodo;

typedef struct {
    Nodo *acc;
    Nodo *aux;
    Nodo *cur;
} Lista;

void init(Lista *l) {
    l->acc = NULL;
    l->aux = NULL;
    l->cur = NULL;
}

int isEmpty(Lista l) {
    return l.acc == NULL;
}

int isFull(Lista l) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if(nuevo == NULL) {
        return 1;
    } else {
        free(nuevo);
        return 0;
    }
}

int isOos(Lista l) {
    return l.cur == NULL;
}

void reset(Lista *l) {
    l->cur = l->acc;
    l->aux = l->acc;
}

void forwards(Lista *l) {
    l->aux = l->cur;
    l->cur = l->cur->sig;
}

Turno copys(Lista l) {
    return l.cur->vipd;
}

void push(Lista *l, Turno t) {
    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));

    aux->vipd = t;
    aux->sig = NULL;

    if(isEmpty(*l)) {
        l->acc = aux;
        l->cur = aux;
    } else {

        if(l->cur == l->acc) {
            aux->sig = l->cur;
            l->acc = aux;
        } else {
            aux->sig = l->cur;
            l->aux->sig = aux;
        }
        l->cur = aux;
    }
}

void suppress(Lista *l) {
    if(l->cur == NULL) {
        return;
    }

    if(l->acc == l->cur) {
        l->acc = l->cur->sig;
        free(l->cur);
        l->cur = l->acc;
    } else {
        l->aux->sig = l->cur->sig;
        free(l->cur);
        l->cur = l->aux->sig;
    }
}

#endif // LISTA_H_INCLUDED
