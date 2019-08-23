//Telephone directory Maintenance System Project
//project by    Samarth Gaonkar     USN 2SD17CS080
//              Shetty Ganeshprasad USN 2SD17CS088
//              Nikhil Vernekar     USN 2SD17CS053
//              Niranjan Kumar      USN  2SD17CS054

//pre-processing directory
#include <stdio.h>
#include "FileFunctions.h" //importing Custom header file containing all file's functions
void system(char *);
int main(void) //start of main function
{
    int choice;    //for switch statement
    while(1)    //to repeat n times
    {
    system("cls"); //system csll for clearing screen
    printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
    printf("                                                         Department Maintenance Menu\n                                                         ===========================\n\n");
    printf("                                                                1. Add Department\n");
    printf("                                                                2. Print Department Details\n");
    printf("                                                                3. Goto Main Menu\n\n");
    printf("                                                    Enter Your Choice  :  "); //displaying options for end users
    scanf("%d", &choice);                                                                 //taking input from users
    switch (choice)                                                                       //start of switch statement
    {
    case 1:
        system("cls"); //sysrem call for clearing screen
        addDept();     //calling user defined function from Filefunction.h for adding department
        break;
    case 2:
        printDept(); //calling user defined function from Filefunction.h for printing department info
        break;
    case 3:
        return (0); //returning to FileFunction.c
    }
    }               //end of switch statement
} //end of main