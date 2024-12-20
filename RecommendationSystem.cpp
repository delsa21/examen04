#include "RecommendationSystem.h"

void RecommendationSystem::addUser(const std::string& username) {
    userManager.addUser(username);
    graph.addEdge(username, username); 

void RecommendationSystem::addContent(const std::string& category, const std::string& content) {
    contentManager.addContent(category, content);
}

void RecommendationSystem::addFriend(const std::string& user1, const std::string& user2) {
    graph.addEdge(user1, user2);
}

void RecommendationSystem::addInterest(const std::string& username, const std::string& category) {
    userManager.addInterest(username, category);
}

std::vector<std::string> RecommendationSystem::recommendContent(const std::string& username) {
    std::set<std::string> friends = graph.bfs(username);
    std::set<std::string> allInterests;

    for (const auto& friendUser : friends) {
        std::set<std::string> interests = userManager.getInterests(friendUser);
        allInterests.insert(interests.begin(), interests.end());
    }

    std::vector<std::string> recommendations;
    for (const auto& interest : allInterests) {
        std::set<std::string> content = contentManager.getContentByCategory(interest);
        recommendations.insert(recommendations.end(), content.begin(), content.end());
    }

    return recommendations;
}



std::set<std::string> RecommendationSystem::getUserInterests(const std::string& username) const {
    return userManager.getInterests(username);
}

std::set<std::string> RecommendationSystem::getUserFriends(const std::string& username) const {
    return graph.bfs(username); // BFS devuelve los amigos de un usuario
}
