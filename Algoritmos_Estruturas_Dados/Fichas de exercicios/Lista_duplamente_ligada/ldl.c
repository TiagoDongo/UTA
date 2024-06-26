#include "Item.h"
#include "LDL.h"

Item newItem(Item i){

    return strdup(i);

}
int itemCompare(Item i1, Item i2){

    return strcmp(i1,i2);

}
void showItem(Item i){
    printf("%s \n",i);
}
void deleteItem(Item i){

    free(i);
}

lista* create() {
    lista * l = malloc(sizeof(lista));
    l->first = l->last = NULL;
    return l;
}

void insertBegin(lista* l, Item i) {
    link n = malloc(sizeof(struct node));
    n->item = newItem(i);
    n->next = l->first;
    n->prev = NULL;

    if (l->first) l->first->prev = n;
    else l->last = n;

    l->first = n;
}

void insertEnd(lista* l, Item i) {
    link n = malloc(sizeof(struct node));
    n->item = newItem(i);
    n->next = NULL;
    n->prev = l->last;

    if (l->last)
    l->last->next = n;
    else
    l->first = n;

    l->last = n;
}

void show(lista* l) {
    link iter;
    for (iter = l->first; iter; iter = iter->next)
    showItem(iter->item);
}

void clear_lista(lista* l) {
    link tofree;

    while (l->first) {
        tofree = l->first;
        l->first = l->first->next;
        deleteItem(tofree->item);
        free(tofree);
    }
    free(l);
}

void removeFirst(lista* l, Item i) {
    link iter = l->first;
    int cmp;
    for (; iter && (cmp = itemCompare(iter->item, i)) < 0; iter = iter->next);

    if (iter && !cmp) {
        if (iter->prev)
            iter->prev->next = iter->next;
        else
            l->first = iter->next;

        if (iter->next)
            iter->next->prev = iter->prev;
        else l->last = iter->prev;

        deleteItem(iter->item);
        free(iter);
    }
}
