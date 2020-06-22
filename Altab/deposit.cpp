#include "deposit.h"
#include "vector"
#include "entry.h"
#include <algorithm>

Deposit::~Deposit()
{
	Clear();
}

void Deposit::Clear(){
    entries.clear();
}

const std::unique_ptr<std::vector<std::shared_ptr<const Entry>>> Deposit::SearchAll(const std::string search)
{
    if (search.empty()){
        return std::make_unique<std::vector<std::shared_ptr<const Entry>>>(entries);
    }
    auto result = std::make_unique<std::vector<std::shared_ptr<const Entry>>>();

    std::string searchUpper;
    std::transform(search.begin(), search.end(), std::back_inserter(searchUpper),
                   (int (*)(int))std::toupper);

    for(std::shared_ptr<const Entry> entry: entries) {
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
