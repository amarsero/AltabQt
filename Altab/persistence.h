#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <string>
#include <deposit.h>

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
    void SaveConfig(Config config);
    Config LoadConfig();
private:
    std::string savePath;
    const Deposit* deposit;
};

#endif // PERSISTENCE_H
