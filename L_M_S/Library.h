#pragma once
#include <vector>
#include "Book.h"
#include "User.h"
#include "BorrowTransaction.h"
using namespace std;

class Library {
private:
    vector<Book> books;
    vector<User> users;
    vector<BorrowTransaction> transactions;
public:
    void addBook(const Book& book);
    void addUser(const User& user);
    void addTransaction(const BorrowTransaction& transaction);
    const vector<Book>& getBooks() const;
    // Additional methods can be added here
};