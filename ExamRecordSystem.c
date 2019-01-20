#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void option();
void showdata();
void getdata();
void case_default();

//***************************************************************
//                   DECLARATION OF VARIABLES IN PROJECT
//****************************************************************
    int id,s_marks,e_marks,m_marks,n_marks;
    char name[20],address,grade;
    char a[0];
    float percentage;
    FILE * fptr;
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
	else //if(count<3)
        {
            printf("----------------------------\n");
            printf("****Invalid login attempt***\n");
            printf("----------------------------\n");
            exit(0);
        }
	//choice();
}

void option()
{
    fptr=fopen("info.txt","r");
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
                getdata();
                break;
            }
        case 2:
            {

                printf("Enter student ID : ");
                scanf("%d",&id);
                if ((fptr = fopen("C:\\Users\sande\OneDrive\Desktop\C\Entrance exam\info.txt","rb")) == NULL)
                    {
                        printf("Error! opening file");
                        // Program exits if the file pointer returns NULL.
                        exit(0);
                    }
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

    fptr = fopen("info.txt","a");
    printf("\n");
    printf("----------------------------------------\n");
    fprintf(fptr,"\n----------------------------------------\n");
    printf("\nEnter the id no of student:");
    scanf("%d",&id);
    fprintf(fptr,"\nID:\t\t%d",id);
    printf("Enter the name of student:");
    gets(a);
    gets(name);
    fprintf(fptr,"\nName:\t\t");
    fputs(name,fptr);
    printf("Enter the marks obtained in Science: ");
    scanf("%d",&s_marks);
    fprintf(fptr,"\nScience:\t%d ",s_marks);
    printf("Enter the marks obtained in English: ");
    scanf("%d",&e_marks);
    fprintf(fptr,"\nEnglish:\t%d ",e_marks);
    printf("Enter the marks obtained in Math: ");
    scanf("%d",&m_marks);
    fprintf(fptr,"\nMath:\t\t%d ",m_marks);
    printf("Enter the marks obtained in Nepali: ");
    scanf("%d",&n_marks);
    fprintf(fptr,"\nNepali:\t\t%d ",n_marks);
    printf("----------------------------------------\n");
    percentage=s_marks+e_marks+m_marks+n_marks/4;



        if(percentage>=60)
            grade='A';
        else if(percentage>=50 && percentage<60)
            grade='B';
        else if(percentage>=30 && percentage<50)
            grade='C';
        else
            grade='F';
        fprintf(fptr,"\nGrade:\t\t%c ",grade);

        showdata();
        fclose(fptr);

}

void showdata()
{
    //fptr = fopen("info.txt","a");
    printf("\nID of a student: %d",id);
    printf("\nName of a student: %s\n",name);
    printf("\nMarks obtained in Science: %d",s_marks);
    if(s_marks>=32)
    {
        printf(" (PASS)");
        //fprintf(fptr,"(PASS)");
    }
    else
    {
        printf(" (FAIL)");
    }
    printf("\nMarks obtained in English: %d",e_marks);
    if(e_marks>=32)
    {
        printf(" (PASS)");
        //fprintf(fptr,"(PASS)");
    }
    else
    {
        printf(" (FAIL)");
        //fprintf(fptr,"(FAIL)");
    }
    printf("\nMarks obtained in Math: %d",m_marks);
    if(m_marks>=32)
    {
        printf(" (PASS)");
        //fprintf(fptr,"(PASS)");
    }
    else
    {
        printf(" (FAIL)");
        //fprintf(fptr,"(FAIL)");
    }
    printf("\nMarks obtained in Nepali: %d",n_marks);
    if(n_marks>=32)
    {
        printf(" (PASS)");
        //fprintf(fptr,"(PASS)");
    }
    else
    {
        printf(" (FAIL)");
        //fprintf(fptr,"(FAIL)");
    }
    //printf("\nPercentage is : %f",percentage);
    printf("\nGrade of a student is %c",grade);

}

main()
{
    login();
}
