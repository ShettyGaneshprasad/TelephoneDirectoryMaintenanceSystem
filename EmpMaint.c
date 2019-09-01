//Telephone directory Maintenance System Project
//project by    Samarth Gaonkar     USN 2SD17CS080
//              Shetty Ganeshprasad USN 2SD17CS088
//              Nikhil Vernekar     USN 2SD17CS053
//              Niranjan Kumar      USN  2SD17CS054

//importing pre-processing directive
#include <stdio.h>
#include "FileFunctions.h" //importing Custom header file containing all file's functions
void system(char *);

int main(void) //statr of main fubction
{
    int choice;    //variable for switch
    while(1) // to repeat n times
    {
    system("cls"); //system call for clearing screen
    printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
    printf("                                                            Employee Maintenance Menu\n                                                         ===========================\n\n");
    printf("                                                                1. Add Employee\n");
    printf("                                                                2. Print Employee Details\n");
    printf("                                                                3. Delete An Employee\n");
    printf("                                                                4. Goto Main Menu\n\n");
    printf("                                                    Enter Your Choice  :  "); //displaying options for end users
    scanf("%d", &choice);                                                                 //taking input from users
    switch (choice)                                                                       //start of switch statement
    {
    case 1:
        system("cls"); //system defined function for clearing screen
        addEmp();      //calling user defined function from Filefunction.h for adding employee in file
        break;
    case 2:
        printEmp(); //calling user defined function from Filefunction.h for printing employee details from file
        break;
    case 3:
        deleteEmp(); //calling user defined function from Filefunction.h for delete employee details from file
        break;
    case 4:
        return (0); //returning to previous function
    }
    }               //end of switch statement
} //end of main function