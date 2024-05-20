#include "selection_sort.h"

#include <iostream>

using namespace std;

void selectionSort(Node** head) {
    if (*head == nullptr) {
        cout << "Lista vazia: Não é possível realizar selectionSort" << endl;
        return;
    }

    Node* outer_current = *head;
    Node* inner_current = nullptr;

    while (outer_current->ptrNext != nullptr) {
        inner_current = outer_current->ptrNext;

        while (inner_current != nullptr) {
            if (outer_current->iPayload > inner_current->iPayload) {
                swapValue(outer_current->iPayload, inner_current->iPayload);
            }
            inner_current = inner_current->ptrNext;
        }

        outer_current = outer_current->ptrNext;
    }
}

void optimizedSelectionSort(Node** head) {
    if (*head == nullptr) {
        cout << "Lista vazia: Não é possível realizar selectionSort" << endl;
        return;
    }

    Node* outer_current = *head;
    Node* inner_current = nullptr;
    Node* swapPtr = nullptr;
    int minValue = 0;

    while (outer_current->ptrNext != nullptr) {
        inner_current = outer_current->ptrNext;
        minValue = outer_current->iPayload;

        while (inner_current != nullptr) {
            if (minValue > inner_current->iPayload) {
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
