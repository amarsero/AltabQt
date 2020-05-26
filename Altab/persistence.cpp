#include "persistence.h"

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <entry.h>
#include <vector>
#include <ios.h>

namespace fs = std::filesystem;

using nlohmann::json;

Persistence::Persistence(const Deposit *deposit)
{
    this->deposit = deposit;
}

Persistence::Persistence(const Deposit *deposit)
{
    this->deposit = deposit;
}

void Persistence::Save()
{
    fs::path filePath{IOS::Instance().GetSaveFolder()};
    filePath += "tuvieja.sav";
    fs::path copy(filePath);
    copy += ".bak";
    {
        std::ofstream file{filePath, std::ios::binary};
        for (Entry* entry : *deposit->Entries)
        {
            int length = entry->SerializedLength();
            char bytes[length];

            SerializableObject serializable(bytes, length, SerializableObjectTypeEnum::ShortcutEntry);

            entry->Serialize(serializable);

            auto vector = serializable.ToVector();

            file.write(vector.data(), vector.size());
        }
    }

    fs::rename(copy, filePath);
}

Config Persistence::LoadConfig()
{
    Config config;

    fs::path configPath = IOS::Instance().GetSaveFolder();
    configPath += "config";

    if (!fs::exists(configPath))
    {
        SaveConfig(config);
    }
    else
    {
        std::ifstream file{configPath};
        json j;
        file >> j;
        config = j;
    }

    return config;
}

void Persistence::SaveConfig(const Config &config)
{
    fs::path path = IOS::Instance().GetSaveFolder();
    path += "config";
    fs::path copy(path);
    copy += ".bak";

    {
        std::ofstream file{copy};
        json j = config;
        file << j;
    }

    fs::rename(copy, path);
}

Config::operator nlohmann::json() const
{
    json j;
    j = json{
                {"testString", this->testString},
                {"testNumber", this->testNumber}
            };
    return j;
}

Config::Config(nlohmann::json &json)
{
    json.at("testString").get_to(this->testString);
    json.at("testNumber").get_to(this->testNumber);
}

void Persistence::SaveConfig(Config config)
{

}

Config Persistence::LoadConfig()
{
    return Config{};
}
