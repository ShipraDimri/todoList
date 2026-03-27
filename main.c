#include "main.h"
struct todo *list = NULL;
int count = 0;
#include"auth.c"
#include"addAndView.c"
int main(){
    if(login()!=1){
        printf("invalid password");
        return 0;
    }
    int choice;
    char ch;
    do{
    printf("\n1.AddTask   ,2.ViewTask    ,3.UpdateTask    ,4.DeleteTask");
    printf("enter the choice:");
    scanf("%d",&choice);

    switch(choice){
        case 1: addTask();
                break;
        case 2: viewTask();
                break;
        case 3:updateTask();
               break;
        case 4:deleteTask();
               break;
        default: printf("invalid choice");

                 break;
    }

printf("do you want to continue?(y/n)");
scanf(" %c",&ch);
}
while(ch=='y'||ch=='Y');

printf("existing.....memory freed\n");
free(list);
return 0;
}

