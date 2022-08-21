#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List * list = (List*)malloc(sizeof(List));
  return list;
}

void * firstList(List * list) {
  if (list == NULL) return NULL;
  if(list->current!=NULL){
//    list->current->prev=list->current->next->prev;
//    list->current->next=list->current->prev->next;
    list->current = list->head;
    return list->current->data;
  }else{
    return list->head->data;
  }
  
}

void * nextList(List * list) {
  if (list == NULL) return NULL;
  if(list->current !=NULL){
    return list->current->next->data;
    list->current=list->current->next;
  }else{
    return list->current->data;
  }
}

void * lastList(List * list) {
  if(list==NULL) return NULL;
  if(list->tail!=NULL){
    return list->tail;
    list->current = list->tail;
  }else{
    return list->current->data;
  }
}

void * prevList(List * list) {
  if(list==NULL) return NULL;
  if(list->current!=NULL){
    return list->current->prev->data;
    list->current = list->current->prev;
  }else{
    return list->current->data;
    list->current = list->current->prev;
  }
}

void pushFront(List * list, void * data) {
  Node *newNode = createNode(data);
  if(list->head!=NULL){
    list->head->prev = newNode;
    newNode->next=list->head;
    list->head = newNode;
  }else{
    list->head = newNode;
    list->tail = newNode;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  Node *current = list->current;
  if (current == NULL) return NULL;
  if (list->head == current){
    current->next->prev = NULL;
    list->head = current->next;
  }else{
    current->prev->next = list->current->next;
    current->next->prev = list->current->next;
  }
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}