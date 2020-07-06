#include <iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
class student
{
public:
  string nam;
  int ye;
  int rollno;
  
   student (string stu_name, int rank)
   {
    cout<< "stu_name :"<<stu_name <<endl;
    cout<< "year :"<<ye <<endl;
    cout<<" roll no :"<<rollno <<endl;
    cout<<"Rank :"<<rank << endl;
    }
    student (int a1)
  {
    cout<< "Rank :"<< a1<<endl;
  }
    student( string name)
  {  cout<< "stu_name :"<<name<<endl;
    cout<< "year :"<<ye<<endl;
    cout<<" roll no :"<<rollno << endl;
    cout<<"No rank"<<endl;
     }
    student ()
    {
       cout << "enter name of student ";
      cin >> nam;
  cout << "enter roll no of student ";
  cin >> rollno;
  cout << "enter year of student ";
  cin >> ye; 
    }
};

int
main ()
{
  
   student s1;
  student s2(70);
  student s3("siddhi",80);
  student s4("fdgh");
  
  
  return 0;
}

