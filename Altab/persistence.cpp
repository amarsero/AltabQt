#include "persistence.h"

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <entry.h>
#include <vector>
#include <ios.h>
#include <deserializableobject.h>

namespace fs = std::filesystem;

using nlohmann::json;

void Persistence::SaveEntries(const Deposit& deposit)
{
    fs::path filePath{IOS::Instance().GetSaveFolder()};
    fs::create_directories(filePath);
    filePath += "tuvieja.sav";
    fs::path copy{filePath};
    copy += ".bak";
    {
		std::ofstream file{copy, std::ios::binary};
        for (auto entry : deposit.entries)
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

void Persistence::LoadEntries(Deposit& deposit)
{
    fs::path filePath{IOS::Instance().GetSaveFolder()};
    fs::create_directories(filePath);
    filePath += "tuvieja.sav";
    {
        std::ifstream file{filePath, std::ios::binary};
		if (file.fail())
			return;
        char type = file.get();
		while(!file.eof())
        {
			int size;
			file.read((char*)&size, sizeof(int));
            char bytes[size];
			file.read(bytes, size);

            DeserializableObject deserializable{bytes, size, type};

            deposit.entries.push_back(Entry::Deserialize(deserializable));

            type = file.get();
		}
	}
}

Config Persistence::LoadConfig()
{
    Config config;

    fs::path configPath = IOS::Instance().GetSaveFolder();
    fs::create_directories(configPath);
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
    fs::path path{IOS::Instance().GetSaveFolder()};
    fs::create_directories(path);
    path += "config";
    fs::path copy(path);
    copy += ".bak";
    {
        std::ofstream file{copy};
        json j = config;
        file << j;
        file.flush();
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
