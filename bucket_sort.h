#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#pragma once

#include "dubblelinkedlist.h"
#include "insertion_sort.h"

template <typename T>
void bucketSort(Node<T>* head);

template <typename T>
void insertBucket(Node<T>* head, int value);

#endif