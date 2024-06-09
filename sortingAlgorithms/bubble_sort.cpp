#include "bubble_sort.h"

#include <iostream>

using namespace std;

template <typename T>
void bubbleSort(Node<T>* head) {
    if (head == nullptr) {
        cout << "Lista vazia: Não é possível realizar bubbleSort" << endl;
        return;
    }

    Node<T>* ptrOuter = head;
    Node<T>* ptrInner = head;

    while (ptrOuter->ptrNext != nullptr) {
        ptrInner = head;
        while (ptrInner->ptrNext != nullptr) {
            if (ptrInner->payload > ptrInner->ptrNext->payload) {
                swapValue(ptrInner->payload, ptrInner->ptrNext->payload);
            }
            ptrInner = ptrInner->ptrNext;
        }
        ptrOuter = ptrOuter->ptrNext;
    }
}

template <typename T>
void optimizedBubbleSort(Node<T>* head) {
    if (head == nullptr) {
        cout << "Lista vazia: Não é possível realizar bubbleSort" << endl;
        return;
    }

    Node<T>* ptrOuter = head;
    Node<T>* ptrInner = head;
    Node<T>* last_correct = head -> ptrPrev;
    bool bUnordered = false;

    while (ptrOuter->ptrNext != nullptr) {
        ptrInner = head;
        bUnordered = false;
        while (ptrInner != last_correct) {
            if (ptrInner->payload > ptrInner->ptrNext->payload) {
                swapValue(ptrInner->payload, ptrInner->ptrNext->payload);
            }
            ptrInner = ptrInner->ptrNext;
            bUnordered = true;
        }
        ptrOuter = ptrOuter->ptrNext;
        last_correct = last_correct->ptrPrev;

        if (bUnordered == false) break;
    }
}

// fazendo instanciação explícita para criar as funções do tipo utilizado em tempo de compilação
template void optimizedBubbleSort<int>(Node<int>*);
template void bubbleSort<int>(Node<int>*);

