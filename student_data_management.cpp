#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{
    string data;
    int n=0,option=0,count_n=0;
    string empty="00";
    string proctor ="";
    ifstream f("C:\\Users\\Amogh Prabhu\\Desktop\\CPP\\PROJECTS\\DATABASE.txt");
    string line;
    for(int i=0;std :: getline(f,line);i++)
    {
        count_n++;
    }
    while(option != 6)
    {
        cout<<"------Available options------"<<endl;
        cout<<endl;
        cout<<"1. Add new Students"<<endl;
        cout<<"2. Student Login"<<endl;
        cout<<"3. Faculty Login"<<endl;
        cout<<"4. proctor Login"<<endl;
        cout<<"5. Admin view"<<endl;
        cout<<"6. Exit"<<endl;
        cin>>option;

        if(option==1)
        {
            cout<<"Enter the number of students"<<endl;
            cin>>n;
            count_n=count_n+n;
            for(int i=0;i<n;i++)
            {
                ofstream outfile;
                outfile.open("C:\\Users\\Amogh Prabhu\\Desktop\\CPP\\PROJECTS\\DATABASE.txt",ios :: app);
                cout<<"Enter your registration number :(7-digit)"<<endl;
                cin>>data;
                outfile<<data<<" ";
                cout<<"Enter your name(5 letter word) : "<<endl;
                cin>>data;
                outfile<<data<<" ";
                outfile<<empty;
                outfile<<" ";
                outfile<<empty;
                cout<<"Enter the proctor ID( 4-digit)"<<endl;
                cin>>proctor;
                outfile<<" ";
                outfile<<proctor<<endl;
            }
        }
        else if(option ==2 )
        {
            char regno[7];
            cout<<"Enter your registraion number"<<endl;
            cin>>regno;
            ifstream infile;
            int check=0;
            infile.open("C:\\Users\\Amogh Prabhu\\Desktop\\CPP\\PROJECTS\\DATABASE.txt",ios :: in);
            while(infile>>data)
            {
                if(strcmp(data.c_str(),regno)==0)
                {
                    cout<<"Registraion Number :"<<data<<endl;
                    infile>>data;
                    cout<<"Name :"<<data<<endl;
                    infile>>data;
                    cout<<"ECE 305 mark :"<<data<<endl;
                    infile>>data;
                    cout<<"ECE 306 mark :"<<data<<endl;
                    infile>>data;
                    cout<<"proctor ID :"<<data<<endl;
                    infile.close();
                    check=1;
                }
            }
            if(check==0)
            {
                cout<<"NO STUDENT FOUND"<<endl;
            }
        }
        else if(option==3)
        {
            string subcode;
            cout<<"Enter the subject code"<<endl;
            cin>>subcode;
            string code1="EC305",code2="EC306",mark="";
            ifstream infile;
            int check=0;
            cout<<" --- Available options---"<<endl;
            cout<<"1.Add data about marks"<<endl;
            cout<<"2.View marks"<<endl;
            cout<<"Enter your option :"<<endl;
            cin>>option;
            if(option==1)
            {
                cout<<"You NEED to enter marks for all students"<<endl;
                for(int i=0;i<count_n;i++)
                {
                    fstream file("C:\\Users\\Amogh Prabhu\\Desktop\\CPP\\PROJECTS\\DATABASE.txt");
                    if(strcmp(subcode.c_str(),code1.c_str())==0)
                    {
                        file.seekp(14+26*i,std::ios_base::beg);
                        cout<<"Enter the mark of student#"<<(i+1)<<": ";
                        cin>>mark;
                        file.write(mark.c_str(),2);
                    }
                    if (strcmp(subcode.c_str(), code2.c_str())== 0) 
                    {
                        file.seekp(17+26*i,std::ios_base::beg);
                        cout << "Enter the mark of student#"<< (i + 1) << ":";
                        cin >> mark;
                        file.write(mark.c_str(), 2);
                    }
                }
            }
            else if(option==2)
            {
                infile.open("C:\\Users\\Amogh Prabhu\\Desktop\\CPP\\PROJECTS\\DATABASE.txt",ios::in);
                if(strcmp(subcode.c_str(),code1.c_str())==0)
                {
                    cout<<"Registraion number -- marks"<<endl;
                    while(infile>>data)
                    {
                        cout<<data;
                        infile>>data;
                        infile>>data;
                        cout<<" - "<<data<<endl;
                        infile>>data;
                        infile>>data;
                        check=1;
                    }
                }
                infile.close();
                infile.open("C:\\Users\\Amogh Prabhu\\Desktop\\CPP\\PROJECTS\\DATABASE.txt");
                if(strcmp(subcode.c_str(),code2.c_str())==0)
                {
                    cout<<"Registration Number - Marks"<<endl;
                    while(infile>>data)
                    {
                        infile>>data;
                        infile>>data;
                        infile>>data;
                        cout<<" -"<<data<<endl;
                        infile>>data;
                        check=1;
                    }
                }
                if(check==0)
                {
                    cout<<"NO such subject code found"<<endl;
                }
            }
        }
            else if(option==4)
            {
                string procid;
                cout<<"Enter the proctor ID :";
                cin>> procid;
                int check=0;
                string temp1,temp2,temp3,temp4,id;
                ifstream infile;
                infile.open("C:\\Users\\Amogh Prabhu\\Desktop\\CPP\\PROJECTS\\DATABASE.txt",ios :: in);
                while(infile>>temp1)
                {
                    infile >> temp2;
                    infile >> temp3;
                    infile >> temp4;
                    infile >>id;
                    if(strcmp(id.c_str(),procid.c_str()) ==0)
                    {
                        cout<<"Registration Number :"<<temp1<<endl;
                        cout<<"Name: "<<temp2<<endl;
                        cout<<"EC305 Mark :"<<temp3<<endl;
                        cout<<"EC306 Mark :"<<temp4<<endl;
                        check=1;
                    }
                }
                if(check==0)
                {
                    cout<<"NO such proctor ID found"<<endl;
                }
            }
            else if(option ==5)
            {
                string password;
                cout<<"Enter the admin password :";
                cin>>password;
                string admin_pass="passadmin";
                if(strcmp(password.c_str(),admin_pass.c_str())==0)
                {
                    cout<<"Reg No.\t\tName\tEC305\tEC306\tproctor ID"<<endl;
                    ifstream infile;
                    infile.open("C:\\Users\\Amogh Prabhu\\Desktop\\CPP\\PROJECTS\\DATABASE.txt",ios::in);
                    string data;
                    while(infile>>data)
                    {
                        cout<<data<<" ";
                        infile>>data;
                        cout<<data<<" ";
                        infile>>data;
                        cout<<data<<" ";
                        infile>>data;
                        cout<<data<<" ";
                        infile>>data;
                        cout<<data<<endl;                        
                    }
                }
            }

        }
    }