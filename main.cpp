#include <iostream>
#include <string>
#include "Contacts.h"

using namespace std;

int main()
{
    int choice;
    cout<<"Choose which operation you want to do from 1 to 5: "<<endl;
    cout<<"1. Add contact"<<endl<<"2. View contact"<< endl<<"3. Edit contact"<<endl<<"4. Delete contact"<<endl<<"5. Quit"<<endl;
    cin>>choice;
    cin.ignore();
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Only eneter a number from the list: "<<endl;
        cin>>choice;
        cin.ignore();
    }
    while(choice!=5){
        switch(choice){
            case 1:{
                cout<<endl;
                Contacts sample;
                sample.get_name();
                sample.get_phone();
                sample.get_email();
                sample.store();
                break;
            }
            case 2:{
                cout<<endl;
                View sample;
                bool flag= sample.check_empty();
                if(flag){
                    cout<<"Here are the contacts saved: "<<endl;
                    sample.print_list();
                }else{
                    cout<<"There are no contacts saved!"<<endl;
                }
                break;
            }
            case 3:{
                cout<<endl;
                View sample;
                bool flag= sample.check_empty();
                if(flag){
                    sample.print_list();
                    Edit detail;
                    detail.contacts_edit();
                }else{
                    cout<<"There are no contacts saved to edit!"<<endl;
                }
                break;
            }
            case 4:{
                cout<<endl;
                View sample;
                bool flag= sample.check_empty();
                if(flag){
                    sample.print_list();
                    Delete detail;
                    detail.contact_deletion();
                }else{
                    cout<<"There are no contacts saved to delete!"<<endl;
                }
                break;

            }
            default:{
                cout<<endl;
                cout<<"Please enter a number from 1 to 5"<<endl;
                break;
            }

        }
        cout<<endl;
        cout<<"Choose which operation you want to do from 1 to 5: "<<endl;
        cout<<"1. Add contact"<<endl<<"2. View contact"<< endl<<"3. Edit contact"<<endl<<"4. Delete contact"<<endl<<"5. Quit"<<endl;
        cin>>choice;
        cin.ignore();
        while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Only eneter a number from the list: "<<endl;
        cin>>choice;
        cin.ignore();
    }
    }
    cout<<"Bye!"<<endl;
    return 0;
}
