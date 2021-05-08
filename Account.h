/*
OHEED IMRAN 
CS-D
19I-0525

*/
#include <string>
#include <iostream>
using namespace std;

class Account
{
protected:
	string Account_Number;
	string PIN_Number;
	string Balance;
public:
	//constructor of the class
	Account();
	//Account(string,string,double);
	//setter of the class
	void setAccount_Number(string);
	void setPin_NUMBER(string);
	void setBalance(string);
	//now the getters
	string getAccount_Number();
	string getPin_Number();
	string getBalance();
	void Input_Pin();
	void Input_Account_Number();
};
//now the defination of the funcitons
Account::Account()
{
	Account_Number="";
	PIN_Number="";
	Balance="";
}
//setter of the class
	void Account::setAccount_Number(string Acc_Num)
	{
		Account_Number=Acc_Num;
	}
	void Account::setPin_NUMBER(string Pin_Num)
	{
		PIN_Number=Pin_Num;
	}
	void Account::setBalance(string UserBal)
	{
		Balance=UserBal;
	}
	//now the getters
	string Account::getAccount_Number()
	{
		return Account_Number;
	}
	string Account::getPin_Number()
	{
		return PIN_Number;
	}
	string Account::getBalance()
	{
		return Balance;
	}
	void Account::Input_Pin()
	{
		 do {
        cout << "Enter Your Pin Number.(5-Digit)"<<endl;
        cin>>PIN_Number;
        }while(PIN_Number.length()!=5);
	}
	void Account::Input_Account_Number()
	{
		cout << "Enter your Account Number: "<<endl;
        cin>>Account_Number;
	}