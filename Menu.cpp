#include "Menu.h"
#include <iostream>

void Menu::mostrarMenuPrincipal() {
    std::cout << "==================================" << std::endl;
    std::cout << "         MENU PRINCIPAL          " << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "1. Agregar Anime" << std::endl;
    std::cout << "2. Mostrar Animes" << std::endl;
    std::cout << "3. Buscar Anime por Género" << std::endl;
    std::cout << "4. Ordenar Animes por Rating" << std::endl;
    std::cout << "5. Salir" << std::endl;
    std::cout << "Ingrese una opción (1-5): ";
}

void Menu::mostrarMenuOrdenar() {
    std::cout << "==================================" << std::endl;
    std::cout << "       MENÚ DE ORDENAMIENTO      " << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "1. Bubble Sort" << std::endl;
    std::cout << "2. Merge Sort" << std::endl;
    std::cout << "3. Quick Sort" << std::endl;
    std::cout << "Ingrese el método de ordenamiento (1-3): ";
}

void Menu::mostrarMensajeBienvenida() {
    std::cout << "¡Bienvenido a la aplicación de Anime!" << std::endl;
    std::cout << "Aquí podrás gestionar y buscar tus animes favoritos." << std::endl;
}

void Menu::mostrarMensajeDespedida() {
    std::cout << "Gracias por usar la aplicación de Anime. ¡Hasta luego!" << std::endl;
}
