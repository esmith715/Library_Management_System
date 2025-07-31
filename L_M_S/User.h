#pragma once
#include <string>
using namespace std;

class User {
private:
    int id;
    string name;
public:
    User(int id, const string& name);
    int getId() const;
    string getName() const;
};