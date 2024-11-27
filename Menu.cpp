#include "Menu.h"
#include <iostream>
#include "RecommendationSystem.h"

void Menu::showMenu() {
    int choice = -1;

    RecommendationSystem recommendationSystem;

    while (choice != 0) {
        std::cout << "\nMenú Principal:\n";
        std::cout << "1. Agregar usuario\n";
        std::cout << "2. Agregar interés\n";
        std::cout << "3. Agregar contenido\n";
        std::cout << "4. Crear conexión de amistad\n";
        std::cout << "5. Ver recomendaciones\n";
        std::cout << "0. Salir\n";
        std::cout << "Elige una opción: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string username;
            std::cout << "Introduce el nombre del usuario: ";
            std::cin >> username;
            recommendationSystem.addUser(username);
            std::cout << "Usuario agregado.\n";
            break;
        }
        case 2: {
            std::string username, interest;
            std::cout << "Introduce el nombre del usuario: ";
            std::cin >> username;
            std::cout << "Introduce el interés: ";
            std::cin >> interest;
            recommendationSystem.addInterest(username, interest);
            std::cout << "Interés agregado.\n";
            break;
        }
        case 3: {
            std::string category, content;
            std::cout << "Introduce la categoría: ";
            std::cin >> category;
            std::cout << "Introduce el contenido: ";
            std::cin.ignore();
            std::getline(std::cin, content);
            recommendationSystem.addContent(category, content);
            std::cout << "Contenido agregado.\n";
            break;
        }
        case 4: {
            std::string user1, user2;
            std::cout << "Introduce el primer usuario: ";
            std::cin >> user1;
            std::cout << "Introduce el segundo usuario: ";
            std::cin >> user2;
            recommendationSystem.addFriend(user1, user2);
            std::cout << "Amistad creada.\n";
            break;
        }
        case 5: {
            std::string username;
            std::cout << "Introduce el nombre del usuario: ";
            std::cin >> username;
            auto recommendations = recommendationSystem.recommendContent(username);
            std::cout << "Recomendaciones:\n";
            for (const auto& rec : recommendations) {
                std::cout << "- " << rec << "\n";
            }
            break;
        }
        case 0:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opción inválida.\n";
        }
    }
}
