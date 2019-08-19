//Telephone directory Maintenance System Project
//project by    Samarth Gaonkar     USN 2SD17CS080
//              Shetty Ganeshprasad USN 2SD17CS088
//              Nikhil Vernekar     USN 2SD17CS053
//              Niranjan Kumar      USN  2SD17CS054

//pre_processing directive
#include <stdio.h>
#include "FileFunctions.h" //importing Custom header file containing all file's functions
void system(char *);

int main(void) //start of main function
{
        int choice;    //variable for switch statement
        FILE *fp1;     //file pointer for file operation
        system("cls"); //calling system call for clearing screen
        printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
        printf("                                                     Telephone Directory Maintenance Menu\n                                                     ====================================\n\n");
        printf("                                                                1. Add Telephone Number\n");
        printf("                                                                2. Telephone Number Enquiry\n");
        printf("                                                                3. Goto Main Menu\n\n");
        printf("                                                                Enter Your Choice  :  "); //menu genration
        scanf("%d", &choice);                                                                             //taking input from users
        switch (choice)
        {
        case 1:
                system("cls"); //system csll for clearing screen
                addTele();     //calling user defined function from Filefunction.h for adding telephone info
                break;
        case 2:
                system("cls"); //system call for clearing screen
                printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
                printf("                                                             Telephone Enquiry Menu\n                                                             ======================\n\n");
                printf("                                                             1. Enquiry on Employee Name\n");
                printf("                                                             2. Enquiry on Telephone Number \n");
                printf("                                                             3. Goto Main Menu\n\n");
                printf("                                                             Enter Your Choice  :  "); //menu genertaion
                scanf("%d", &choice);                                                                          //taking input from user
                switch (choice)
                {
                case 1:
                        enquiryEmp(); //calling user defined function from Filefunction.h for enquiring about employee
                        break;
                case 2:
                        enquiryTele(); //calling user defined function from Filefunction.h for enquiriing about telephone number
                        break;
                case 3:
                        return (0); //return to FileFunction.c

                } //end of inner switch statement

        case 3:
                return (0);
        } //end of outerswitch statement
} //end of main