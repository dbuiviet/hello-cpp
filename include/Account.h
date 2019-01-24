//This is the start of header guard
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>

class Account
{

    private:
        std::string name;
        int balance{0};

    public:

        //constructor
        Account(std::string accountName, int initialBalance)
        {
            name = accountName;
            if (initialBalance > 0)
                balance = initialBalance;
        }

        void setName(std::string accountName)
        {
            name = accountName;
        }

        std::string getName() const
        {
            return name;
        }

        void deposit(int depositAmount)
        {
            if (depositAmount > 0)
                balance += depositAmount;
        }

        int getBalance() const
        {
            return balance;
        }

        void displayAccount()
        {
            std::cout << "The account: " << this->getName() << " has balance of $" << this->getBalance() << std::endl;
        }

};


//This is the end of header guard
#endif

