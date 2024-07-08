#ifndef LDL_H_INCLUDED
#define LDL_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Item newItem(Item i);
int itemCompare(Item i1, Item i2);
void showItem(Item i);
void deleteItem(Item i);
lista* create();
void insertBegin(lista* l, Item i);
void insertEnd(lista* l, Item i);
void insertSorted(lista* l, Item i);
void show(lista* l);
void clear_lista(lista* l);
void removeFirst(lista* l, Item i);
void removeAll(lista* l, Item i);



#endif // LDL_H_INCLUDED
