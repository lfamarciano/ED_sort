#include <iostream>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

// Funções Lista Duplamente Ecadeada 
Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void insertAfter(Node*, int);
void displayList(Node*);
void insertBefore(Node*, int);
Node* searchNodebyValue(Node*, int);
void deleteNodebyValue(Node**, int);

// Funções para Bubble Sort
void swapValue(int&, int&);
void bubbleSort(Node**);
void optimizedBubbleSort(Node** head);

int main()
{
    Node* head = nullptr;
    displayList(head);
    bubbleSort(&head);
    cout << "==============" << endl;
    insertEnd(&head,10);
    insertEnd(&head,3);
    insertEnd(&head,1);
    insertEnd(&head,13);
    insertEnd(&head,0);
    insertEnd(&head,7);
    displayList(head);
    cout << "==============" << endl;
    auto timeStart = high_resolution_clock::now();
    bubbleSort(&head);
    auto timeStop = high_resolution_clock::now();
    
    displayList(head);
    
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo para ordenação: " << timeDuration.count() << " nanosegundos" << endl;
    cout << "======================== FIM ========================" << endl;
    return 0;
}

void swapValue(int& irefValue1, int& irefValue2){
    int iTemp = irefValue1;
    irefValue1 = irefValue2;
    irefValue2 = iTemp;
}

void bubbleSort(Node** head){
    if (*head == nullptr)
    {
      cout << "Lista vazia: Não é possível realizar bubbleSort" << endl;
      return;
    }

    Node* outer_current = *head;
    Node* inner_current = *head;

    while (outer_current->ptrNext != nullptr)
    {
        inner_current = *head;
        while (inner_current->ptrNext != nullptr)
        {
            if (inner_current->iPayload > inner_current->ptrNext->iPayload)
            {
                swapValue(inner_current->iPayload, inner_current->ptrNext->iPayload);
            }
            inner_current = inner_current->ptrNext;
        }
        outer_current = outer_current->ptrNext;
    }
}

void optimizedBubbleSort(Node** head){
    if (*head == nullptr)
    {
      cout << "Lista vazia: Não é possível realizar bubbleSort" << endl;
      return;
    }

    Node* outer_current = *head;
    Node* inner_current = *head;
    Node* last_correct = *head;
    bool bUnordered = false;
  
    while(last_correct->ptrNext != nullptr) last_correct = last_correct->ptrNext;

    while (outer_current->ptrNext != nullptr)
    {
        inner_current = *head;
        bUnordered = false;
        while (inner_current != last_correct)
        {
            if (inner_current->iPayload > inner_current->ptrNext->iPayload)
            {
                swapValue(inner_current->iPayload, inner_current->ptrNext->iPayload);
            }
            inner_current = inner_current->ptrNext;
            bUnordered = true;
        }
        outer_current = outer_current->ptrNext;
        last_correct = last_correct->ptrPrev;

        if (bUnordered==false) break;
    }
}

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
        return; //Usa return pra sair da função, o resto do código não será executado
    }
    
    if  (node -> ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar displayList" << endl;
        return;
       
    }
    
    Node* temp = node;
     
    cout << "Payload: ";
    
    while(temp != nullptr)
    {
        cout << temp->iPayload<< " ";
        temp = temp->ptrNext;
    }
    
    cout << endl;
}

void insertFront(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
    // newNode->ptrNext = nullptr;
    
    if (*head != nullptr)
    {
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;
        
        return;
    }
}

void insertEnd(Node** head, int iPayload)
{
  Node* newNode = createNode(iPayload);
  //newNode -> ptrNext = nullptr;
  
  if (*head == nullptr)
  {
      //newNode -> ptrNext = nullptr; Essa linha não é obrigatória pois já definimos anteriormente
      (*head) = newNode;
      return;
      
  }
  
  Node* temp = (*head);
  
  //Percorremos a lista até seu fim(ptrNext do ultimo nó é NULL)
  while(temp->ptrNext != nullptr) temp = temp->ptrNext;
  
  newNode->ptrPrev = temp; //newNode aponta para o fim da lista
  temp->ptrNext = newNode; //Antigo último elemento aponta para o novo nó
}

void insertAfter(Node* ptrLocation, int iPayload)
{
    if (ptrLocation == nullptr)
    {
        cout << "Location é NULL." << endl;
        return;
    }
    
    Node* newNode = createNode(iPayload);
    
    // Corrigir nó a ser inserido
    newNode->ptrNext = ptrLocation->ptrNext;
    newNode->ptrPrev = ptrLocation;
    
    // Corrigir o ponto de inserção
    ptrLocation->ptrNext = newNode;
    
    if (newNode->ptrNext != nullptr) newNode->ptrNext->ptrPrev = newNode;
}

void deleteNode(Node** head, Node* ptrDelete)
{
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi posível remover." << endl;
        return;
    }
    
    // Caso o ptrDelete seja o primero elemento da lista
    if (*head == ptrDelete) (*head) = ptrDelete->ptrNext;
    
    // Se o ptrDelete não é o último nó
    if (ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
    
    // Se o ptrDelete não é o primeiro nó
    if (ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;

    free(ptrDelete);
}


void insertBefore(Node* ptrLocation, int iPayload)
{
    if (ptrLocation == nullptr)
    {
        cout << "Location é NULL." << endl;
        return;
    }
    
    Node* newNode = createNode(iPayload);
    
    // Corrigir nó a ser inserido
    newNode->ptrPrev = ptrLocation->ptrPrev;
    newNode->ptrNext = ptrLocation;
    
    // Corrigir o ponto de inserção
    ptrLocation->ptrPrev = newNode;
    
    if (newNode->ptrPrev != nullptr) newNode->ptrPrev->ptrNext = newNode;
}


Node* searchNodebyValue(Node* head, int iValue)
{
    if (head == nullptr)
    {
        //newNode -> ptrNext = nullptr; Essa linha não é obrigatória pois já definimos anteriormente
        cout << "Ponteiro head é nulo" << endl;
        return nullptr;
    }
    
    Node* temp = head;
    
    //Percorremos a lista até achar algum valor correspondênte ou até seu fim
    while(temp != nullptr && temp->iPayload != iValue) 
    {
        temp = temp->ptrNext;
    }
    
    if (temp == nullptr)
    {
        cout << "Não tem nó com esse valor!" << endl;
        return nullptr;
    }

    return temp;
}


void deleteNodebyValue(Node** head, int iValue)
{
    if (*head == nullptr)
    {
        //newNode -> ptrNext = nullptr; Essa linha não é obrigatória pois já definimos anteriormente
        cout << "Ponteiro head é nulo" << endl;
        return;
    }
    
    Node* temp = searchNodebyValue(*head, iValue);
    
    deleteNode(head, temp);
}
