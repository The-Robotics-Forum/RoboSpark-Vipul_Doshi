#include<iostream>
#include<string.h>
using namespace std;

class String
{
    char *arr;
    int size;

    public:
    String()
    {
        size=20;
        arr=new char[size];
    }
    String(int s)
    {
        size=s;
        arr=new char[size];
    }

    String(char *s)
    {
        size=strlen(s);
        arr=new char[size];
        for(int i=0; i < size;i++)
        {
            arr[i]=s[i];
        }
    }
    void display();
    void input(char *s);
    int length(String);
    void append(String);
    void operator =(String);
    String operator +(String );
    String operator *(int );
    ~String()
    {
        delete []arr;

    }
};

void String :: input(char *s)
    {
        size=strlen(s);
         for(int i=0; i < size;i++)
        {
            arr[i]=s[i];
        }

    }
void String :: display()
    {
         for(int i=0; i < size;i++)
        {
           cout<<arr[i];
        }
        cout<<endl;
    }
int String :: length(String s)
{
    return(s.size);
}
void String:: append(String s)
{
    int counter=this->size;
    this->size= this->size + s.size;
    for(int i=0;i<s.size;i++)
    {
        this->arr[counter]=s.arr[i];
        counter++;
    }
}
String String :: operator +(String s)
{
    int tempsize=(this->size)+(s.size);
    String temp(tempsize);
    int counter=0;
    for(int i=0;i<this->size;i++)
    {
        temp.arr[i]=this->arr[i];
        counter++;
    }
    for(int i=0; i < temp.size ; i++)
    {
        temp.arr[counter]=s.arr[i];
        counter++;
    }
    return (temp);

}

String String :: operator *(int n)
{   int counter=0;
    String temp2(n*this->size);
    while(n--)
    {
        for(int i=0;i<this->size;i++)
        {
            temp2.arr[counter]=this->arr[i];
            counter++;
        }

    }
    return (temp2);
}
void String :: operator = (String s)
{
    this->size=s.size;
    for(int i=0;i<this->size;i++)
    {
        this->arr[i]=s.arr[i];
    }
}


int main()
{
    String s1="vaishnav",s2="Nitin",s3="Sonawane",s4;
    (s1+s2+s3).display();

return 0;
}
