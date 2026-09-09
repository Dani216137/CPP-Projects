# Bank Manager

A console-based banking application written in C++.

The project allows users to create and manage bank accounts and perform basic banking operations.

## Features

- Create new accounts
- Search for accounts
- Delete accounts
- Block and unblock accounts
- Deposit money
- Withdraw money
- Transfer money between accounts
- Save and load account data from files
- Transaction and activity logging
- Input validation

## Concepts Practiced

- Structs
- `std::vector`
- Functions
- References
- File input/output
- String handling
- Input validation
- Exception handling
- Modular code organization
- C++17 features

## Data Storage

Account information is stored in files, allowing the data to be loaded again when the program is started.

Money is internally stored as an integer value representing cents.

For example:

```text
100  = 1.00
1050 = 10.50
