#include<stdio.h>
int main()
{
    struct book
    {
        int id;
        char* name;
        int year;
        float cgpa;
    };

    struct book b[5];

    int id[5] = {10000,10001,10002,10003,10004};
    char* name[5] = {"Jayant Meshram","Vinit Goswami","Vikas Shashtri","Piyush Chaudhari","Arun Prakash"};
    int year[5] = {1,4,1,3,2};
    float cgpa[5] = {8.3,8.8,7.9,9.2,8.6};

    for(int i=0;i<5;i++)
    {
        b[i].id=id[i];
        b[i].name=name[i];
        b[i].year=year[i];
        b[i].cgpa=cgpa[i];
    }
    
    for(int i=0;i<5;i++)
    {
        printf("\n\nStudent Id:%d\nStudent Name:%s\nCurrent Year:%d\nCGPA:%f",b[i].id,b[i].name,b[i].year,b[i].cgpa);
    }
}