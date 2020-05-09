#include "deposit.h"
#include "vector"
#include "entry.h"

Deposit::Deposit()
{
    Entries = new std::vector<Entry*>();
}
