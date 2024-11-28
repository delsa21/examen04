#ifndef RECOMMENDATION_SYSTEM_H
#define RECOMMENDATION_SYSTEM_H

#include "UserManager.h"
#include "ContentManager.h"
#include "Graph.h"

#include <set>
#include <string>
#include <vector>

class RecommendationSystem {
public:
    void addUser(const std::string& username);
    void addContent(const std::string& category, const std::string& content);
    void addFriend(const std::string& user1, const std::string& user2);
    void addInterest(const std::string& username, const std::string& category);
    
    std::vector<std::string> recommendContent(const std::string& username);

    // Nuevos métodos
    std::set<std::string> getUserInterests(const std::string& username) const;
    std::set<std::string> getUserFriends(const std::string& username) const;

private:
    UserManager userManager;
    ContentManager contentManager;
    Graph graph;
};

#endif
