#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <set>
#include <string>
#include <queue>

class Graph {
public:
    void addEdge(const std::string& user1, const std::string& user2);
    std::set<std::string> bfs(const std::string& startUser) const;

private:
    std::unordered_map<std::string, std::set<std::string>> adjList;
};

#endif

