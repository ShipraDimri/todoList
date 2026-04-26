#include"main.h"
extern struct Task *list; 
extern int count;
void addTask() {
    list = realloc(list, (count + 1) * sizeof(struct Task));
    //list[count].ID = count + 1; 
    printf("Task Name: ");
    scanf(" %[^\n]s", list[count].Taskname);
    printf("Priority (1-High, 2-Low): ");
    scanf(" %d", &list[count].priority);
    list[count].status = 0;
    count++;
    saveAllToFile();
    /*FILE *fp = fopen("todo.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%d|%s|%d|Pending\n", list[count].ID, list[count].Taskname, list[count].priority);
        fclose(fp);
    }
    
    count++;*/
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

void loadTasks() {
    FILE *fp = fopen("todo.txt", "r");
    if (fp == NULL) return;
    if(list!=NULL){
        free(list);
        list=NULL;
    }

    char line[200], statusStr[15];
    count = 0; 
    while (fgets(line, sizeof(line), fp)) {
        list = realloc(list, (count + 1) * sizeof(struct Task));
        // %[^|] matlab '|' aane tak sab kuch read karo
        sscanf(line, "%d|%[^|]|%d|%s", &list[count].ID, list[count].Taskname, &list[count].priority, statusStr);
        
        if (strcmp(statusStr, "Pending") == 0) list[count].status = 0;
        else list[count].status = 1;
        
        count++;
    }
    fclose(fp);
}