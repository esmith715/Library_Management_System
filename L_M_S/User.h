#pragma once
#include <string>
using namespace std;

enum class UserType { Regular, Admin };

class User {
protected:
    int id;
    string name;
    UserType type;
public:
    User(int id, const string& name, UserType type = UserType::Regular);
    virtual ~User() = default;
    int getId() const;
    string getName() const;
    UserType getType() const;
    virtual bool isAdmin() const { return type == UserType::Admin; }
};