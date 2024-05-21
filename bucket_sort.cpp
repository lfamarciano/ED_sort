#include "bucket_sort.h"

#include <iostream>

using namespace std;

void insertBucket(Node** head, int value) {

    insertEnd(head, value);

    return;
}

void bucketSort(Node* head) {
    if (head == nullptr) {
        cout << "Lista vazia: Não é possível realizar bucketSort" << endl;
        return;
    }

    int iBucketCount = 10;  // Número de buckets
    Node* buckets[iBucketCount] = {nullptr};

    // Encontra o valor máximo na lista para definir o intervalo dos buckets
    int iMaxValue = head->iPayload;
    Node* ptrCurrent = head->ptrNext;
    while (ptrCurrent != nullptr) {
        if (ptrCurrent->iPayload > iMaxValue) {
            iMaxValue = ptrCurrent->iPayload;
        }
        ptrCurrent = ptrCurrent->ptrNext;
    }

    int iBucketIndex;

    // Distribui os elementos nos buckets
    ptrCurrent = head;
    while (ptrCurrent != nullptr) {
        iBucketIndex = (ptrCurrent->iPayload * iBucketCount) / (iMaxValue + 1);
        insertBucket(&buckets[iBucketIndex], ptrCurrent->iPayload);
        ptrCurrent = ptrCurrent->ptrNext;
    }

    // Ordena os elementos nos buckets usando insertion sort
    for (int i = 0; i < iBucketCount; ++i){
        insertionSort(buckets[i]);
    }

    Node* ptrBucket = nullptr;
    ptrCurrent = head;

    //Aqui, trocaremos as cargas com base nos buckets
    for (int i = 0; i < iBucketCount; ++i) {
        if (buckets[i] != nullptr) {
            ptrBucket = buckets[i];
            while (ptrBucket != nullptr) {
                    ptrCurrent->iPayload = ptrBucket->iPayload;
                    ptrCurrent = ptrCurrent->ptrNext;
                    ptrBucket = ptrBucket->ptrNext;
                }
            
            deleteList(&buckets[i]);
        }
    }

    return;
}