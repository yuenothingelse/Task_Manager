#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

HashNode *hashTable[TABLE_SIZE] = {NULL};

int hashFunction(const char *course)
{
    int hash = 0;

    while(*course)
    {
        hash = (hash * 31 + *course) % TABLE_SIZE;
        course++;
    }

    return hash;
}

void insertHash(Task task)
{
    int index =
        hashFunction(task.course);

    HashNode *newNode =
        (HashNode *)malloc(
            sizeof(HashNode));

    if(newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->task = task;
    newNode->next = hashTable[index];

    hashTable[index] = newNode;
}

void searchByCourse(const char *course)
{
    int index =
        hashFunction(course);

    HashNode *current =
        hashTable[index];

    int found = 0;

    while(current)
    {
        if(strcmp(
            current->task.course,
            course) == 0)
        {
            printf("---------------------------------\n");

            printf(
                "ID        : %d\n",
                current->task.id);

            printf(
                "Title     : %s\n",
                current->task.title);

            printf(
                "Course    : %s\n",
                current->task.course);

            printf(
                "Deadline  : %s\n",
                current->task.deadline);

            printf(
                "Priority  : %d\n",
                current->task.priority);

            printf(
                "Status    : %s\n",
                current->task.status == COMPLETED ?
                "Completed" :
                "Pending");

            printf("---------------------------------\n");

            found = 1;
        }

        current =
            current->next;
    }

    if(!found)
    {
        printf(
            "\nNo tasks found for course: %s\n",
            course);
    }
}

void displayCourseTasks(const char *course)
{
    searchByCourse(course);
}

void deleteHash(int id)
{
    for(int i = 0;
        i < TABLE_SIZE;
        i++)
    {
        HashNode *current =
            hashTable[i];

        HashNode *previous =
            NULL;

        while(current)
        {
            if(current->task.id == id)
            {
                if(previous == NULL)
                {
                    hashTable[i] =
                        current->next;
                }
                else
                {
                    previous->next =
                        current->next;
                }

                free(current);
                return;
            }

            previous =
                current;

            current =
                current->next;
        }
    }
}

void updateHash(Task task)
{
    for(int i = 0;
        i < TABLE_SIZE;
        i++)
    {
        HashNode *current =
            hashTable[i];

        while(current)
        {
            if(current->task.id == task.id)
            {
                current->task =
                    task;

                return;
            }

            current =
                current->next;
        }
    }

    insertHash(task);
}

void freeHashTable()
{
    for(int i = 0;
        i < TABLE_SIZE;
        i++)
    {
        HashNode *current =
            hashTable[i];

        while(current)
        {
            HashNode *temp =
                current;

            current =
                current->next;

            free(temp);
        }

        hashTable[i] = NULL;
    }
}
