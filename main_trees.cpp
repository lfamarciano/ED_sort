#include <iostream>
#include <fstream>
#include <chrono>
#include "../doubleLinkedList/dubblelinkedlist.h"
#include "../trees/binarytree.h"

using namespace std;
using namespace std::chrono;

namespace duracaoAlgoritmo
{
    enum Algoritmo {BubbleSort, BubbleSortOtimizado, SelectionSort, SelectionSortOtimizado, InsertionSort, BucketSort};

    template <typename T>
    float tempoExecucao(Node<T>* head, Algoritmo algoritmo)
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
    // int randomValue;
    // NodeTree<int>* root1 = nullptr;
    // NodeTree<int>* root2 = nullptr;
    // Node<int>* head = nullptr;

    // cout << "DFS; BFS" << endl;

    // for (int iNumListas = 0; iNumListas<100; iNumListas++) // testando em 100 árvores
    // {
    //     head = nullptr;
    //     root1 = nullptr;
    //     root2 = nullptr;

    //     auto timeStart = high_resolution_clock::now();
    //     for (int iTamLista = 0; iTamLista < 10000; iTamLista++) // adicionando 10000 valores entre 0 e 100000 na árvore
    //     {
    //         randomValue = rand() % 100001;

    //         //cria 2 árvores iguais
    //         root1 = insertNodeTree(root1, randomValue);
    //         root2 = insertNodeTree(root2, randomValue);
    //     }
    //     auto timeStop = high_resolution_clock::now();
    //     auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    //     for (int iTamLista = 0; iTamLista < 10000; iTamLista++) // adicionando 10000 valores entre 0 e 100000 em uma lista
    //     {
    //         randomValue = rand() % 100001;

    //         insertFront(&head, randomValue);

    //     }
    //     cout << tempoExecucao(head1, BubbleSort) << ";";
    //     cout << tempoExecucao(head2, BubbleSortOtimizado) << ";";
    //     cout << tempoExecucao(head3, SelectionSort) << ";";
    //     cout << tempoExecucao(head4, SelectionSortOtimizado) << ";";
    //     cout << tempoExecucao(head5, InsertionSort) << ";";
    //     cout << tempoExecucao(head6, BucketSort) << endl;

    //     deleteList(&head);

    
    // }



    return 0;
}