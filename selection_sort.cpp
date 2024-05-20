#include "selection_sort.h"

#include <iostream>

using namespace std;

void selectionSort(Node* head) {
    if (head == nullptr) {
        cout << "Lista vazia: Não é possível realizar selectionSort" << endl;
        return;
    }

    Node* ptrOuter = head;
    Node* ptrInner = nullptr;

    while (ptrOuter->ptrNext != nullptr) {
        ptrInner = ptrOuter->ptrNext;

        while (ptrInner != nullptr) {
            if (ptrOuter->iPayload > ptrInner->iPayload) {
                swapValue(ptrOuter->iPayload, ptrInner->iPayload);
            }
            ptrInner = ptrInner->ptrNext;
        }

        ptrOuter = ptrOuter->ptrNext;
    }
}

void optimizedSelectionSort(Node* head) {
    if (head == nullptr) {
        cout << "Lista vazia: Não é possível realizar selectionSort" << endl;
        return;
    }

    Node* ptrOuter = head;
    Node* ptrInner = nullptr;
    Node* ptrSwap = nullptr;
    int minValue = 0;

    while (ptrOuter->ptrNext != nullptr) {
        ptrInner = ptrOuter->ptrNext;
        minValue = ptrOuter->iPayload;

        while (ptrInner != nullptr) {
            if (minValue > ptrInner->iPayload) {
                minValue = ptrInner->iPayload;
                ptrSwap = ptrInner;
            }
            ptrInner = ptrInner->ptrNext;
        }

        // usando essa condição pois na última iteração faz uma troca indevida
        if (minValue < ptrOuter->iPayload) swapValue(ptrOuter->iPayload, ptrSwap->iPayload);
        ptrOuter = ptrOuter->ptrNext;
    }
}
