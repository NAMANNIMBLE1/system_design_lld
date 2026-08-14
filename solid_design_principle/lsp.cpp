#include<bits/stdc++.h>
using namespace std;

class nonWithdrawableAccount{
    public:
        virtual void deposit(double amount) = 0; // pure virtual function
}; 

class withdrawableAccount : public nonWithdrawableAccount{
    public:
        virtual void withdraw(double amount) = 0; // pure virtual function
};


class currentAccount: public withdrawableAccount{
    private:
        double balance;

    public:
        currentAccount(double initialBalance) : balance(initialBalance) {
            balance = initialBalance;
        }

        void deposit(double amount) override {
            balance += amount;
            cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
        }

        void withdraw(double amount) override {
            if(amount <= balance){
                balance -= amount;
                cout << "Withdrew: " << amount << ", New Balance: " << balance << endl;
            } else {
                cout << "Insufficient funds for withdrawal!" << endl;
            }
        }
};

class savingsAccount: public withdrawableAccount{
    private:
        double balance;

    public:
        savingsAccount(double initialBalance) : balance(initialBalance) {
            balance = initialBalance;
        }

        void deposit(double amount) override {
            balance += amount;
            cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
        }

        void withdraw(double amount) override{
            if(amount <= balance){
                balance -= amount;
                cout << "Withdrew: " << amount << ", New Balance: " << balance << endl;
            } else {
                cout << "Insufficient funds for withdrawal!" << endl;
            }
        }
};


class FixedDepositAccount: public nonWithdrawableAccount{
    private:
        double balance;

    public:
        FixedDepositAccount(double initialBalance) : balance(initialBalance) {
            balance = initialBalance;
        }

        void deposit(double amount) override {
            balance += amount;
            cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
        }
};

int main(){

    nonWithdrawableAccount* account1 = new currentAccount(1000);
    nonWithdrawableAccount* account2 = new savingsAccount(2000);
    nonWithdrawableAccount* account3 = new FixedDepositAccount(3000);

    withdrawableAccount* withdrawable1 = dynamic_cast<withdrawableAccount*>(account1);
    withdrawableAccount* withdrawable2 = dynamic_cast<withdrawableAccount*>(account2);  

    account1->deposit(500);
    account2->deposit(1000);
    account3->deposit(1500);

    withdrawable1->withdraw(300);
    withdrawable2->withdraw(500);
    // account3->withdraw(200); // This line will cause a compile-time error since FixedDepositAccount does not have a withdraw method
    
    account1->deposit(200); 
    
    delete account1;
    delete account2;
    delete account3;    

    return 0;
}