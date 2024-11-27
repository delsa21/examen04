#include <iostream>
#include "Graph.h"

// Agregar una conexión entre dos usuarios
void Graph::addEdge(const std::string& user1, const std::string& user2) {
    adjList[user1].push_back(user2);
    adjList[user2].push_back(user1);
}

// Realizar BFS para encontrar amigos directos e indirectos
std::unordered_set<std::string> Graph::bfs(const std::string& startUser) {
    std::unordered_set<std::string> visited; // Para almacenar los nodos visitados
    std::queue<std::string> toVisit;         // Cola para nodos a visitar

    // Agregar el usuario inicial a la cola y marcarlo como visitado
    toVisit.push(startUser);
    visited.insert(startUser);

    // Búsqueda en amplitud
    while (!toVisit.empty()) {
        std::string currentUser = toVisit.front();
        toVisit.pop();

        // Explorar todos los vecinos del usuario actual
        for (const std::string& friendUser : adjList[currentUser]) {
            if (visited.find(friendUser) == visited.end()) {
                visited.insert(friendUser);
                toVisit.push(friendUser);
            }
        }
    }

    return visited; // Devolver todos los amigos encontrados
}

using namespace std;


