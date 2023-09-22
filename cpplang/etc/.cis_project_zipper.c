
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <limits.h>

std::string findLanguageDir(const std::string& currentDir) {
    std::string dir = currentDir;
    while (true) {
        std::size_t lastSlash = dir.find_last_of("/");
        if (lastSlash == std::string::npos) {
            return ""; // Cannot find any matching parent/grandparent directory
        }
        std::string parentDir = dir.substr(0, lastSlash);
        lastSlash = parentDir.find_last_of("/");
        if (lastSlash == std::string::npos) {
            return ""; // Cannot find any matching parent/grandparent directory
        }
        std::string languageDir = parentDir.substr(lastSlash + 1);

        if (languageDir == "cpplang" || languageDir == "clang") {
            return languageDir; // Found a matching directory
        }

        dir = parentDir; // Continue searching upwards
    }
}

int main() {
    std::string username = "christopher_nowacki";
    std::string classname;

    // Get the current directory name
    char buffer[PATH_MAX];
    if(getcwd(buffer, sizeof(buffer)) == NULL) {
        std::cerr << "Error: Could not get current directory." << std::endl;
        return 1;
    }
    std::string currentDir = buffer;
    
    // Derive the classname from the parent/grandparent directory that matches either "cpplang" or "clang"
    classname = findLanguageDir(currentDir);
    if(classname.empty()) {
        std::cerr << "Error: Could not determine language directory (cpplang/clang)." << std::endl;
        return 1;
    }

    std::size_t lastSlash = currentDir.find_last_of("/");
    std::string dirName = currentDir.substr(lastSlash + 1);

    // Construct the zip command
    std::string zipCommand = "zip -r ";
    zipCommand += username + "_" + classname + "_" + dirName + "_assignments.zip *";

    // Execute the zip command
    if(system(zipCommand.c_str()) == -1) {
        std::cerr << "Error: Could not execute zip command." << std::endl;
        return 1;
    }

    std::cout << "Successfully created the zip file." << std::endl;
    return 0;
}

