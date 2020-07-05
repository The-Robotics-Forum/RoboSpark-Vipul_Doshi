/* Task2 Overload the showRank function in the following way -
When the function has only int as an argument, print that integer as rank.
When the function has only student as an argument, print the student details and print "no rank".
When the function received one student and one int as arguments, print the student details and the rank.
Rank is not a data member of Student*/
#include<iostream>
#include<string.h>
using namespace std;

class Student
{
public:
    string name;
    int roll=1111;
    float cgpa=8.6;
    int year=1;

    Student()
    {
        cout << "Default called.\n";
        name = "default name";
        roll = 00;
        cgpa = 10;
        year = 4;
    }


    Student(int r)
    {
        cout << "\nRank is: "<<r<<endl<<endl;
    }

    Student(string n, int r)
    {
        name = n;
        cout << "\nName : "<<name;
        Display();
        cout<<"Rank of the student is: "<<r;
    }

    Student(string n)
    {
        name = n;
        cout << "\nName : "<<name;
        Display();
        cout<<"No Rank\n\n";
    }
     //public zone

    void Display()
    {
        cout << "\nRoll No:" << roll << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Year: " << year << endl;
    }

};

int main()
{
    Student(4);
    Student("Jayant Meshram");
    Student("Jayant Mehsram",4);

}