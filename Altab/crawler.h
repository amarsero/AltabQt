#ifndef CRAWLER_H
#define CRAWLER_H
#include <string>
#include "deposit.h"
#include <filesystem>
#include <shortcutentry.h>

namespace fs = std::filesystem;

class Crawler
{
public:
    static void CrawlNewPath(Deposit& deposit, const std::string path);
private:
    static ShortcutEntry *GetEntry(fs::path path);
    static uint8_t *GetIcon(fs::path path);
};

#endif // CRAWLER_H
