#include <iostream>
#include <fstream>
#include <chrono>
#include "../doubleLinkedList/dubblelinkedlist.h"
#include "../trees/binarytree.h"

using namespace std;
using namespace std::chrono;

namespace duracaoAlgoritmo
{
    enum Algoritmo {BubbleSort, BubbleSortOtimizado, SelectionSort, SelectionSortOtimizado, InsertionSort, BucketSort, DFS, BFS, ListSearch};

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
                break;
            default:
                break;
        }

        auto timeStop = high_resolution_clock::now();

        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        return timeDuration.count();
    }

    template <typename T>
    float tempoExecucao(NodeTree<T>* root, T value, Algoritmo algoritmo)
    {
        auto timeStart = high_resolution_clock::now();
        
        switch (algoritmo)
        {
            case DFS:
                dfsSearch(root, value);
                break;
            case BFS:
                bfsSearch(root, value);
                break;
            default:
                break;
        }

        auto timeStop = high_resolution_clock::now();

        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        return timeDuration.count();
    }

    template <typename T>
    float tempoExecucao(Node<T>* head, T value, Algoritmo algoritmo)
    {
        auto timeStart = high_resolution_clock::now();
        
        switch (algoritmo)
        {
            case ListSearch:
                searchNodebyValue(head, value);
                break;
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
    NodeTree<int>* root1 = nullptr;
    NodeTree<int>* root2 = nullptr;
    Node<int>* head = nullptr;

    cout << "DFS; BFS" << endl;

    for (int iNumListas = 0; iNumListas<100; iNumListas++) // testando em 100 árvores
    {
        head = nullptr;
        root1 = nullptr;
        root2 = nullptr;

        auto timeStart = high_resolution_clock::now();
        for (int iTamTree = 0; iTamTree < 10000; iTamTree++) // adicionando 10000 valores entre 0 e 100000 na árvore
        {
            randomValue = rand() % 100001;

            //cria 2 árvores iguais
            root1 = insertNodeTree(root1, randomValue);
            root2 = insertNodeTree(root2, randomValue);
        }
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << timeDuration.count() << ";";

        auto timeStart = high_resolution_clock::now();
        for (int iTamLista = 0; iTamLista < 10000; iTamLista++) // adicionando 10000 valores entre 0 e 100000 em uma lista
        {
            randomValue = rand() % 100001;

            insertFront(&head, randomValue);

        }
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << timeDuration.count() << ";";
        
        int sumDFS = 0;
        int sumBFS = 0;
        int sumList = 0;
        for (int numValues = 0; numValues < 5; numValues++){
            randomValue = rand() % 100001;
            sumDFS = sumDFS + tempoExecucao(root1, randomValue, DFS);
            sumBFS = sumBFS + tempoExecucao(root2, randomValue, BFS);
            sumList = sumList + tempoExecucao(head, randomValue, ListSearch);
        }
        cout << sumDFS/5 << ";";
        cout << sumBFS/5 << ";";
        cout << sumList/5 << ";";

        deleteList(&head);
        deleteTree(&root1);
        deleteTree(&root2);
    }



    return 0;
}