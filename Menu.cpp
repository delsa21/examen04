#include "RecommendationSystem.h"
#include <iostream>
#include <string>

void displayMenu() {
    std::cout << "1. Crear Usuario\n"
              << "2. Añadir Amistad\n"
              << "3. Añadir Intereses\n"
              << "4. Agregar contenido\n"
              << "5. Conseguir Recomendaciones\n"
              << "6. Salir\n";
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
            std::cout << "Ingresar Usuario: ";
            std::cin >> user1;
            system.addUser(user1);
            break;

        case 2:
            std::cout << "Escribir usuarios que quieran crear amistad: ";
            std::cin >> user1 >> user2;
            system.addFriend(user1, user2);
            break;

        case 3:
            std::cout << "Ingresa usario y categoría del interés: ";
            std::cin >> user1 >> category;
            system.addInterest(user1, category);
            break;

        case 4:
            std::cout << "Ingresa categoría y contenido: ";
            std::cin >> category >> content;
            system.addContent(category, content);
            break;

        case 5:
            std::cout << "Ingresa usuario para conseguir recomendaciones: ";
            std::cin >> user1;
            for (const auto& rec : system.recommendContent(user1)) {
                std::cout << rec << std::endl;
            }
            break;

        case 6:
            std::cout << "Saliendo...\n";
            break;

        default:
            std::cout << "Opción Invalida, intenta de nuevo.\n";
            break;
        }
    } while (choice != 6);
}
