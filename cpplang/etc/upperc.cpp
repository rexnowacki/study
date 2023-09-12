
#include <iostream>
#include <string>
#include <algorithm>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

std::string to_lowercase(const std::string &str) {
    std::string new_str = str;
    std::transform(new_str.begin(), new_str.end(), new_str.begin(), ::tolower);
    return new_str;
}

void process_directory(const std::string &dir_path, bool recursive) {
    DIR *dir;
    struct dirent *ent;
    struct stat st;

    dir = opendir(dir_path.c_str());
    if (dir == nullptr) {
        std::cerr << "Could not open directory: " << dir_path << std::endl;
        return;
    }

    while ((ent = readdir(dir)) != nullptr) {
        std::string filename = ent->d_name;

        if (filename == "." || filename == "..") continue; // Skip . and ..

        std::string full_path = dir_path + "/" + filename;

        if (stat(full_path.c_str(), &st) == -1) continue;

        if (S_ISDIR(st.st_mode) && recursive) {
            process_directory(full_path, recursive);
        } else {
            std::string new_filename = to_lowercase(filename);
            if (filename != new_filename) {
                std::string new_full_path = dir_path + "/" + new_filename;
                if (rename(full_path.c_str(), new_full_path.c_str()) == 0) {
                    std::cout << "Renamed " << full_path << " to " << new_full_path << std::endl;
                } else {
                    std::cerr << "Failed to rename " << full_path << std::endl;
                }
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    bool recursive = false;
    if (argc > 1 && std::string(argv[1]) == "-r") {
        recursive = true;
    }

    process_directory(".", recursive);
    return 0;
}
