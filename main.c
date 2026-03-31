#include "main.h"
#include"auth.c"
#include"addAndView.c"
#include"Taskupdate.c"
#include"Taskdeletion.c"

 struct Task *list = NULL;
  int count = 0;
int main() {
    if (login() != 1){
        printf("invalid password");
        return 0;}

    int choice;
    char ch;
    do {
        printf("\n1.Add  2.View  3.Update  4.Delete  5.Exit\nChoice: ");
        scanf(" %d", &choice);

        switch(choice) {
            case 1: addTask(); break;
            case 2: viewTask(); break;
            case 3: updateTask(list, count); break;
            case 4: count = deleteTask(list, count); break; // Count update hoga
            case 5: exit(0);
            default: printf("Invalid choice!");
        }
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    free(list);
    return 0;
}