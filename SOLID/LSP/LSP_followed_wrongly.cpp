#include<iostream>
#include<vector>

using namespace std;

class Account {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;

    virtual ~Account() = default;
};

class SavingsAcc : public Account {
private:
    double balance = 0;
public:
    void deposit(double amount){
        this->balance += amount; 
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount){
        if(balance>=amount){
            balance = balance - amount;
            cout << "Withdraw amount: "<< amount << " from Savings Account. New balance: " << balance << endl;
        }else{
            cout << "Insufficient funds in the Savings Account!\n";
        }
        
    }
};

class CurrentAcc : public Account {
private:
    double balance = 0;
public:
    void deposit(double amount){
        this->balance += amount; 
        cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount){
        if(balance>=amount){
            balance = balance - amount;
            cout << "Withdraw amount: "<< amount << " from Current Account. New balance: " << balance << endl;
        }else{
            cout << "Insufficient funds in the Current Account!\n";
        }
    }
};

class FixedDepositAcc : public Account {
private:
    double balance = 0;
public:
    void deposit(double amount){
        this->balance += amount; 
        cout << "Deposited: " << amount << " in Fixed Deposit Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount){
        throw logic_error("Withdrawal not allowed in Fixed Term Account!");
    }
};

class BankClient {
private:
    vector<Account *> accounts;

public: 
    BankClient(vector<Account*> accounts){
        this->accounts = accounts;
    }

    void processTransaction(){
        for(Account* acc: accounts){
            acc->deposit(1000);

            if(typeid(*acc) == typeid(FixedDepositAcc)){
                cout << "Skipping withdrawal for Fixed Term Account.\n" ;
            }
            else{
                try{
                    acc->withdraw(500);
                }catch (const logic_error &e){
                    cout << "Exception: " << e.what() << endl;
                }
            }
        }
    }
};


int main(){
    vector<Account*> accounts;
    accounts.push_back(new SavingsAcc());
    accounts.push_back(new CurrentAcc());
    accounts.push_back(new FixedDepositAcc());
    
    BankClient *client = new BankClient(accounts);

    client->processTransaction();

    return 0;

}