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
        printf("                                                                1. Add Department\n");
        printf("                                                                2. Print Department Details\n");
        printf("                                                                3. Goto Main Menu\n\n");
        printf("                                                    Enter Your Choice  :  ");
        scanf("%d",&choice);
                switch(choice)
        {
            case 1 :system("cls");
                     addDept();
                     break;
            case 2 :printDept();
                     break;
            case 3 :return(0); 
        }
}