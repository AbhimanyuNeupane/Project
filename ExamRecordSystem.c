#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Data
{
    int id,s_marks,e_marks,m_marks,n_marks;
    char name[20];
    char a[0];
    float percentage;
    char grade;
}save_d[50],read_d[50];



void getdata();
void read_data();
void option();
void showdata();
void case_default();
//***************************************************************
//                   DECLARATION OF VARIABLES IN PROJECT
//****************************************************************
    int id,s_marks,e_marks,m_marks,n_marks;
    char name[20],address,grade;
    char a[0];
    float percentage;
    FILE *fptr;
//***************************************************************
//                   FUNCTION USED IN PROJECT
//****************************************************************
void login()
{
    int num,count=0;
	do
	{
		system("cls");
        if(count>0)
            {
                printf("-------------------\n");
                printf("****Invalid pin****\n");
                printf("-------------------\n");
            }
            printf("Enter the password:   \n");
            scanf("%d",&num);
            count++;
	}while((num!=1234)&&(count<3));   //boundary value//
	if((count<=3) && (num==1234))
        {
            system("cls");
            printf("--------------------------\n");
            printf("   ***Welcome***\n");
            printf("--------------------------\n");
            option();
        }
	else
        {
            printf("----------------------------\n");
            printf("****Invalid login attempt***\n");
            printf("----------------------------\n");
            exit(0);
        }
}

void option()
{
    int choice;
    char inp;
    int n;
    printf("\nPress 1 to enter record of student\n");
    printf("Press 2 to search existing student\n");
    printf("Press 3 to exit\n");
    printf("Enter you choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            {
                getdata();//
                break;
            }

        case 2:
            {
                read_data();//
                break;
            }
        case 3:
            {
                printf("\n***Thank you so much***");
                exit(0);
                break;
            }
        default:
            {
                case_default();
                break;
            }
    }

}
void case_default()
{
    char inp;
    printf("\n--Invalid Input--\n");
    printf("\nDo you want to exit or not (Y/N):");
    scanf("%s",&inp);
    if(inp =='Y' || inp =='y' )
    {
        exit(0);
    }
     else if(inp == 'N' || inp == 'n')
     {
         option();
     }
     else
     {
         //printf("\nInvalid selection");
         case_default();
     }
}


void getdata()
{
     char record;
     int i=0;
     FILE*fptr = fopen("info.txt","a");
    do{
            fflush(stdin);
            printf("\nDo you want to enter a record(Y/N) :");

            scanf("%c",&record);
            if(record=='Y' || record=='y')
            {
                printf("\n");
                printf("----------------------------------------\n");
                printf("\nEnter the id no of student:");
                scanf("%d",&id);
                fprintf(fptr,"%d\t",id);
                printf("Enter the name of student:");
                fflush(stdin);
                //gets(a);
                gets(name);
                fputs(name,fptr);
                fprintf(fptr,"\t");
                printf("Enter the marks obtained in Science: ");
                scanf("%d",&s_marks);
                fprintf(fptr,"%d\t",s_marks);
                printf("Enter the marks obtained in English: ");
                scanf("%d",&e_marks);
                fprintf(fptr,"%d\t",e_marks);
                printf("Enter the marks obtained in Math: ");
                scanf("%d",&m_marks);
                fprintf(fptr,"%d\t",m_marks);
                printf("Enter the marks obtained in Nepali: ");
                scanf("%d",&n_marks);
                fprintf(fptr,"%d\t",n_marks);
                printf("----------------------------------------\n");
                percentage=s_marks+e_marks+m_marks+n_marks/400;
                //printf("1");
                //getch();
                if(percentage>=60)
                {
                    grade='A';
                }

                else if(percentage>=50 && percentage<60)
                {
                    grade='B';
                }

                else if(percentage>=30 && percentage<50)
                {
                    grade='C';
                }

                else
                {
                    grade='F';
                }
                i++;

            }
                //printf("2");
                //getch();
    fprintf(fptr,"%c\n",grade);
    printf("\n");
    showdata();
    fclose(fptr);
    }while(record!='n');
}

void read_data()
{



int id;
int i=0;
fptr = fopen("info.txt","r");
printf("Enter student ID : ");
scanf("%d",&id);
printf("\n");
do
{

    fscanf(fptr,"%d\t%s\t %d\t %d\t %d\t %d\t %c\n" ,&save_d[i].id,&save_d[i].name,&save_d[i].s_marks,&save_d[i].e_marks,&save_d[i].m_marks,&save_d[i].n_marks,&save_d[i].grade);
    //printf("%d %s %d %d %d %d" ,save_d[i].id,save_d[i].name,save_d[i].s_marks,save_d[i].e_marks,save_d[i].m_marks,save_d[i].n_marks);

        printf("**The following data are**\n");
        printf("\n");
        printf("ID: %d\n",save_d[i].id);
        printf("Name: %s\n",save_d[i].name);
        printf("Science : %d\n",save_d[i].s_marks);
        printf("English : %d\n",save_d[i].e_marks);
        printf("Math : %d\n",save_d[i].m_marks);
        printf("Nepali : %d\n",save_d[i].n_marks);
        printf("Grade : %c\n",save_d[i].grade);
        printf("\n");
        i++;

}while(!feof(fptr));
fclose(fptr);
}

void showdata()
{
    printf("**You have entered these values***\n");
    printf("\nID of a student: %d",id);
    printf("\nName of a student: %s\n",name);
    printf("\nMarks obtained in Science: %d",s_marks);
    if(s_marks>=32)
    {
        printf(" (PASS)");
    }
    else
    {
        printf(" (FAIL)");
    }
    printf("\nMarks obtained in English: %d",e_marks);
    if(e_marks>=32)
    {
        printf(" (PASS)");
    }
    else
    {
        printf(" (FAIL)");
    }
    printf("\nMarks obtained in Math: %d",m_marks);
    if(m_marks>=32)
    {
        printf(" (PASS)");
    }
    else
    {
        printf(" (FAIL)");
    }
    printf("\nMarks obtained in Nepali: %d",n_marks);
    if(n_marks>=32)
    {
        printf(" (PASS)");
    }
    else
    {
        printf(" (FAIL)");
    }
    printf("\nGrade of a student is %c",grade);

}

main()
{
    login();
    //read_data();
}
