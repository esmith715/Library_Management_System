#pragma once
#include <string>
using namespace std;

class BorrowTransaction {
private:
    int userId;
    int bookId;
    string date;
public:
    BorrowTransaction(int userId, int bookId, const string& date);
    int getUserId() const;
    int getBookId() const;
    string getDate() const;
};