#include <iostream>
#include <fstream>
#include <chrono>
#include "dubblelinkedlist.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"

using namespace std;
using namespace std::chrono;

namespace duracaoAlgoritmo
{
    enum Algoritmo {BubbleSort, BubbleSortOtimizado, SelectionSort, SelectionSortOtimizado, InsertionSort};

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
    Node* head = nullptr;
    cout << "BubbleSort; BubbleSortOtimizado; SelectionSort; SelectionSortOtimizado; InserionSort" << endl;

    for (int iNumListas = 0; iNumListas<100; iNumListas++) // testando em 100 listas
    {
        head = nullptr;
        for (int iTamLista = 0; iTamLista < 10000; iTamLista++) // adicionando 10000 valores na lista
        {
            randomValue = rand() % 20000;
            insertEnd(&head, randomValue);
        }
        cout << tempoExecucao(head, BubbleSort) << ";";
        cout << tempoExecucao(head, BubbleSortOtimizado) << ";";
        cout << tempoExecucao(head, SelectionSort) << ";";
        cout << tempoExecucao(head, SelectionSortOtimizado) << ";";
        cout << tempoExecucao(head, InsertionSort) << endl;

        deleteList(&head);
        
    
    }
    
    return 0;
}