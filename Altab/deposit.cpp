#include "deposit.h"
#include "vector"
#include "entry.h"
#include <algorithm>

Deposit::Deposit()
{
    Entries = new std::vector<Entry*>();
}

Deposit::~Deposit()
{
    Clear();
    delete Entries;
}

void Deposit::Clear(){
    std::for_each(Entries->begin(),Entries->end(), [](auto entry){delete entry;});
    Entries->clear();
}

const std::vector<Entry *>* Deposit::SearchAll(const std::string search)
{
    if (search.empty()){
        return new std::vector<Entry*>(*Entries);
    }
    std::vector<Entry*>* result = new std::vector<Entry*>();

    std::string searchUpper;
    std::transform(search.begin(), search.end(), std::back_inserter(searchUpper),
                   (int (*)(int))std::toupper);

    for(Entry* entry: *Entries) {
        std::string nameUpper;
        std::transform(entry->Name.begin(), entry->Name.end(), std::back_inserter(nameUpper),
                       (int (*)(int))std::toupper);

        if (nameUpper.find(searchUpper) != std::string::npos)
        {
            result->push_back(entry);
        }
    }
    return result;
}
