#include "RecommendationSystem.h"
#include <iostream>
#include <string>

void displayMenu() { //Se agregan las opciones que se le desplegarán al usuario
    std::cout << "1. Agregar Usuario\n"
              << "2. Agregar Amigo\n"
              << "3. Agregar Interes\n"
              << "4. Agregar Contenido\n"
              << "5. Recomendacion\n"
              << "6. Ver Usuario\n"
              << "7. Exit\n";
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
            std::cout << "Usuario " << user1 << " agregado con exito.\n";
            break;

        case 2:
            std::cout << "Ingresa dos usuarios para conectar: ";
            std::cin >> user1 >> user2;
            system.addFriend(user1, user2);
            std::cout << "Amigos " << user1 << " y " << user2 << " conectados con exito.\n";
            break;

        case 3:
            std::cout << "Ingresa Usuario y la Categoria: ";
            std::cin >> user1 >> category;
            system.addInterest(user1, category);
            std::cout << "Interes '" << category << "' agregado a " << user1 << " con exito.\n";
            break;

        case 4:
            std::cout << "Ingresa la categoria y su Contenido: ";
            std::cin >> category >> content;
            system.addContent(category, content);
            std::cout << "Contenido '" << content << "' agregado a la categoria '" << category << "' con exito.\n";
            break;

        case 5:
            std::cout << "Ingresa Usuario para la recomendacion: ";
            std::cin >> user1;
            for (const auto& rec : system.recommendContent(user1)) {
                std::cout << rec << std::endl;
            }
            break;

        case 6:
            std::cout << "Ingresa el Usuario para ver su informacion: ";
            std::cin >> user1;

            // Mostrar intereses
            std::cout << "Intereses de " << user1 << ":\n";
            for (const auto& interest : system.getUserInterests(user1)) {
                std::cout << " - " << interest << std::endl;
            }

            // Mostrar amigos
            std::cout << "Amigos de " << user1 << ":\n";
            for (const auto& friendUser : system.getUserFriends(user1)) {
                std::cout << " - " << friendUser << std::endl;
            }
            break;

        case 7:
            std::cout << "SALIENDO...\n";
            break;

        default:
            std::cout << "Opción invalida...\n";
            break;
        }
    } while (choice != 7);
}
