#include "dfsSearch.h"
#include "../trees/binarytree.h"

#include <iostream>

using namespace std;

template <typename T>
NodeTree<T>* dfsSearch(NodeTree<T>* startingNode, T target)
{
    if (startingNode == nullptr) return nullptr;

    if (startingNode->payload == target) return startingNode;

    NodeTree* result = dfsSearch(startingNode->ptrLeft, target);
    if (result != nullptr) return result;

    return dfsSearch(startingNode->ptrRight, target);
}

// fazendo instanciação explícita para criar as funções do tipo utilizado em tempo de compilação
template NodeTree<int>* dfsSearch<int>(NodeTree<int>*, int);