/*Create a student class. Add the necessary data members and also add a dynamic array to store the marks of 5 subjects (use new keyword). Initialize the data members using constructors. We don't know the cgpa yet so assign it some random value in constructor. Write following functions inside the class -
Function to return the total marks. Function to calculate and store the cgpa in the variable, Funtion to take input (Dont take cgpa as input) and to display the data.
Think : Where can you use delete keyword to free the memory allocated to the marks array*/

// VIT CGPA calculating project :)
#include<bits/stdc++.h>
using namespace std;

class student
{
    int GR_no,total_marks;
    string name;
    float cgpa;
    int *arr;
public:
    student()
    {
        cout<<"WELCOME TO VIT CGPA calculating project (assume each subject has 4 credits)"<<endl;
        GR_no=0;
        string name="student";
        cgpa=0.0f;
        total_marks=0;
    }
    void setdata()
    {
        cout<<"Enter Gr no. :";
        cin>>GR_no;
        cout<<"Enter name :";
        cin>>name;
        arr=new int[5];
        cout<<"Enter marks of five subjects out of 100 :"<<endl;
        for(int i=0; i<5; i++)
        {
            cout<<"subject "<<(i+1)<<" :";
            cin>>arr[i];
        }

    }
    void calculate()
    {
        float credit_points=0;
        for(int i=0; i<5; i++)
        {
            total_marks=total_marks+arr[i];
            credit_points=credit_points+4*(arr[i]/10+1);

        }
        cgpa=credit_points/(4*5);
    }
    void getdata()
    {
        cout<<"\n"<<"GR_no :"<<GR_no<<endl;
        cout<<"Name :"<<name<<endl;
        cout<<"Total marks( /500):"<<total_marks<<endl;
        cout<<"Your CGPA :"<<cgpa<<endl;

    }
};
int main()
{
    student s1;
    s1.setdata();
    s1.calculate();
    s1.getdata();
    return 0;
}
