#include <stdio.h>
#include <stdlib.h>

typedef struct arvb {
    int info;
    struct arvb *esq;
    struct arvb *dir;
} Arvb;

Arvb *criaarvb () {
    return NULL;
}

int estavazia (Arvb *a) {
    return (a==NULL);
}

Arvb *retira(Arvb *a, int v) {
    if (estavazia(a)) {
        return NULL;
    } else if (v < a->info) {
        a->esq = retira(a->esq,v);
    } else if (v > a->info) {
        a->dir = retira(a->dir,v);
    } else {
        if ( a->esq == NULL && a->dir == NULL) {
            free(a);
            a=NULL;
        }  else if ( a->esq == NULL ) {
            Arvb *aux = a->dir;
            free(a);
            a = aux;
        }  else if ( a->dir == NULL ) {
            Arvb *aux = a->esq;
            free(a);
            a = aux;
        } else {
            Arvb *aux = a->esq;
            while(aux->dir!=NULL) {
                aux = aux->dir;
            }
            a->info=aux->info;
            aux->info=v;
            a->esq = retira(a->esq,v);
        }
    }
    return a;
}
