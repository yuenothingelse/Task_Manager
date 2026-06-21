#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

BSTNode *createNode(Task task)
{
    BSTNode *newNode =
        (BSTNode *)malloc(
            sizeof(BSTNode));

    if(newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    newNode->task = task;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}




BSTNode *insertBST(
    BSTNode *root,
    Task task)
{
    if(root == NULL)
    {
        return createNode(task);
    }

    if(task.id < root->task.id)
    {
        root->left =
            insertBST(
                root->left,
                task);
    }
    else if(task.id > root->task.id)
    {
        root->right =
            insertBST(
                root->right,
                task);
    }

    return root;
}




BSTNode *searchBST(
    BSTNode *root,
    int id)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->task.id == id)
    {
        return root;
    }

    if(id < root->task.id)
    {
        return searchBST(
            root->left,
            id);
    }

    return searchBST(
        root->right,
        id);
}



BSTNode *findMin(
    BSTNode *root)
{
    while(root &&
          root->left)
    {
        root =
            root->left;
    }

    return root;
}




BSTNode *deleteBST(
    BSTNode *root,
    int id)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(id < root->task.id)
    {
        root->left =
            deleteBST(
                root->left,
                id);
    }
    else if(id > root->task.id)
    {
        root->right =
            deleteBST(
                root->right,
                id);
    }
    else
    {
        if(root->left == NULL)
        {
            BSTNode *temp =
                root->right;

            free(root);

            return temp;
        }

        if(root->right == NULL)
        {
            BSTNode *temp =
                root->left;

            free(root);

            return temp;
        }

        BSTNode *temp =
            findMin(
                root->right);

        root->task =
            temp->task;

        root->right =
            deleteBST(
                root->right,
                temp->task.id);
    }

    return root;
}




int updateTaskInBST(
    BSTNode *root,
    int id,
    Task updatedTask)
{
    BSTNode *node =
        searchBST(
            root,
            id);

    if(node == NULL)
    {
        return 0;
    }

    node->task = updatedTask;

    return 1;
}




void printTask(
    Task task)
{
    printf("---------------------------------\n");

    printf(
        "ID        : %d\n",
        task.id);

    printf(
        "Title     : %s\n",
        task.title);

    printf(
        "Course    : %s\n",
        task.course);

    printf(
        "Deadline  : %s\n",
        task.deadline);

    printf(
        "Priority  : %d\n",
        task.priority);

    printf(
        "Status    : %s\n",
        task.status == COMPLETED ?
        "Completed" :
        "Pending");

    printf("---------------------------------\n");
}




void inorderTraversal(
    BSTNode *root)
{
    if(root == NULL)
    {
        return;
    }

    inorderTraversal(
        root->left);

    printTask(
        root->task);

    inorderTraversal(
        root->right);
}




void preorderTraversal(
    BSTNode *root)
{
    if(root == NULL)
    {
        return;
    }

    printTask(
        root->task);

    preorderTraversal(
        root->left);

    preorderTraversal(
        root->right);
}



void postorderTraversal(
    BSTNode *root)
{
    if(root == NULL)
    {
        return;
    }

    postorderTraversal(
        root->left);

    postorderTraversal(
        root->right);

    printTask(
        root->task);
}



int countTasks(
    BSTNode *root)
{
    if(root == NULL)
    {
        return 0;
    }

    return 1 +
           countTasks(
               root->left) +
           countTasks(
               root->right);
}




int countCompletedTasks(
    BSTNode *root)
{
    if(root == NULL)
    {
        return 0;
    }

    int count =
        (root->task.status ==
         COMPLETED);

    return count +
           countCompletedTasks(
               root->left) +
           countCompletedTasks(
               root->right);
}




int countPendingTasks(
    BSTNode *root)
{
    if(root == NULL)
    {
        return 0;
    }

    int count =
        (root->task.status ==
         PENDING);

    return count +
           countPendingTasks(
               root->left) +
           countPendingTasks(
               root->right);
}
