#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <vector>
#include <entry.h>

class Deposit
{
public:
    Deposit();
    std::vector<Entry*>* Entries;
};

#endif // DEPOSIT_H
