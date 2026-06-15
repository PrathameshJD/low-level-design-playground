#include<iostream>
#include<vector>

using namespace std;

class Account {
public:
    virtual void deposit(double amount) = 0;
    virtual ~Account() = default;
};

class Withdrawable {
public:
    virtual void withdraw(double amount) = 0;
    virtual ~Withdrawable() = default;
};

class SavingsAcc : public Account, public Withdrawable {
private:
    double balance = 0;

public:
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if(balance >= amount){
            balance -= amount;
            cout << "Withdraw amount: "<< amount << " from Savings Account. New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Savings\n";
        }
    }
};

class CurrentAcc : public Account, public Withdrawable {
private:
    double balance = 0;

public:
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if(balance >= amount){
            balance -= amount;
            cout << "Withdraw amount: "<< amount << " from Current Account. New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Current\n";
        }
    }
};

class FixedDepositAcc : public Account {
private:
    double balance = 0;

public:
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Deposit Account. New Balance: " << balance << endl;
    }
};

class BankClient {
private:
    vector<Account*> accounts;
    vector<Withdrawable*> withdrawableAccounts;

public:
    BankClient(vector<Account*> accs,
               vector<Withdrawable*> waccs)
        : accounts(accs),
          withdrawableAccounts(waccs) {}

    void processTransaction() {

        // deposit for all accounts
        for (Account* acc : accounts) {
            acc->deposit(1000);
        }

        // withdraw only where supported
        for (Withdrawable* acc : withdrawableAccounts) {
            acc->withdraw(500);
        }
    }
};


int main() {

    vector<Account*> accounts;
    vector<Withdrawable*> withdrawables;

    SavingsAcc* s = new SavingsAcc();
    CurrentAcc* c = new CurrentAcc();
    FixedDepositAcc* f = new FixedDepositAcc();

    accounts.push_back(s);
    accounts.push_back(c);
    accounts.push_back(f);

    withdrawables.push_back(s);
    withdrawables.push_back(c);

    BankClient client(accounts, withdrawables);
    client.processTransaction();

    return 0;
}