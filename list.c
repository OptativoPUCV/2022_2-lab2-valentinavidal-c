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
    return NULL;
  }
  
}

void * nextList(List * list) {
  if (list == NULL) return NULL;
  if(list->current !=NULL){
    if(list->current == list->tail){
      return NULL;
    }else{
      list->current=list->current->next;
      return list->current->data;
    }
  }else{
    return NULL;
  }
}

void * lastList(List * list) {
  if(list==NULL) return NULL;
  if(list->tail!=NULL){
    list->current = list->tail;
    return list->tail->data;
  }else{
    list->current=list->tail;
    return NULL;
  }
}

void * prevList(List * list) {
  if(list==NULL) return NULL;
  if(list->current!=NULL){
    if(list->current == list->head){
      return NULL;
    }else{
      list->current = list->current->prev;
      return list->current->data;
    }
  }else{
    return NULL;
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
  Node *newNode = createNode(data);
  if (list->current!=NULL){
    if (list->current != list->tail){
      newNode->next = list->current->next;
      newNode->prev = list->current;
      list->current->next = newNode;
    }else{
      if(list->tail!=NULL){
        newNode->prev = list->tail;
        list->current->next = newNode;
        list->tail = newNode;
      }
    }
  }
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
  if (list == NULL) return NULL;
  void *current = list->current->data;
//  Node *newNode = createNode(current->data);
  else{
    if (list->head == list->current){
      list->current=list->current->next;
      list->head = list->current;
      free(list->head->prev);
      return newNode->data;
    }else if(list->current==list->tail){
      list->current->prev = list->tail;
      free(list->current);
      return newNode->data;
    }else{
      list->current->prev->next = list->current->next;
      list->current->next->prev = list->current->next;
      free(list->current);
      return newNode->data;
    }
  }
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}