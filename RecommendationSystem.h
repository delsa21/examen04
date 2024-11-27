#ifndef RECOMMENDATIONSYSTEM_H
#define RECOMMENDATIONSYSTEM_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>

class Graph {
private:
    std::unordered_map<std::string, std::vector<std::string>> adjList;

public:
    void addEdge(const std::string& user1, const std::string& user2);
    std::unordered_set<std::string> bfs(const std::string& startUser);
};

class ContentManager {
private:
    std::unordered_map<std::string, std::vector<std::string>> contentByInterest;

public:
    void addContent(const std::string& interest, const std::string& content);
    std::vector<std::string> getContentByInterest(const std::string& interest);
};

class UserManager {
private:
    std::unordered_map<std::string, std::vector<std::string>> userInterests;

public:
    void addUser(const std::string& user);
    void addInterest(const std::string& user, const std::string& interest);
    std::vector<std::string> getInterests(const std::string& user);
};

class RecommendationSystem {
private:
    Graph graph;
    ContentManager contentManager;
    UserManager userManager;

public:
    void addUser(const std::string& user);
    void addContent(const std::string& interest, const std::string& content);
    void addFriend(const std::string& user1, const std::string& user2);
    std::vector<std::string> recommendContent(const std::string& user);
};

#endif // RECOMMENDATIONSYSTEM_H

