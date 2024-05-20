#include "bubble_sort.h"

#include <iostream>

using namespace std;

void bubbleSort(Node** head) {
    if (*head == nullptr) {
        cout << "Lista vazia: Não é possível realizar bubbleSort" << endl;
        return;
    }

    Node* outer_current = *head;
    Node* inner_current = *head;

    while (outer_current->ptrNext != nullptr) {
        inner_current = *head;
        while (inner_current->ptrNext != nullptr) {
            if (inner_current->iPayload > inner_current->ptrNext->iPayload) {
                swapValue(inner_current->iPayload, inner_current->ptrNext->iPayload);
            }
            inner_current = inner_current->ptrNext;
        }
        outer_current = outer_current->ptrNext;
    }
}

void optimizedBubbleSort(Node** head) {
    if (*head == nullptr) {
        cout << "Lista vazia: Não é possível realizar bubbleSort" << endl;
        return;
    }

    Node* outer_current = *head;
    Node* inner_current = *head;
    Node* last_correct = *head;
    bool bUnordered = false;

    while (last_correct->ptrNext != nullptr) last_correct = last_correct->ptrNext;

    while (outer_current->ptrNext != nullptr) {
        inner_current = *head;
        bUnordered = false;
        while (inner_current != last_correct) {
            if (inner_current->iPayload > inner_current->ptrNext->iPayload) {
                swapValue(inner_current->iPayload, inner_current->ptrNext->iPayload);
            }
            inner_current = inner_current->ptrNext;
            bUnordered = true;
        }
        outer_current = outer_current->ptrNext;
        last_correct = last_correct->ptrPrev;

        if (bUnordered == false) break;
    }
}