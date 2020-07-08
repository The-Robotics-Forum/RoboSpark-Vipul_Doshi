/*2. Overload the showRank function in the following way -
When the function has only int as an argument, print that integer as rank.
When the function has only student as an argument, print the student details and print "no rank".
When the function received one student and one int as arguments, print the student details and the rank.
Rank is not a data member of Student*/

#include<bits/stdc++.h>
using namespace std;

class student
{
    int roll_no;
    string name;
public:
    void getdata(int r,string s)
    {
        roll_no=r;
        name=s;
    }
    void showrank(int theRank)
    {
        cout<<"Rank :"<<theRank<<endl;
    }
    void showrank(student &s )
    {
        cout<<endl <<"Roll no :"<<this->roll_no<<endl;
        cout<< "Name :"<<this->name<<endl;
    }
    void showrank(student &s,int theRank)
    {
        cout<<endl <<"Roll no :"<<this->roll_no<<endl;
        cout<< "Name :"<<this->name<<endl;
        cout<<"Rank :"<<theRank<<endl;
    }
};


int main()
{
    student s1,s2;
    s1.getdata(50,"Vaishnav");
    s1.showrank(1770);
    s1.showrank(s2);
    s1.showrank(s2,1770);

    return 0;
}
