#include "insertion_sort.h"

#include <iostream>

using namespace std;

void insertionSort(Node* head) {
    if (head == nullptr) {
        cout << "Lista vazia: Não é possível realizar insertionSort" << endl;
        return;
    }
    
    Node* ptrOuter = head->ptrNext;

    while(ptrOuter != nullptr) {
        Node* ptrInner = ptrOuter->ptrPrev;
        Node* current = ptrOuter;
        
        while(ptrInner != nullptr && ptrInner->iPayload > current->iPayload) {
            swapValue(current->iPayload, ptrInner->iPayload);
            
            current = ptrInner;
            ptrInner = ptrInner->ptrPrev;
        }
        
    ptrOuter = ptrOuter->ptrNext;
    }
}