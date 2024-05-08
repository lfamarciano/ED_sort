#include <iostream>
#include "lista_duplamente_encadeada.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void swapValue(int&, int&);
void bubbleSort(Node**);
void optimizedBubbleSort(Node**);
void optimizedBubbleSort(int arriNumbers[], int iLength);
void selectionSort(Node**);
void optimizedSelectionSort(Node**);

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
