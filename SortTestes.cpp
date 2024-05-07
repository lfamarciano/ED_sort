#include <iostream>
#include <chrono>
#include <cstdlib> // para usar valores aleatórios nas listas

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

using std::rand; // para usar valores aleatórios nas listas

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
void displayList(Node*);
void deleteList(Node** head);

// Funções para Bubble e Selection Sort
void swapValue(int&, int&);
void bubbleSort(Node**);
void optimizedBubbleSort(Node**);
void selectionSort(Node**);
void optimizedSelectionSort(Node**);

int main()
{
    // Node* head = nullptr;
    // displayList(head);
    // bubbleSort(&head);
    // cout << "==============" << endl;
    // insertEnd(&head,10);
    // insertEnd(&head,3);
    // insertEnd(&head,1);
    // insertEnd(&head,13);
    // insertEnd(&head,0);
    // insertEnd(&head,7);
    // displayList(head);
    // deleteList(&head);
    // displayList(head);
    // head = nullptr;
    // insertEnd(&head,10);
    // insertEnd(&head,3);
    // insertEnd(&head,1);
    // insertEnd(&head,13);
    // insertEnd(&head,0);
    // insertEnd(&head,7);
    // displayList(head);;


    // cout << "==============" << endl;
    // selectionSort(&head);
    // displayList(head);
    // cout << "==============" << endl;

    auto timeStart = high_resolution_clock::now();
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    long int arriTempoBubble[10];
    long int arriTempoBubbleOptimized[10];
    long int arriTempoSelection[10];
    long int arriTempoSelectionOptimized[10];

    int randomValue;
    Node* head = nullptr;

    for (int iNumListas = 0; iNumListas<10; iNumListas++) // testando em 10 listas
    {
        head = nullptr;
        for (int iTamLista = 0; iTamLista < 10000; iTamLista++) // adicionando 10000 valores na lista
        {
            randomValue = rand() % 501;
            insertEnd(&head, randomValue);
        }
        // tempo da bubble sort
        timeStart = high_resolution_clock::now();
        bubbleSort(&head);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTempoBubble[iNumListas] = timeDuration.count();

        // tempo da bubble sort otimizada
        timeStart = high_resolution_clock::now();
        optimizedBubbleSort(&head);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTempoBubbleOptimized[iNumListas] = timeDuration.count();

        // tempo da selection sort
        timeStart = high_resolution_clock::now();
        selectionSort(&head);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTempoSelection[iNumListas] = timeDuration.count();

        // tempo da selection sort otimizada
        timeStart = high_resolution_clock::now();
        optimizedSelectionSort(&head);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTempoSelectionOptimized[iNumListas] = timeDuration.count();

        deleteList(&head);
    }
    cout << "======================== FIM ========================" << endl;
    return 0;
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

void selectionSort(Node** head)
{
    if (*head == nullptr)
    {
      cout << "Lista vazia: Não é possível realizar selectionSort" << endl;
      return;
    }

    Node* outer_current = *head;
    Node* inner_current = nullptr;

    while (outer_current->ptrNext != nullptr)
    {
        inner_current = outer_current->ptrNext;

        while (inner_current != nullptr)
        {
            if (outer_current->iPayload > inner_current->iPayload)
            {
                swapValue(outer_current->iPayload, inner_current->iPayload);
            }
            inner_current = inner_current->ptrNext;
        }

        outer_current = outer_current->ptrNext;
    }
}

void optimizedSelectionSort(Node** head)
{   
    if (*head == nullptr)
    {
      cout << "Lista vazia: Não é possível realizar selectionSort" << endl;
      return;
    }

    Node* outer_current = *head;
    Node* inner_current = nullptr;
    Node* swapPtr = nullptr;
    int minValue = 0;
    
    while (outer_current->ptrNext != nullptr)
    {
        inner_current = outer_current->ptrNext;
        minValue = outer_current->iPayload;

        while (inner_current != nullptr)
        {
            if (minValue > inner_current->iPayload)
            {
                minValue = inner_current->iPayload;
                swapPtr = inner_current;
            }
            inner_current = inner_current->ptrNext;
        }

        // usando essa condição pois na última iteração faz uma troca indevida
        if (minValue < outer_current->iPayload) swapValue(outer_current->iPayload, swapPtr->iPayload);
        outer_current = outer_current->ptrNext;
    }
}

void deleteList(Node** head)
{
    Node* current = *head;
    Node* next = nullptr;

    while(current != nullptr)
    {
        next=current->ptrNext;
        free(current);
        current = next;
    }
    free(next);
}