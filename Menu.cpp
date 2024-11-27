#include "RecommendationSystem.h"
#include <iostream>
#include <string>

void displayMenu() {
    std::cout << "1. Add User\n"
              << "2. Add Friend\n"
              << "3. Add Interest\n"
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
            std::cout << "Enter username: ";
            std::cin >> user1;
            system.addUser(user1);
            break;

        case 2:
            std::cout << "Enter two usernames to connect: ";
            std::cin >> user1 >> user2;
            system.addFriend(user1, user2);
            break;

        case 3:
            std::cout << "Enter username and interest category: ";
            std::cin >> user1 >> category;
            system.addInterest(user1, category);
            break;

        case 4:
            std::cout << "Enter category and content: ";
            std::cin >> category >> content;
            system.addContent(category, content);
            break;

        case 5:
            std::cout << "Enter username to get recommendations: ";
            std::cin >> user1;
            for (const auto& rec : system.recommendContent(user1)) {
                std::cout << rec << std::endl;
            }
            break;

        case 6:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid option. Try again.\n";
            break;
        }
    } while (choice != 6);
}
