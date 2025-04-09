#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ATM {
private:
    string userPIN = "1234";
    float balance = 1000.0;

public:
    void checkBalance() {
        cout << "Current Balance: $" << balance << endl;
    }

    void deposit(float amount) {
        balance += amount;
        cout << "Deposited $" << amount << ". New Balance: $" << balance << endl;
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New Balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    bool authenticate(string pin) {
        return pin == userPIN;
    }
};

int main() {
    ATM atm;
    string pin;

    cout << "Enter your PIN: ";
    cin >> pin;

    if (atm.authenticate(pin)) {
        int choice;
        do {
            cout << "\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\nChoice: ";
            cin >> choice;

            if (choice == 1) atm.checkBalance();
            else if (choice == 2) {
                float amount;
                cout << "Enter amount: ";
                cin >> amount;
                atm.deposit(amount);
            }
            else if (choice == 3) {
                float amount;
                cout << "Enter amount: ";
                cin >> amount;
                atm.withdraw(amount);
            }
        } while (choice != 4);
    } else {
        cout << "Invalid PIN!" << endl;
    }

    return 0;
}
