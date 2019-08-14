#include<stdio.h>
struct DEPT
{
    char dept_name[15];
    int dept_code;
};
int main(void)
{
    FILE *fp;
    FILE *fp1;

    int c=0,x=0;
    struct DEPT d1,d2;
    fp=fopen("depti.txt","a+");
    fp1=fp;
    while(fread(&d1,sizeof(struct DEPT),1,fp1))
        c++;
    fclose(fp1);
    struct DEPT d[25];
    while(x!=1){
        printf("enter\n");
        scanf("%d",&x);
    printf("Enter the name and code\n");
    d1.dept_code=1000+c;
    scanf("%s",d1.dept_name);
    if(fp==NULL)
        {
            printf("incorrect\n");
        }
    fwrite(&d1, sizeof(struct DEPT),1,fp);
    if(fwrite!=0)
    {
        c++;
        printf("success\n");
    }
    }
    fclose(fp);
    fp1=fopen("depti.txt","r");
    while(fread(&d2, sizeof(struct DEPT),1,fp1))
        printf("%d\t\t%s\n",d2.dept_code,d2.dept_name);
    fclose(fp1);
}