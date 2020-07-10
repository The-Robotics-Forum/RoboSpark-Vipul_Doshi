/*Task for today -
Problem statement On Inheritance
I want my Personal data, Professional data, & Academic data to be separated in different classes and 4th class called biodata.
If I create object of biodata class then using that object I can get all my professional, personal and academic data.
Decide which type of inheritance you will be using to achieve this goal .
Take data members in classes as follows:
personal class - Name, Surname, address, mobile_no, dob.
professional class - name_of_organization, job_profile, project.
Academic - year_of_passing, cgpa, college_name, branch
member functions
All class includes default constructor(if data members are present), and one function to get data from user for its data member.
Note :- define all data members as protected so that you can access this members in its derived class directly*/
#include<iostream>
using namespace std;

class personal_data
{
    string name, surname, dob, address;
    long long mobile;
    
    public:
        void get_input_personal();
        void display_personal();
};

class professional_data
{
    string name_of_org, job_profile,project;
    
    public:
        void get_input_pro();
        void display_pro();
};

class academic_data
{
    int year;
    float cgpa;
    string college_name;
    string branch;
    
    public:
        void get_input_acad();
        void display_acad();
};


void personal_data::get_input_personal()
{
    cout<<"Enter First Name: ";
    cin>>name;
    cout<<"Enter Last Name: ";
    cin>>surname;
    cout<<"Enter mobile no: ";
    cin>>mobile;
    cin.ignore();
    cout<<"Enter dob in DD/MM/YYYY format: ";
    getline(cin,dob);
    cout<<"Enter address: ";
    getline(cin,address);
}

void professional_data::get_input_pro()
{
    cout<<"Enter Name of organiozation: ";
    getline(cin,name_of_org);
    cout<<"Enter Job Profile: ";
    getline(cin,job_profile);
    cout<<"Enter Project Name: ";
    getline(cin,project);
}

void academic_data::get_input_acad()
{
    cout<<"Enter Name of College: ";
    getline(cin,college_name);
    cout<<"Enter Branch name: ";
    getline(cin,branch);
    cout<<"Year of passing: ";
    cin>>year;
    cout<<"Enter CGPA: ";
    cin>>cgpa;
}

void personal_data::display_personal()
{
    cout<<"Name: "<<name<<" "<<surname<<endl;
    cout<<"Date of Birth: "<<dob<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Mobile No.: "<<mobile<<endl;
}

void professional_data::display_pro()
{
    cout<<"Name of Organization: "<<name_of_org<<endl;
    cout<<"Job Profile: "<<job_profile<<endl;
    cout<<"Project: "<<project<<endl;
}

void academic_data::display_acad()
{
    cout<<"Name of College: "<<college_name<<endl;
    cout<<"Branch: "<<branch<<endl;
    cout<<"Year of passing: "<<year<<endl;
    cout<<"CGPA: "<<cgpa;
}

class biodata: public personal_data, public professional_data, public academic_data
{
    public:
        biodata();
        void display();
};

biodata::biodata()
{
    get_input_personal();
    get_input_pro();
    get_input_acad();
    display();
}

void biodata::display()
{
    cout<<"***************Personal Information***************"<<endl;
    display_personal();
    cout<<"\n***************Professional Information***************"<<endl;
    display_pro();
    cout<<"\n***************Academic Information***************"<<endl;
    display_acad();
}

int main()
{
    biodata b;
}