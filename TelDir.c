#include<stdio.h>
#include<string.h>
void system(char *);
int main(void)
{
    int userID,choice;
    while(1)
    {
        system("cls");
        printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
        printf("                                                                Login Screen\n                                                                ============\n\n");
        printf("                                                    Enter the user ID   :  ");
        scanf("%d",&userID);
        while(1)
        {
            system("cls");
            printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
            printf("                                                                   Main  Menu\n                                                                   ==========\n\n");
            printf("                                                                1. Department Maintenance\n");
            printf("                                                                2. Employee Maintenance\n");
            printf("                                                                3. Telephone Directory Maintenance\n");
            printf("                                                                4. Exit\n\n");
            printf("                                                    Enter Your Choice  :  ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1 : system("DeptMaint.exe");
                     break;
                case 2 : system("EmpMaint.exe");
                        break;
                case 3 :break;
                case 4 : return(0); 
        }
        }
        
    }
    return(0);
}