#pragma once

#include <iostream>
#include <cstdlib> // Para a função malloc e free

typedef struct Node{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

// Funções Lista Duplamente Encadeada 
Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void displayList(Node*);
void deleteList(Node**);

