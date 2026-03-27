#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct todo{
    char name[30];
    int priority;
    int status;
};
int login();
void addTaask();
void viewTask();
void updateTask();
void deleteTask();
#endif