
#include <stdio.h>
#include <string.h>

char registeredUser[30] = ""; 
char registeredPass[30] = "";
int isRegistered = 0;
int login() {
    char u[30], p[30];
    int choice;

    while(1) {
        printf("\n--- WELCOME ---\n");
        printf("1. Register\n2. Login\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter a new username: ");
            scanf(" %[^\n]s", registeredUser); 
            
            printf("Enter a new password : ");
            scanf(" %[^\n]s", registeredPass);
            
            isRegistered = 1;
            printf("Registration Successful!now login yourself.\n");
        } 
        else if(choice == 2) {
            if(isRegistered == 0) {
                printf("Error: first register yourself!\n");
                continue; 
            }

            printf("Enter username: ");
            scanf(" %[^\n]s", u);
            printf("Enter password: ");
            scanf(" %[^\n]s", p);

            if(strcmp(u, registeredUser) == 0 && strcmp(p, registeredPass) == 0) {
                printf("Successfully Logged IN\n");
                return 1;
            } else {
                printf("invalid username or password!\n");
            }
        } 
        else if(choice == 3) return 0;
        else{
            printf("Invalid choice! Please try again.\n");
        }
    }
}