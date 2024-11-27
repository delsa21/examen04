#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class UserManager {
private:
    // Mapa para asociar usuarios con sus intereses
    std::unordered_map<std::string, std::unordered_set<std::string>> userInterests;

public:
    // Método para agregar un nuevo usuario
    void addUser(const std::string& username);

    // Método para agregar un interés a un usuario
    void addInterest(const std::string& username, const std::string& interest);

    // Método para obtener los intereses de un usuario
    std::vector<std::string> getInterests(const std::string& username) const;
};

#endif // USERMANAGER_H

