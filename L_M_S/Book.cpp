#include "Book.h"

Book::Book(int id, const string& title, const string& author)
    : id(id), title(title), author(author), isAvailable(true) {}

int Book::getId() const { return id; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
bool Book::available() const { return isAvailable; }
void Book::setAvailable(bool available) { isAvailable = available; }