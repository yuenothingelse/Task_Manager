#include <string.h>

#include "sort.h"


static void swapTask(
    Task *a,
    Task *b)
{
    Task temp = *a;
    *a = *b;
    *b = temp;
}


//SORT BY TITLE
static int partitionTitle(
    Task arr[],
    int low,
    int high)
{
    char pivot[100];

    strcpy(
        pivot,
        arr[high].title);

    int i =
        low - 1;

    for(int j = low;
        j < high;
        j++)
    {
        if(strcmp(
            arr[j].title,
            pivot) < 0)
        {
            i++;

            swapTask(
                &arr[i],
                &arr[j]);
        }
    }

    swapTask(
        &arr[i + 1],
        &arr[high]);

    return i + 1;
}



void quickSortByTitle(
    Task arr[],
    int low,
    int high)
{ if(low < high)
    {
        int pi =
            partitionTitle(
                arr,
                low,
                high);

        quickSortByTitle(
            arr,
            low,
            pi - 1);

        quickSortByTitle(
            arr,
            pi + 1,
            high);
    }
}



//SORT BY PRIORITY
static int partitionPriority(
    Task arr[],
    int low,
    int high)
{
    int pivot =
        arr[high].priority;

    int i =
        low - 1;

    for(int j = low;
        j < high;
        j++)
    {
        if(arr[j].priority <
           pivot)
        {
            i++;

            swapTask(
                &arr[i],
                &arr[j]);
        }
    }

    swapTask(
        &arr[i + 1],
        &arr[high]);

    return i + 1;
}



void quickSortByPriority(
    Task arr[],
    int low,
    int high)
{
    if(low < high)
    {
        int pi =
            partitionPriority(
                arr,
                low,
                high);

        quickSortByPriority(
            arr,
            low,
            pi - 1);

        quickSortByPriority(
            arr,
            pi + 1,
            high);
    }
}



//SORT BY DEADLINE
static int partitionDeadline(
    Task arr[],
    int low,
    int high)
{
    char pivot[20];

    strcpy(
        pivot,
        arr[high].deadline);

    int i =
        low - 1;

    for(int j = low;
        j < high;
        j++)
    {
        if(strcmp(
            arr[j].deadline,
            pivot) < 0)
        {
            i++;

            swapTask(
                &arr[i],
                &arr[j]);
        }
    }

    swapTask(
        &arr[i + 1],
        &arr[high]);

    return i + 1;
}



void quickSortByDeadline(
    Task arr[],
    int low,
    int high)
{
    if(low < high)
    {
        int pi =
            partitionDeadline(
                arr,
                low,
                high);

        quickSortByDeadline(
            arr,
            low,
            pi - 1);

        quickSortByDeadline(
            arr,
            pi + 1,
            high);
    }
}
