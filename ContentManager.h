#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class ContentManager {
public:
    // Constructor
    ContentManager();

    // Método para agregar contenido a una categoría
    void addContent(const std::string& category, const std::string& content);

    // Método para obtener los contenidos de una categoría
    std::vector<std::string> getContentByCategory(const std::string& category) const;

private:
    // Mapa que asocia cada categoría con un conjunto de contenidos
    std::unordered_map<std::string, std::unordered_set<std::string>> categoryMap;
};

#endif // CONTENTMANAGER_H
