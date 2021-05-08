/*
OHEED IMRAN 
CS-D
19I-0525

*/
#include <iostream>
using namespace std;

class ATM
{
    protected:
        int atm_Options;
        double Remaining_Ammount;
        int NoOf_20_Bills;
    public:
        //constructor
        ATM();
        int getatm_Options();
        double getRemaining_Ammount();
        int getNoOf_20_Bills();
        //setter
        void setatm_Options(int);
        void setRemaining_Ammount(double);
        void setNoOf_20_Bills(int);
        void Display_Options();
        void InputUserChoice();
};
ATM::ATM()
{
    atm_Options=0;
    Remaining_Ammount=0;
    NoOf_20_Bills=0;
}
void ATM::Display_Options()
{
    cout << "WithDrawal Options: "<<endl;
    cout << "1- 20"<<endl;
    cout << "2- 40"<<endl;
    cout << "3- 60"<<endl;
    cout << "4- 100"<<endl;
    cout << "5- 200"<<endl;
    cout << "6- Cancel Transaction"<<endl;
    InputUserChoice();
}
void ATM::InputUserChoice()
{
    //time check for the 20 seconds
    do{
        cout << "Enter your Option: ";
        cin>>atm_Options;
    }while(atm_Options>=7  || atm_Options <=0);
}
//now the setter and the getter
void ATM::setatm_Options(int a)
{
    atm_Options=a;   
}
void ATM::setRemaining_Ammount(double a)
{
    Remaining_Ammount=a;
}
void ATM::setNoOf_20_Bills(int a)
{
    NoOf_20_Bills=a;
}
//now the getter
int ATM::getatm_Options()
{
    return atm_Options;
}
double ATM::getRemaining_Ammount()
{
    return Remaining_Ammount;
}
int  ATM::getNoOf_20_Bills()
{
    return NoOf_20_Bills;
}
