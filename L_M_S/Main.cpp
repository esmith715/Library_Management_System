#include <iostream>
#include <limits>
#include "Book.h"
#include "User.h"
#include "AdminUser.h"
#include "BorrowTransaction.h"
#include "Library.h"
using namespace std;

void showMenu(bool isAdmin) {
    cout << "\n--- Library Management System Menu ---\n";
    cout << "1. List Books\n";
    cout << "2. List Users\n";
    cout << "3. List Transactions\n";
    cout << "4. Borrow Book\n";
    if (isAdmin) {
        cout << "5. Add Book\n";
        cout << "6. Add User\n";
    }
    cout << "0. Exit\n";
    cout << "Select an option: ";
}

int main() {
    cout << "Library Management System Base Initialized." << endl;

    // --- User role selection ---
    User* currentUser = nullptr;
    bool isAdmin = false;
    while (true) {
        cout << "\nLogin as:\n";
        cout << "1. Admin\n";
        cout << "2. Regular User\n";
        cout << "Select option: ";
        int loginChoice;
        cin >> loginChoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (loginChoice == 1) {
            string code;
            cout << "Enter admin code: ";
            getline(cin, code);
            if (code == "admin123") { // Example admin code
                isAdmin = true;
                cout << "Logged in as Admin.\n";
                break;
            } else {
                cout << "Incorrect admin code.\n";
            }
        } else if (loginChoice == 2) {
            isAdmin = false;
            cout << "Logged in as Regular User.\n";
            break;
        } else {
            cout << "Invalid option. Try again.\n";
        }
    }

    int choice;
    do {
        showMenu(isAdmin);
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
            case 1:
                cout << "[List Books] (Not implemented)\n";
                break;
            case 2:
                cout << "[List Users] (Not implemented)\n";
                break;
            case 3:
                cout << "[List Transactions] (Not implemented)\n";
                break;
            case 4:
                cout << "[Borrow Book] (Not implemented)\n";
                break;
            case 5:
                if (isAdmin)
                    cout << "[Add Book] (Not implemented)\n";
                else
                    cout << "Invalid option.\n";
                break;
            case 6:
                if (isAdmin)
                    cout << "[Add User] (Not implemented)\n";
                else
                    cout << "Invalid option.\n";
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
