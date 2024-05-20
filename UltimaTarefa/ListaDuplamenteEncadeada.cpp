#include "ListaDuplamenteEncadeada.h"

using namespace std;

Node* createNode(int iPayload)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    
    return temp;
}

void displayList(Node* node)
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar displayList" << endl;
        return; // Usa return pra sair da função, o resto do código não será executado
    }
    
    if (node->ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar displayList" << endl;
        return;
    }
    
    Node* temp = node;
     
    cout << "Payload: ";
    
    while(temp != nullptr)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }
    
    cout << endl;
}

void insertFront(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
    
    if (*head != nullptr)
    {
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
    }
    *head = newNode;
}

void insertEnd(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
    
    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }
  
    Node* temp = *head;
  
    // Percorremos a lista até seu fim(ptrNext do último nó é NULL)
    while(temp->ptrNext != nullptr) temp = temp->ptrNext;
  
    newNode->ptrPrev = temp; // newNode aponta para o fim da lista
    temp->ptrNext = newNode; // Antigo último elemento aponta para o novo nó
}

void deleteList(Node** head)
{
    Node* current = *head;
    Node* next = nullptr;

    while(current != nullptr)
    {
        next = current->ptrNext;
        free(current);
        current = next;
    }
    *head = nullptr; // Garanta que o ponteiro da lista aponte para null após a deleção
}
