#include "RecommendationSystem.h"
#include <iostream>
#include <string>

void displayMenu() {
    std::cout << "1. Agregar Usuario\n"
              << "2. Agregar Amigo\n"
              << "3. Agregar Interes\n"
              << "4. Agregar Contenido\n"
              << "5. Recomendacion\n"
              << "6. Ver Usuario\n"
              << "7. Exit\n";
}

#include "RecommendationSystem.h"
#include <iostream>
#include <string>

void displayMainMenu() {
    std::cout << "==================== MENU PRINCIPAL ====================\n";
    std::cout << "1. Agregar Usuario\n"
              << "2. Gestionar Amistades\n"
              << "3. Gestionar Intereses\n"
              << "4. Gestionar Contenido\n"
              << "5. Obtener Recomendaciones\n"
              << "6. Ver Informacion de Usuario\n"
              << "7. Salir\n";
}

void displayFriendshipMenu() {
    std::cout << "==================== GESTIONAR AMISTADES ====================\n";
    std::cout << "1. Agregar Amigo\n"
              << "2. Volver al Menu Principal\n";
}

void displayInterestMenu() {
    std::cout << "==================== GESTIONAR INTERESES ====================\n";
    std::cout << "1. Agregar Interes\n"
              << "2. Volver al Menu Principal\n";
}

void displayContentMenu() {
    std::cout << "==================== GESTIONAR CONTENIDO ====================\n";
    std::cout << "1. Agregar Contenido\n"
              << "2. Volver al Menu Principal\n";
}

void menu() {
    RecommendationSystem system;
    int choice;
    std::string username, user1, user2, category, content;

    do {
        displayMainMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: // Agregar Usuario
            std::cout << "Ingresa el nombre del Usuario: ";
            std::cin >> username;
            system.addUser(username);
            std::cout << "Usuario '" << username << "' agregado con exito.\n";
            break;

        case 2: // Gestionar Amistades
            {
                int friendshipChoice;
                do {
                    displayFriendshipMenu();
                    std::cin >> friendshipChoice;
                    switch (friendshipChoice) {
                    case 1:
                        std::cout << "Ingresa el Usuario: ";
                        std::cin >> user1;
                        std::cout << "Ingresa el Usuario a hacer amigo de " << user1 << ": ";
                        std::cin >> user2;
                        system.addFriend(user1, user2);
                        std::cout << "Amigos '" << user1 << "' y '" << user2 << "' conectados con exito.\n";
                        break;
                    case 2:
                        std::cout << "Volviendo al menu principal...\n";
                        break;
                    default:
                        std::cout << "Opcion invalida...\n";
                        break;
                    }
                } while (friendshipChoice != 2);
            }
            break;

        case 3: // Gestionar Intereses
            {
                int interestChoice;
                do {
                    displayInterestMenu();
                    std::cin >> interestChoice;
                    switch (interestChoice) {
                    case 1:
                        std::cout << "Ingresa el Usuario: ";
                        std::cin >> username;
                        std::cout << "Ingresa la Categoria de Interes para " << username << ": ";
                        std::cin >> category;
                        system.addInterest(username, category);
                        std::cout << "Interes '" << category << "' agregado a '" << username << "' con exito.\n";
                        break;
                    case 2:
                        std::cout << "Volviendo al menu principal...\n";
                        break;
                    default:
                        std::cout << "Opcion invalida...\n";
                        break;
                    }
                } while (interestChoice != 2);
            }
            break;

        case 4: // Gestionar Contenido
            {
                int contentChoice;
                do {
                    displayContentMenu();
                    std::cin >> contentChoice;
                    switch (contentChoice) {
                    case 1:
                        std::cout << "Ingresa la Categoria de Contenido: ";
                        std::cin >> category;
                        std::cout << "Ingresa el Contenido para la categoria '" << category << "': ";
                        std::cin >> content;
                        system.addContent(category, content);
                        std::cout << "Contenido '" << content << "' agregado a la categoria '" << category << "' con exito.\n";
                        break;
                    case 2:
                        std::cout << "Volviendo al menu principal...\n";
                        break;
                    default:
                        std::cout << "Opcion invalida...\n";
                        break;
                    }
                } while (contentChoice != 2);
            }
            break;

        case 5: // Obtener Recomendaciones
            std::cout << "Ingresa el nombre del Usuario para obtener recomendaciones: ";
            std::cin >> username;
            for (const auto& rec : system.recommendContent(username)) {
                std::cout << rec << std::endl;
            }
            break;

        case 6: // Ver Informacion de Usuario
            std::cout << "Ingresa el nombre del Usuario para ver su informacion: ";
            std::cin >> username;

            // Mostrar intereses
            std::cout << "Intereses de " << username << ":\n";
            for (const auto& interest : system.getUserInterests(username)) {
                std::cout << " - " << interest << std::endl;
            }

            // Mostrar amigos
            std::cout << "Amigos de " << username << ":\n";
            for (const auto& friendUser : system.getUserFriends(username)) {
                std::cout << " - " << friendUser << std::endl;
            }
            break;

        case 7: // Salir
            std::cout << "SALIENDO...\n";
            break;

        default:
            std::cout << "Opcion invalida...\n";
            break;
        }
    } while (choice != 7);
}
