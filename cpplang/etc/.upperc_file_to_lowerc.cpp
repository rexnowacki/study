
#include <iostream>
#include <string>
#include <algorithm>
#include <dirent.h>
#include <unistd.h>

std::string to_lowercase(const std::string &str) {
    std::string new_str = str;
    std::transform(new_str.begin(), new_str.end(), new_str.begin(), ::tolower);
    return new_str;
}

int main() {
    DIR *dir;
    struct dirent *ent;

    dir = opendir(".");
    if (dir == nullptr) {
        std::cerr << "Could not open current directory." << std::endl;
        return 1;
    }

    while ((ent = readdir(dir)) != nullptr) {
        std::string filename = ent->d_name;
        std::string new_filename = to_lowercase(filename);

        if (filename != new_filename) {
            if (rename(filename.c_str(), new_filename.c_str()) == 0) {
                std::cout << "Renamed " << filename << " to " << new_filename << std::endl;
            } else {
                std::cerr << "Failed to rename " << filename << std::endl;
            }
        }
    }

    closedir(dir);
    return 0;
}
