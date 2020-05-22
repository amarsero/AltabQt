#include "deposit.h"
#include "vector"
#include "entry.h"

Deposit::Deposit()
{
    Entries = new std::vector<Entry*>();
}

const std::vector<Entry *>* Deposit::SearchAll(std::string search)
{
    if (search.empty()){
        return new std::vector<Entry*>(*Entries);
    }
    std::vector<Entry*>* result = new std::vector<Entry*>();
    for(Entry* entry: *Entries) {
        if (entry->Name.find(search) != std::string::npos)
        {
            result->push_back(entry);
        }
    }
    return result;
}
