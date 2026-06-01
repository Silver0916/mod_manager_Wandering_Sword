#pragma once

#include <filesystem>
#include<vector>

namespace fs = std::filesystem;

// struct for storing related paths
struct Paths{
    fs::path steam_path;
    fs::path game_path;
    fs::path mod_path;
};

fs::path input_steam_path();
bool validate_steam_path(const fs::path& steam_path);
fs::path concat_game_path(const fs::path& steam_path);
bool validate_game_path(const fs::path& game_path);
fs::path concat_mod_path(const fs::path& game_path);
bool validate_mod_path(const fs::path& mod_path);
bool find_paths(Paths& game_paths);