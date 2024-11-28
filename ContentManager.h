#ifndef CONTENT_MANAGER_H
#define CONTENT_MANAGER_H

#include <unordered_map>
#include <set>
#include <string>

class ContentManager {
public:
    void addContent(const std::string& category, const std::string& content);
    std::set<std::string> getContentByCategory(const std::string& category) const;

private:
    std::unordered_map<std::string, std::set<std::string>> contents;
};

#endif

