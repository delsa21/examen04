#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <unordered_map>
#include <set>
#include <string>

class UserManager {
public:
    void addUser(const std::string& username);
    void addInterest(const std::string& username, const std::string& category);
    std::set<std::string> getInterests(const std::string& username) const;

private:
    std::unordered_map<std::string, std::set<std::string>> userInterests;
};

#endif
