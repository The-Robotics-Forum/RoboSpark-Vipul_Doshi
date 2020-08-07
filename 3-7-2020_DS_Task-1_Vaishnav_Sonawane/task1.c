#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 10



struct Student
{
    int roll_no;
    char name[10];
};
typedef struct Queue{
    int front,rear;
    struct Student S[10];
}Queue;
void init(Queue* q)
{
    q->front = 0;
    q->rear = 0;
}


void Enqueue(Queue *q, int roll , char name[]){
    if(q->rear == (MAX-1))
    {
        printf("Queue is Full");
    }
    else
    {
        q-> S[q->rear].roll_no = roll ;
        strcpy(q-> S[q->rear].name , name) ;
        q -> rear++;




    }
}

void print(Queue *q)
{
    int temp  =  q -> front;
    while(temp < q -> rear)
    {
        printf("Student Roll no is %d\n",q -> S[temp].roll_no);
        printf("Student Name is %s",q -> S[temp].name);
        temp++;
    }
}
int main(){
    Queue *q1 = (Queue *)malloc(sizeof(Queue));
    init(q1);
    int choice = 1,roll;
    char Name[20];
    while(choice)
    {
        printf("\nEnter student Roll no:");
        scanf("%d",&roll);
        printf("\nEnter student Name:");
        scanf("%s",Name);
        //fflush(stdin);
        if(roll %2 == 0)
        {
           Enqueue(q1 , roll, Name);
        }
        printf("Do you want to continue(Y = 1, N = 0)");
        scanf("%d",&choice);
    }
    print(q1);



}
