#include "User.h"

User::User(int id, const string& name, UserType type)
    : id(id), name(name), type(type) {}

int User::getId() const { return id; }
string User::getName() const { return name; }
UserType User::getType() const { return type; }