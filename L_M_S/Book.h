#pragma once
#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool isAvailable;
public:
    Book(int id, const string& title, const string& author);
    int getId() const;
    string getTitle() const;
    string getAuthor() const;
    bool available() const;
    void setAvailable(bool available);
};