#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    int ID;
    char Taskname[100];
    int priority;
    int status;
};

int login();
void addTask();
void viewTask();
void updateTask(struct Task T[], int n); 
int deleteTask(struct Task T[], int n);

void saveAllToFile();


#endif