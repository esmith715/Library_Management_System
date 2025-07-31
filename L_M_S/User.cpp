#include "User.h"

User::User(int id, const string& name) : id(id), name(name) {}

int User::getId() const { return id; }
string User::getName() const { return name; }