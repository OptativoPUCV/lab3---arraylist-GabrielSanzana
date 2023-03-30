#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
    ArrayList *localList = malloc(sizeof(ArrayList));
    localList->data = malloc(sizeof(void*));
    localList->capacity = 2;
    localList->size = 0;
    return localList;
}

void append(ArrayList * l, void * data){
  if(l->capacity == l->size)
  {
    l->capacity=l->capacity*2;
    l->data = realloc(l->data,l->capacity);
  }
  
  l->data[l->size]=data;
  l->size++;
  
}

void push(ArrayList * l, void * data, int i){
  if(l->capacity == l->size)
  {
    l->capacity=l->capacity*2;
    l->data = realloc(l->data,l->capacity);
  }
  if(i>l->size)
    return;
  for(int k=l->size ; k>i ; k--)
      l->data[k] = l->data[k-1];
  l->data[i]=data;
  l->size++;
    
}

void* pop(ArrayList * l, int i){
    if(i>=l->size || abs(i)>l->size)
      return NULL;
    if(i<0)
     i+=l->size;
    void* aux=get(l,i);
    for(int k=i; k<l->size-1; k++)
      l->data[k] = l->data[k+1];
    l->size--;
    return aux;
  
    
}

void* get(ArrayList * l, int i){
    if(i>l->size || abs(i)>l->size)
      return NULL;
    if(i<0) 
      i+=l->size;
    return l->data[i];
      
    
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    l=createList();
}
