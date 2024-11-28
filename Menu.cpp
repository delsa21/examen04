#include "Menu.h"

void Menu::mostrarMenuPrincipal() {
    std::cout << "==================================" << std::endl;
    std::cout << "         MENU PRINCIPAL          " << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "1. Agregar Usuario" << std::endl;
    std::cout << "2. Agregar Amigo" << std::endl;
    std::cout << "3. Agregar Interés" << std::endl;
    std::cout << "4. Obtener Recomendaciones" << std::endl;
    std::cout << "5. Salir" << std::endl;
    std::cout << "Ingrese una opción (1-5): ";
}

void Menu::mostrarMensajeBienvenida() {
    std::cout << "¡Bienvenido al sistema de recomendaciones de contenido!" << std::endl;
}

void Menu::mostrarMensajeDespedida() {
    std::cout << "Gracias por usar el sistema de recomendaciones. ¡Hasta luego!" << std::endl;
}
