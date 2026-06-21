#include <stdio.h>

#include "display.h"


void showMainMenu()
{
    printf("\n");
    printf("=========================================\n");
    printf("        SMART TASK MANAGER\n");
    printf("=========================================\n");
    printf("1. Dashboard\n");
    printf("2. Add Task\n");
    printf("3. Edit Task\n");
    printf("4. Delete Task\n");
    printf("5. Search Task By ID\n");
    printf("6. Search Task By Course\n");
    printf("7. Show All Tasks\n");
    printf("8. Show Priority Tasks\n");
    printf("9. Sort Tasks\n");
    printf("10. Mark Task Completed\n");
    printf("11. Task Statistics\n");
    printf("12. Complexity Analysis\n");
    printf("13. Load Sample Data\n");
    printf("0. Exit\n");
    printf("=========================================\n");
}



void showDashboard(
    BSTNode *root,
    MinHeap *heap)
{
    int totalTasks =
        countTasks(root);

    int completedTasks =
        countCompletedTasks(root);

    int pendingTasks =
        countPendingTasks(root);

    printf("\n");
    printf("=========================================\n");
    printf("              DASHBOARD\n");
    printf("=========================================\n");

    printf(
        "Total Tasks      : %d\n",
        totalTasks);

    printf(
        "Completed Tasks  : %d\n",
        completedTasks);

    printf(
        "Pending Tasks    : %d\n",
        pendingTasks);

    Task *highest =
        getHighestPriorityTask(
            heap);

    printf(
        "\nHighest Priority Task\n");

    printf(
        "-----------------------------------------\n");

    if(highest != NULL)
    {
        printf(
            "ID       : %d\n",
            highest->id);

        printf(
            "Title    : %s\n",
            highest->title);

        printf(
            "Course   : %s\n",
            highest->course);

        printf(
            "Deadline : %s\n",
            highest->deadline);

        printf(
            "Priority : %d\n",
            highest->priority);

        printf(
            "Status   : %s\n",
            highest->status == COMPLETED ?
            "Completed" :
            "Pending");
    }
    else
    {
        printf(
            "No task available.\n");
    }

    printf(
        "=========================================\n");
}



void showStatistics(
    BSTNode *root)
{
    int totalTasks =
        countTasks(root);

    int completedTasks =
        countCompletedTasks(root);

    int pendingTasks =
        countPendingTasks(root);

    printf("\n");
    printf("=========================================\n");
    printf("            TASK STATISTICS\n");
    printf("=========================================\n");

    printf(
        "Total Tasks      : %d\n",
        totalTasks);

    printf(
        "Completed Tasks  : %d\n",
        completedTasks);

    printf(
        "Pending Tasks    : %d\n",
        pendingTasks);

    if(totalTasks > 0)
    {
        double percentage =
            ((double)completedTasks /
             totalTasks) * 100.0;

        printf(
            "Completion Rate  : %.2f%%\n",
            percentage);
    }
    else
    {
        printf(
            "Completion Rate  : 0%%\n");
    }

    printf(
        "=========================================\n");
}



void showComplexityAnalysis()
{
    printf("\n");
    printf("=========================================\n");
    printf("         COMPLEXITY ANALYSIS\n");
    printf("=========================================\n");

    printf(
        "BST Search             : O(log n)\n");

    printf(
        "BST Insert             : O(log n)\n");

    printf(
        "BST Delete             : O(log n)\n");

    printf(
        "Tree Traversal         : O(n)\n");

    printf(
        "Hash Search            : O(1)\n");

    printf(
        "Hash Insert            : O(1)\n");

    printf(
        "Heap Insert            : O(log n)\n");

    printf(
        "Heap Delete            : O(log n)\n");

    printf(
        "Highest Priority       : O(1)\n");

    printf(
        "Quick Sort Average     : O(n log n)\n");

    printf(
        "Quick Sort Worst Case  : O(n²)\n");

    printf(
        "=========================================\n");
}
