#ifndef TASK_H
#define TASK_H

#define TITLE_LENGTH 100
#define COURSE_LENGTH 50
#define DEADLINE_LENGTH 20

typedef enum {
    PENDING = 0,
    COMPLETED = 1
} TaskStatus;

typedef struct {
    int id;
    char title[TITLE_LENGTH];
    char course[COURSE_LENGTH];
    char deadline[DEADLINE_LENGTH];
    int priority;
    TaskStatus status;
} Task;

#endif
