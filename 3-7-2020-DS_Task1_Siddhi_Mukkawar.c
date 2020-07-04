#include <stdio.h>
#include <stdlib.h>

typedef struct stud
{
    char name[20];
    int roll[5];
    int roll_no;
    int rear,front;
}stud;
void initialize(stud* p)
{
    p->rear = 0;
    p->front = 0;
}
void enqueue(stud* p, int num)
{
    if(num%2 == 0)
    {
        p->roll[p->rear++] = num;
    }
}
void print(stud* p)
{
    if(isEmpty(p))
    {
        printf("Queue is empty");
        return;
    }
    printf("\nFront ");
    for(int i=p->front; i<p->rear; i++)
    {
        printf("%d ",p->roll[i]);
    }
    printf(" Rear\n");
}
int isEmpty(stud* p)
{
    return p->front == p->rear;
}
int main()
{
    struct stud student;
    stud* q1 = (stud*)malloc(sizeof(stud));
    initialize(q1);
    printf("Enter details for 5 Student");
    for(int i=1;i<=5;i=i+1)
    {
        printf("\nEnter Stud %d Name : ",i);
        scanf("%s",student.name);
        printf("\nEnter Roll : ");
        scanf("%d",&student.roll_no);
        enqueue(q1,student.roll_no);
    }
    print(q1);
}
