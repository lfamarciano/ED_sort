#pragma once

using std::cin;
using std::cout;
using std::endl;
using std::string;

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

