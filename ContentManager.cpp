#include "ContentManager.h"
#include <iostream>

// Constructor por defecto
ContentManager::ContentManager() {}

// Método para agregar contenido a una categoría
void ContentManager::addContent(const std::string& category, const std::string& content) {
    // Se inserta el contenido en el conjunto correspondiente a la categoría
    categoryMap[category].insert(content);
}

// Método para obtener los contenidos de una categoría
std::vector<std::string> ContentManager::getContentByCategory(const std::string& category) const {
    std::vector<std::string> contents;

    // Buscamos la categoría en el mapa
    auto it = categoryMap.find(category);
    if (it != categoryMap.end()) {
        // Si la categoría existe, copiamos los contenidos a un vector
        for (const auto& content : it->second) {
            contents.push_back(content);
        }
    }

    return contents;
}
