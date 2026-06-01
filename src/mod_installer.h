#include "path_finder.h"
#include <filesystem>
#include <vector>

// function to validate the mod path, return true if valid, false if not
bool validate_mod_path(const std::filesystem::path& mod_path);

// function to unzip and install mods
bool unzip_mod(const std::filesystem::path& mod_path, const std::filesystem::path& game_path);
bool install_mod(const std::filesystem::path& mod_path, const std::filesystem::path& game_path);