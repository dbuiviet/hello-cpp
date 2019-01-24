//This is the start of header guard
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>

class Account
{

    private:
        std::string name;
        long balance{0};

    public:

        //constructor
        Account(std::string accountName, long initialBalance)
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

        void deposit(long depositAmount)
        {
            if (depositAmount > 0)
                balance += depositAmount;
        }

        long getBalance() const
        {
            return balance;
        }

        void displayAccount()
        {
            //using this-> pointer
            std::cout << "The account: " << this->getName() << " has balance of $" << this->getBalance() << std::endl;
        }

};


//This is the end of header guard
#endif

