#include "bucket_sort.h"

#include <iostream>

using namespace std;

template <typename T>
void insertBucket(Node<T>** head, T value) {

    insertEnd(head, value);

    return;
}

template <typename T>
void bucketSort(Node<T>* head) {
    if (head == nullptr) {
        cout << "Lista vazia: Não é possível realizar bucketSort" << endl;
        return;
    }

    int iBucketCount = 10;  // Número de buckets
    Node<T>* buckets[iBucketCount] = {nullptr};

    // Encontra o valor máximo na lista para definir o intervalo dos buckets
    int iMaxValue = head->payload;
    Node<T>* ptrCurrent = head->ptrNext;
    while (ptrCurrent != nullptr) {
        if (ptrCurrent->payload > iMaxValue) {
            iMaxValue = ptrCurrent->payload;
        }
        ptrCurrent = ptrCurrent->ptrNext;
    }

    int iBucketIndex;

    // Distribui os elementos nos buckets
    ptrCurrent = head;
    while (ptrCurrent != nullptr) {
        iBucketIndex = (ptrCurrent->payload * iBucketCount) / (iMaxValue + 1);
        insertBucket(&buckets[iBucketIndex], ptrCurrent->payload);
        ptrCurrent = ptrCurrent->ptrNext;
    }

    // Ordena os elementos nos buckets usando insertion sort
    for (int i = 0; i < iBucketCount; ++i){
        insertionSort(buckets[i]);
    }

    Node<T>* ptrBucket = nullptr;
    ptrCurrent = head;

    //Aqui, trocaremos as cargas com base nos buckets
    for (int i = 0; i < iBucketCount; ++i) {
        if (buckets[i] != nullptr) {
            ptrBucket = buckets[i];
            while (ptrBucket != nullptr) {
                    ptrCurrent->payload = ptrBucket->payload;
                    ptrCurrent = ptrCurrent->ptrNext;
                    ptrBucket = ptrBucket->ptrNext;
                }
            
            deleteList(&buckets[i]);
        }
    }

    return;
}