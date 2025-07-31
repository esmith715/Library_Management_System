#include <iostream>
#include "Book.h"
#include "User.h"
#include "BorrowTransaction.h"
#include "Library.h"
using namespace std;

int main() {
    cout << "Library Management System Base Initialized." << endl;

    // Sample objects for testing
    Book book1(1, "1984", "George Orwell");
    User user1(1, "John Doe");
    BorrowTransaction transaction1(1, 1, "2023-10-01");

    // Library instance
    Library library;
    library.addBook(book1);
    library.addUser(user1);
    library.addTransaction(transaction1);

    return 0;
}
