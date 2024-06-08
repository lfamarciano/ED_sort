#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#pragma once

template <typename T>
struct Node{
    T payload;
    Node* ptrNext;
    Node* ptrPrev;
};

template <typename T>
void swapValue(T& refValue1, T& refValue2);

template <typename T>
Node<T>* createNode(T payload);

template <typename T>
void displayList(Node<T>* node);

template <typename T>
void insertFront(Node<T>** head, T payload);

template <typename T>
void insertEnd(Node<T>** head, T payload);

template <typename T>
void deleteList(Node<T>** head);

template <typename T>
void deleteFirst(Node<T>** head);

#endif