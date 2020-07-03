#include<stdio.h>
struct student
{
    int stud_ID;
    char stud_name[20];
    int stud_year;
    float stud_cgpa;

};

void main()
{
   struct student stud1;


    printf("\nEnter Your Details ");
    printf("\nID : ");
    scanf("%d", &stud1.stud_ID);
    printf("Enter your Name : ");
    scanf("%s",stud1.stud_name);
    printf("Enter year : ");
    scanf("%d", &stud1.stud_year);
    printf("Enter CGPA :");
    scanf("%f",&stud1.stud_cgpa);

    printf("\n\n\nSTUDENT INFO \nID :%d \nNAME: %s\nyear: %d\nCGPA:%f\n Thank You!!!",stud1.stud_ID,stud1.stud_name,stud1.stud_year,stud1.stud_cgpa);

    return 0;



}
