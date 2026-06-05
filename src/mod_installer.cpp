#include "mod_installer.h"
#include <filesystem>
#include <vector>
#include <iostream>
#include <miniz.h>

namespace fs = std::filesystem;

// function to validate the mod path, return true if valid, false if not
bool validate_mod_path(const fs::path& mod_path){
    if (!fs::exists(mod_path) || !fs::is_directory(mod_path)){
        std::wcerr << L" Mod not found at: " << mod_path << std::endl;
        return false;
    }
    return true;
}

// function to unzip and install mods
bool unzip_mod(const fs::path& mod_path){
    // if the mod path is not valid or the file is not a zip file, return false
    if (!validate_mod_path(mod_path) || mod_path.extension() != L".zip"){
        std::wcerr << L"mod file not found: " << mod_path << std::endl;
        return false;
    }

    // unzip the mod file to a temporary directory
    fs::path temp_dir = fs::temp_directory_path() / mod_path.stem();

}