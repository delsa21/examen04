#include "UserManager.h"

void UserManager::addUsuario(const std::string& username) {
    if (userInterests.find(username) == userInterests.end()) {
        userInterests[username] = {};
    }
}

void UserManager::addInterest(const std::string& username, const std::string& category) {
    if (userInterests.find(username) != userInterests.end()) {
        userInterests[username].insert(category);
    }
}

std::set<std::string> UserManager::getInterests(const std::string& username) const {
    if (userInterests.find(username) != userInterests.end()) {
        return userInterests.at(username);
    }
    return {};
}
