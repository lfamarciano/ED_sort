#include <iostream>
#include <cstdlib>

template <typename T>
NodeTree<T>* createNodeTree(T payload)
{
    NodeTree<T>* tmp = (NodeTree<T>*) malloc(sizeof(NodeTree<T>));
    
    if (tmp == nullptr)
    {
        cerr << "Erro em createNode: malloc" << endl;
        exit(1);
    }
    
    tmp->iPayload = payload;
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
    
    if(iData < startingNode->iPayload)
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
    if (startingNodeTree == nullptr) return;

    Node<NodeTree<T>*>* head = nullptr; 
    NodeTree<T>*  currentNode = nullptr;

    insertEnd(&head, startingNode);

    while (head != nullptr)
    {   
        currentNode = head;
        deleteFirst(&head)

        cout << currentNode->iPayload << " ";
        
        if (currentNode->ptrLeft != nullptr)
        {
            insertEnd(&head, currentNode -> ptrLeft);
        }
        
        if (currentNode->ptrRight != nullptr)
        {
            insertEnd(&head, currentNode -> ptrRight);
        }

        head = head -> ptrNext;
    }
    cout << endl;
}

template void NodeTree<int>* createNode(int);
template NodeTree<int>* insertNodeTree(NodeTree<int>*, int);
template void bfsTraversal(NodeTree<int>*);