#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a bank account
struct BankAccount {
    int accountNumber;
    char customerName[50];
    float balance;
};

// Function prototypes
void createAccount();
void deposit();
void withdraw();
void transfer();
void viewAccountDetails();

// Global variables
struct BankAccount account;
int accountCreated = 0; // Flag to check if account is created

int main() {
    int choice;

    printf("Welcome to the Banking System Simulator\n");

    do {
        // Display menu
        printf("\nMain Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. View Account Details\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                transfer();
                break;
            case 5:
                viewAccountDetails();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 6.\n");
        }
    } while(choice != 6);

    return 0;
}

void createAccount() {
    if(accountCreated) {
        printf("Account already exists!\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &account.accountNumber);
    printf("Enter customer name: ");
    scanf(" %[^\n]s", account.customerName);
    printf("Enter initial balance: ");
    scanf("%f", &account.balance);

    accountCreated = 1;
    printf("Account created successfully!\n");
}

void deposit() {
    if(!accountCreated) {
        printf("Account does not exist. Please create an account first.\n");
        return;
    }

    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if(amount <= 0) {
        printf("Invalid amount. Deposit amount must be greater than zero.\n");
        return;
    }

    account.balance += amount;
    printf("Deposit successful. Updated balance: %.2f\n", account.balance);
}

void withdraw() {
    if(!accountCreated) {
        printf("Account does not exist. Please create an account first.\n");
        return;
    }

    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if(amount <= 0 || amount > account.balance) {
        printf("Invalid amount or insufficient balance.\n");
        return;
    }

    account.balance -= amount;
    printf("Withdrawal successful. Updated balance: %.2f\n", account.balance);
}

void transfer() {
    if(!accountCreated) {
        printf("Account does not exist. Please create an account first.\n");
        return;
    }

    int targetAccount;
    float amount;

    printf("Enter target account number: ");
    scanf("%d", &targetAccount);

    printf("Enter amount to transfer: ");
    scanf("%f", &amount);

    if(amount <= 0 || amount > account.balance) {
        printf("Invalid amount or insufficient balance.\n");
        return;
    }

    // Simulate transfer (for simplicity, assume same account for now)
    account.balance -= amount;
    printf("Transfer successful. Updated balance: %.2f\n", account.balance);
}

void viewAccountDetails() {
    if(!accountCreated) {
        printf("Account does not exist. Please create an account first.\n");
        return;
    }

    printf("\nAccount Details:\n");
    printf("Account Number: %d\n", account.accountNumber);
    printf("Customer Name: %s\n", account.customerName);
    printf("Balance: %.2f\n", account.balance);
}
