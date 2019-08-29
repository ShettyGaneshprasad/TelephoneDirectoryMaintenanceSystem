//Telephone directory Maintenance System Project
//project by    Samarth Gaonkar     USN 2SD17CS080
//              Shetty Ganeshprasad USN 2SD17CS088
//              Nikhil Vernekar     USN 2SD17CS053
//              Niranjan Kumar      USN 2SD17CS054

//pre-processing Directory
#include <stdio.h>
#include <string.h>
void system(char *);
void sleep(int);
//structure for Dept
struct Dept
{
    char name[15]; //for storing name
    int code;      //for storing dept code
};
typedef struct Dept DEPT;

//structure for employee
struct Emp
{
    char ename[25]; //for storing employee name
    int ecode;      //for storing employe code
    char dname[15]; //for storing department name
    int dcode;      //for storing department code
    char loc[5];    //for storing location
    int tele;       //for storing telephone no
};
typedef struct Emp EMP;

//user defined function for adding department
int addDept(void);
int addDept(void)
{
    int end;
    DEPT d1, d2;
    FILE *fp1;     //file pointer for file operation
    FILE *fp2;     //file pointer for file operation
    char name[15]; //char for stioring name
    char dummy;
    fp1 = fopen("dept.txt", "a+"); //opening file dept.txt for file operation in append read and write mode
    fp2 = fp1;
     dummy = getchar();
    do
    {
    fseek(fp2, 0, SEEK_END); //moving file pointer to end of file
    end = ftell(fp2);        //storing end location to variable end
    system("cls");
    if (end == 0)
    {
        d1.code = 1000;
    }
    else
    {
        fseek(fp2, -20, SEEK_END);
        fread(&d2, sizeof(DEPT), 1, fp2);
        fseek(fp2, 0, SEEK_END);
        d1.code = (d2.code) + 1;
    }
    printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
    printf("                                                                 Add a Department \n");
    printf("                                                    Department Code           :\t%d\n", d1.code);
    printf("                                                    Enter the Department Name :\t");
    //scanf("%s", d1.name);
    gets(d1.name);
    if(strlen(d1.name) > 15)
    {
    printf("                                                    The Department name is too Big \n");
            sleep(3);
    }
    }while (strlen(d1.name) > 15);


    fseek(fp2, 0, SEEK_SET);
    while (fread(&d2, sizeof(DEPT), 1, fp1))
    {
        strcpy(name, d1.name);
        strlwr(name);
        strlwr(d2.name);
        if (!strcmp(name, d2.name))
        {
            printf("                                            The Department name is already exist !!!!\n");
            printf("                                                     Press Enter Key To Continue .....");
            dummy = getchar();
            dummy = getchar();
            return (0);
        }
    }
    fwrite(&d1, sizeof(DEPT), 1, fp1);
    printf("\n\n                                                 Department Added Sucessfully !!!!\n");
    printf("                                                     Press Enter Key To Continue .....");
    dummy = getchar();
    //dummy = getchar();
    fclose(fp1); //closeing opened file
}

//user defined function for printing department details
void printDept(void)
{
    FILE *fp1; //file pointer for file opertaion
    FILE *fp2; //file pointer for file operation
    DEPT d1;
    char dummy;
    fp1 = fopen("dept.txt", "a+"); //opening file dept.txt for file operation in append read and write mode
    fp2 = fopen("dept.txt", "a");  //opening file dept.txt for file operation in append read and write mode
    int end, beg;
    fseek(fp2, 0, SEEK_END);
    end = ftell(fp2);
    system("cls"); //system csll for clearing screen
    printf("\n\n\n\n\n\n\n");
    fclose(fp2);
    beg = ftell(fp1);
    printf("                                                        Telephone Directory Maintenance System\n                                                        ======================================\n\n");
    if (end == 0)
        printf("\t\t\t\t\t\t\t\t\tThere are no Departments!!!!\n");
    else
    {
        printf("\t\t\t\t\t\t\tDepartment Code\t\t\tDepartment Name\n\n");
        while (fread(&d1, sizeof(DEPT), 1, fp1))
        {
            //fread(&d1,sizeof(DEPT),1,fp1);
            printf("       \t\t\t\t \t\t\t%4d\t\t\t\t%-25s\n", d1.code, d1.name);
        }
        fclose(fp1);
    }
    printf("  \t\t\t\t\t\t\tPress Enter Key to Continue.....");
    dummy = getchar();
    dummy = getchar();
}

//user defined function for adding employee
int addEmp(void)
{
    int end, dCode, flag = 0;
    EMP d1;
    EMP d2;
    DEPT d3;
    FILE *fp1;                     //file pointer for file operation
    FILE *fp2;                     //file pointer for file operation
    FILE *fp3;                     //file pointer for file operation
    fp3 = fopen("dept.txt", "a+"); //opening file dept.txt for file operation in append read and write mode
    fseek(fp3, 0, SEEK_END);
    if(ftell(fp3)==0)
    {
        printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
        printf("\n\n\n\n\n\n\n\n                                                    There are No departments !!!! Please add and Continue.... \n");
        sleep(3);
        return(0);
    }
    fseek(fp3, 0, SEEK_SET);
    char dummy;
    dummy=getchar();
    fp1 = fopen("emp.txt", "a+"); //opening file emp.txt for file operation in append read and write mode
    fp2 = fp1;

    do
    {
    system("cls");
    fseek(fp2, 0, SEEK_END);
    end = ftell(fp2);
    if (end == 0)
    {
        d1.ecode = 1000;
    }
    else
    {
        //to get the emoloyee code of previous employee
        fseek(fp2, -64, SEEK_END);
        fread(&d2, sizeof(EMP), 1, fp2);
        fseek(fp2, 0, SEEK_END);
        d1.ecode = (d2.ecode) + 1;
    }

    printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
    printf("                                                                 Add a Department \n");
    printf("                                                    Employee ID                    :\t%d\n", d1.ecode);
    printf("                                                    Enter the Employee Name        :\t");
    gets(d1.ename);
    //scanf("%s", d1.ename);
        if(strlen(d1.ename) > 25)
        {
        printf("                                                    The Employee name is too Big \n");
        sleep(3);
        }
    }while (strlen(d1.ename) > 25);

    printf("                                                    Enter the Employee location   :\t");
    scanf("%s", d1.loc);
    while (strlen(d1.loc) > 5)
    {
        printf("                                            The Employee location is too Big \n");
        printf("                                                    Enter the Employee location    :\t");
        scanf("%s", d1.loc);
    }
    printf("\t\t\t\t\t\t\tDepartment Code\t\t\tDepartment Name\n\n");
    while (fread(&d3, sizeof(DEPT), 1, fp3))
    {
        printf("       \t\t\t\t \t\t\t%4d\t\t\t\t%-25s\n", d3.code, d3.name);
    }
    printf("                                             (Select the Employee department code from above table)\n");
    while (1)
    {
        printf("                                                    Enter the Employee department code :\t");
        scanf("%d", &dCode);
        fseek(fp3, 0, SEEK_SET);
        //the below code will searchs department name
        while (fread(&d3, sizeof(DEPT), 1, fp3) && (!flag))
        {
            if (dCode == d3.code)
            {
                flag = 1;
                strcpy(d1.dname, d3.name);
                d1.dcode = d3.code;
            }
        }
        if (flag == 0)
        {
            printf("                                                    Invalid Department code\n");
        }
        else
        {
            break;
        }
    }
    if (end == 0)
    {
        d1.ecode = 1000;
    }
    else
    {
        d1.ecode = (d2.ecode) + 1;
    }
    char name3[25],loc3[5];
    strcpy(name3,d1.ename);
    strlwr(name3);
    strcpy(loc3,d1.loc);
    strlwr(loc3);    
    fseek(fp2,0,SEEK_SET);
    // the below code will handle duplication of employees
    while(fread(&d2,sizeof(EMP),1,fp2))
    {
        strlwr(d2.ename);
        strlwr(d2.loc);
        if(!strcmp(name3,d2.ename)&&d1.dcode==d2.dcode&&(!strcmp(d2.loc,loc3)))//comparing all parameters 
        {
            printf("                                            All the details entered is matching with already exist Employee\n");
            printf("                                            Are you sure want to continue??? press any key for yes and n for no :");
            scanf(" %c",&dummy);
                    
            if(dummy == 'n'||dummy=='N')
            {
                printf("                                            Adding Employee is aborted\n");
                printf("                                                     Press Enter Key To Continue .....");
                dummy = getchar();
                dummy = getchar();
                return(0);
            }            
        }

    }
    fwrite(&d1, sizeof(EMP), 1, fp1);
    system("cls");
    printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
    printf("                                                                 Add a Department \n");
    printf("                                                    Employee ID          :   %d\n", d1.ecode);
    printf("                                                    Employee Name        :   %s\n", d1.ename);
    printf("                                                    Employee location    :   %s\n", d1.loc);
    printf("                                                    Department  Code     :   %d\n", d1.dcode);
    printf("                                                    Department Name      :   %s\n", d1.dname);
    printf("\n\n                                                 Employee Added Sucessfully !!!!\n");
    printf("                                                     Press Enter Key To Continue .....");

    dummy = getchar();
    dummy = getchar();
    system("cls"); //system csll for clearing screen
    fclose(fp1);
}

//user defined function for printing employee details
void printEmp(void)
{
    FILE *fp1; //file pointer for file operation
    FILE *fp2; //file pointer for file operation
    EMP d1;
    char dummy;
    fp1 = fopen("emp.txt", "a+"); //opening file emp.txt for file operation in append read and write mode
    fp2 = fopen("emp.txt", "a");  //opening file emp.txt for file operation in append read and write mode
    int end;
    fseek(fp2, 0, SEEK_END);
    end = ftell(fp2);
    system("cls"); //system csll for clearing screen
    printf("\n\n\n\n\n\n\n");
    fclose(fp2);
     printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
    if (end == 0)
        printf("\t\t\t\t\t\t\t\t\tThere are no Employees!!!!\n");
    else
    {
        printf("Employee ID  \t\tEmployee Name\t\t  Employee Location\t\tDepartment code\t\tDepartment Name\t\tTelephone\n\n");
        while (fread(&d1, sizeof(EMP), 1, fp1))
        {
            printf("%4d\t\t\t%-25s %-5s\t\t\t\t%4d\t\t\t%-15s\t\t", d1.ecode, d1.ename, d1.loc, d1.dcode, d1.dname);
            if ((d1.tele / 1000) == d1.dcode)
            {
                printf("%d\n", d1.tele);
            }
            else
            {
                printf("\n");
            }
        }
        fclose(fp1);
    }
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue.....");
    dummy = getchar();
    dummy = getchar();
}

//user defined function for adding telephone details
void addTele(void)
{
    FILE *fpe; //file pointer for file operation
    FILE *fpd; //file pointer for file operation
    EMP e, temp;
    int eCode, flag = 0, count;
    int dummy, teleno, i, j;
    fpe = fopen("emp.txt", "a+");
    fseek(fpe, 0, SEEK_END);
        if(ftell(fpe)==0)
    {
        printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
        printf("\n\n\n\n\n\n\n\n                                                    There are No Employees !!!! Please add and Continue.... \n");
        sleep(3);
        return;
    }
    fseek(fpe, 0, SEEK_END);
    count = ftell(fpe) / 64;
    EMP e1[count];
    fpd = fopen("emp.txt", "r");
    fread(&e1, sizeof(EMP), count, fpd);
    fwrite(&e1, sizeof(EMP), count, fpd);
    fclose(fpd);
    while (1)
    {
        printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
        printf("                                                             Add Telephone Number \n                                                             ====================\n\n");
        printf("                                                    Enter the Employee  ID :\t");
        scanf("%d", &eCode);

        for (i = 0; i < count; i++)
        {
            if (eCode == e1[i].ecode)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            system("cls"); //system csll for clearing screen
            printf("\n\n\n\n\n\n\n\n\n\n");
            printf("                                                    Invalid Employee ID !!!!\n");
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue.....");
            dummy = getchar();
            dummy = getchar();
            system("cls"); //system csll for clearing screen
        }
        else
        {
            break;
        }
    }
    teleno = (e1[i].dcode) * 1000 + 1;
    for (j = 0; j < count; j++)
    {
        if (teleno == e1[j].tele && e1[i].ecode == e1[j].ecode)
        {
            printf("                                                    Employee Telephone is Already allocated !!!!\n");
            break;
        }
        else if (teleno == e1[j].tele)
        {
            teleno++;
        }
        else
        {
            continue;
        }
    }
    e1[i].tele = teleno;
    system("cls");
    printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
    printf("                                                             Add Telephone Number \n                                                             ====================\n\n");
    printf("                                                    Employee ID                    :   %d\n", e1[i].ecode);
    printf("                                                    Employee location              :   %s\n", e1[i].loc);
    printf("                                                    Department  Code               :   %d\n", e1[i].dcode);
    printf("                                                    Telephone Number Allocated     :   %d\n", e1[i].tele);
    printf("\n\n                                             Employee Telephone Number Added Sucessfully !!!!\n");
    printf("                                                    Press Any Key To Continue .....");
    fclose(fpe);
    fpd = fopen("emp.txt", "w");
    fwrite(&e1, sizeof(EMP), count, fpd);
    fclose(fpd);
    dummy = getchar();
    dummy = getchar();
    system("cls"); //system csll for clearing screen
}

//user defined function for enquiring about employee
void enquiryEmp(void)
{
    int dummy;
    char name[15], name1[15], name2[15];
    FILE *fp1;
    EMP d1;
    system("cls"); //system csll for clearing screen
    fp1 = fopen("emp.txt", "a+");
    fseek(fp1, 0, SEEK_SET);
    fseek(fp1, 0, SEEK_END);
    if(ftell(fp1)==0)
    {
        printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
        printf("\n\n\n\n\n\n\n\n                                                    There are No Employees !!!! Please add and Continue.... \n");
        sleep(3);
        return;
    }
    fseek(fp1, 0, SEEK_SET);
    printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
    printf("                                                          Telephone Enquiry by Name\n                                                          =========================\n\n");
    printf("                                                          Enter Employee Name :  ");
    scanf("%s", name);
    strcpy(name1, strlwr(name));
    printf("\t\t\tEmployee Name\t\t  Employee Location\t\tDepartment Name\t\tTelephone\n\n");
    while (fread(&d1, sizeof(EMP), 1, fp1))
    {
        strcpy(name2, d1.ename);
        strlwr(name2);
        if (!strcmp(name1, name2))
        {
            printf("\t\t\t%-25s %-5s\t\t\t\t%-15s\t\t", d1.ename, d1.loc, d1.dname);
            if ((d1.tele / 1000) == d1.dcode)
            {
                printf("%d\n", d1.tele);
            }
            else
            {
                printf("\n");
            }
        }
    }
    fclose(fp1);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue.....");
    dummy = getchar();
    dummy = getchar();
}

//user defined function for enquiry telephone details
void enquiryTele(void)
{
    int dummy;
    int teleno, count = 0;
    FILE *fp1; //file pointer for file operation
    EMP d1;
    system("cls"); //system csll for clearing screen
    fp1 = fopen("emp.txt", "a+");
    fseek(fp1, 0, SEEK_END);

    if(ftell(fp1)==0)
    {
        printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
        printf("\n\n\n\n\n\n\n\n                                                    There are No Employees !!!! Please add and Continue.... \n");
        sleep(3);
        return;
    }
    fseek(fp1, 0, SEEK_SET);
    printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
    printf("                                                          Telephone Number Enquiry \n                                                          =========================\n\n");
    printf("                                                          Enter Employee Telephone Number :  ");
    scanf("%d", &teleno);
    while (fread(&d1, sizeof(EMP), 1, fp1))
    {
        if ((d1.tele) == teleno)
        {
            printf("                                                          Employee Name                   :   %s\n", d1.ename);
            printf("                                                          Employee location               :   %s\n", d1.loc);
            printf("                                                          Department  Name                :   %s\n", d1.dname);
            count++;
        }
    }
    if (count == 0)
    {
        printf("                                                          Invalid Telephone Number !!!! \n");
    }
    fclose(fp1);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue.....");
    dummy = getchar();
    dummy = getchar();
}