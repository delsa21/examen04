#include "ContentManager.h"

void ContentManager::addContent(const std::string& category, const std::string& content) {
    contents[category].insert(content);
}

std::set<std::string> ContentManager::getContentByCategory(const std::string& category) const {
    if (contents.find(category) != contents.end()) {
        return contents.at(category);
    }
    return {};
}
