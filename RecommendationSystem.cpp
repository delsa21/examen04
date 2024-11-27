#include "RecommendationSystem.h"

// Graph Methods
void Graph::addEdge(const std::string& user1, const std::string& user2) {
    adjList[user1].push_back(user2);
    adjList[user2].push_back(user1);
}

std::unordered_set<std::string> Graph::bfs(const std::string& startUser) {
    std::unordered_set<std::string> visited;
    std::queue<std::string> toVisit;

    toVisit.push(startUser);
    visited.insert(startUser);

    while (!toVisit.empty()) {
        std::string currentUser = toVisit.front();
        toVisit.pop();

        for (const auto& neighbor : adjList[currentUser]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                toVisit.push(neighbor);
            }
        }
    }

    return visited;
}

// ContentManager Methods
void ContentManager::addContent(const std::string& interest, const std::string& content) {
    contentByInterest[interest].push_back(content);
}

std::vector<std::string> ContentManager::getContentByInterest(const std::string& interest) {
    return contentByInterest[interest];
}

// UserManager Methods
void UserManager::addUser(const std::string& user) {
    if (userInterests.find(user) == userInterests.end()) {
        userInterests[user] = {};
    }
}

void UserManager::addInterest(const std::string& user, const std::string& interest) {
    userInterests[user].push_back(interest);
}

std::vector<std::string> UserManager::getInterests(const std::string& user) {
    return userInterests[user];
}

// RecommendationSystem Methods
void RecommendationSystem::addUser(const std::string& user) {
    userManager.addUser(user);
}

void RecommendationSystem::addContent(const std::string& interest, const std::string& content) {
    contentManager.addContent(interest, content);
}

void RecommendationSystem::addFriend(const std::string& user1, const std::string& user2) {
    graph.addEdge(user1, user2);
}

std::vector<std::string> RecommendationSystem::recommendContent(const std::string& user) {
    std::unordered_set<std::string> friends = graph.bfs(user);
    std::unordered_map<std::string, int> interestCount;
    std::vector<std::string> recommendations;

    // Obtener intereses de los amigos
    for (const auto& friendUser : friends) {
        if (friendUser != user) { // Excluir al usuario actual
            std::vector<std::string> interests = userManager.getInterests(friendUser);
            for (const auto& interest : interests) {
                interestCount[interest]++;
            }
        }
    }

    // Recomendar contenido basado en intereses populares
    for (const auto& [interest, count] : interestCount) {
        std::vector<std::string> content = contentManager.getContentByInterest(interest);
        recommendations.insert(recommendations.end(), content.begin(), content.end());
    }

    return recommendations;
}


