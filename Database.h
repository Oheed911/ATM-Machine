#include "Account.h"
#include "User.h"
#include "ATM.h"
#include <fstream>

//Data base class 
class Database:public Account,public User,public ATM
{
    protected:
        string File_NAME;
        fstream myFile;
    public:
    //constructor of the class
        Database(string FN)
        {
            File_NAME=FN;
            myFile.open(File_NAME,ios::app);
            myFile.close();            
        }
        void setFileName(string);
        string getFileName(); 
        bool FileSearch();
        void FileWrite();
        void UpdateBalance();  
        void FileWriteNewAccountUserInfo(); 
};
//class Functionality
void Database::setFileName(string FN)
{
    File_NAME=FN;
}
string Database::getFileName()
{
    return File_NAME;
}
void Database::FileWrite()
{
    myFile<<Account_Number<<",";
    myFile<<PIN_Number<<",";
    myFile<<Balance<<";"<<endl;
}
bool Database::FileSearch()
{
    int Account_Present=0;
    ifstream m;
    m.open("database.txt",ios::in);
    while (!m.eof()){
        string temp_read;
        string temp_acc;
        string temp_pin;
        string temp_balance;
        int count=1;
        getline(m,temp_read);
        for (int i=0;i<temp_read.length();i++)
        {
            if (count==1)
            {
                if (temp_read[i]==',')
                {
                    count++;
                }
                else
                    temp_acc+=temp_read[i];
            }
            else if(count==2)
            {
                if (temp_read[i]==',')
                {
                    count++;
                }
                else
                    temp_pin+=temp_read[i];
            } 
            else if (count==3)
            {
                if (temp_read[i]==';')
                {
                    count++;
                }
                else
                    temp_balance+=temp_read[i];
            }
        }
        //now checking if the file is the
        if (Account_Number==temp_acc && PIN_Number==temp_pin)
        {
            Balance=temp_balance;
            Account_Present=1;
            m.close();
            return true;
        }
        else 
            continue;
    }
    if (Account_Present==0)
    {
        cout << "Your Account Number or Pin is Wrong."<<endl;
        m.close();
        return false;
    }
    else 
        return false;
}
//function to update the balance 
void Database::UpdateBalance()
{
    fstream tempFile;
    string temp_read;
    string temp_acc;
    string temp_pin;
    string temp_balance;
    remove("tempFile.txt");
    tempFile.open("tempFile.txt",ios::app);
    int Account_Present=0;
    int index_Balance=0;
    ifstream Upd;
    Upd.open("database.txt",ios::app);
    while (!Upd.eof())
    {
        temp_read="";
        temp_acc="";
        temp_pin="";
        temp_balance="";
        int count=1;
        getline(Upd,temp_read);
        for (int i=0;i<temp_read.length();i++)
        {
            if (count==1)
            {
                if (temp_read[i]==',')
                {
                    count++;
                }
                else
                    temp_acc+=temp_read[i];
            }
            else if(count==2)
            {
                if (temp_read[i]==',')
                {
                    count++;
                }
                else
                    temp_pin+=temp_read[i];
            } 
            else if (count==3)
            {
                if (temp_read[i]==';')
                {
                    count++;
                }
                else
                {
                    index_Balance++;
                    temp_balance+=temp_read[i];
                }
            }
        }
        if (Account_Number==temp_acc && PIN_Number==temp_pin)
        {
            tempFile<<temp_acc<<",";
            tempFile<<temp_pin<<",";
            tempFile<<Balance<<";"<<endl;
        }
        else
        {
            tempFile<<temp_read<<endl;
        }
    }
    tempFile.close();
    //now removing the data base file
    //remove("database.txt");
    //now copying the updated temp file into the database txt file
    tempFile.open("tempFile.txt");
    //now creating the database file
    ofstream againdatabase;
   againdatabase.open("database.txt",ios::trunc);
   //now writing into the file

   while (!tempFile.eof())
   {
       temp_read="";
        //now reading the temp file
        getline(tempFile,temp_read);
        againdatabase<<temp_read<<endl;
   }
   remove("tempFile.txt");
}

//now if the user makes a new account its personal information will be written in the UserInfor.txt File
void Database::FileWriteNewAccountUserInfo()
{
    ofstream UserFile;
    UserFile.open("UserInfo.txt",ios::app);
    UserFile<<Account_Number<<",";
    UserFile<<getName()<<",";
    UserFile<<getCnic()<<",";
    UserFile<<getAge()<<",";
    UserFile<<getAdress()<<",";
    UserFile<<get_Gender()<<".";
    UserFile<<endl;
    UserFile.close();
    //now Writing the Info From the file
}
