// Saul Resendiz
// CIS 17-B
// Lesson 1 Assignment

#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
using namespace std;

class BankAccount {
// PRIVATE MEMBERS
private:
    string accountHolderName;
    int accountNumber;
    double balance;
//PUBLIC MEMBERS
public:
    BankAccount(string accName, double startBalance) {  // CLASS CONSTRUCTOR
        accountHolderName = accName;    // ACCOUNT NAME HOLDER
        balance = startBalance;     // ACOUNT INITIAL BALANCE
    }

    void deposit(double amount) {
        try {
            if (amount < 0) {   // Input Validation
                throw invalid_argument("Deposit amount cannot be negative.");
            }
            balance += amount;  // Adding to total balance count
            cout << "Deposit successful! New balance: $" << balance << endl;
        } 
        catch (const exception& e) {    // Exception Error Mssg
            cout << "ERROR: " << e.what() << endl;
        }
    }

    void withdraw(double amount) {
        try {
            if (amount < 0) {       // Input Validation
                throw invalid_argument("Withdrawal amount must be positive.");  
            }
            if (amount > balance) { // Input Validation
                throw invalid_argument("Insufficient funds!");
            }
            balance -= amount;  // Subtracting withdraw amount from account balance
            cout << "Withdrawal completed. New balance: $" << balance << endl;
        } 
        catch (const exception& e) {
            cout << "ERROR: " << e.what() << endl;
        }
    }

    void getBalance() const {   // function to display users current balance 
        cout << "Current Balance: $" << balance << endl;
    }
};

// MAIN
int main() {
    
    BankAccount* userAccount = nullptr;     // Creating an empty users bank account object
    int userChoice;

    do {
        // Display menu to user/console
        cout << "\nWelcome to Simple Bank System!" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Create account" << endl;
        cout << "2. Deposit money" << endl;
        cout << "3. Withdraw money" << endl;
        cout << "4. Check balance" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1: { // CREATE ACCOUNT
                string accName;
                double startBalance;

                cout << "Enter account holder name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Clearing any potential leftover newline char
                getline(cin, accName);

                cout << "Enter initial deposit: ";  //Intialize bank acc starting balance 
                cin >> startBalance;

                userAccount = new BankAccount(accName, startBalance);   // Initializing users' bank acc object with values
                cout << "Account created successfully!" << endl;
                break;
            }

            case 2: // DEPOSIT MONEY
                if (userAccount) {  // If an account is created already:
                    cout << "Enter amount to deposit: ";
                    double userDepositAmount;
                    cin >> userDepositAmount;
                    userAccount->deposit(userDepositAmount);
                } 
                else 
                {
                    cout << "Need an account first." << endl;
                }
                break;

            case 3: // WITHDRAW MONEY
                if (userAccount) {  // If an account is created already:
                    cout << "Enter amount to withdraw: ";
                    double userWithdrawAmount;
                    cin >> userWithdrawAmount;
                    userAccount->withdraw(userWithdrawAmount);
                } 
                else 
                {
                    cout << "Need an account first." << endl;
                }
                break;

            case 4: // CHECK BALANCE
                if (userAccount) {
                    userAccount->getBalance();
                } 
                else 
                {
                    cout << "Need an account firts." << endl;
                }
                break;

            case 5: // EXITING GOODBYE MSG
                cout << "Thank you for using Simple Bank System!" << endl;
                break;

            default:
                cout << "Invalid input!" << endl;
        }
    } while (userChoice != 5);  // KEEPS THE MENU LOOPING, AS LONG AS USER DOESNT SELECT "5", or Exit 

    delete userAccount;     // Deleting the bank acc account object
    return 0;
}
