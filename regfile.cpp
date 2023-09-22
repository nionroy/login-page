#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void login();
void reg();
void forgot();
int main(){
int c;
    cout<<"\t\t\t________________________________________________\n\n\n";
    cout<<"\t\t\t       welcome to the login page      \n\n\n";
    cout<<"\t\t\t________________________   menu     _____________________\n\n";
    cout<<"                                                                  \n";
    cout<<"\t|press 1 to login                        |"<<endl;
    cout<<"\t|press 2 to Register                     |"<<endl;
    cout<<"\t|press 3 if you forgot your password     |"<<endl;
    cout<<"\t press 4 to exit                         |"<<endl;
    cout<<"\t please enter your choice :";
    cin>>c;
    cout<<endl;
    switch(c)
    {
    case 1:
        login();
        break;
    case 2:
        reg();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout<<"\t\t\t thank you!   \n\n";
    default:
        system("cls");
        cout<<"\t\t\t please select option bellow  \n"<<endl;
        main();
    }



}
void login(){
    int count;
    string userid,password,id,pass;
    system("cls");
    cout<<"\t\t\t please enter the username and password :  "<<endl;
    cout<<"\t\t\t username ";
    cin>>userid;
    cout<<"\t\t\t password ";
    cin>>password;

    ifstream input("records.txt");
    while(input>>id>>pass)
    {
        if(id==userid &&pass==password){
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1){
        cout<<userid<<"\n your login is successfull \n thanks for logging in !\n";
        main();
    }
    else{
        cout<<"\n login error \n check your username and passwords\n";
        main();
    }

}
void reg()
{
    string ruserid,rpassword,rid,rpass;
    system("cls");
    cout<<"\t\t\t enter the user name :";
    cin>>ruserid;
    cout<<"\t\t\t enter the password :";
    cin>>rpassword;
    ofstream f1("records.txt", ios::app);
    f1<<ruserid<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\t\t\t registration is successfull \n";
    main();


}
void forgot()
{
    int option;
    system("cls");
    cout<<"\t\t\t you forgot the password ?no worries \n";
    cout<<"press 1 to search your id by username "<<endl;
    cout<<"press 2 to go back to the main menu "<<endl;
    cout<<"\t\t\t enter the choice :";
    cin>>option;
    switch (option)
    {
    case 1:
        {
            int count=0;
            string suserid,sid,spass;
            cout<<"\t\t\t\enter the userid witch you rembered:";
            cin>>suserid;
            ifstream f2("records.txt");
            while(f2>>sid>>spass)
                  {
                  if(sid==suserid){
                      count=1;
                  }

                  }
            f2.close();
            if(count==1)
            {
                cout<<"\n\n your account is found!\n";
                cout<<"\n\n your password is  :"<<spass;
                main();
            }

            else{
                cout<<"\n\t sorry your account is not found! \n";
                main();
            }
            break;
        }
    case 2:
        {
            main();
        }
        default:
        cout<<"\t\t\t wrong choice ! please try again "<<endl;
        forgot();

    }

}

