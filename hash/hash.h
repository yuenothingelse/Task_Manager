#ifndef HASH_H
#define HASH_H

#include "../models/task.h"

#define TABLE_SIZE 23

typedef struct HashNode {
    Task task;
    struct HashNode *next;
} HashNode;

extern HashNode *hashTable[TABLE_SIZE];

//HASH FUNC
int hashFunction(const char *course);

//INSERT
void insertHash(Task task);

//SEARCH
void searchByCourse(const char *course);

//DELETE
void deleteHash(int id);

//UPDATE
void updateHash(Task task);

//DISPLAY
void displayCourseTasks(const char *course);

//CLEAN UP
void freeHashTable();

#endif
