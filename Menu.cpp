#include <iostream>
#include <string>
#include "ContentManager.h"

class Menu {
private:

public:
    void showMenu()
      int choice = -1;
      while (choice != 0) {
        std::cout << "\n--- Menu ---\n";
        std::cout << "1. Agregar nuevo usario\n";
        std::cout << "2. Agregar un amigo\n";
        std::cout << "3. Agregar interés a usario\n";
        std::cout << "4. Recomendaciones de contenido\n";
        std::cout << "0. Salir\n";
std::cin >> choice;

            switch (choice) {
                case 1:
                    addUser();
                    break;
                case 2:
                    addFriend();
                    break;
                case 3:
                    addInterest();
                    break;
                case 4:
                    getRecommendations();
                    break;
                case 0:
                    std::cout << "Saliendo del programa. ¡Hasta luego!\n";
                    break;
                default:
                    std::cout << "Opción inválida. Intente nuevamente.\n";
            }
        }
    }

private:
    void addUser() {
        std::string username;
        std::cout << "Ingrese el nombre del nuevo usuario: ";
        std::cin >> username;
        if (userManager.addUser(username)) {
            graph.addNode(username);
            std::cout << "Usuario agregado exitosamente.\n";
        } else {
            std::cout << "El usuario ya existe.\n";
        }
    }

    void addFriend() {
        std::string user1, user2;
        std::cout << "Ingrese el nombre del usuario: ";
        std::cin >> user1;
        std::cout << "Ingrese el nombre del amigo: ";
        std::cin >> user2;
        if (graph.addEdge(user1, user2)) {
            std::cout << "Amigo agregado exitosamente.\n";
        } else {
            std::cout << "Error al agregar amigo. Verifique los nombres.\n";
        }
    }

    void addInterest() {
        std::string username, interest;
        std::cout << "Ingrese el nombre del usuario: ";
        std::cin >> username;
        std::cout << "Ingrese el interés a agregar: ";
        std::cin.ignore();
        std::getline(std::cin, interest);
        if (userManager.addInterest(username, interest)) {
            std::cout << "Interés agregado exitosamente.\n";
        } else {
            std::cout << "Error al agregar interés. Verifique el usuario.\n";
        }
    }

    void getRecommendations() {
        std::string username;
        std::cout << "Ingrese el nombre del usuario: ";
        std::cin >> username;
        auto recommendations = recommendationSystem.getRecommendations(username, graph, userManager);
        if (!recommendations.empty()) {
            std::cout << "Recomendaciones de contenido:\n";
            for (const auto& content : recommendations) {
                std::cout << "- " << content << "\n";
            }
        } else {
            std::cout << "No hay recomendaciones disponibles.\n";
        }
    }
};
