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

struct Config {
    std::string testString;
    int testNumber;
};

class Persistence
{
public:
    Persistence(const Deposit* deposit);
    void Save();
    void Load();
    Config LoadConfig();
    void SaveConfig(const Config& config);
private:
    const Deposit* deposit;

};

#endif // PERSISTENCE_H
