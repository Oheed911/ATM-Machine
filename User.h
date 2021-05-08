/*
OHEED IMRAN 
CS-D
19I-0525

*/
#include <cstring>
#include <iostream>
using namespace std;

class User
{
    private:
        string Name;
        string Cnic;
        string Age;
        string Adress;
        char gender;
    public:
    //constructor
    User();
    //now the setter and the getters;
    string getName();
    string getCnic();
    string getAge();
    string getAdress();
    char get_Gender();
    //now the setters
    void setName(string);
    void setCnic(string);
    void setAge(string);
    void setAdress(string);
    void setgender(char);
    void Input_UserIfo();
};
    string User::getName()
    {
        return Name;
    }
    string User::getCnic()
    {
        return Cnic;
    }
    string User::getAge()
    {
        return Age;
    }
    string User::getAdress()
    {
        return Adress;
    }
    char User::get_Gender()
    {
        return gender;
    }
    //now the setters
    void User::setName(string Nam)
    {
        Name=Nam;
    }
    void User::setCnic(string C)
    {
        Cnic=C;
    }
    void User::setAge(string age_user)
    {
        Age=age_user;
    }
    void User::setAdress(string Addr)
    {
        Adress=Addr;
    }
    void User::setgender(char g)
    {
        gender=g;
    }
    User::User()
    {
        Name="";
        Cnic="";
        Age="";
        Adress="";
        gender='\0';
    }
    void User::Input_UserIfo()
    {
        cout << "Enter Your Name: "<<endl;
        cin.ignore();
        getline(cin,Name);
        do{
        cout << "Enter User CNIC NUMBER: (greater than 13 Digit) ";
        cin>>Cnic;
        }while(Cnic.length()<13);
        do{
        cout << "Enter User Age:(Must Be Greater than 17) "<<endl;
        cin>>Age;
        }while(stoi(Age)<18);
        //now inputing the Adress:
        cout << "Enter Your Adress: "<<endl;
        cin.ignore();
        getline(cin,Adress);
        do {
        cout << "Enter Your Gender :(M/F) :";
        cin>>gender;
        }while(gender!='M'&& gender!='F' && gender!='m' && gender!='f');

    }