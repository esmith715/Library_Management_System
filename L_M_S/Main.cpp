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

////////////////////////////////////////////////////////////////

void listBooks(const Library& library) {
    const auto& books = library.getBooks();
    if (books.empty()) {
        cout << "No books in the library.\n";
        return;
    }
    cout << "\n--- Book List ---\n";
    for (const auto& book : books) {
        cout << "ID: " << book.getId()
             << ", Title: " << book.getTitle()
             << ", Author: " << book.getAuthor()
             << ", Available: " << (book.available() ? "Yes" : "No") << endl;
    }
}


////////////////////////////////////////////////////////////////////////////

void listUsers(const Library& library) {
    const auto& users = library.getUsers();
    if (users.empty()) {
        cout << "No users in the library.\n";
        return;
    }
    cout << "\n--- User List ---\n";
    for (const auto& user : users) {
        cout << "ID: " << user.getId()
             << ", Name: " << user.getName()
             << ", Type: " << (user.isAdmin() ? "Admin" : "Regular") << endl;
    }
}


//////////////////////////////////////////////////////////////////////////////

void listTransactions(const Library& library) {
    const auto& transactions = library.getTransactions();
    if (transactions.empty()) {
        cout << "No transactions in the library.\n";
        return;
    }
    cout << "\n--- Transaction List ---\n";
    for (const auto& transaction : transactions) {
        cout << "User ID: " << transaction.getUserId()
             << ", Book ID: " << transaction.getBookId()
             << ", Date: " << transaction.getDate() << endl;
    }
}

//////////////////////////////////////////////////////////////////////////////


void borrowBook(Library& library) {
    int userId, bookId;
    cout << "Enter your user ID: ";
    if (!(cin >> userId)) {
        cout << "Invalid input for user ID. Operation cancelled.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cout << "Enter book ID to borrow: ";
    if (!(cin >> bookId)) {
        cout << "Invalid input for book ID. Operation cancelled.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Find user
    const auto& users = library.getUsers();
    auto userIt = std::find_if(users.begin(), users.end(), [userId](const User& u) { return u.getId() == userId; });
    if (userIt == users.end()) {
        cout << "User not found.\n";
        return;
    }

    // Find book
    auto& books = const_cast<vector<Book>&>(library.getBooks());
    auto bookIt = std::find_if(books.begin(), books.end(), [bookId](const Book& b) { return b.getId() == bookId; });
    if (bookIt == books.end()) {
        cout << "Book not found.\n";
        return;
    }
    if (!bookIt->available()) {
        cout << "Book is already borrowed.\n";
        return;
    }

    // Mark book as borrowed
    bookIt->setAvailable(false);

    // Get date (simple version)
    string date;
    cout << "Enter borrow date (YYYY-MM-DD): ";
    getline(cin, date);

    // Add transaction
    library.addTransaction(BorrowTransaction(userId, bookId, date));
    cout << "Book borrowed successfully.\n";
}


/////////////////////////////////////////////////////////////////////////

int main() {
    cout << "Library Management System Base Initialized." << endl;

    Library library;

    // Example books and users
    library.addBook(Book(1, "1984", "George Orwell"));
    library.addBook(Book(2, "To Kill a Mockingbird", "Harper Lee"));
    library.addUser(User(1, "Alice"));
    library.addUser(AdminUser(2, "Bob"));

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
                listBooks(library);
                break;
            case 2:
                listUsers(library);
                break;
            case 3:
                listTransactions(library);
                break;
            case 4:
                borrowBook(library);
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
