#include <iostream>
#include "binarytree.h"

using namespace std;

int main()
{
    NodeTree<int>* root = nullptr;
    NodeTree<int>* achado = nullptr;

    root = insertNodeTree(root, 42);
    root = insertNodeTree(root, 13);
    root = insertNodeTree(root, 11);
    root = insertNodeTree(root, 10);
    root = insertNodeTree(root, 28);
    root = insertNodeTree(root, 51);
    root = insertNodeTree(root, 171);

    cout << "BFS Traversal: ";
    bfsTraversal(root);

    cout << "Procurando node: ";
    achado = bfsSearch(root, 30);
    cout << ((achado != nullptr) ? achado->payload : -1) << endl;

    cout << "Procurando node: ";
    achado = bfsSearch(root, 10);
    cout << ((achado != nullptr) ? achado->payload : -1) << endl;

    cout << "Procurando node: ";
    achado = bfsSearch(root, 42);
    cout << ((achado != nullptr) ? achado->payload : -1) << endl;

    cout << "Procurando node: ";
    achado = bfsSearch(root, 171);
    cout << ((achado != nullptr) ? achado->payload : -1) << endl;

    return 0;
}

template <typename T>
NodeTree<T>* createNodeTree(T payload)
{
    NodeTree<T>* tmp = (NodeTree<T>*) malloc(sizeof(NodeTree<T>));
    
    if (tmp == nullptr)
    {
        cerr << "Erro em createNode: malloc" << endl;
        exit(1);
    }
    
    tmp->payload = payload;
    tmp->ptrLeft = nullptr;
    tmp->ptrRight = nullptr;
    
    return tmp;
}

template <typename T>
NodeTree<T>* insertNodeTree(NodeTree<T>*  startingNode, T data)
{
    if(startingNode == nullptr)
    {
        return createNodeTree(data);
    }
    
    if(data < startingNode->payload)
    {
        startingNode->ptrLeft = insertNodeTree(startingNode->ptrLeft, data);
    }
    else
    {
        startingNode->ptrRight = insertNodeTree(startingNode->ptrRight, data);
    }
    
    return startingNode;
}

template <typename T>
void bfsTraversal(NodeTree<T>* startingNode)
{
    if (startingNode == nullptr) return;

    Node<NodeTree<T>*>* head = nullptr; 
    NodeTree<T>*  currentNode = nullptr;

    insertEnd(&head, startingNode);

    while (head != nullptr)
    {   
        currentNode = head->payload;

        cout << currentNode -> payload << " ";
        
        if (currentNode->ptrLeft != nullptr)
        {   
            insertEnd(&head, currentNode -> ptrLeft);
        }
        
        if (currentNode->ptrRight != nullptr)
        {   
            insertEnd(&head, currentNode -> ptrRight);
        }

        deleteFirst(&head);
    }

    cout << endl;

    deleteList(&head); //Apaga a lista, caso necessário

    //displayList(head); //Para verificar que a lista está sendo apagada

    return;
}

template <typename T>
NodeTree<T>* bfsSearch(NodeTree<T>* startingNode, T target)
{
    if (startingNode == nullptr) return nullptr;

    if (startingNode->payload == target) return startingNode;

    Node<NodeTree<T>*>* head = nullptr; 
    NodeTree<T>*  currentNode = nullptr;

    insertEnd(&head, startingNode);

    while (head != nullptr)
    {   
        currentNode = head->payload;

        if (currentNode->payload == target){
            break;
        }
        
        if (currentNode->ptrLeft != nullptr)
        {   
            insertEnd(&head, currentNode -> ptrLeft);
        }
        
        if (currentNode->ptrRight != nullptr)
        {   
            insertEnd(&head, currentNode -> ptrRight);
        }

        deleteFirst(&head);
    }

    if(head == nullptr) return nullptr;

    deleteList(&head); //Apaga a lista, caso necessário

    return currentNode;
}

template <typename T>
NodeTree<T>* dfsSearch(NodeTree<T>* startingNode, T target)
{
    if (startingNode == nullptr) return nullptr;

    if (startingNode->payload == target) return startingNode;

    NodeTree<T>* result = dfsSearch(startingNode->ptrLeft, target);
    if (result != nullptr) return result; 

    return dfsSearch(startingNode->ptrRight, target);
}

template NodeTree<int>* createNodeTree(int);
template NodeTree<int>* insertNodeTree(NodeTree<int>*, int);
template NodeTree<int>* bfsSearch(NodeTree<int>*, int);
template NodeTree<int>* dfsSearch<int>(NodeTree<int>*, int);
template void bfsTraversal(NodeTree<int>*);