#include "insertion_sort.h"

#include <iostream>

using namespace std;

template class Node<int>;

template <typename T>
void insertionSort(Node<T>* head) {
    // Verifica se a lista está vazia
    if (head == nullptr) {
        cout << "Lista vazia: Não é possível realizar insertionSort" << endl;
        return;
    }
    
    Node<T>* ptrOuter = head->ptrNext;

    // Algoritmo do Insertion Sort
    while(ptrOuter != nullptr) {
        Node<T>* ptrInner = ptrOuter->ptrPrev;
        Node<T>* current = ptrOuter;
        
        while(ptrInner != head->ptrPrev && ptrInner->payload > current->payload) {
            swapValue(current->payload, ptrInner->payload);
            
            current = ptrInner;
            ptrInner = ptrInner->ptrPrev;
        }
        
        ptrOuter = ptrOuter->ptrNext;
    }
}

// Fazendo instanciação explícita para criar a função do tipo utilizado em tempo de compilação
template void insertionSort<int>(Node<int>*);
