#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Account {
protected:
    string customerName;
    long long int accountNo;
    string accountType;
    float accountBalance;

public:
    Account(string cName = "Default", long int accNo = 0, string accType = "Savings", float accBal = 500.0)
        : customerName(cName), accountNo(accNo), accountType(accType), accountBalance(accBal) {}

    void depositAmt(float dpamt) {
        accountBalance += dpamt;
        cout << "Balance after deposit: " << accountBalance << endl;
    }

    void displayBalance() const {
        cout << "Account Balance: " << accountBalance << endl;
    }

    void withdrawal(float withdrawalAmt) {
        if (accountBalance >= withdrawalAmt) {
            accountBalance -= withdrawalAmt;
            cout << "Balance after withdrawal: " << accountBalance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
};

class CurrentAccount : public Account {
    float minimumBalance;
    float serviceCharge;

public:
    CurrentAccount(string cName, long int accNo, float accBal = 500.0, float minBal = 500.0, float serCharge = 150.0)
        : Account(cName, accNo, "Current", accBal), minimumBalance(minBal), serviceCharge(serCharge) {}

    void checkMinimumBal() {
        if (accountBalance < minimumBalance) {
            cout << "Account balance is below the minimum amount." << endl;
            cout << "Penalty will be imposed!" << endl;
            accountBalance -= serviceCharge;
            cout << "Balance after penalty: " << accountBalance << endl;
        }
    }
};

class SavingAccount : public Account {
    double rate;
    int num_times_compounded;

public:
    SavingAccount(string cName, long int accNo, float accBal = 500.0, double r = 2.0, int ntc = 1)
        : Account(cName, accNo, "Savings", accBal), rate(r), num_times_compounded(ntc) {}

    void computeInterest() {
        double amount = accountBalance * pow((1 + rate / num_times_compounded), num_times_compounded);
        double compoundInterest = amount - accountBalance;
        accountBalance += compoundInterest;
        cout << "Compound interest: " << compoundInterest << endl;
        cout << "Balance after interest: " << accountBalance << endl;
    }
};

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Deposit Amount\n";
    cout << "2. Withdraw Amount\n";
    cout << "3. Display Balance\n";
    cout << "4. Compute Interest (Savings Account)\n";
    cout << "5. Check Minimum Balance (Current Account)\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    string accountType;
    cout << "Enter account type (Savings/Current): ";
    cin >> accountType;

    Account* account = nullptr;
    if (accountType == "Savings") {
        account = new SavingAccount("John Doe", 123456789);
    } else if (accountType == "Current") {
        account = new CurrentAccount("Jane Doe", 987654321);
    } else {
        cout << "Invalid account type!" << endl;
        return 0;
    }

    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                float dpAmt;
                cout << "Enter deposit amount: ";
                cin >> dpAmt;
                account->depositAmt(dpAmt);
                break;
            }
            case 2: {
                float wdAmt;
                cout << "Enter withdrawal amount: ";
                cin >> wdAmt;
                account->withdrawal(wdAmt);
                break;
            }
            case 3:
                account->displayBalance();
                break;
            case 4:
                if (accountType == "Savings") {
                    static_cast<SavingAccount*>(account)->computeInterest();
                } else {
                    cout << "Interest computation is only available for Savings Account." << endl;
                }
                break;
            case 5:
                if (accountType == "Current") {
                    static_cast<CurrentAccount*>(account)->checkMinimumBal();
                } else {
                    cout << "Minimum balance check is only available for Current Account." << endl;
                }
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    delete account;
    return 0;
}