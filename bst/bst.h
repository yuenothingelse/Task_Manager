#ifndef BST_H
#define BST_H

#include "../models/task.h"

typedef struct BSTNode {
    Task task;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

//CREATE
BSTNode *createNode(Task task);

//INSERT
BSTNode *insertBST(
    BSTNode *root,
    Task task
);

//SEARCH
BSTNode *searchBST(
    BSTNode *root,
    int id
);

//DELETE
BSTNode *deleteBST(
    BSTNode *root,
    int id
);

//UPDATE
int updateTaskInBST(
    BSTNode *root,
    int id,
    Task updatedTask
);

//HELP
BSTNode *findMin(
    BSTNode *root
);

//TRAVERSAL
void inorderTraversal(
    BSTNode *root
);

void preorderTraversal(
    BSTNode *root
);

void postorderTraversal(
    BSTNode *root
);

//STATISTK
int countTasks(
    BSTNode *root
);

int countCompletedTasks(
    BSTNode *root
);

int countPendingTasks(
    BSTNode *root
);

//DISPLAY
void printTask(
    Task task
);

#endif
