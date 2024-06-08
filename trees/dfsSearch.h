#ifndef DFSSEARCH_H
#define DFSSEARCH_H

#pragma once

#include "../doubleLinkedList/dubblelinkedlist.h"

template <typename T>
NodeTree<T>* dfsSearch(NodeTree<T>* startingNode, T target);

#endif