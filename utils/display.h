#ifndef DISPLAY_H
#define DISPLAY_H

#include "../bst/bst.h"
#include "../heap/heap.h"

//MENU
void showMainMenu();

//DASHBOARD
void showDashboard(
    BSTNode *root,
    MinHeap *heap
);

//STATISTIK
void showStatistics(
    BSTNode *root
);

//COMPLEXITY
void showComplexityAnalysis();

#endif
