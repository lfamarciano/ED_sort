#include "selection_sort.h"

#include <iostream>

using namespace std;

template <typename T>
void selectionSort(Node<T>* head) {
    if (head == nullptr) {
        cout << "Lista vazia: Não é possível realizar selectionSort" << endl;
        return;
    }

    Node<T>* ptrOuter = head;
    Node<T>* ptrInner = nullptr;

    while (ptrOuter->ptrNext != nullptr) {
        ptrInner = ptrOuter->ptrNext;

        while (ptrInner != nullptr) {
            if (ptrOuter->payload > ptrInner->payload) {
                swapValue(ptrOuter->payload, ptrInner->payload);
            }
            ptrInner = ptrInner->ptrNext;
        }

        ptrOuter = ptrOuter->ptrNext;
    }
}

template <typename T>
void optimizedSelectionSort(Node<T>* head) {
    if (head == nullptr) {
        cout << "Lista vazia: Não é possível realizar selectionSort" << endl;
        return;
    }

    Node<T>* ptrOuter = head;
    Node<T>* ptrInner = nullptr;
    Node<T>* ptrSwap = nullptr;
    int minValue = 0;

    while (ptrOuter->ptrNext != nullptr) {
        ptrInner = ptrOuter->ptrNext;
        minValue = ptrOuter->payload;

        while (ptrInner != nullptr) {
            if (minValue > ptrInner->payload) {
                minValue = ptrInner->payload;
                ptrSwap = ptrInner;
            }
            ptrInner = ptrInner->ptrNext;
        }

        // usando essa condição pois na última iteração faz uma troca indevida
        if (minValue < ptrOuter->payload) swapValue(ptrOuter->payload, ptrSwap->payload);
        ptrOuter = ptrOuter->ptrNext;
    }
}

// fazendo instanciação explícita para criar as funções do tipo utilizado em tempo de compilação
template void selectionSort<int>(Node<int>*);
template void optimizedSelectionSort<int>(Node<int>*);