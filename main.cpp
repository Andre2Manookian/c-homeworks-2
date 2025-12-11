#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For formatting the currency

using namespace std;

// --- The Account Blueprint (Our Class) ---
class BankAccount {
private:
 
    double balance;
    vector<string> history; // Stores transaction summaries

public:
   
    BankAccount(double initialAmount) {
        balance = initialAmount;
        history.push_back("Account Opened with $" + to_string(initialAmount));
    }

  
    void showBalance() {
        cout << "\n--- Current Balance ---" << endl;
       
        cout << "Your balance is: $" << fixed << setprecision(2) << balance << endl;
        cout << "-----------------------\n" << endl;
    }

   
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            
            history.push_back("Deposited $" + to_string(amount));
            cout << "Deposit successful. Added $" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Error: Deposit must be a positive amount." << endl;
        }
    }

    // 3. Feature: Withdraw
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal must be a positive amount." << endl;
            return;
        }

        // **Feature Requirement: Balance Check**
        if (amount <= balance) {
            balance -= amount;
           
            history.push_back("Withdrew $" + to_string(amount));
            cout << "Withdrawal successful. Took out $" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Insufficient funds! You tried to withdraw $" << fixed << setprecision(2) << amount
                 << ", but only have $" << balance << endl;
        }
    }

   
    void showLastTransaction() {
        cout << "\n--- Last Activity ---" << endl;
        if (history.empty()) {
            cout << "No recorded activities." << endl;
        } else {
    
            cout << history.back() << endl;
        }
        cout << "---------------------\n" << endl;
    }
};

// --- Main Program (ATM Simulation) ---
int main() {
    // 1. Create the Account object
    BankAccount myAccount(450.50);
    
    cout << "Welcome to the Simple ATM!" << endl;

    // First check
    myAccount.showBalance();

    // 2. Do a Deposit
    cout << "\n--> DEPOSIT $100.00" << endl;
    myAccount.deposit(100.00);
    myAccount.showBalance();

    // 3. Do a Successful Withdrawal
    cout << "\n--> WITHDRAW $50.00" << endl;
    myAccount.withdraw(50.00);
    myAccount.showBalance();

    // 4. Attempt a large Withdrawal (Should fail)
    cout << "\n--> ATTEMPT WITHDRAW $1000.00" << endl;
    myAccount.withdraw(1000.00);

    // 5. Show the last successful transaction (the $50 withdrawal)
    myAccount.showLastTransaction();

    return 0;
}
