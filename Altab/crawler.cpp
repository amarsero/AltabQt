#include "crawler.h"

void Crawler::CrawlNewPath(Deposit& deposit, const std::string path)
{
    for (auto &filePath: fs::directory_iterator(path)) {
        fs::path extension = filePath.path().extension();
        if (extension == ".exe" || extension == ".lnk") {
            ShortcutEntry* entry = Crawler::GetEntry(filePath.path());

        }
    }
}

ShortcutEntry* Crawler::GetEntry(fs::path path){
    ShortcutEntry* entry = new ShortcutEntry();
    entry->FullPath = path;
    entry->Name = path.filename().replace_extension();
    if (path.extension() == ".lnk")
    {

    } else {
        entry->TargetPath = entry->FullPath;
        entry->Icon = Crawler::GetIcon(path);
    }
}

uint8_t* GetIcon()
{
    return nullptr;
}
