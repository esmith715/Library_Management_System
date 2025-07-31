#include "BorrowTransaction.h"

BorrowTransaction::BorrowTransaction(int userId, int bookId, const string& date)
    : userId(userId), bookId(bookId), date(date) {}

int BorrowTransaction::getUserId() const { return userId; }
int BorrowTransaction::getBookId() const { return bookId; }
string BorrowTransaction::getDate() const { return date; }