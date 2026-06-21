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

//HELPERS

int findTaskIndexByID(int id)
{
    for(int i = 0; i < taskCount; i++)
    {
        if(taskList[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

void rebuildStructures()
{
    root = NULL;

    freeHashTable();

    initHeap(&heap);

    for(int i = 0; i < taskCount; i++)
    {
        root = insertBST(root, taskList[i]);

        insertHash(taskList[i]);

        insertHeap(&heap, taskList[i]);
    }
}

//LOAD FILE DATA CSV

void loadDataFromFile()
{
    if(taskCount > 0)
    {
        printf("\nData already loaded.\n");
        return;
    }

    FILE *fp =
        fopen("sample_data.csv", "r");

    if(fp == NULL)
    {
        printf(
            "\nFailed to open sample_data.csv\n");

        return;
    }

    char line[512];

    fgets(
        line,
        sizeof(line),
        fp);

    while(
        fgets(
            line,
            sizeof(line),
            fp))
    {
        if(taskCount >= MAX_TASKS)
        {
            break;
        }

        Task task;

        char *token;

        token = strtok(line, ",");

        if(token == NULL)
            continue;

        task.id = atoi(token);

        token = strtok(NULL, ",");

        if(token == NULL)
            continue;

        strcpy(task.title, token);

        token = strtok(NULL, ",");

        if(token == NULL)
            continue;

        strcpy(task.course, token);

        token = strtok(NULL, ",");

        if(token == NULL)
            continue;

        strcpy(task.deadline, token);

        token = strtok(NULL, ",");

        if(token == NULL)
            continue;

        task.priority = atoi(token);

        task.status = PENDING;

        task.title[
            strcspn(
                task.title,
                "\r\n")] = '\0';

        task.course[
            strcspn(
                task.course,
                "\r\n")] = '\0';

        task.deadline[
            strcspn(
                task.deadline,
                "\r\n")] = '\0';

        taskList[taskCount++] = task;

        root =
            insertBST(
                root,
                task);

        insertHash(task);

        insertHeap(
            &heap,
            task);
    }

    fclose(fp);

    printf(
        "\nSample data loaded successfully.\n");
}

//ADD TASK

void addTask()
{
    if(taskCount >= MAX_TASKS)
    {
        printf("\nStorage Full.\n");
        return;
    }

    Task task;

    printf("\nTask ID : ");
    scanf("%d", &task.id);

    if(findTaskIndexByID(task.id) != -1)
    {
        printf("\nID already exists.\n");
        return;
    }

    getchar();

    printf("Title : ");
    fgets(task.title, TITLE_LENGTH, stdin);
    task.title[strcspn(task.title,"\n")] = '\0';

    printf("Course : ");
    fgets(task.course, COURSE_LENGTH, stdin);
    task.course[strcspn(task.course,"\n")] = '\0';

    printf("Deadline (YYYY-MM-DD) : ");
    fgets(task.deadline, DEADLINE_LENGTH, stdin);
    task.deadline[strcspn(task.deadline,"\n")] = '\0';

    printf("Priority (1 Highest) : ");
    scanf("%d", &task.priority);

    task.status = PENDING;

    taskList[taskCount++] = task;

    root = insertBST(root, task);

    insertHash(task);

    insertHeap(&heap, task);

    printf("\nTask Added Successfully.\n");
}

//EDIT TASK

void editTask()
{
    int id;

    printf("\nEnter Task ID : ");
    scanf("%d",&id);

    int index =
        findTaskIndexByID(id);

    if(index == -1)
    {
        printf("\nTask Not Found.\n");
        return;
    }

    getchar();

    printf("New Title : ");
    fgets(taskList[index].title,
          TITLE_LENGTH,
          stdin);

    taskList[index].title[
        strcspn(
            taskList[index].title,
            "\n")] = '\0';

    printf("New Course : ");
    fgets(taskList[index].course,
          COURSE_LENGTH,
          stdin);

    taskList[index].course[
        strcspn(
            taskList[index].course,
            "\n")] = '\0';

    printf("New Deadline : ");
    fgets(taskList[index].deadline,
          DEADLINE_LENGTH,
          stdin);

    taskList[index].deadline[
        strcspn(
            taskList[index].deadline,
            "\n")] = '\0';

    printf("New Priority : ");
    scanf("%d",
          &taskList[index].priority);

    rebuildStructures();

    printf("\nTask Updated.\n");
}

//DELETE TASK

void deleteTask()
{
    int id;

    printf("\nEnter Task ID : ");
    scanf("%d",&id);

    int index =
        findTaskIndexByID(id);

    if(index == -1)
    {
        printf("\nTask Not Found.\n");
        return;
    }

    for(int i = index;
        i < taskCount - 1;
        i++)
    {
        taskList[i] =
            taskList[i + 1];
    }

    taskCount--;

    rebuildStructures();

    printf("\nTask Deleted.\n");
}

//SEARCH BY ID

void searchTaskByID()
{
    int id;

    printf("\nTask ID : ");
    scanf("%d",&id);

    BSTNode *node =
        searchBST(
            root,
            id);

    if(node == NULL)
    {
        printf("\nTask Not Found.\n");
        return;
    }

    printTask(
        node->task);
}

//SEARCH BY COURSE

void searchTaskByCourse()
{
    char course[COURSE_LENGTH];

    getchar();

    printf("\nCourse : ");

    fgets(course,
          COURSE_LENGTH,
          stdin);

    course[
        strcspn(
            course,
            "\n")] = '\0';

    searchByCourse(course);
}

//SHOW ALL TASKS

void showAllTasks()
{
    if(root == NULL)
    {
        printf("\nNo Tasks Available.\n");
        return;
    }

    printf(
        "\n===== ALL TASKS =====\n");

    inorderTraversal(root);
}

//SHOW PRIORITY TASKS

void showPriorityTasks()
{
    displayPriorityQueue(
        &heap);
}

//MARK COMPLETED


void markTaskCompleted()
{
    int id;

    printf("\nTask ID : ");
    scanf("%d",&id);

    int index =
        findTaskIndexByID(id);

    if(index == -1)
    {
        printf("\nTask Not Found.\n");
        return;
    }

    taskList[index].status =
        COMPLETED;

    rebuildStructures();

    printf(
        "\nTask Marked As Completed.\n");
}

//SORT MENU

void sortTasks()
{
    if(taskCount == 0)
    {
        printf("\nNo Tasks Available.\n");
        return;
    }

    Task temp[MAX_TASKS];

    for(int i = 0;
        i < taskCount;
        i++)
    {
        temp[i] =
            taskList[i];
    }

    int choice;

    printf("\n");
    printf("1. Sort By Title\n");
    printf("2. Sort By Priority\n");
    printf("3. Sort By Deadline\n");

    printf("Choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            quickSortByTitle(
                temp,
                0,
                taskCount - 1);
            break;

        case 2:
            quickSortByPriority(
                temp,
                0,
                taskCount - 1);
            break;

        case 3:
            quickSortByDeadline(
                temp,
                0,
                taskCount - 1);
            break;

        default:
            return;
    }

    printf(
        "\n===== SORT RESULT =====\n");

    for(int i = 0;
        i < taskCount;
        i++)
    {
        printf(
            "%d | %s | %s | %s | P:%d | %s\n",
            temp[i].id,
            temp[i].title,
            temp[i].course,
            temp[i].deadline,
            temp[i].priority,
            temp[i].status ==
            COMPLETED ?
            "Completed" :
            "Pending");
    }
}

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
