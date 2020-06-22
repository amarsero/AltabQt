#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <string>

#include <deposit.h>
#include <json.hpp>
#include <filesystem>

struct Config {
    Config() = default;

    std::string testString;
    int testNumber;

    operator nlohmann::json() const;
    Config(nlohmann::json& json);
};

class Persistence
{
public:
    static void SaveEntries(const Deposit& deposit);
    static void LoadEntries(Deposit& deposit);
    static Config LoadConfig();
    static void SaveConfig(const Config& config);
};

#endif // PERSISTENCE_H
