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

    Node* ptrNext;
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

    Node* ptrNewHead = nullptr;
    Node* ptrLast = nullptr;

    //Aqui, faremos um bucket apontar para o outro, formando apeans uma lista
    for (int i = 0; i < iBucketCount; ++i) {
        if (buckets[i] != nullptr) {
            // Primeiro bucket
            if (ptrNewHead == nullptr) {
                ptrNewHead = buckets[i];
                ptrLast = buckets[i];
                // Acha o último elemento do bucket
                while (ptrLast->ptrNext != nullptr) {
                    ptrLast = ptrLast->ptrNext;
                }
            } 
            // Outros buckets além do primeiro
            else {
                ptrLast->ptrNext = buckets[i];
                buckets[i]->ptrPrev = ptrLast;
                while (ptrLast->ptrNext != nullptr) {
                    ptrLast = ptrLast->ptrNext;
                }
            }
        }
    }

    // Copia os valores ordenados de volta para a lista original
    ptrCurrent = head;
    Node* ptrBucketCurrent = ptrNewHead;
    while (ptrBucketCurrent != nullptr) {
        ptrCurrent->iPayload = ptrBucketCurrent->iPayload;
        ptrCurrent = ptrCurrent->ptrNext;
        ptrBucketCurrent = ptrBucketCurrent->ptrNext;
    }

    // Libera a memória dos nós temporários criados nos buckets (estão todos em uma lista)
    deleteList(&ptrNewHead);
}