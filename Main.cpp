#include <iostream>
#include "ContentManager.h"

int main() {
    ContentManager manager;

    // Agregar contenidos
    manager.addContent("Noticias", "Últimas noticias sobre tecnología");
    manager.addContent("Noticias", "El cambio climático es una amenaza global");
    manager.addContent("Entretenimiento", "Películas más esperadas de 2024");

    // Obtener contenidos por categoría
    std::vector<std::string> noticias = manager.getContentByCategory("Noticias");
    std::cout << "Contenido en la categoría 'Noticias':" << std::endl;
    for (const auto& content : noticias) {
        std::cout << "- " << content << std::endl;
    }

    std::vector<std::string> entretenimiento = manager.getContentByCategory("Entretenimiento");
    std::cout << "\nContenido en la categoría 'Entretenimiento':" << std::endl;
    for (const auto& content : entretenimiento) {
        std::cout << "- " << content << std::endl;
    }

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------
#include "UserManager.h"
#include <iostream>

int main() {
    UserManager um;

    // Agregar usuarios
    um.addUser("alice");
    um.addUser("bob");

    // Agregar intereses
    um.addInterest("alice", "movies");
    um.addInterest("alice", "music");
    um.addInterest("bob", "sports");

    // Obtener intereses
    try {
        auto aliceInterests = um.getInterests("alice");
        std::cout << "Intereses de Alice: ";
        for (const auto& interest : aliceInterests) {
            std::cout << interest << " ";
        }
        std::cout << std::endl;

        auto bobInterests = um.getInterests("bob");
        std::cout << "Intereses de Bob: ";
        for (const auto& interest : bobInterests) {
            std::cout << interest << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}


//-----------------------------------------------------------------------------------------------------------------------------
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
//_______________________________________________________________________________________________________________________________________________
#include <iostream>
#include "RecommendationSystem.h"

int main() {
    RecommendationSystem rs;

    // Agregar usuarios
    rs.addUser("Alice");
    rs.addUser("Bob");
    rs.addUser("Charlie");
    rs.addUser("David");

    // Agregar intereses
    rs.addUser("Alice");
    rs.addContent("Music", "Song A");
    rs.addContent("Music", "Song B");
    rs.addContent("Movies", "Movie X");

    rs.addUser("Bob");
    rs.addInterest("Bob", "Music");
    rs.addInterest("Bob", "Movies");

    rs.addUser("Charlie");
    rs.addInterest("Charlie", "Books");

    rs.addUser("David");
    rs.addInterest("David", "Music");

    // Crear conexiones de amistad
    rs.addFriend("Alice", "Bob");
    rs.addFriend("Bob", "Charlie");
    rs.addFriend("Alice", "David");

    // Obtener recomendaciones para Alice
    std::vector<std::string> recommendations = rs.recommendContent("Alice");

    std::cout << "Recomendaciones para Alice:" << std::endl;
    for (const auto& content : recommendations) {
        std::cout << "- " << content << std::endl;
    }

    return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "Menu.cpp"

int main() {
    Menu menu;
    menu.showMenu();
    return 0;
}
