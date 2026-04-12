#include <iostream>
#include <vector>
#include <algorithm>

class User {
public:
    int id;
    std::string name;
    bool active;

    User(int id, std::string name, bool active)
        : id(id), name(name), active(active) {}
};

User findByName(const std::vector<User>& users, const std::string& name) {
    for (const auto& u : users) {
        if (u.name == name) {
            return u;
        }
    }
    return User(0, "", false);
}

void printUser(const User& u) {
    if (u.active && !u.name.empty()) {
        std::cout << "User: " << u.name << " (" << u.id << ")\n";
    } else {
        std::cout << "Inactive or not found\n";
    }
}

void processUsers(const std::vector<User>& users) {
    std::for_each(users.begin(), users.end(), [](const User& u) {
        if (u.active) {
            std::cout << "Active: " << u.name << "\n";
        } else {
            std::cout << "Inactive: " << u.name << "\n";
        }
    });
}

int main() {
    std::vector<User> users = {
        User(1, "Sumit", true),
        User(2, "Alex", false),
        User(3, "Dev", true)
    };

    User result = findByName(users, "Sumit");
    printUser(result);

    processUsers(users);

    return 0;
}