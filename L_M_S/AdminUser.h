#pragma once
#include "User.h"

class AdminUser : public User {
public:
    AdminUser(int id, const string& name)
        : User(id, name, UserType::Admin) {}
    bool isAdmin() const override { return true; }
    // Add admin-specific methods here
};