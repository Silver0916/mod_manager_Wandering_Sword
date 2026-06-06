#include "mod_installer.h"
#include <filesystem>
#include <vector>
#include <iostream>
#include <miniz.h>
#include <string>

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
/*bool unzip_mod(const fs::path& mod_path){
    // if the mod path is not valid or the file is not a zip file, return false
    if (!validate_mod_path(mod_path) || mod_path.extension() != L".zip"){
        std::wcerr << L"mod file not found: " << mod_path << std::endl;
        return false;
    }

    // unzip the mod file to a temporary directory
    fs::path temp_dir = fs::temp_directory_path() / mod_path.stem();

}
    */

bool install_mod(const fs::path& game_mod_dir, const fs::path& mod_path){
    // validate the mod path
    if (!validate_mod_path(mod_path)){
        std::wcerr << L"Mod path is not valid: " << mod_path << std::endl;
        return false;
    }

    // copy the mod files to the game mod directory
    try {
            fs::copy(mod_path, game_mod_dir, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
            std::wcout << L"Mod installed successfully from: " << mod_path << std::endl;
        return true;
    } 
    catch (const fs::filesystem_error& e) {
        std::wcerr << L"Error installing mod: " << e.what() << std::endl;
        return false;
    }
}

std::wstring get_mod_path(){
    /*
    get the mod path from the user input, return the mod path as a wstring
    input: the user input of the mod path
    output: the mod path as a wstring
    */
    std::wcout << L"enter  the path of mod:";
    std::wstring mod_path;
    std::getline(std::wcin, mod_path);
    return mod_path;
}