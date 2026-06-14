#include <stdio.h>
#include <string.h>

#include "heap.h"

static void swapTask(
    Task *a,
    Task *b)
{
    Task temp = *a;
    *a = *b;
    *b = temp;
}

static void heapifyUp(
    MinHeap *heap,
    int index)
{
    while(index > 0)
    {
        int parent =
            (index - 1) / 2;

        if(heap->tasks[parent].priority
           <=
           heap->tasks[index].priority)
        {
            break;
        }

        swapTask(
            &heap->tasks[parent],
            &heap->tasks[index]);

        index = parent;
    }
}

static void heapifyDown(
    MinHeap *heap,
    int index)
{
    while(1)
    {
        int left =
            2 * index + 1;

        int right =
            2 * index + 2;

        int smallest =
            index;

        if(left < heap->size &&
           heap->tasks[left].priority <
           heap->tasks[smallest].priority)
        {
            smallest = left;
        }

        if(right < heap->size &&
           heap->tasks[right].priority <
           heap->tasks[smallest].priority)
        {
            smallest = right;
        }

        if(smallest == index)
        {
            break;
        }

        swapTask(
            &heap->tasks[index],
            &heap->tasks[smallest]);

        index = smallest;
    }
}

void initHeap(
    MinHeap *heap)
{
    heap->size = 0;
}

void insertHeap(
    MinHeap *heap,
    Task task)
{
    if(heap->size >= MAX_HEAP_SIZE)
    {
        printf("Heap is full.\n");
        return;
    }

    heap->tasks[heap->size] =
        task;

    heapifyUp(
        heap,
        heap->size);

    heap->size++;
}

void deleteHeap(
    MinHeap *heap,
    int taskId)
{
    int index = -1;

    for(int i = 0;
        i < heap->size;
        i++)
    {
        if(heap->tasks[i].id == taskId)
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        return;
    }

    heap->tasks[index] =
        heap->tasks[
            heap->size - 1];

    heap->size--;

    heapifyDown(
        heap,
        index);
}

void updateHeap(
    MinHeap *heap,
    Task task)
{
    for(int i = 0;
        i < heap->size;
        i++)
    {
        if(heap->tasks[i].id == task.id)
        {
            heap->tasks[i] =
                task;

            heapifyUp(
                heap,
                i);

            heapifyDown(
                heap,
                i);

            return;
        }
    }

    insertHeap(
        heap,
        task);
}

Task *getHighestPriorityTask(
    MinHeap *heap)
{
    if(heap->size == 0)
    {
        return NULL;
    }

    return &heap->tasks[0];
}

void displayPriorityQueue(
    MinHeap *heap)
{
    if(heap->size == 0)
    {
        printf(
            "\nNo tasks available.\n");

        return;
    }

    printf(
        "\n========== PRIORITY TASKS ==========\n");

    for(int i = 0;
        i < heap->size;
        i++)
    {
        printf(
            "ID: %d\n",
            heap->tasks[i].id);

        printf(
            "Title: %s\n",
            heap->tasks[i].title);

        printf(
            "Course: %s\n",
            heap->tasks[i].course);

        printf(
            "Deadline: %s\n",
            heap->tasks[i].deadline);

        printf(
            "Priority: %d\n",
            heap->tasks[i].priority);

        printf(
            "Status: %s\n",
            heap->tasks[i].status == COMPLETED ?
            "Completed" :
            "Pending");

        printf(
            "---------------------------------\n");
    }
}
