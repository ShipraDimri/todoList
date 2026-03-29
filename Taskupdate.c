#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions.h"
struct Task
{
    int ID;
    char Taskname[100];
};
void updateTask(struct Task T[], int n)
{
    int id, i,j;
    char newTask[100];
    printf("Enter ID to update task: ");
    scanf("%d",&id);
    for(i=0; i<n; i++)
    {
        if(T[i].ID == id)
        printf("Enter new Task: ");
        scanf("%s",newTask);
        for(j=0; newTask[j]!='\0'; j++)
        {
            T[i].Taskname[j] = newTask[j];
        }
        T[i].Taskname[j] = '\0';
        printf("Task update successfully!\n");
    }
    printf("ID not found\n");
}


