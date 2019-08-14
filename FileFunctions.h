#include<stdio.h>
#include<string.h>
void system(char *);
struct Dept
{
    char name[15];
    int code;

};
typedef struct Dept DEPT;
struct Emp
{
    char ename[25];
    int ecode;
    char dname[15];
    int dcode;
    char loc[5];
    int tele;
};
typedef struct Emp EMP;
void addDept(void);
void addDept(void)
{
    int end;
    DEPT d1,d2;
    FILE *fp1;
    FILE *fp2;
    char dummy;
    fp1=fopen("dept.txt","a+");
    fp2=fp1;
    fseek(fp2,0,SEEK_END);
    end=ftell(fp2);
    if(end==0)
     {
            d1.code=1000;
     }
    else
    {
        fseek(fp2,-20,SEEK_END);
        fread(&d2,sizeof(DEPT),1,fp2);
        fseek(fp2,0,SEEK_END);
        d1.code=(d2.code)+1;
    }
    
            printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
            printf("                                                                 Add a Department \n");
            printf("                                                    Department Code           :\t%d\n",d1.code);
            printf("                                                    Enter the Department Name :\t");
            scanf("%s", d1.name);
            while(strlen(d1.name)>15)
            {
                printf("                                            The Department name is too Big \n");
            printf("                                                    Enter the Department Name :\t");
            scanf("%s", d1.name);
            }
            fwrite(&d1,sizeof(DEPT),1,fp1);
                fseek(fp1,-20,SEEK_END);
                fread(&d2,sizeof(DEPT),1,fp1);

            printf("\n\n                                                 Department Added Sucessfully !!!!\n");
            printf("                                                     Press Any Key To Continue .....");
            dummy=getchar();
            dummy=getchar();
    fclose(fp1);
}
void printDept(void)
{
    FILE *fp1;
    FILE *fp2;
    DEPT d1;
    char  dummy;
    fp1=fopen("dept.txt","a+");
    fp2=fopen("dept.txt","a");
    int end,beg;
    fseek(fp2,0,SEEK_END);
    end=ftell(fp2);
    system("cls");
    printf("\n\n\n\n\n\n\n");
    fclose(fp2);
    beg=ftell(fp1);
    if(end==0)
    printf("\t\t\t\t\t\t\t\t\tThere are no Departments!!!!\n");
    else
    {
        printf("\t\t\t\t\t\t\tDepartment Code\t\t\tDepartment Name\n\n");
    while( fread(&d1,sizeof(DEPT),1,fp1))
    {
        //fread(&d1,sizeof(DEPT),1,fp1);
        printf("       \t\t\t\t \t\t\t%4d\t\t\t\t%-25s\n",d1.code,d1.name);
    }
    fclose(fp1);
    }
    printf("\t\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue.....");
    dummy=getchar();
    dummy=getchar();
}
void addEmp(void)
{
    int end,dCode,flag=0;
    EMP d1;    
    EMP d2;
    DEPT d3;
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    fp3=fopen("dept.txt","a+");
        fseek(fp3,0,SEEK_SET);
    char dummy;
    fp1=fopen("emp.txt","a+");
    fp2=fp1;
    fseek(fp2,0,SEEK_END);
    end=ftell(fp2);
    if(end==0)
     {
            d1.ecode=1000;
     }
    else
    {
        fseek(fp2,-64,SEEK_END);
        fread(&d2,sizeof(EMP),1,fp2);
        fseek(fp2,0,SEEK_END);
        d1.ecode=(d2.ecode)+1;
    }
    
            printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
            printf("                                                                 Add a Department \n");
            printf("                                                    Employee Code                  :\t%d\n",d1.ecode);
            printf("                                                    Enter the Employee Name        :\t");
            scanf("%s", d1.ename);
            while(strlen(d1.ename)>25)
            {
                printf("                                            The Employee name is too Big \n");
            printf("                                                    Enter the Employee Name        :\t");
            scanf("%s", d1.ename);
            }
             printf("                                                    Enter the Employee location   :\t");
            scanf("%s", d1.loc);
            while(strlen(d1.loc)>5)
            {
                printf("                                            The Employee name is too Big \n");
            printf("                                                    Enter the Employee location    :\t");
            scanf("%s", d1.loc);
            }
        printf("\t\t\t\t\t\t\tDepartment Code\t\t\tDepartment Name\n\n");
        while( fread(&d3,sizeof(DEPT),1,fp3))
        {
             //fread(&d1,sizeof(DEPT),1,fp1);
            printf("       \t\t\t\t \t\t\t%4d\t\t\t\t%-25s\n",d3.code,d3.name);
        }
        printf("                                             (Select the Employee department code from above table)\n");
        while(1)
        {
            printf("                                                    Enter the Employee department code :\t");
            scanf("%d",&dCode);
            fseek(fp3,0,SEEK_SET);
                while( fread(&d3,sizeof(DEPT),1,fp3)&&(!flag))
                {
                    if(dCode==d3.code)
                    {
                        flag=1;
                         strcpy(d1.dname,d3.name);
                         d1.dcode=d3.code;
                    }
                        
                    
                }
                if(flag==0)
                {
                    printf("                                                    Invalid Department code\n");
                }
                else
                {
                    break;
                }       
        }   
                       
            fwrite(&d1,sizeof(EMP),1,fp1);
                fseek(fp1,-64,SEEK_END);
                fread(&d2,sizeof(EMP),1,fp1);
                printf("%d\n%s\n",d2.ecode,d2.ename);
                system("cls");
            printf("                                                    Telephone Directory Maintenance System\n                                                    ======================================\n\n");
            printf("                                                                 Add a Department \n");
            printf("                                                    Employee Code        :   %d\n",d1.ecode);
            printf("                                                    Employee Name        :   %s\n",d1.ename);
            printf("                                                    Employee location    :   %s\n",d1.loc);
            printf("                                                    Department  Code     :   %d\n",d1.dcode);
            printf("                                                    Department Name      :   %s\n",d1.dname);
            printf("\n\n                                                 Employee Added Sucessfully !!!!\n");
            printf("                                                     Press Any Key To Continue .....");
            
            dummy=getchar();
            dummy=getchar();
            system("cls");
    fclose(fp1);
}
void printEmp(void)
{
    FILE *fp1;
    FILE *fp2;
    EMP d1;
    char  dummy;
    fp1=fopen("emp.txt","a+");
    fp2=fopen("emp.txt","a");
    int end,beg;
    fseek(fp2,0,SEEK_END);
    end=ftell(fp2);
    system("cls");
    printf("\n\n\n\n\n\n\n");
    fclose(fp2);
    beg=ftell(fp1);
    if(end==0)
    printf("\t\t\t\t\t\t\t\t\tThere are no Employees!!!!\n");
    else
    {
        printf("Employee Code\t\tEmployee Name\t\t  Employee Location\t\tDepartment code\t\tDepartment Name\t\tTelephone\n\n");
    while( fread(&d1,sizeof(EMP),1,fp1))
    {
        printf("%4d\t\t\t%-25s %-5s\t\t\t\t%4d\t\t\t%-15s\n",d1.ecode,d1.ename,d1.loc,d1.dcode,d1.dname);
    }
    fclose(fp1);
    }
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue.....");
    dummy=getchar();
    dummy=getchar();
}