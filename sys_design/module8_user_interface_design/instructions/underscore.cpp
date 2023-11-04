
#include <iostream>
#include <string>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

std::string process_filename(const std::string& original) {
    std::string new_name = original;
    
    // Convert spaces to underscores
    std::replace(new_name.begin(), new_name.end(), ' ', '_');
    
    // Convert all characters to lowercase
    std::transform(new_name.begin(), new_name.end(), new_name.begin(), ::tolower);
    
    return new_name;
}

int main(int argc, char* argv[]) {
    std::string path = ".";
    
    if (argc >= 2) {
        path = argv[1];
    }

    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file()) { // Only process files, skip directories
            std::string old_path = entry.path().string();
            std::string new_name = process_filename(entry.path().filename().string());
            std::string new_path = entry.path().parent_path().string() + "/" + new_name;

            if (old_path != new_path) {
                try {
                    fs::rename(old_path, new_path);
                    std::cout << "Renamed: " << old_path << " -> " << new_path << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << "Error renaming file: " << e.what() << std::endl;
                }
            }
        }
    }

    return 0;
}
