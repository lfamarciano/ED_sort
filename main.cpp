#include <iostream>
#include <chrono>
#include "dubblelinkedlist.h"
#include "bubble_sort.h"
#include "selection_sort.h"

using namespace std;
using namespace std::chrono;

int main()
{
    auto timeStart = high_resolution_clock::now();
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    int arriTempoBubble[20];
    int arriTempoBubbleOptimized[20];
    int arriTempoSelection[20];
    int arriTempoSelectionOptimized[20];


    int randomValue;
    Node* head = nullptr;

    for (int iNumListas = 0; iNumListas<20; iNumListas++) // testando em 10 listas
    {
        head = nullptr;
        for (int iTamLista = 0; iTamLista < 10000; iTamLista++) // adicionando 10000 valores na lista
        {
            randomValue = rand() % 501;
            insertEnd(&head, randomValue);
        }
        // tempo da bubble sort
        timeStart = high_resolution_clock::now();
        bubbleSort(&head);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTempoBubble[iNumListas] = timeDuration.count();

        // tempo da bubble sort otimizada
        timeStart = high_resolution_clock::now();
        optimizedBubbleSort(&head);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTempoBubbleOptimized[iNumListas] = timeDuration.count();

        // tempo da selection sort
        timeStart = high_resolution_clock::now();
        selectionSort(&head);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTempoSelection[iNumListas] = timeDuration.count();

        // tempo da selection sort otimizada
        timeStart = high_resolution_clock::now();
        optimizedSelectionSort(&head);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTempoSelectionOptimized[iNumListas] = timeDuration.count();

        deleteList(&head);

    }
    
    return 0;
}