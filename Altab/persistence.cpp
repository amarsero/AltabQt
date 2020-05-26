#include "persistence.h"

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <entry.h>

Persistence::Persistence(const Deposit *deposit)
{
    this->deposit = deposit;
}

void Persistence::Save()
{
    std::ofstream file;
//    file.open(savePath + "tuvieja.sav.bak");

//    for (Entry* entry : *deposit->Entries)
//    {
//        entry->Serialize(file);
//    }

//    file.close();

    const char* bakPath = (savePath + "tuvieja.sav.bak").c_str();
    const char* path = (savePath + "tuvieja.sav.bak").c_str();

    remove(path);
    std::rename(bakPath, path);
    remove(bakPath);
}

void Persistence::SaveConfig(Config config)
{

}

Config Persistence::LoadConfig()
{
    return Config{};
}
