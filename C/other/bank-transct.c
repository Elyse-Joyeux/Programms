#include <stdio.h>
#include <string.h>
enum AccountType { SAVINGS, CHECKING };
struct BankAccount {
    int accountNumber;
    enum AccountType type;
    char ownerName[100];
    double balance;
};
void createAccount(struct BankAccount *account, int number, enum AccountType type, const char *name) {
    account->accountNumber = number;
    account->type = type;
    strncpy(account->ownerName, name, 99);
    account->ownerName[99] = '\0'; // Ensure null-termination
    account->balance = 0.0;
}
void deposit(struct BankAccount *account, double amount) {
    if (amount > 0) {
        account->balance += amount;
        printf("Deposited %.2f to account %d.\n", amount, account->accountNumber);
    } else {
        printf("Invalid deposit amount.\n");
    }
}
void withdraw(struct BankAccount *account, double amount) {
    if (amount > 0 && account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawn %.2f from account %d.\n", amount, account->accountNumber);
    } else {
        printf("Invalid withdrawal amount or insufficient balance.\n");
    }
}
void checkBalance(const struct BankAccount *account) {
    printf("Account %d balance: %.2f\n", account->accountNumber, account->balance);
}
int main() {
    struct BankAccount myAccount;
    createAccount(&myAccount, 123456, SAVINGS, "John Doe");
    deposit(&myAccount, 100.0);
    withdraw(&myAccount, 50.0);
    checkBalance(&myAccount);
    return 0;
}