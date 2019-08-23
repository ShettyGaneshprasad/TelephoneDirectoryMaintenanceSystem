//Telephone directory Maintenance System Project
//project by    Samarth Gaonkar     USN 2SD17CS080
//              Shetty Ganeshprasad USN 2SD17CS088
//              Nikhil Vernekar     USN 2SD17CS053
//              Niranjan Kumar      USN  2SD17CS054

//pre processing directory
#include <stdio.h>
#include <string.h>
void system(char *);
void sleep(int );
int main(void) //start of main function
{
    while(1){
    int userID, choice; //variables for user id and switch
    while (1)           //while loop for menu generation
    {
        system("cls"); //system call for clearing screen
        printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
        printf("                                                                Login Screen\n                                                                ============\n\n");
        printf("                                                    Enter the user ID   :  ");
        scanf("%d", &userID); //taking input from user
        //Belove code will authenticates the user
        if(userID==1780)
                {
                        printf("\n\n\n\n                                                    Welcome... Samarth Gaonkar...");
                        sleep(3);
                        break;        
                }
        else if(userID==1788)
                {
                        printf("\n\n\n\n                                                    Welcome... Shetty Ganeshprasad...");
                        sleep(3);
                        break;        
                }
              else if(userID==1753)
                {
                        printf("\n\n\n\n                                                    Welcome... Nikhil Vernekar...");
                        sleep(3);
                        break;        
                }
               else if(userID==1754)
                {
                        printf("\n\n\n\n                                                    Welcome... Niranjan Kumar...");
                        sleep(3);
                        break;        
                }
                        else
                {
                        printf("\n\n\n\n                                                    Invalid User ID... Try Again...");
                        sleep(3); 
                }  
    }
        while (1)             //while loops for menu generation
        {
            system("cls"); //system call for clearing screen
            printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
            printf("                                                                   Main  Menu\n                                                                   ==========\n\n");
            printf("                                                                1. Department Maintenance\n");
            printf("                                                                2. Employee Maintenance\n");
            printf("                                                                3. Telephone Directory Maintenance\n");
            printf("                                                                4. Exit\n\n");
            printf("                                                    Enter Your Choice  :  "); //menu generation
            scanf("%d", &choice);                                                                 //taking input from users
            switch (choice)                                                                       //switch statement for menu selection
            {
            case 1:
                system("DeptMaint.exe"); //calling DeptMaint.exe for department maintenance
                break;
            case 2:
                system("EmpMaint.exe"); //calling EmpMaint.exe for Employee maintenance
                break;
            case 3:
                system("TelDir.exe"); //calling Teldir.exe for telephone directory maintenance
                break;
            case 4:
                system("cls"); //calling system call for clearing screen
                return (0);
            } //emd of switch statement
        }
    }
    return (0);
} //end of main function