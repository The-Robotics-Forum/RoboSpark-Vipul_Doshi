#include <iostream>
#include<string.h>
using namespace std;
class student
{
public:
  string nam;
  int ye;
  int rollno;
  int CGPA;
    student (string stu_name, int stu_roll, int year)
  {
    nam = stu_name;
    ye = year;
    rollno = stu_roll;
    CGPA = 0;
  }

  int totalmarks (int *a1)
  {
    int sum = 0;
    for (int i = 0; i < 5; i++)
      {
	sum = sum + a1[i];
	return sum;
      }
  }
  int cgpa (int *a1)
  {
    int c = totalmarks (a1) / 5;
    return c;
  }
  void showdetails ()
  {
    cout << "Name :" << nam << endl;
    cout << "Year :" << ye << endl;
    cout << "Roll_no :" << rollno << endl;
  }
};

int
main ()
{
  string name;
  int year1;
  int roll;
  int *mark = new int[5];
  cout << "enter name of student ";
  cin >> name;
  cout << "enter roll no of student ";
  cin >> roll;
  cout << "enter year of student ";
  cin >> year1;
  student s (name, year1, roll);
  cout << "enter marks of 5 subject\n";
  cin >> mark[0];
  cin >> mark[1];
  cin >> mark[2];
  cin >> mark[3];
  cin >> mark[4];
  s.showdetails ();
  cout << "total marks are " << s.totalmarks (mark) << "\n";
  cout << "CGPA is " << s.cgpa (mark);
  return 0;
}
