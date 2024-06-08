#include "dfsSearch.h"
#include "../trees/binarytree.h"

#include <iostream>

using namespace std;

template <typename T>
NodeTree<T>* dfsSearch(NodeTree<T>* startingNode, T target)
{
    if (startingNode == nullptr) return nullptr;  // Caso base: nó nulo

    if (startingNode->payload == target) return startingNode;  // Encontrou o alvo

    // Buscar na subárvore esquerda
    NodeTree* result = dfsSearch(startingNode->ptrLeft, target);
    if (result != nullptr) return result;  // Encontrou na subárvore esquerda

    // Buscar na subárvore direita
    return dfsSearch(startingNode->ptrRight, target);  // Resultado da subárvore direita
}

// fazendo instanciação explícita para criar as funções do tipo utilizado em tempo de compilação
template NodeTree<int>* dfsSearch<int>(NodeTree<int>*, int);