#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class for Bank Account
class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string name, int accNo) {
        accountHolder = name;
        accountNumber = accNo;
        balance = 0.0;
    }

    // Getter for Account Number
    int getAccountNumber() const {
        return accountNumber;
    }

    // Deposit Money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Withdraw Money
    void withdraw(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }

    // Transfer Money to another account
    bool transfer(BankAccount &receiver, double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            receiver.balance += amount;
            return true;
        }
        return false;
    }

    // Display Account Details
    void display() const {
        cout << "\nAccount Holder: " << accountHolder
             << "\nAccount Number: " << accountNumber
             << "\nBalance: $" << balance << endl;
    }
};

// Function to find account by account number
BankAccount* findAccount(vector<BankAccount> &accounts, int accountNumber) {
    for (auto &account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            return &account;
        }
    }
    return nullptr;
}

int main() {
    vector<BankAccount> accounts;
    int choice;
    int nextAccountNumber = 1001; // Starting account number

    do {
        cout << "\n=== Online Banking System ===\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Money\n";
        cout << "5. View Account Details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                cout << "Enter account holder name: ";
                cin.ignore(); // Ignore leftover newline
                getline(cin, name);

                BankAccount newAccount(name, nextAccountNumber++);
                accounts.push_back(newAccount);

                cout << "Account created successfully. Your Account Number is " 
                     << newAccount.getAccountNumber() << ".\n";
                break;
            }

            case 2: {
                int accNo;
                double amount;
                cout << "Enter account number: ";
                cin >> accNo;
                BankAccount *acc = findAccount(accounts, accNo);

                if (acc) {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    acc->deposit(amount);
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }

            case 3: {
                int accNo;
                double amount;
                cout << "Enter account number: ";
                cin >> accNo;
                BankAccount *acc = findAccount(accounts, accNo);

                if (acc) {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    acc->withdraw(amount);
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }

            case 4: {
                int senderAccNo, receiverAccNo;
                double amount;
                cout << "Enter your account number: ";
                cin >> senderAccNo;
                cout << "Enter receiver's account number: ";
                cin >> receiverAccNo;
                cout << "Enter amount to transfer: ";
                cin >> amount;

                BankAccount *sender = findAccount(accounts, senderAccNo);
                BankAccount *receiver = findAccount(accounts, receiverAccNo);

                if (sender && receiver) {
                    if (sender->transfer(*receiver, amount)) {
                        cout << "Transfer successful.\n";
                    } else {
                        cout << "Transfer failed. Insufficient balance or invalid amount.\n";
                    }
                } else {
                    cout << "One or both accounts not found.\n";
                }
                break;
            }

            case 5: {
                int accNo;
                cout << "Enter account number: ";
                cin >> accNo;
                BankAccount *acc = findAccount(accounts, accNo);

                if (acc) {
                    acc->display();
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }

            case 6:
                cout << "Thank you for using Online Banking System. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
