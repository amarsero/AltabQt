#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <vector>
#include <entry.h>

class Deposit
{
public:
    Deposit();
    ~Deposit();
    std::vector<Entry*>* Entries;

    const std::vector<Entry*>* SearchAll(const std::string search);
    void Clear();
};

#endif // DEPOSIT_H
