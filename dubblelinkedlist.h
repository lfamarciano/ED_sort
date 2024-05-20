#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#pragma once

typedef struct Node{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void displayList(Node*);
void deleteList(Node**);
void swapValue(int&, int&); //adicionei aqui para não ter que ficar definindo toda vez

#endif