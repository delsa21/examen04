#include <iostream>
#include "Menu.h"
#include "RecommendationSystem.h"

int main() {
    RecommendationSystem system;
    Menu menu;

    menu.mostrarMensajeBienvenida();
    int option;
    
    while (true) {
        menu.mostrarMenuPrincipal();
        std::cin >> option;

        if (option == 1) {
            // Agregar Usuario
        } else if (option == 2) {
            // Agregar Amigo
        } else if (option == 3) {
            // Agregar Interés
        } else if (option == 4) {
            // Obtener Recomendaciones
        } else if (option == 5) {
            menu.mostrarMensajeDespedida();
            break;
        }
    }

    return 0;
}
