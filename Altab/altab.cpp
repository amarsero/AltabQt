#include "altab.h"
#include <future>
#include <crawler.h>

Altab::Altab() {
    std::async(std::launch::async, &Altab::Init, this);
}

void Altab::Init()
{
    LoadConfig();
	Persistence::LoadEntries(deposit);
    Crawler::CrawlNewPath(deposit, "D:/Users/Agus/Desktop");
    Crawler::CrawlNewPath(deposit, "D:/Users/Public/Desktop");
    Crawler::CrawlNewPath(deposit, "C:/Users/Pun/Desktop");
    Crawler::CrawlNewPath(deposit, "C:/Users/Public/Desktop");
//    Deposit.Entries.Add(new Entries.GoogleSearchEntry());
//    Deposit.Entries.Add(new Entries.YoutubeSearchEntry());
//    Deposit.RemoveDuplicates();
    Persistence::SaveEntries(deposit);
}

void Altab::LoadConfig() {
    persistence.LoadConfig();
}
