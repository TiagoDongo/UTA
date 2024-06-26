#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
typedef char* Item;

typedef struct node *link;

struct node {
    Item item;
    link next;
    link prev;
};

typedef struct {
    link first;
    link last;
} lista;


#endif // ITEM_H_INCLUDED
