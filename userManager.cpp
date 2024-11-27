#include "UserManager.h"
#include <stdexcept>
#include <algorithm>

// Método para agregar un nuevo usuario
void UserManager::addUser(const std::string& username) {
    if (userInterests.find(username) == userInterests.end()) {
        userInterests[username] = std::unordered_set<std::string>();
    } else {
        throw std::runtime_error("Usuario ya existe.");
    }
}

// Método para agregar un interés a un usuario
void UserManager::addInterest(const std::string& username, const std::string& interest) {
    auto it = userInterests.find(username);
    if (it != userInterests.end()) {
        it->second.insert(interest);
    } else {
        throw std::runtime_error("Usuario no encontrado.");
    }
}

// Método para obtener los intereses de un usuario
std::vector<std::string> UserManager::getInterests(const std::string& username) const {
    auto it = userInterests.find(username);
    if (it != userInterests.end()) {
        return std::vector<std::string>(it->second.begin(), it->second.end());
    } else {
        throw std::runtime_error("Usuario no encontrado.");
    }
}
