/* 07-07-2020-Create your own String class.Implement String class similar to the strings in Python and C++. (The way we implemented the List class). 
Overload+ operator to concatenate two string. Overload* operator to multiply string. (Ex: "yash"*2 returns "yashyash"). 
2*"yash" should also return "yashyash". Overload the input and output operator. Try to overload as many operators as you can*/
#include <iostream> 
#include <cstring> 
using namespace std; 

class mystring 
{ 
    char *str;
	
public: 
	mystring(); 
	mystring(char* val); 

	int length(); 
    void copying(mystring &obj1); 
    void swapping(mystring &obj1); 

    friend ostream &operator<<( ostream &output, const mystring &obj); 
	friend istream &operator>>( istream &input, mystring &obj); 
    
    

    mystring operator*(int a);
	mystring &operator=(const mystring &obj1); 
    mystring operator+(const mystring &obj1);
    
    mystring(const mystring& source); 
    mystring(mystring&& source); 
	~mystring() { delete str; } 
}; 
mystring::mystring() : str{ nullptr } 
{ 
	str = new char[1]; 
	str[0] = '\0'; 
} 

mystring::mystring(char* val) 
{ 
	if (val == nullptr)
	{ 
		str = new char[1]; 
		str[0] = '\0'; 
	} 
    else
	{ 
		str = new char[strlen(val) + 1]; 
		strcpy(str, val); 
	} 
} 
mystring::mystring(const mystring& source) 
{ 
    str = new char[strlen(source.str) + 1]; 
    strcpy(str, source.str); 
} 
mystring::mystring(mystring&& source) 
{ 
    str = source.str; 
    source.str = nullptr; 
} 
istream& operator>>(istream& input, mystring &obj) 
{ 
	char* tempstring = new char[1000]; 
	input >> tempstring; 
	obj = mystring{ tempstring }; 
	delete[] tempstring; 
	return input; 
} 

ostream& operator<<(ostream& output, const mystring &obj) 
{ 
	output << obj.str; 
	return output; 
} 

int mystring::length(void)
{
    return strlen(str);
}

mystring& mystring::operator=( const mystring &obj1) 
{ 
	if (this == &obj1) 
		return *this; 
	delete[] str; 
	str = new char[strlen(obj1.str) + 1]; 
	strcpy(str, obj1.str); 
	return *this; 
} 

mystring mystring::operator+(const mystring& obj1) 
{ 
	int length = strlen(this->str) + strlen(obj1.str); 
	char* tempstring = new char[length + 1]; 
	strcpy(tempstring, this->str); 
	strcat(tempstring, obj1.str); 
	mystring temp{tempstring};  
	delete[] tempstring; 
	return temp; 
}

mystring mystring::operator*(int a) 
{ 
	int length = strlen(this->str); 
	char* tempstring = new char[(a*length) + 1]; 
    strcpy(tempstring, this->str); 
    while(a>1)
    {
	    strcat(tempstring, this->str);
        a--;
    }
    mystring temp{tempstring};  
	delete[] tempstring; 
	return temp; 
}
mystring operator*(int a,mystring &obj)
{
    return obj*a;
}

void mystring:: swapping(mystring &obj1) 
{ 
    mystring  temp{obj1};
	obj1 = *this; 
	*this = temp; 
} 

void mystring:: copying(mystring &obj1) 
{ 
	mystring temp{ obj1 }; 
	*this = obj1; 
} 

int main() 
{ 
	mystring a; 
    mystring b; 

    cout<<"Enter value of 1st string: ";
    cin>>a;
    cout<<"Enter value of 2nd string: ";
    cin>>b;
	cout << "1st String: "<< a << endl; 
	cout << "2nd String: "<< b << endl; 
    cout << "Length of 1st String: "<< a.length() << endl; 
	cout << "Length of 2nd String: "<< b.length() << endl;  
    cout << "Multiplying 1st String twice: "<< a*2 << endl;
    cout << "Multiplying 2nd String thrice: "<< 3*b << endl;
	cout << "Concatinating: "<<a+b<<endl;    
    a.swapping(b);
    cout <<"Strings after Swapping:\n1st String: "<<a<<"\n2nd String:"<<b;
    a.copying(b);
    cout <<"\nStrings after Copying 2nd string into 1st:\n1st String: "<<a<<"\n2nd String:"<<b;
    cout << "\nPerforming a = a + b";
    a=a+b;
    cout << "\nFinal value of \n1st String: "<< a << endl; 
	cout << "2nd String: "<< b << endl; 
    

	return 0; 
} 
