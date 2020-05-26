#include "windowsos.h"
#include <stdlib.h>
#include <filesystem>

WindowsOS::WindowsOS()
{

}


std::string WindowsOS::GetSaveFolder()
{
    if (cache.count("SaveFolder") == 0)
       cache["SaveFolder"] = std::string(getenv("APPDATA")) + std::filesystem::path::preferred_separator;
    return cache["SaveFolder"];
}
