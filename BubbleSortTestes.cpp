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
void printArray(int[], int);
void bubbleSort(int[], int);
void optimizedBubbleSort(int[], int);

int main()
{
    
    return 0;
}

void swapValue(int& irefValue1, int& irefValue2){
    int iTemp = irefValue1;
    irefValue1 = irefValue2;
    irefValue2 = iTemp;
}

void printArray(int arriNumbers[], int iLength){
    for (int i=0; i < iLength; i++) cout << arriNumbers[i] << " ";
    cout << endl;
}

void bubbleSort(int arriNumbers[], int iLength){
    for (int iOuterLoop=0; iOuterLoop<iLength-1; iOuterLoop++){
        for (int iInnerLoop=0; iInnerLoop<iLength-1; iInnerLoop++){
            if (arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop + 1])
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop + 1]);
        }
    }
}

void optimizedBubbleSort(int arriNumbers[], int iLength){
    bool bUnordered = false;
    
    for (int iOuterLoop=0; iOuterLoop<iLength-1; iOuterLoop++){
        bUnordered = false;
        for (int iInnerLoop=0; iInnerLoop<iLength-1-iOuterLoop; iInnerLoop++){
            if (arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop + 1])
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop + 1]);
                bUnordered = true;
        }
        
        if (bUnordered == false) break;
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
