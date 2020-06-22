#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <vector>
#include <entry.h>

class Deposit
{
public:
    ~Deposit();
    std::vector<std::shared_ptr<const Entry>> entries;

    const std::unique_ptr<std::vector<std::shared_ptr<const Entry>>> SearchAll(const std::string search);
    void Clear();
};

#endif // DEPOSIT_H
