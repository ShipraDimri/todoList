#include"main.h"

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
        saveAllToFile();
        printf("Task Deleted succesfully!\n");
        return n;
    }
    printf("Task not found!\n");
    return n;
}