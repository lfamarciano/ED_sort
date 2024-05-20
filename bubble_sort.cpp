#include "bubble_sort.h"

#include <iostream>

using namespace std;

void bubbleSort(Node* head) {
    if (head == nullptr) {
        cout << "Lista vazia: Não é possível realizar bubbleSort" << endl;
        return;
    }

    Node* ptrOuter = head;
    Node* ptrInner = head;

    while (ptrOuter->ptrNext != nullptr) {
        ptrInner = head;
        while (ptrInner->ptrNext != nullptr) {
            if (ptrInner->iPayload > ptrInner->ptrNext->iPayload) {
                swapValue(ptrInner->iPayload, ptrInner->ptrNext->iPayload);
            }
            ptrInner = ptrInner->ptrNext;
        }
        ptrOuter = ptrOuter->ptrNext;
    }
}

void optimizedBubbleSort(Node* head) {
    if (head == nullptr) {
        cout << "Lista vazia: Não é possível realizar bubbleSort" << endl;
        return;
    }

    Node* ptrOuter = head;
    Node* ptrInner = head;
    Node* last_correct = head;
    bool bUnordered = false;

    while (last_correct->ptrNext != nullptr) last_correct = last_correct->ptrNext;

    while (ptrOuter->ptrNext != nullptr) {
        ptrInner = head;
        bUnordered = false;
        while (ptrInner != last_correct) {
            if (ptrInner->iPayload > ptrInner->ptrNext->iPayload) {
                swapValue(ptrInner->iPayload, ptrInner->ptrNext->iPayload);
            }
            ptrInner = ptrInner->ptrNext;
            bUnordered = true;
        }
        ptrOuter = ptrOuter->ptrNext;
        last_correct = last_correct->ptrPrev;

        if (bUnordered == false) break;
    }
}