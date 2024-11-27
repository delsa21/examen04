#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>

class Graph {
private:
    std::unordered_map<std::string, std::vector<std::string>> adjList;

public:
    // Agregar una conexión entre dos usuarios
    void addEdge(const std::string& user1, const std::string& user2);

    // Realizar BFS y devolver un conjunto de amigos
    std::unordered_set<std::string> bfs(const std::string& startUser);
};

#endif // GRAPH_H
