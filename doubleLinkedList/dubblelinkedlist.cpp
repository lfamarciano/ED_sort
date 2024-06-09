#include "dubblelinkedlist.h"
#include "../trees/binarytree.h"

#include <iostream>

using namespace std;

template <typename T>
void swapValue(T& refValue1, T& refValue2) {
    T temp = refValue1;
    refValue1 = refValue2;
    refValue2 = temp;
}

template <typename T>
Node<T>* createNode(T payload)
{
    Node<T>* temp = new Node<T>;
    temp->payload = payload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    
    return temp;
}

template <typename T>
void displayList(Node<T>* node)
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar displayList" << endl;
        return;
    }
    
    if (node->ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar displayList" << endl;
        return;
    }
    
    Node<T>* temp = node;
     
    cout << "Payload: ";
    
    while(temp != nullptr)
    {
        cout << temp->payload << " ";
        temp = temp->ptrNext;
    }
    
    cout << endl;
}

template <typename T>
void insertFront(Node<T>** head, T payload)
{
    Node<T>* newNode = createNode(payload);
    
    if (*head != nullptr)
    {
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;
        return;
    }
    
    (*head) = newNode;
}

template <typename T>
void insertEnd(Node<T>** head, T payload)
{
    Node<T>* newNode = createNode(payload);
    
    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }
  
    Node<T>* temp = *head;
  
    // Percorre a lista até seu fim (ptrNext do último nó é NULL)
    while(temp->ptrNext != nullptr) temp = temp->ptrNext;
  
    newNode->ptrPrev = temp; // newNode aponta para o fim da lista
    temp->ptrNext = newNode; // Antigo último elemento aponta para o novo nó
}

template <typename T>
void deleteList(Node<T>** head)
{
    Node<T>* current = *head;
    Node<T>* next = nullptr;

    while(current != nullptr)
    {
        next = current->ptrNext;
        delete current;
        current = next;
    }
    *head = nullptr; // Garante que o ponteiro da lista aponte para null após a deleção
}

template <typename T>
void deleteFirst(Node<T>** head)
{
    if (head == nullptr){
        cout << "Não é possível fazer a operação de deleção." << endl;
        return;
    }
    
    // Garante que vamos deletar o primeiro elemento.
    Node<T>* ptrDelete = (*head);

    if ((*head) -> ptrNext == nullptr){
        delete ptrDelete;
        (*head) = nullptr;
        return;
    }

    (*head)->ptrNext->ptrPrev = nullptr;
    (*head) = (*head)->ptrNext;

    delete ptrDelete;

    return;
}

// fazendo instanciação explícita para criar as funções do tipo utilizado em tempo de compilação
template void swapValue<int>(int&, int&);
template Node<int>* createNode<int>(int);
template void displayList<int>(Node<int>*);
template void insertFront<int>(Node<int>**, int);
template void insertEnd<int>(Node<int>**, int);
template void deleteList<int>(Node<int>**);
template void deleteFirst<NodeTree<int>*>(Node<NodeTree<int>*>**);

template Node<NodeTree<int>>* createNode<NodeTree<int>>(NodeTree<int>);
template void insertEnd<NodeTree<int>*>(Node<NodeTree<int>*>**, NodeTree<int>*);
template void displayList<NodeTree<int>*>(Node<NodeTree<int>*>*);
