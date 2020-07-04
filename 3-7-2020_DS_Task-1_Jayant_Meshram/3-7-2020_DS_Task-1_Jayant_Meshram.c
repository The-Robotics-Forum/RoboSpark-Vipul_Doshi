/*Task 1 Create a structure of students containing name,roll numbers. Create a queue of students (alongwith functions) which only allow students with even roll numbers.*/
#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int roll_no[11];
    char* name[11];
    int front, rear;
};

void init(struct queue *q)
{   
    q->rear=0;
    q->front=0;
    q->name[11]=(char*)malloc(sizeof(char)*25);
}

void enqueue(int x,char *name,struct queue *q)
{
   q->roll_no[q->rear]=x;
   q->name[q->rear++]=name;
}

int isEmpty(struct queue *q)
{
    return q->front==q->rear;
}

void print(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("List is Empty");
        return;
    }
    printf("\n\nStudents with Even roll nos are as follow:\n");
    for(int i=0;i<6;i++)
    {
        printf("\nRoll No: %d  Name: %s",q->roll_no[i],q->name[i]);
    }
}

int main()
{
    struct student
    {
        int roll_no;
        char* name;
    };

    struct student s[11];

    int roll[11] = {10000,10001,10002,10003,10004,10005,10006,10007,10008,10009,10010};
    char* nme[11] = {"Jayant Meshram","Vinit Goswami","Vikas Shashtri","Piyush Chaudhari","Arun Prakash","Abhishek Sukhdeve","Shubham Gayakwad","Arjun Patil","Viraj Sharma","Vipul singh","Aditya Chauvhan"};

    for(int i=0;i<11;i++)
    {
        s[i].roll_no=roll[i];
        s[i].name=nme[i];
    }
    printf("\nAll Students:");
    for(int i=0;i<11;i++)
    {
        printf("\nRoll no: %d  Name: %s",s[i].roll_no,s[i].name);
    }

    struct queue q;
    init(&q);

    for(int i=0;i<11;i++)
    {
        if(s[i].roll_no%2==0)
        {
            enqueue(s[i].roll_no,s[i].name,&q);
        }
    }
    print(&q);
}