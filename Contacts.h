#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

class Contacts
{
private:
    int num;
public:
    string name;
    string phone;
    string email;
    void get_name(){
        cout<<"Enter name: "<<endl;
        getline(cin, name);
    }
    void get_phone(){
        cout<<"Enter phone number: "<<endl;
        getline(cin, phone);
    }
    void get_email(){
        cout<<"Enter Email: "<<endl;
        getline(cin, email);

    }

    void store(){
        ofstream file;
        file.open("ContactsList.txt", ios::app);
        if(file.is_open()){
            file <<"Name: "<<name << "   " <<"Phone number: "<< phone << "   " <<"Email: "<< email << endl;
        }
        else{
            cout<<"File cannot open"<<endl;
        }
        file.close();
    }
};

class Delete
{
private:
    int choice;
public:
    void contact_deletion(){
        string temp;
        vector <string> line;
        ifstream file;
        file.open("ContactsList.txt");
        if(file.is_open()){
            while(getline(file,temp)){
                line.push_back(temp);
            }
        }else{
            cout<<"File cannot be opened"<<endl;
        }
        int max=line.size();
        cout<<"Choose the number of the contact you want to delete."<<endl;
        cin>>choice;
        cin.ignore();
        while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Please only enter a number from the list: "<<endl;
            cin>>choice;
            cin.ignore();
        }else if(choice>max || choice<1){
            cout<<"Only a number from the list: "<<endl;
            cin>>choice;
            cin.ignore();
        }else{
            break;
        }
    }
        file.close();
        ofstream file_write;
        file_write.open("ContactsList.txt");
        if(file_write.is_open()){
            for(int i=0; i<line.size(); i++){
                if(i!= choice-1){
                    file_write<<line[i]<<endl;
                }
            }

        }else{
            cout<<"File cannot be opened!"<<endl;
        }
        file_write.close();
    }
};

class Edit
{
private:
    int choice;
    Contacts A;
public:
    void contacts_edit(){
        string temp;
        vector <string> line;
        ifstream file;
        file.open("ContactsList.txt");
        if(file.is_open()){
            while(getline(file,temp)){
                line.push_back(temp);
            }
        }else{
            cout<<"File cannot be opened"<<endl;
        }
        int max= line.size();
        cout<<"Enter the number where you want to edit the contact details"<<endl;
        cin>>choice;
        cin.ignore();
        while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Please only enter a number from the list: "<<endl;
            cin>>choice;
            cin.ignore();
        }else if(choice>max || choice<1){
            cout<<"Only a number from the list: "<<endl;
            cin>>choice;
            cin.ignore();
        }else{
            break;
        }
        }

        file.close();
        A.get_name();
        A.get_phone();
        A.get_email();
        line[choice-1]="Name: "+A.name+"   "+"Phone number: "+A.phone+"   "+"Email: "+A.email;
        ofstream file_write;
        file_write.open("ContactsList.txt");
        if(file_write.is_open()){
            for(int i=0; i<line.size(); i++){
                file_write<<line[i]<<endl;
            }

        }else{
            cout<<"File cannot be opened!"<<endl;
        }
        file_write.close();

    }
};

class View
{
private:
    string temp="";
    string store="";
    int num;

public:
    int length(){
        string temp="";
        vector <string> store;
        ifstream file;
        file.open("ContactsList.txt");
        if(file.is_open()){
            while(getline(file,temp)){
                store.push_back(temp);
            }
        }else{
            cout<<"The length of the file cannot be calculated!"<<endl;
        }
        return store.size();
    }

    bool check_empty(){
        ifstream file;
        file.open("ContactsList.txt");
        if(file.is_open()){
            while(getline(file,temp)){
                return true;
            }
        }
        return false;
    }

    void print_list(){
        num= length();
        ifstream file;
        file.open("ContactsList.txt");
        if(file.is_open()){
            int i=1;
            while(getline(file,temp)&& i<=length()){
                store+=to_string(i)+"."+temp;
                store+='\n';
                i++;
            }
            cout<<store;
        }
        else{
            cout<<"File cannot be opened!"<<endl;
        }
        file.close();
    }

};
#endif
