#include"main.h"
extern struct Task *list; 
extern int count;
void addTask() {
    list = realloc(list, (count + 1) * sizeof(struct Task));
    
    list[count].ID = count + 1; 

    printf("Task Name: ");
    scanf(" %[^\n]s", list[count].Taskname);
    
    printf("Priority (1-High, 2-Low): ");
    scanf(" %d", &list[count].priority);
    
    list[count].status = 0;
    count++;
    printf("Task Added Successfully with ID: %d\n", list[count-1].ID);
}

void viewTask() {
    if (count == 0) {
        printf("Empty!\n");
        return;
    }
    printf("\n--- YOUR TASKS ---\n");
    for (int i = 0; i < count; i++) {
       
        char statusText[15];
        if (list[i].status == 0) {
            strcpy(statusText, "Pending");
        } else {
            strcpy(statusText, "Completed");
        }
        printf("ID: %d | Name: %s | Priority: %d | Status: [%s]\n", 
                list[i].ID, list[i].Taskname, list[i].priority, statusText);
    }
}