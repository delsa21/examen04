#include <iostream>
#include "ContentManager.h"
#include "UserManager.h"
#include "Graph.h"
#include "RecommendationSystem.h"
#include "Menu.h"

int main() {
    // ------------------ ContentManager ------------------
    ContentManager contentManager;

    // Agregar contenidos
    contentManager.addContent("Noticias", "Últimas noticias sobre tecnología");
    contentManager.addContent("Noticias", "El cambio climático es una amenaza global");
    contentManager.addContent("Entretenimiento", "Películas más esperadas de 2024");

    // Obtener contenidos por categoría
    std::vector<std::string> noticias = contentManager.getContentByCategory("Noticias");
    std::cout << "Contenido en la categoría 'Noticias':" << std::endl;
    for (const auto& content : noticias) {
        std::cout << "- " << content << std::endl;
    }

    std::vector<std::string> entretenimiento = contentManager.getContentByCategory("Entretenimiento");
    std::cout << "\nContenido en la categoría 'Entretenimiento':" << std::endl;
    for (const auto& content : entretenimiento) {
        std::cout << "- " << content << std::endl;
    }

    // ------------------ UserManager ------------------
    UserManager userManager;

    // Agregar usuarios
    userManager.addUser("alice");
    userManager.addUser("bob");

    // Agregar intereses
    userManager.addInterest("alice", "movies");
    userManager.addInterest("alice", "music");
    userManager.addInterest("bob", "sports");

    // Obtener intereses
    try {
        auto aliceInterests = userManager.getInterests("alice");
        std::cout << "\nIntereses de Alice: ";
        for (const auto& interest : aliceInterests) {
            std::cout << interest << " ";
        }
        std::cout << std::endl;

        auto bobInterests = userManager.getInterests("bob");
        std::cout << "Intereses de Bob: ";
        for (const auto& interest : bobInterests) {
            std::cout << interest << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // ------------------ Graph ------------------
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
    std::cout << "\nAmigos de Alice:" << std::endl;
    for (const auto& friendName : friends) {
        std::cout << friendName << std::endl;
    }

    // ------------------ RecommendationSystem ------------------
    RecommendationSystem recommendationSystem;

    // Agregar usuarios y contenidos
    recommendationSystem.addUser("Alice");
    recommendationSystem.addContent("Music", "Song A");
    recommendationSystem.addContent("Music", "Song B");
    recommendationSystem.addContent("Movies", "Movie X");

    recommendationSystem.addUser("Bob");
    recommendationSystem.addInterest("Bob", "Music");
    recommendationSystem.addInterest("Bob", "Movies");

    recommendationSystem.addUser("Charlie");
    recommendationSystem.addInterest("Charlie", "Books");

    recommendationSystem.addUser("David");
    recommendationSystem.addInterest("David", "Music");

    // Crear conexiones de amistad
    recommendationSystem.addFriend("Alice", "Bob");
    recommendationSystem.addFriend("Bob", "Charlie");
    recommendationSystem.addFriend("Alice", "David");

    // Obtener recomendaciones para Alice
    std::vector<std::string> recommendations = recommendationSystem.recommendContent("Alice");

    std::cout << "\nRecomendaciones para Alice:" << std::endl;
    for (const auto& content : recommendations) {
        std::cout << "- " << content << std::endl;
    }

    // ------------------ Menu ------------------
    Menu menu;
    std::cout << "\nMostrando el menú principal:" << std::endl;
    menu.showMenu();

    return 0;
}
