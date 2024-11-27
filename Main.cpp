#include "Menu.cpp"

int main() {
    Menu menu;
    menu.showMenu();
    return 0;
}
#include <iostream>
#include "Graph.h"
//Graph
int main() {
    Graph graph;

    // Agregar relaciones de amistad
    graph.addEdge("Alice", "Bob");
    graph.addEdge("Alice", "Charlie");
    graph.addEdge("Bob", "David");
    graph.addEdge("Charlie", "Eve");
    graph.addEdge("Eve", "Frank");

    // Realizar una búsqueda en amplitud desde Alice
    std::unordered_set<std::string> friends = graph.bfs("Alice");

    // Imprimir los amigos directos e indirectos de Alice
    std::cout << "Amigos de Alice:" << std::endl;
    for (const auto& friendName : friends) {
        std::cout << friendName << std::endl;
    }

    return 0;
}
