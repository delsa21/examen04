#ifndef RECOMMENDATIONSYSTEM_H
#define RECOMMENDATIONSYSTEM_H

#include "Graph.h"
#include "UserManager.h"
#include "ContentManager.h"

class RecommendationSystem {
private:
    Graph graph;
    UserManager userManager;
    ContentManager contentManager;

public:
    void addUser(const std::string& username);
    void addInterest(const std::string& username, const std::string& interest);
    void addContent(const std::string& category, const std::string& content);
    void addFriend(const std::string& user1, const std::string& user2);
    std::vector<std::string> recommendContent(const std::string& username);
};

#endif
