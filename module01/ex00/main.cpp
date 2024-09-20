#include "Hammer.hpp"
#include "Shovel.hpp"
#include "Workshop.hpp"


int main() {

    try {
        Hammer *hammer1 = new Hammer();
        Shovel *shovel1 = new Shovel();

        Worker *bob = new Worker("Bob", Position(1,2,3), Statistic(5));
        Worker *anna = new Worker("Anna", Position(3,1,6), Statistic(3));
        
        Workshop<Hammer> *diy = new Workshop<Hammer>("DIY");
        diy->register_worker(*anna);

        bob->take_tool(*shovel1);
        bob->take_tool(*hammer1);
        Workshop<Shovel> *craftsmen = new Workshop<Shovel>("Craftsmen");
        craftsmen->register_worker(*bob);



        delete bob;
        delete anna;
        delete hammer1;
        delete shovel1;
        delete diy;
        delete craftsmen;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
