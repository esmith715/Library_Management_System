#include <iostream>
#include <vector>
#include <string>

using namespace std;

// -------------------- Book Class --------------------
class Book {
private:
    int id;
    string title;
    string author;
    bool isAvailable;
public:
    Book(int id, const string& title, const string& author)
        : id(id), title(title), author(author), isAvailable(true) {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool available() const { return isAvailable; }
    void setAvailable(bool available) { isAvailable = available; }
};

// -------------------- User Class --------------------
class User {
private:
    int id;
    string name;
public:
    User(int id, const string& name) : id(id), name(name) {}

    int getId() const { return id; }
    string getName() const { return name; }
};

// -------------------- BorrowTransaction Class --------------------
class BorrowTransaction {
private:
    int userId;
    int bookId;
    string date;
public:
    BorrowTransaction(int userId, int bookId, const string& date)
        : userId(userId), bookId(bookId), date(date) {}

    int getUserId() const { return userId; }
    int getBookId() const { return bookId; }
    string getDate() const { return date; }
};

// -------------------- Library Class --------------------
class Library {
private:
    vector<Book> books;
    vector<User> users;
    vector<BorrowTransaction> transactions;
public:
    void addBook(const Book& book) { books.push_back(book); }
    void addUser(const User& user) { users.push_back(user); }
    void addTransaction(const BorrowTransaction& transaction) { transactions.push_back(transaction); }

    // Additional methods can be added here
};

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
