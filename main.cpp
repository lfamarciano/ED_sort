#include <iostream>
#include <fstream>
#include <chrono>
#include "dubblelinkedlist.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "bucket_sort.h"

using namespace std;
using namespace std::chrono;

namespace duracaoAlgoritmo
{
    enum Algoritmo {BubbleSort, BubbleSortOtimizado, SelectionSort, SelectionSortOtimizado, InsertionSort, BucketSort};

    float tempoExecucao(Node* head, Algoritmo algoritmo)
    {
        auto timeStart = high_resolution_clock::now();
        
        switch (algoritmo)
        {
            case BubbleSort:
                bubbleSort(head);
                break;
            case BubbleSortOtimizado:
                optimizedBubbleSort(head);
                break;
            case SelectionSort:
                selectionSort(head);
                break;
            case SelectionSortOtimizado:
                optimizedSelectionSort(head);
                break;
            case InsertionSort:
                insertionSort(head);
                break;
            case BucketSort:
                bucketSort(head);
            default:
                break;
        }

        auto timeStop = high_resolution_clock::now();

        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        return timeDuration.count();
    }
}

using namespace duracaoAlgoritmo;

int main()
{
    int randomValue;
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    Node* head3 = nullptr;
    Node* head4 = nullptr;
    Node* head5 = nullptr;
    Node* head6 = nullptr;

    cout << "BubbleSort; BubbleSortOtimizado; SelectionSort; SelectionSortOtimizado; InsertionSort; BucketSort" << endl;

    for (int iNumListas = 0; iNumListas<100; iNumListas++) // testando em 100 listas
    {
        head1 = nullptr;
        head2 = nullptr;
        head3 = nullptr;
        head4 = nullptr;
        head5 = nullptr;
        head6 = nullptr;

        for (int iTamLista = 0; iTamLista < 10000; iTamLista++) // adicionando 10000 valores na lista
        {
            randomValue = rand() % 101;

            //cria 5 listas iguais
            insertEnd(&head1, randomValue);
            insertEnd(&head2, randomValue);
            insertEnd(&head3, randomValue);
            insertEnd(&head4, randomValue);
            insertEnd(&head5, randomValue);
            insertEnd(&head6, randomValue);
        }
        cout << tempoExecucao(head1, BubbleSort) << ";";
        cout << tempoExecucao(head2, BubbleSortOtimizado) << ";";
        cout << tempoExecucao(head3, SelectionSort) << ";";
        cout << tempoExecucao(head4, SelectionSortOtimizado) << ";";
        cout << tempoExecucao(head5, InsertionSort) << ";";
        cout << tempoExecucao(head6, BucketSort) << endl;

        deleteList(&head1);
        deleteList(&head2);
        deleteList(&head3);
        deleteList(&head4);
        deleteList(&head5);
        deleteList(&head6);
    
    }
    
    return 0;
}