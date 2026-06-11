#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "models/task.h"

#include "bst/bst.h"
#include "hash/hash.h"
#include "heap/heap.h"
#include "sort/sort.h"
#include "utils/display.h"

#define MAX_TASKS 100

Task taskList[MAX_TASKS];

int taskCount = 0;

BSTNode *root = NULL;

MinHeap heap;

//MAIN

int main()
{
    initHeap(&heap);

    int choice;

    do
    {
        showMainMenu();

        printf("\nChoice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                showDashboard(root, &heap);
                break;

            case 2:
                addTask();
                break;

            case 3:
                editTask();
                break;

            case 4:
                deleteTask();
                break;

            case 5:
                searchTaskByID();
                break;

            case 6:
                searchTaskByCourse();
                break;

            case 7:
                showAllTasks();
                break;

            case 8:
                showPriorityTasks();
                break;

            case 9:
                sortTasks();
                break;

            case 10:
                markTaskCompleted();
                break;

            case 11:
                showStatistics(root);
                break;

            case 12:
                showComplexityAnalysis();
                break;

            case 13:
                loadDataFromFile();
                break;

            case 0:
                printf("\nThank You.\n");
                break;

            default:
                printf("\nInvalid Choice.\n");
        }

    } while(choice != 0);

    freeHashTable();

    return 0;
}
