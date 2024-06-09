#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "../doubleLinkedList/dubblelinkedlist.h"
#include <iostream>

#pragma once

// Estrutura do nó da árvore
template <typename T>
struct NodeTree
{
    T payload;
    NodeTree* ptrLeft;
    NodeTree* ptrRight;

};

template <typename T>
NodeTree<T>* createNodeTree(T);

template <typename T>
NodeTree<T>* insertNodeTree(NodeTree<T>*, T);

template <typename T>
void deleteTree(NodeTree<T>**);

template <typename T>
void bfsTraversal(NodeTree<T>*);

template <typename T>
NodeTree<T>* bfsSearch(NodeTree<T>*, T);

template <typename T>
NodeTree<T>* dfsSearch(NodeTree<T>*, T);

// #include "binarytree.tpp"

#endif // BINARYTREE_H