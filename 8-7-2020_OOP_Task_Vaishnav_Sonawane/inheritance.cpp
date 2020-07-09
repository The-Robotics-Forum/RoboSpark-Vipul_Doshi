#include<bits/stdc++.h>
using namespace std;

class personal_class
{
protected:
    string Name,Surname,address;
    int mobile;
    string dob;

public:
    personal_class()
    {
        Name="User name";
        Surname="User Surname";
        address="User Address";
        mobile=111111111;
        dob="01/01/2001";
    }
protected:

    void get_personal_data()
    {
        cout<<"Enter your pesonal details"<<endl;
        cout<<"Name :";
        cin>>Name;
        cout<<"Surname :";
        cin>>Surname;
        cout<<"Address :";
        cin>>address;
        cout<<"Mobile :";
        cin>>mobile;
        cout<<" Date of birth :";
        cin>>dob;
    }
    void show_personal()
    {
        cout<<"Personal Details :"<<endl;
        cout<<"Name :"<<Name<<endl;
        cout<<"Surname :"<<Surname<<endl;
        cout<<"Address :"<<address<<endl;
        cout<<"Mobile :"<<mobile<<endl;
        cout<<" Date of birth :"<<dob<<endl<<endl;


    }

};

class professional_class
{
protected:
    string name_of_organization,job_profile,project;
public:
    professional_class()
    {
        name_of_organization="TRF";
        job_profile="software";
        project="Robospark";
    }
protected:
    void get_prof_data()
    {

        cout<<"Enter professional details"<<endl;
        cout<<"Name of org :";
        cin>>name_of_organization;
        cout<<"JOb Profile :";
        cin>>job_profile;
        cout<<"Project :";
        cin>>project;
    }

    void show_professional()
    {
        cout<<"Professional details"<<endl;
        cout<<"Name of org :"<<name_of_organization<<endl;
        cout<<"JOb Profile :"<<job_profile<<endl;
        cout<<"Project :"<<project<<endl<<endl;

    }


};

class academic_year
{
protected:
    int year_of_passing;
    string college_name,branch;
    float cgpa;
public:
    academic_year()
    {
        year_of_passing=2023;
        college_name="VIT";
        branch="IT";
        cgpa=0.0f;
    }
    protected:

    void get_acad_data()
    {
        cout<<"Enter Academic details"<<endl;
        cout<<"College name :";
        cin>>college_name;
        cout<<"year_of_passing :";
        cin>>year_of_passing;
        cout<<"Branch :";
        cin>>branch;
        cout<<"CGPA :";
        cin>>cgpa;

    }
     void show_academic()
    {
        cout<<"Academic details"<<endl;
        cout<<"College name :"<<college_name<<endl;
        cout<<"year_of_passing :"<<year_of_passing<<endl;
        cout<<"Branch :"<<branch<<endl;
        cout<<"CGPA :"<<cgpa<<endl<<endl;

    }
};

class biodata : protected personal_class, protected professional_class, protected academic_year
{
public:
    void show_info()
    {
        show_personal();
        show_professional();
        show_academic();

    }
    void Edit_info()
    {
        get_personal_data();
        get_prof_data();
        get_acad_data();
    }




};

int main()
{
    biodata b1;
    b1.show_info();
    b1.Edit_info();
    b1.show_info();
return 0;
}

