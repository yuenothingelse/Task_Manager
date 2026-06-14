#ifndef HEAP_H
#define HEAP_H

#include "../models/task.h"

#define MAX_HEAP_SIZE 100

typedef struct {
    Task tasks[MAX_HEAP_SIZE];
    int size;
} MinHeap;

//INISIALISASI
void initHeap(MinHeap *heap);

//INSERT
void insertHeap(
    MinHeap *heap,
    Task task
);

//DELETE
void deleteHeap(
    MinHeap *heap,
    int taskId
);

//UPDATE
void updateHeap(
    MinHeap *heap,
    Task task
);

//GETTER
Task *getHighestPriorityTask(
    MinHeap *heap
);

//DISPLAY
void displayPriorityQueue(
    MinHeap *heap
);

#endif
