#include<stdio.h>
#include"FileFunctions.h"
void system(char *);
int main(void)
{
    int choice;
    FILE *fp1;
        system("cls");
        printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
        printf("                                                         Department Maintenance Menu\n                                                         ===========================\n\n");
        printf("                                                                1. Add Employee\n");
        printf("                                                                2. Print Employee Details\n");
        printf("                                                                3. Goto Main Menu\n\n");
        printf("                                                    Enter Your Choice  :  ");
        scanf("%d",&choice);
                switch(choice)
        {
            case 1 :system("cls");
                     addEmp();
                     break;
            case 2 :printEmp();
                     break;
            case 3 :return(0); 
        }
}