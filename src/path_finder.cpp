#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <filesystem>
#include "path_finder.h"

namespace fs = std::filesystem;
const std::wstring APP_ID = L"1876890";
const std::wstring CONFIG_FILE = L"config.txt";
const std::wstring RECORD_FILE = L"installed_mods.txt";

// function for returning a pure path
fs::path input_steam_path(){
    std::wcout<<L"enter the steam path (e.g. C:/Program Files (x86)/Steam): ";
    // Read the input from the user
    std::wstring input_steam_path;
    std::getline(std::wcin, input_steam_path);
    // Remove any leading or trailing whitespace
    input_steam_path.erase(0, input_steam_path.find_first_not_of(L" \t\n\r\f\v"));
    input_steam_path.erase(input_steam_path.find_last_not_of(L" \t\n\r\f\v") + 1);
    return input_steam_path;
}

bool validate_steam_path(const fs::path& steam_path){
    // check if the path exists and is a directory
    if (!fs::exists(steam_path) || !fs::is_directory(steam_path)){
        std::wcerr << L"Invalid Steam path: " << steam_path << std::endl;
        return false;
    }
    return true;
}

// concatenate the steam path with the game path
fs::path concat_game_path(const fs::path& steam_path){
    fs::path game_path = steam_path / L"steamapps" / L"common" / L"Wandering Sword";
    return game_path;
}

bool validate_game_path(const fs::path& game_path){
    if (!fs::exists(game_path) || !fs::is_directory(game_path)){
        std::wcerr << L"Game not found at: " << game_path << std::endl;
        return false;
    }
    return true;
}

// concatenate the game path with the mod path
fs::path concat_mod_path(const fs::path& game_path){
    fs::path mod_path = game_path /L"Wandering_Sword" / L"Content" / L"Paks";
    return mod_path;
}

// check if the game mod path exists
bool validate_mod_path(const fs::path& mod_path){
    if (!fs::exists(mod_path) || !fs::is_directory(mod_path)){
        std::wcerr << L" Mod not found at: " << mod_path << std::endl;
        return false;
    }
    return true;
}

// find and validate all paths, return a struct of paths
bool find_paths(Paths& game_paths){
    while (true){
        game_paths.steam_path = input_steam_path();
        if (validate_steam_path(game_paths.steam_path)){
            break;
        }
    }
    game_paths.game_path = concat_game_path(game_paths.steam_path);
    if (!validate_game_path(game_paths.game_path)){
        std::wcerr << L"Game not found at: " << game_paths.game_path << std::endl;
        return false;
    }
    game_paths.mod_path = concat_mod_path(game_paths.game_path);
    if (!validate_mod_path(game_paths.mod_path)){
        std::wcerr << L" Mod not found at: " << game_paths.mod_path << std::endl;
        return false;
    }
    return true;
}