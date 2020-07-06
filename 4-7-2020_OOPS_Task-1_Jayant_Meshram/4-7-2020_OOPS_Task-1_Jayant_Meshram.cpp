/*Task1 Create a student class. Add the necessary data members and also add a dynamic array to store the marks of 5 subjects (use new keyword). Initialize the data members using constructors. We don't know the cgpa yet so assign it some random value in constructor. Write following functions inside the class -
Function to return the total marks. Function to calculate and store the cgpa in the variable, Funtion to take input (Dont take cgpa as input) and to display the data.*/
#include<iostream>
#include<string.h>
using namespace std;

class student
{
    private:
        string name;
        int roll;
        int *marks;
        int year;
        int length;
        float cgpa;
    
    public:
        student()
        {
            name="Default";
            roll=00;
            year=00;
            length=5;
            cgpa=0.0; 
        }
        void getInput();
        void showInput();
        int total();
        void calculate_cgpa();
};
void  student::getInput()
{
    cout<<"Enter Name of the student: ";
    getline(cin,name);
    cout<<"Studying Year: ";
    cin>>year;
    cout<<"Enter Roll no: ";
    cin>>length;
    cout<<"Enter total no of subjects: ";
    cin>>length;
    marks = new int[length];
    cout<<"Enter marks in(out of 100):\n";
    for(int i=0;i<length;i++)
    {
        cout<<"Subject"<<i+1<<": ";
        cin>>marks[i];
    }
}
void  student::showInput()
{
    cout<<"Name : "<<name<<endl;;
    cout<<"Studying Year: "<<year<<endl;
    cout<<"Enter Roll no: "<<roll<<endl;
    cout<<"No of subjects appeared: "<<length<<endl;
    cout<<"Marks obtained in in:\n";
    for(int i=0;i<length;i++)
    {
        cout<<"Subject"<<i+1<<" :  "<<marks[i]<<endl;
    }
    cout<<"Total marks : "<<total()<<endl;
    cout<<"CGPA obtained : "<<cgpa<<endl;
    delete marks;
}

int student::total()
{  
    int sum=0;
    for(int i=0;i<length;i++)
    {
        sum = sum + marks[i];
    }
    return sum;
}

void student::calculate_cgpa()
{  
    cgpa=total()/(length*10);
}


int main()
{
    student s;
    s.getInput();
    s.calculate_cgpa();
    s.showInput();
}