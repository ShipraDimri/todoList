
#include "main.h"

void updateTask(struct Task T[], int n) {
    int id, i, choice;
    char newTask[100];
    
    printf("Enter ID to update task: ");
    scanf("%d", &id);

    for(i = 0; i < n; i++) {
        if(T[i].ID == id) {
            printf("\n--- Updating Task ID: %d ---\n", id);
            printf("1. Update Task Name\n");
            printf("2. Mark as Completed (Status Update)\n");
            printf("3. Update Both\n");
            printf("Choice: ");
            scanf("%d", &choice);

            if (choice == 1 || choice == 3) {
                printf("Enter new Task Name: ");
                scanf(" %[^\n]s", T[i].Taskname); // Space ke sath naam lene ke liye
            }

            if (choice == 2 || choice == 3) {
                T[i].status = 1; // Mark as Completed
                printf("Status marked as COMPLETED!\n");
            }

            printf("Task updated successfully!\n");
            saveAllToFile(); // Update the file with the modified task
            return;
        }
    }
    printf("ID not found\n");
}

void saveAllToFile() {
    FILE *fp = fopen("todo.txt", "w"); // "w" mode purani file ko clear karke naya data likhega
    if (fp != NULL) {
        for (int i = 0; i < count; i++) {
            list[i].ID=i+1;
            char *statusStr = (list[i].status == 0) ? "Pending" : "Completed";
            fprintf(fp, "%d|%s|%d|%s\n", list[i].ID, list[i].Taskname, list[i].priority, statusStr);
        }
        fclose(fp);
    }
}