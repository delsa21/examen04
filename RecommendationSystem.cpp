#include "RecommendationSystem.h"

// Delegar a UserManager
void RecommendationSystem::addUser(const std::string& username) {
    userManager.addUser(username);
}

void RecommendationSystem::addInterest(const std::string& username, const std::string& interest) {
    userManager.addInterest(username, interest);
}

// Delegar a ContentManager
void RecommendationSystem::addContent(const std::string& category, const std::string& content) {
    contentManager.addContent(category, content);
}

// Delegar a Graph
void RecommendationSystem::addFriend(const std::string& user1, const std::string& user2) {
    graph.addEdge(user1, user2);
}

// Lógica de recomendaciones (combinando intereses y conexiones)
std::vector<std::string> RecommendationSystem::recommendContent(const std::string& username) {
    // Obtener los amigos del usuario
    auto friends = graph.bfs(username);

    // Acumular los intereses de los amigos
    std::unordered_set<std::string> recommendedInterests;
    for (const auto& friendName : friends) {
        try {
            auto interests = userManager.getInterests(friendName);
            recommendedInterests.insert(interests.begin(), interests.end());
        } catch (...) {
            // Ignorar usuarios sin intereses
        }
    }

    // Convertir a vector y devolver
    return std::vector<std::string>(recommendedInterests.begin(), recommendedInterests.end());
}
