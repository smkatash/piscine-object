#include "Shovel.hpp"

Shovel::Shovel() {
    std::cout << "Shovel is created.\n";
    this->number_of_uses = 0;
    this->worker = nullptr;
}

Shovel::~Shovel() {
    take_away_from_worker();
    std::cout << "Shovel is destroyed.\n";
}

void    Shovel::use() {
    std::cout << "Using the shovel: scrape, scrape...\n";
    this->number_of_uses++;
}

int     Shovel::get_number_of_uses() { return this->number_of_uses; }
