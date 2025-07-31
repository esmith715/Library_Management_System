#include "Library.h"

void Library::addBook(const Book& book) { books.push_back(book); }
void Library::addUser(const User& user) { users.push_back(user); }
void Library::addTransaction(const BorrowTransaction& transaction) { transactions.push_back(transaction); }