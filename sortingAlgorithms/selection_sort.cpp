#include "selection_sort.h"

#include <iostream>

using namespace std;

template <typename T>
void selectionSort(Node<T>* head) {
    // Verifica se a lista está vazia
    if (head == nullptr) {
        cout << "Lista vazia: Não é possível realizar selectionSort" << endl;
        return;
    }

    Node<T>* ptrOuter = head;
    Node<T>* ptrInner = nullptr;

    // Algoritmo do Selection Sort
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
    // Verifica se a lista está vazia
    if (head == nullptr) {
        cout << "Lista vazia: Não é possível realizar selectionSort" << endl;
        return;
    }

    Node<T>* ptrOuter = head;
    Node<T>* ptrInner = nullptr;
    Node<T>* ptrSwap = nullptr;
    int minValue = 0;

    // Algoritmo do Selection Sort Otimizado
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

        // Evita a troca desnecessária na última iteração
        if (minValue < ptrOuter->payload) swapValue(ptrOuter->payload, ptrSwap->payload);
        ptrOuter = ptrOuter->ptrNext;
    }
}

// Fazendo instanciação explícita para criar as funções do tipo utilizado em tempo de compilação
template void selectionSort<int>(Node<int>*);
template void optimizedSelectionSort<int>(Node<int>*);