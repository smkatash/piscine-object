#include "Hammer.hpp"

Hammer::Hammer() {
    std::cout << "Hammer is created.\n";
    this->number_of_uses = 0;
    this->worker = nullptr;
}

Hammer::~Hammer() {
    take_away_from_worker();
    std::cout << "Hammer is destroyed.\n";
}

void    Hammer::use() {
    this->number_of_uses++;
    std::cout << "Using the hammer: bang, bang...\n";
}

int     Hammer::get_number_of_uses() { return this->number_of_uses; }

