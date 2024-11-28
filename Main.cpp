#include <iostream>
#include "Menu.h"
#include "RecommendationSystem.h"

int main() {
    // Crear instancias necesarias
    RecommendationSystem recommendationSystem;
    Menu menu;

    // Mostrar mensaje de bienvenida
    menu.mostrarMensajeBienvenida();

    // Llamar al menú principal
    menu.mostrarMenuPrincipal();

    int option;
    std::cin >> option;

    switch(option) {
        case 1: {
            std::string username, category, content;
            std::cout << "Ingrese el nombre de usuario: ";
            std::cin >> username;
            recommendationSystem.addUsuario(username);
            std::cout << "Ingrese categoría del contenido: ";
            std::cin >> category;
            std::cout << "Ingrese contenido: ";
            std::cin >> content;
            recommendationSystem.addContent(category, content);
            std::cout << "Contenido agregado!" << std::endl;
            break;
        }
        case 2: {
            // Mostrar los contenidos por categoría (esto puede ajustarse a tus necesidades)
            std::string category;
            std::cout << "Ingrese categoría para mostrar contenidos: ";
            std::cin >> category;
            std::set<std::string> contents = recommendationSystem.contentManager.getContentByCategory(category);
            for (const auto& content : contents) {
                std::cout << content << std::endl;
            }
            break;
        }
        case 3: {
            std::string username, category;
            std::cout << "Ingrese el nombre de usuario: ";
            std::cin >> username;
            std::cout << "Ingrese la categoría de interés: ";
            std::cin >> category;
            recommendationSystem.addInterest(username, category);
            break;
        }
        case 4: {
            std::string username;
            std::cout << "Ingrese el nombre de usuario para recomendaciones: ";
            std::cin >> username;
            std::vector<std::string> recommendations = recommendationSystem.recommendContent(username);
            std::cout << "Recomendaciones para " << username << ":" << std::endl;
            for (const auto& recommendation : recommendations) {
                std::cout << recommendation << std::endl;
            }
            break;
        }
        case 5:
            menu.mostrarMensajeDespedida();
            break;
        default:
            std::cout << "Opción no válida!" << std::endl;
            break;
    }

    return 0;
}
