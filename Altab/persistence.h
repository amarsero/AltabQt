#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <string>
#include <deposit.h>

class Persistence
{
public:
    Persistence(const std::string savePath, const Deposit* deposit);
    void Save();
    void Load();
private:
    std::string savePath;
    const Deposit* deposit;
};

#endif // PERSISTENCE_H
