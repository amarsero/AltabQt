#ifndef ALTAB_H
#define ALTAB_H

#include <entry.h>
#include <deposit.h>
#include <persistence.h>

class Altab
{
public:
    Altab();
private:
    Deposit deposit;
    Persistence persistence;
    void Init();
    void LoadConfig();
};

#endif // ALTAB_H
