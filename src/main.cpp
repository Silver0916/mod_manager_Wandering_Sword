#include <iostream>
#include "path_finder.h"
#include "mod_installer.h"
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main(){
    Paths game_paths;
    if (!find_paths(game_paths)){
        std::wcerr << L"Failed to find valid paths. Exiting." << std::endl;
        return 1;
    }

    std::wstring mod_path = get_mod_path();
    if (!install_mod(game_paths.mod_install_dir, mod_path)){
        std::wcerr << L"Failed to install mod. Exiting." << std::endl;
        return 1;
    }

    std::wcout << L"Mod installed successfully!" << std::endl;
    return 0;
}