
void addTask() {
    struct todo *temp = realloc(list, (count + 1) * sizeof(struct todo));
    if (temp == NULL) {
        printf("memory not allocated");
        return;}
    list = temp;

    printf("Task Name: ");
    scanf(" %[^\n]s", list[count].name);
    printf("Priority (1-High, 2-Low): ");
    scanf("%d", &list[count].priority);
    
    list[count].status = 0; 
    count++;
    printf("Added!\n");
}

void viewTask() {
    if (count == 0) { printf("Khali hai!\n"); return; }
    for (int i = 0; i < count; i++) {
        printf("%d. %s [%s]\n", i+1, list[i].name, list[i].status ? "Done" : "Pending");
    }
}
void updateTask() { printf("Upcoming in Phase 2\n"); }
void deleteTask() { printf("Upcoming in Phase 2\n"); }