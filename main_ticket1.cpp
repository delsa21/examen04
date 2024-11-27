#include <iostream>
#include "ContentManager.h"

int main() {
    ContentManager manager;

    // Agregar contenidos
    manager.addContent("Noticias", "Últimas noticias sobre tecnología");
    manager.addContent("Noticias", "El cambio climático es una amenaza global");
    manager.addContent("Entretenimiento", "Películas más esperadas de 2024");

    // Obtener contenidos por categoría
    std::vector<std::string> noticias = manager.getContentByCategory("Noticias");
    std::cout << "Contenido en la categoría 'Noticias':" << std::endl;
    for (const auto& content : noticias) {
        std::cout << "- " << content << std::endl;
    }

    std::vector<std::string> entretenimiento = manager.getContentByCategory("Entretenimiento");
    std::cout << "\nContenido en la categoría 'Entretenimiento':" << std::endl;
    for (const auto& content : entretenimiento) {
        std::cout << "- " << content << std::endl;
    }

    return 0;
}

