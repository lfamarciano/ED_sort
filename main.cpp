#include <iostream>
#include <fstream>
#include <chrono>
#include "doubleLinkedList/doublelinkedlist.h"
#include "trees/binarytree.h"
#include "sortingAlgorithms/bubble_sort.h"
#include "sortingAlgorithms/selection_sort.h"
#include "sortingAlgorithms/insertion_sort.h"
#include "sortingAlgorithms/bucket_sort.h"

using namespace std;
using namespace std::chrono;

namespace duracaoAlgoritmo
{
    enum Algoritmo {BubbleSort, BubbleSortOtimizado, SelectionSort, SelectionSortOtimizado, InsertionSort, BucketSort, DFS, BFS, ListSearch};

    // Calcula o tempo de execução dos algoritmos de sort
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

    // Calcula o tempo de execução das buscas nas arvores
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

    // Calcula o tempo de execução na lista
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
    NodeTree<int>* root = nullptr;
    Node<int>* head1 = nullptr;
    Node<int>* head2 = nullptr;
    Node<int>* head3 = nullptr;
    Node<int>* head4 = nullptr;
    Node<int>* head5 = nullptr;
    Node<int>* head6 = nullptr;
    Node<int>* head7 = nullptr;
    auto timeStart = high_resolution_clock::now();
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    // Primeira linah do CSV
    cout << "Tree Creation Time; List Creation Time; BubbleSort; BubbleSortOtimizado; SelectionSort; SelectionSortOtimizado; InsertionSort; BucketSort; DFS Time; BFS Time; List Search Time" << endl;

    for (int iNumListas = 0; iNumListas<100; iNumListas++) // Executando os testes 100 vezes
    {
        head1 = nullptr;
        head2 = nullptr;
        head3 = nullptr;
        head4 = nullptr;
        head5 = nullptr;
        head6 = nullptr;
        head7 = nullptr;
        root = nullptr;

        // Calcula o tempo de criação da árvore
        timeStart = high_resolution_clock::now();
        for (int iTamTree = 0; iTamTree < 10000; iTamTree++) // Adicionando 10000 valores entre 0 e 100000 na árvore
        {
            randomValue = rand() % 100001;

            // Cria 2 árvores iguais
            root = insertNodeTree(root, randomValue);
        }
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << timeDuration.count() << ";";

        // Cria 6 vezes a mesma lista para ordenar com os algoritmos
        for (int iTamLista = 0; iTamLista < 10000; iTamLista++) // Adicionando 10000 entre 0 e 100 valores na lista
        {
            randomValue = rand() % 101;

            // Cria 6 listas iguais
            insertFront(&head1, randomValue);
            insertFront(&head2, randomValue);
            insertFront(&head3, randomValue);
            insertFront(&head4, randomValue);
            insertFront(&head5, randomValue);
            insertFront(&head6, randomValue);
        }

        // Calcula o tempo de criação da lista
        timeStart = high_resolution_clock::now();
        for (int iTamLista = 0; iTamLista < 10000; iTamLista++) // Adicionando 10000 entre 0 e 10001 valores na lista
        {
            randomValue = rand() % 10001;

            insertFront(&head7, randomValue);
        }
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << timeDuration.count() << ";";

        //------------------------------------------------------------------------------------------------------------

        // Calcula o tempo de busca na arvore com BFS, DFS e na lista
        int sumDFS = 0;
        int sumBFS = 0;
        int sumList = 0;

        // Executa a busca de 5 valores aleatórios diferentes (entre 0 e 100000), então faz a média
        for (int numValues = 0; numValues < 5; numValues++){
            randomValue = rand() % 100001;
            sumDFS = sumDFS + tempoExecucao(root, randomValue, DFS);
            sumBFS = sumBFS + tempoExecucao(root, randomValue, BFS);
            sumList = sumList + tempoExecucao(head7, randomValue, ListSearch);
        }

        // Printa no terminal os valores, em foramto csv
        cout << tempoExecucao(head1, BubbleSort) << ";";
        cout << tempoExecucao(head2, BubbleSortOtimizado) << ";";
        cout << tempoExecucao(head3, SelectionSort) << ";";
        cout << tempoExecucao(head4, SelectionSortOtimizado) << ";";
        cout << tempoExecucao(head5, InsertionSort) << ";";
        cout << tempoExecucao(head6, BucketSort) << ";";
        cout << sumDFS/5 << ";";
        cout << sumBFS/5 << ";";
        cout << sumList/5 << endl;

        // Libera a memória de todas as listas e arvores para recomeçar o loop
        deleteList(&head1);
        deleteList(&head2);
        deleteList(&head3);
        deleteList(&head4);
        deleteList(&head5);
        deleteList(&head6);
        deleteTree(&root);
    }

    return 0;
}