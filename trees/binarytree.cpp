#include <iostream>
#include "binarytree.h"

using namespace std;

template <typename T>
NodeTree<T>* createNodeTree(T payload)
{
    // Aloca memória para um novo nó da árvore
    NodeTree<T>* tmp = (NodeTree<T>*) malloc(sizeof(NodeTree<T>));
    
    if (tmp == nullptr)
    {
        cerr << "Erro em createNode: malloc" << endl;
        exit(1);
    }
    
    // Inicializa os campos do nó
    tmp->payload = payload;
    tmp->ptrLeft = nullptr;
    tmp->ptrRight = nullptr;
    
    return tmp;
}
template <typename T>
NodeTree<T>* insertNodeTree(NodeTree<T>*  startingNode, T data)
{
    // Se o nó não existe, cria um novo nó com os dados fornecidos
    if(startingNode == nullptr)
    {
        return createNodeTree(data);
    }
    
    // Percorre a arvore até achar o local adequado para inserção
    if(data < startingNode->payload)
    {
        startingNode->ptrLeft = insertNodeTree(startingNode->ptrLeft, data);
    }
    else
    {
        startingNode->ptrRight = insertNodeTree(startingNode->ptrRight, data);
    }
    
    return startingNode;
}

// Deleta a árvore de forma recursiva
template <typename T>
void deleteTree(NodeTree<T>** startingNode) {
    if ((*startingNode)->ptrLeft != nullptr){
        deleteTree(&((*startingNode)->ptrLeft));
    }

    if ((*startingNode)->ptrRight != nullptr){
        deleteTree(&((*startingNode)->ptrRight));
    }

    delete (*startingNode);
    (*startingNode) = nullptr;
    return;
}



template <typename T>
void bfsTraversal(NodeTree<T>* startingNode)
{
    if (startingNode == nullptr) return;

    Node<NodeTree<T>*>* head = nullptr; // Cria a lista para inserção dos nós da árvore
    NodeTree<T>* currentNode = nullptr;

    insertEnd(&head, startingNode);

    // Travessia BFS
    while (head != nullptr)
    {   
        currentNode = head->payload;

        cout << currentNode -> payload << " ";
        
        // Insere os filhos do nó atual na lista
        if (currentNode->ptrLeft != nullptr)
        {   
            insertEnd(&head, currentNode -> ptrLeft);
        }
        
        if (currentNode->ptrRight != nullptr)
        {   
            insertEnd(&head, currentNode -> ptrRight);
        }

        // Remove o primeiro nó da lista (já passamos por ele)
        deleteFirst(&head);
    }

    cout << endl;

    deleteList(&head); //Apaga a lista, caso necessário

    return;
}

template <typename T>
NodeTree<T>* bfsSearch(NodeTree<T>* startingNode, T target)
{
    if (startingNode == nullptr) return nullptr;

    // Verifica se o primeiro nó é o alvo
    if (startingNode->payload == target) return startingNode;

    Node<NodeTree<T>*>* head = nullptr; // Cria a lista para inserção dos nós da árvore
    NodeTree<T>*  currentNode = nullptr;

    insertEnd(&head, startingNode);

    // Busca BFS
    while (head != nullptr)
    {   
        currentNode = head->payload;

        // Verifica se o nó tem o valor procurado
        if (currentNode->payload == target){
            break;
        }
        
        // Insere os filhos do nó atual na lista
        if (currentNode->ptrLeft != nullptr)
        {   
            insertEnd(&head, currentNode -> ptrLeft);
        }
        
        if (currentNode->ptrRight != nullptr)
        {   
            insertEnd(&head, currentNode -> ptrRight);
        }

        // Remove o primeiro nó da lista (já passamos por ele)
        deleteFirst(&head);
    }

    if(head == nullptr) return nullptr; //Se não encontrar, retorna um ponteiro nulo.

    deleteList(&head); //Apaga a lista, aqui é necessário

    return currentNode;
}

template <typename T>
NodeTree<T>* dfsSearch(NodeTree<T>* startingNode, T target)
{
    if (startingNode == nullptr) return nullptr;

    // Verifica se o primeiro nó é o alvo
    if (startingNode->payload == target) return startingNode;

    // Procura recursivamente
    NodeTree<T>* result = dfsSearch(startingNode->ptrLeft, target); //No ramo esquerdo
    if (result != nullptr) return result; 

    return dfsSearch(startingNode->ptrRight, target); //No ramo direito (nullptr se não encontrar)
}

// Fazendo instanciação explícita para criar as funções do tipo utilizado em tempo de compilação
template NodeTree<int>* createNodeTree(int);
template NodeTree<int>* insertNodeTree(NodeTree<int>*, int);
template void deleteTree(NodeTree<int>**);
template NodeTree<int>* bfsSearch(NodeTree<int>*, int);
template NodeTree<int>* dfsSearch<int>(NodeTree<int>*, int);
template void bfsTraversal(NodeTree<int>*);