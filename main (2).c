#include <stdio.h>
struct student
{ int student_id;
  char Studen_name[20];
  int stude_year;
  float stud_CGPA;
};
int main()
{ struct student s1;
 struct student s2;
 struct student s3;
 struct student s4;
 printf("enter s1 student id");
 scanf("%d",&s1.student_id);
 printf("enter s1 student_year");
 scanf("%d",&s1.stude_year);
 printf("enter s1 student CGPA");
 scanf("%f",&s1.stud_CGPA);
 printf("enter s1 student name");
 scanf("%s",s1.Studen_name);
 
printf("enter s2 student id");
 scanf("%d",&s2.student_id);
 printf("enter s2 student_year");
 scanf("%d",&s2.stude_year);
 printf("enter s2 student CGPA");
 scanf("%f",&s2.stud_CGPA);
 printf("enter s2 student name");
 scanf("%s",s2.Studen_name);

printf("enter s3 student id");
scanf("%d",&s3.student_id);
 printf("enter s3 student_year");
 scanf("%d",&s3.stude_year);
 printf("enter s3 student CGPA");
 scanf("%f",&s3.stud_CGPA);
 printf("enter s3 student name");
 scanf("%s",s3.Studen_name);

printf("enter s4 student id");
 scanf("%d",&s4.student_id);
 printf("enter s4 student_year");
 scanf("%d",&s4.stude_year);
 printf("enter s4 student CGPA");
scanf("%f",&s4.stud_CGPA);
 printf("enter s4 student name");
 scanf("%s",s4.Studen_name);
printf("s1 student id : %d \ns1 student name : %s \ns1 student year : %d \ns1 student CGPA : %f \n",s1.student_id,s1.Studen_name,s1.stude_year,s1.stud_CGPA);
printf("s2 student id : %d \ns2 student name : %s \ns2 student year : %d \ns2 student CGPA : %f \n",s2.student_id,s2.Studen_name,s2.stude_year,s2.stud_CGPA);
 printf("s3 student id : %d \ns3 student name : %s \ns3 student year : %d \ns3 student CGPA : %f \n",s3.student_id,s3.Studen_name,s3.stude_year,s3.stud_CGPA);
 printf("s4 student id : %d \ns4 student name : %s \ns4 student year : %d \ns4 student CGPA : %f \n",s4.student_id,s4.Studen_name,s4.stude_year,s4.stud_CGPA);
 return 0;
}