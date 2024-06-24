#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Bank {

    char name[50];
    char acc_type;
    long int acc_no;
    double balance;

public:
    
    void getValue();
    double deposit();
    void withd();
    void display();

};

void Bank::getValue()
{
    cout<<"Enter your name: \n";
    cin.getline(name, 50);
    cout<<"Enter account type Savings(s)/Current(c)."<<endl;
    cin>>acc_type;
    acc_no = rand();
    cout<<"Your account number is "<<acc_no;

    if (acc_type == 's'){
        balance = 10;
    }
    else {
        balance = 100;
    }
}

void Bank::display(){
    cout<<""<<name;
    cout<<"\n Your balance is "<<balance;
}

double Bank::deposit()
{
    int temp;
    cout<<"Enter the amount you want to deposit: "<<endl;
    cin>>temp;
    balance = balance + temp;
    cout<<"You current balance is now "<<balance;
}

void Bank::withd()
{
    int temp;
    cout<<"Enter the amount you want to withdraw: "<<endl;
    cin>>temp;
    if (temp < balance){
        balance = balance - temp;
        cout<<"Your current balance is now "<<balance;
    }
    else {
        cout<<"Please enter an amount that you can afford.";
    }

}

int main()
{
    int ch;
    Bank b1[10];
    for(int i = 1; i <= 10; i++)
    {
        b1[i].getValue();
        cout<<"\n Enter your choice \n 1.Deposit \n 2.Withdraw \n 3.Display Balance: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            b1[i].deposit();
            break;
        case 2:
            b1[i].withd();
            break;
        case 3:
            b1[i].display();
            break;
        default:
            cout<<"Invalid input!";
        }
    }
    return 0;
}