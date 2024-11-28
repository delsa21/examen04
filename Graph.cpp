#include "Graph.h"
#include <queue>

void Graph::addEdge(const std::string& user1, const std::string& user2) {
    adjList[user1].insert(user2);
    adjList[user2].insert(user1);
}

std::set<std::string> Graph::bfs(const std::string& startUser) const {
    std::set<std::string> visited;
    std::queue<std::string> queue;

    queue.push(startUser);
    visited.insert(startUser);

    while (!queue.empty()) {
        std::string current = queue.front();
        queue.pop();

        for (const auto& neighbor : adjList.at(current)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                queue.push(neighbor);
            }
        }
    }

    return visited;
}
