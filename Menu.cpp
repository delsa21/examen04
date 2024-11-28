#include "RecommendationSystem.h"
#include <iostream>
#include <string>

void displayMenu() {
    std::cout << "1. Agregar Usuario\n"
              << "2. Agregar Amigo\n"
              << "3. Agregar Interes\n"
              << "4. Agregar Contenido\n"
              << "5. Recomendacion\n"
              << "6. Exit\n";
}

void menu() {
    RecommendationSystem system;
    int choice;
    std::string user1, user2, category, content;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Ingresa el Usuario: ";
            std::cin >> user1;
            system.addUser(user1);
            break;

        case 2:
            std::cout << "Ingresa dos usuarios para conectar: ";
            std::cin >> user1 >> user2;
            system.addFriend(user1, user2);
            break;

        case 3:
            std::cout << "Ingresa Usuario y la Categoria: ";
            std::cin >> user1 >> category;
            system.addInterest(user1, category);
            break;

        case 4:
            std::cout << "Ingresa la categoria y su Contenido: ";
            std::cin >> category >> content;
            system.addContent(category, content);
            break;

        case 5:
            std::cout << "Ingresa Usuario para la recomendacion: ";
            std::cin >> user1;
            for (const auto& rec : system.recommendContent(user1)) {
                std::cout << rec << std::endl;
            }
            break;

        case 6:
            std::cout << "SALIENDO...\n";
            break;

        default:
            std::cout << "Invalido...\n";
            break;
        }
    } while (choice != 6);
}
