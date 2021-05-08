/*
OHEED IMRAN 
CS-D
19I-0525

*/

#include "Database.h"
#include <cstdlib>
#include <ctime>
class Engine:public Database
{
    private:
        int FirstOptions;
        int SecondOptions;
    public:
        Engine();
        int getFirstOptions();
        int getSecondaryOptions();
        void setFirstOptions(int);
        void setSecondOptions(int);
        void Display_FirstOptions();
        void Input_FirstOptions();
        void Input_SecondOptions();
        void Check_First_Options();
        void Display_SecondOptions();
        void Check_Second_Options();
};
Engine::Engine():Database("database.txt")
{
    FirstOptions=0;
    SecondOptions=0;
}
int Engine::getFirstOptions()
{
    return FirstOptions;
}
int Engine::getSecondaryOptions()
{
    return SecondOptions;
}
void Engine::setFirstOptions(int a)
{
    FirstOptions=a;
}
void Engine::setSecondOptions(int b)
{
    SecondOptions=b;
}
void Engine::Display_FirstOptions()
{

    cout << "Welcome! "<<endl;
    cout << "1- LOGIN TO YOUR CURRENT ACCOUNT. "<<endl;
    cout << "2- Create Your New Account. "<<endl;
    cout <<"3- Exit."<<endl;
    Input_FirstOptions();
    //now storing the cash in the atm
    setNoOf_20_Bills(500);
    setRemaining_Ammount(NoOf_20_Bills*20);
    Check_First_Options();
}
void Engine::Input_FirstOptions()
{
    cout << "Choose from the above Options: "<<endl;
    cin>>FirstOptions;
}
void Engine::Check_First_Options()
{
    if (FirstOptions==1)
    {
            Input_Account_Number();
            Input_Pin();
            if (FileSearch())
            {
                Display_SecondOptions();
            }
            else if (!FileSearch())
            {
                Display_FirstOptions();
            }
    }
    else if (FirstOptions==2)
    {
        int tempB;
        float temp2;
        srand(time(0));
        long long int temp;
        temp=10000+(rand()%99999+1);
        setAccount_Number(to_string(temp));
        cout << "Your Randomnly Generated Account number is : "<<getAccount_Number()<<endl;
        Input_Pin();
        Input_UserIfo();
        myFile.open(File_NAME,ios::app);
        do
        {
            cout << "Enter The ammount you want to deposit in Your Bank Account(Non-Negative in Cents) : "<<endl;
            cin>>tempB;
        }while (tempB<0);
        //now we have to convert this into dollars
        temp2=tempB/100.0;
        //now setting the balance
        setBalance(to_string(temp2));
        //calling the Function to write into the class
        FileWrite();
        FileWriteNewAccountUserInfo();

    }
    else if (FirstOptions==3)
    {
        cout << "Thank You For Visiting."<<endl;
    }
    else
    {
        cout << "You have entered Worng Option: "<<endl;
        cout << "Choose From 1-3."<<endl;
        Display_FirstOptions();
    }
}
void Engine::Display_SecondOptions()
{
    cout << "Welcome to the main Menue: "<<endl;
    cout << "1- View My Balance. "<<endl;
    cout << "2- WithDraw Cash. "<<endl;
    cout << "3- Deposit Funds. "<<endl;
    cout << "4- Exit."<<endl;
    Input_SecondOptions();
    Check_Second_Options();
}
void Engine::Input_SecondOptions()
{
     do{
       cout << "Enter your choice. "<<endl;
       cin>>SecondOptions; 
    }while (SecondOptions>5 || SecondOptions <=0);
}
void Engine::Check_Second_Options()
{
    switch(SecondOptions)
    {
        case 1:
            cout << "Your  Current Balance is: "<<Balance<<endl;
        break;
        //for withdrawa Options
        case 2: 
            InputAgain:
            double temp;
            Display_Options();
            if (atm_Options==1)
            {
                if (stof(Balance)>=20)
                {
              
                    temp=stoi(Balance)-20;
                    setNoOf_20_Bills(getNoOf_20_Bills()-1);
                    setRemaining_Ammount(getRemaining_Ammount()-20);
                    cout <<getNoOf_20_Bills()<<endl;
                    cout << getRemaining_Ammount()<<endl;
                    Balance=to_string(temp);
                    UpdateBalance();
                    cout << "Transaction Succssful!"<<endl;
                    cout << "Thanks For Comming. "<<endl;
                }
                else 
                {
                    cout << "Your Balance is Less than the ammount you want to debit."<<endl; 
                    cout << "Your Current Balance IS: "<<getBalance()<<endl;
                    goto InputAgain;
                }  
            }
            else if(atm_Options==2) 
            {
               if (stof(Balance)>=40)
                {
                
                    temp=stof(Balance)-40;
                    setNoOf_20_Bills(getNoOf_20_Bills()-2);
                    setRemaining_Ammount(getRemaining_Ammount()-40);
                    Balance=to_string(temp);
                    UpdateBalance();
                    cout << "Transaction Succssful!"<<endl;
                    cout << "Thanks For Comming. "<<endl;
                }
               else 
                {
                    cout << "Your Balance is Less than the ammount you want to debit."<<endl; 
                    cout << "Your Current Balance IS: "<<getBalance()<<endl;
                    goto InputAgain;
                } 
            }
            else if(atm_Options==3)
            {
                if (stof(Balance)>60)
                {
                    
                    temp=stof(Balance)-60;
                    setNoOf_20_Bills(getNoOf_20_Bills()-3);
                    setRemaining_Ammount(getRemaining_Ammount()-60);
                    Balance=to_string(temp);
                    UpdateBalance();
                    cout << "Transaction Succssful!"<<endl;
                    cout << "Thanks For Comming. "<<endl;
                }
                else 
                {
                    cout << "Your Balance is Less than the ammount you want to debit."<<endl; 
                    cout << "Your Current Balance IS: "<<getBalance()<<endl;
                    goto InputAgain;
                }  
            }
            else if (atm_Options==4)
            {
                
                
                if (stof(Balance)>100)
                {
                    
                    temp=stof(Balance)-100;
                    setNoOf_20_Bills(getNoOf_20_Bills()-5);
                    setRemaining_Ammount(getRemaining_Ammount()-100);
                    Balance=to_string(temp);
                    UpdateBalance();
                    cout << "Transaction Succssful!"<<endl;
                    cout << "Thanks For Comming. "<<endl;
                }
               else 
                {
                    cout << "Your Balance is Less than the ammount you want to debit."<<endl; 
                    cout << "Your Current Balance IS: "<<getBalance()<<endl;
                    goto InputAgain;
                } 
            }
            else if (atm_Options==5)
            {
                if (stof(Balance)>200)
                {
                    cout << getRemaining_Ammount()<<endl;
                cout << getNoOf_20_Bills()<<endl;
                    temp=stof(Balance)-200;
                    setNoOf_20_Bills(getNoOf_20_Bills()-10);
                    setRemaining_Ammount(getRemaining_Ammount()-200);
                    Balance=to_string(temp);
                    UpdateBalance();
                    cout << "Transaction Succssful!"<<endl;
                    cout << "Thanks For Comming. "<<endl;
                }
                else 
                {
                    cout << "Your Balance is Less than the ammount you want to debit."<<endl; 
                    cout << "Your Current Balance IS: "<<getBalance()<<endl;
                    goto InputAgain;
                } 
            }
            else if(atm_Options==6)
            {
                Display_SecondOptions();
            }
         break; 
         //now if the user wants to deposit dunds the money
         case 3:
            int temp_cash; 
            double convertedIntoDollars;
            cout << "If You Want to Go Back, Press Zero: "<<endl;
            do{
                cout << "Enter the ammount You want to deposit in your bank account: "<<endl;
                cin>>temp_cash;
            }while(temp_cash<0);
            if (temp_cash==0)
            {
                cout << "You Have Pressed Zero therefore, Taking you back."<<endl;
                Display_FirstOptions();
            }
            //now converitng the cents inot dollars
            cout << "Your Entered Ammount is (Ignoring the Decimal Point): "<<temp_cash<<endl;
            convertedIntoDollars=(temp_cash/100.0);
            //now storing it into the Account Balance.
            setBalance(to_string(convertedIntoDollars+stof(getBalance())));
            //now updating the balance in the database
            UpdateBalance();
            cout << "Your New Balnace Is : "<<getBalance()<<endl;
            cout << "Thank You For Visisting. "<<endl;
        break;
        case 4:
            cout << "Exiting..."<<endl; 
            Display_FirstOptions();
        break;
        default:
            cout << "You have Entered Wrong Option."<<endl;
            cout << "Enter Agaian: "<<endl;
            Input_SecondOptions();
    }
}

