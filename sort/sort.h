#ifndef SORT_H
#define SORT_H

#include "../models/task.h"

//TITLE
void quickSortByTitle(
    Task arr[],
    int low,
    int high
);

//PRIORITY
void quickSortByPriority(
    Task arr[],
    int low,
    int high
);

//D LINE
void quickSortByDeadline(
    Task arr[],
    int low,
    int high
);

#endif
