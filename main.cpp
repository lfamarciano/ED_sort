#include <iostream>
#include "estatistica_descritiva.h"
#include "lista_duplamente_encadeada.h"
#include "sort.h"

int main()
{
    auto timeStart = high_resolution_clock::now();
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    long int arriTempoBubble[20];
    long int arriTempoBubbleOptimized[20];
    long int arriTempoSelection[20];
    long int arriTempoSelectionOptimized[20];

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
    int tamanho = 20;
    cout << "--------------Bubble Sort--------------" << endl
    cout << "Média: " << calcularMedia(arriTempoBubble, tamanho) << endl;
    cout << "Mediana: " << calcularMediana(arriTempoBubble, tamanho) << endl;
    cout << "Moda: " << calcularModa(arriTempoBubble, tamanho) << endl;
    cout << "Desvio Padrão: " << calcularDesvioPadrao(arriTempoBubble, tamanho) << endl;

    cout << "--------------Bubble Sort Otimizado--------------" << endl
    cout << "Média: " << calcularMedia(arriTempoBubbleOptimized, tamanho) << endl;
    cout << "Mediana: " << calcularMediana(arriTempoBubbleOptimized, tamanho) << endl;
    cout << "Moda: " << calcularModa(arriTempoBubbleOptimized, tamanho) << endl;
    cout << "Desvio Padrão: " << calcularDesvioPadrao(arriTempoBubbleOptimized, tamanho) << endl;

    cout << "--------------Selection Sort--------------" << endl
    cout << "Média: " << calcularMedia(arriTempoSelection, tamanho) << endl;
    cout << "Mediana: " << calcularMediana(arriTempoSelection, tamanho) << endl;
    cout << "Moda: " << calcularModa(arriTempoSelection, tamanho) << endl;
    cout << "Desvio Padrão: " << calcularDesvioPadrao(arriTempoSelection, tamanho) << endl;

    cout << "--------------Selection Sort Otimizado--------------" << endl
    cout << "Média: " << calcularMedia(arriTempoSelectionOptimized, tamanho) << endl;
    cout << "Mediana: " << calcularMediana(arriTempoSelectionOptimized, tamanho) << endl;
    cout << "Moda: " << calcularModa(arriTempoSelectionOptimized, tamanho) << endl;
    cout << "Desvio Padrão: " << calcularDesvioPadrao(arriTempoSelectionOptimized, tamanho) << endl;

    cout << "======================== FIM ========================" << endl;
    return 0;
}