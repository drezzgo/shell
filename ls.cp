#include <iostream>
#include <dirent.h>
#include <vector>
#include <string>

void listDirectory(const std::vector<std::string>& args) {
    const char *path = (args.size() > 0) ? args[0].c_str() : ".";
    DIR *dir = opendir(path);
    if (dir == nullptr) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::cout << entry->d_name << std::endl;
    }

    closedir(dir);
}