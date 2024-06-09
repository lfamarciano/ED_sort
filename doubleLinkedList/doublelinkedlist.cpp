#include "doublelinkedlist.h"
#include "../trees/binarytree.h"

#include <iostream>

using namespace std;

// Troca os valores de duas referências
template <typename T>
void swapValue(T& refValue1, T& refValue2) {
    T temp = refValue1;
    refValue1 = refValue2;
    refValue2 = temp;
}

// Cria um novo nó com a carga fornecida
template <typename T>
Node<T>* createNode(T payload)
{
    Node<T>* temp = new Node<T>;
    temp->payload = payload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    
    return temp;
}

// Exibe a lista
template <typename T>
void displayList(Node<T>* node)
{
    if (node == nullptr) {
        cout << "Lista vazia: Não é possível exibir a lista" << endl;
        return;
    }
    
    // Verifica se estamos começando do nó principal
    if (node->ptrPrev->ptrNext != nullptr) {
        cout << "Meio ou fim da lista: Não é possível exibir a lista" << endl;
        return;
    }
    
    Node<T>* temp = node;
     
    cout << "Carga: ";
    
    // Exibe a lista
    while(temp != nullptr) {
        cout << temp->payload << " ";
        temp = temp->ptrNext;
    }
    
    cout << endl;
}

// Insere um novo nó no início da lista
template <typename T>
void insertFront(Node<T>** head, T payload)
{
    Node<T>* newNode = createNode(payload);
    
    if ((*head) == nullptr) {
        (*head) = newNode;
        (*head)->ptrPrev = (*head); // Adiciona um ponteiro para o último elemento
        return;
    }
    
    newNode->ptrPrev = (*head)->ptrPrev; // Adiciona um ponteiro para o último elemento
    (*head)->ptrPrev = newNode;
    newNode->ptrNext = (*head);
    (*head) = newNode;

    return;
}

// Insere um novo nó no final da lista
template <typename T>
void insertEnd(Node<T>** head, T payload)
{
    Node<T>* newNode = createNode(payload);
    
    if ((*head) == nullptr) {
        (*head) = newNode;
        (*head)->ptrPrev = (*head);
        return;
    }
  
    Node<T>* last = (*head)->ptrPrev; // Acessa o último elemento
    
    (*head)->ptrPrev = newNode; // Adiciona um ponteiro para o último elemento

    newNode->ptrPrev = last; 
    last->ptrNext = newNode;

    return;
}

// Busca um nó pelo seu valor
template <typename T>
Node<T>* searchNodebyValue(Node<T>* head, T value)
{
    if (head == nullptr) {
        return nullptr;
    }
    
    Node<T>* temp = head;
    
    // Percorre elemento a elemento verificando o valor
    while(temp != nullptr && temp->payload != value) {
        temp = temp->ptrNext;
    }
    
    if (temp == nullptr) {
        return nullptr;
    }

    return temp;
}

// Remove toda a lista
template <typename T>
void deleteList(Node<T>** head)
{
    Node<T>* current = *head;
    Node<T>* next = nullptr;

    // Deleta elemento a elemento, começando do primeiro
    while(current != nullptr) {
        next = current->ptrNext;
        delete current;
        current = next;
    }

    *head = nullptr; // Garante que o ponteiro da lista aponte para null após a deleção
}

// Remove o primeiro nó da lista
template <typename T>
void deleteFirst(Node<T>** head)
{
    if (head == nullptr) {
        cout << "Não é possível fazer a operação de deleção." << endl;
        return;
    }
    
    Node<T>* ptrDelete = (*head); // Guarda o nó a ser removido (head)

    // Caso só tenha 1 elemento
    if ((*head)->ptrNext == nullptr) {
        delete ptrDelete;
        (*head) = nullptr; // Garante que o ponteiro da lista aponte para null após a deleção
        return;
    }

    (*head)->ptrNext->ptrPrev = (*head)->ptrPrev;
    (*head) = (*head)->ptrNext;

    delete ptrDelete;

    return;
}

// Fazendo instanciação explícita para criar as funções do tipo utilizado em tempo de compilação
template void swapValue<int>(int&, int&);
template Node<int>* createNode<int>(int);
template void displayList<int>(Node<int>*);
template void insertFront<int>(Node<int>**, int);
template void insertEnd<int>(Node<int>**, int);
template void deleteList<int>(Node<int>**);
template void deleteFirst<NodeTree<int>*>(Node<NodeTree<int>*>**);
template Node<int>* searchNodebyValue<int>(Node<int>*, int);

template Node<NodeTree<int>>* createNode<NodeTree<int>>(NodeTree<int>);
template void insertEnd<NodeTree<int>*>(Node<NodeTree<int>*>**, NodeTree<int>*);
template void displayList<NodeTree<int>*>(Node<NodeTree<int>*>*);
template void deleteList<NodeTree<int>*>(Node<NodeTree<int>*>**);