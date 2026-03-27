
int login(){
    char p[30];
    printf("enter the password to login:");
    scanf("%s",p);
    if(strcmp(p,"1234")==0){
        printf("Sucessfully Logged IN\n");
        return 1;
    }
    return 0;
}