# Bank Account Management System

## Overview
This project implements a simple bank account management system in C++. The system supports two types of accounts: **Savings Account** and **Current Account**. Users can perform various operations such as depositing money, withdrawing money, displaying the account balance, computing interest (for savings accounts), and checking for minimum balance (for current accounts).

## Features
- **Savings Account:**
  - Provides compound interest.
  - Allows deposit and withdrawal.
  - Displays balance.
  
- **Current Account:**
  - Provides cheque book facility.
  - Imposes a penalty if the balance falls below a minimum level.
  - Allows deposit and withdrawal.
  - Displays balance.

## Classes and Methods

### Class: `Account`
**Base class for both Savings and Current accounts.**

- **Attributes:**
  - `customerName`: Name of the account holder.
  - `accountNo`: Account number.
  - `accountType`: Type of the account (Savings or Current).
  - `accountBalance`: Balance in the account.

- **Methods:**
  - `Account(string cName, long int accNo, string accType, float accBal)`: Constructor to initialize account details.
  - `depositAmt(float dpamt)`: Deposits the given amount into the account.
  - `displayBalance()`: Displays the current account balance.
  - `withdrawal(float withdrawalAmt)`: Withdraws the specified amount from the account, if sufficient balance is available.

### Class: `SavingAccount`
**Derived class from `Account` for Savings Account.**

- **Additional Attributes:**
  - `rate`: Interest rate.
  - `num_times_compounded`: Number of times interest is compounded.

- **Additional Methods:**
  - `SavingAccount(string cName, long int accNo, float accBal, double r, int ntc)`: Constructor for Savings Account.
  - `computeInterest()`: Computes and adds compound interest to the balance.

### Class: `CurrentAccount`
**Derived class from `Account` for Current Account.**

- **Additional Attributes:**
  - `minimumBalance`: Minimum balance to maintain.
  - `serviceCharge`: Penalty charge if the balance falls below the minimum balance.

- **Additional Methods:**
  - `CurrentAccount(string cName, long int accNo, float accBal, float minBal, float serCharge)`: Constructor for Current Account.
  - `checkMinimumBal()`: Checks if the balance is below the minimum balance and imposes a penalty if necessary.

## Menu-Based User Interface
The program provides a menu-based user interface to perform various operations on the accounts:
1. Deposit Amount
2. Withdraw Amount
3. Display Balance
4. Compute Interest (Savings Account only)
5. Check Minimum Balance (Current Account only)
6. Exit

## Usage
1. Clone the repository.
2. Compile the `main.cpp` file using a C++ compiler.
3. Run the executable.
4. Follow the on-screen menu to interact with the system.

## Example
```
Enter account type (Savings/Current): Savings
Menu:
1. Deposit Amount
2. Withdraw Amount
3. Display Balance
4. Compute Interest (Savings Account)
5. Check Minimum Balance (Current Account)
6. Exit
Enter your choice: 1
Enter deposit amount: 1000
Balance after deposit: 1500
```

## Requirements
- C++ compiler

## License
This project is licensed under the MIT License.

## Author
[Shivam Rathod](https://github.com/shivamr021)
