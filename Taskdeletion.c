#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions.h"
struct Task
{
    int ID;
    char Taskname[100];
};
int deleteTask(struct Task T[], int n)
{
    int id ,i ,j;
    printf("Enter Task ID to delete: ");
    scanf("%d",&id);
    for(i=0 ;i<n ;i++)
    {
        if(T[i].ID == id)
        for(j=i; j<n-1; j++)
        {
            T[j]=T[j+1];
        }
        n--;
        printf("Task Deleted succesfully!\n");
    }
    printf("Task not found!\n");
    return n;
}