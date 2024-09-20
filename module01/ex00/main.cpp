#include "Hammer.hpp"
#include "Shovel.hpp"
#include "Workshop.hpp"

void    test_composition() {
    Worker bob = Worker("Bob", 1,2,3,5);
    Worker anna = Worker("Anna", 5,7,3,8);
    Worker jim = Worker("Jim", Position(1,2,3), Statistic(5));
}
void    test_aggregation() {
    Worker *bob = new Worker("Bob", 1,2,3,5);
    Worker *anna = new Worker("Anna", 5,7,3,8);
    
    Shovel *shovel = new Shovel();
    bob->take_tool(shovel);
    delete bob;
    anna->take_tool(shovel);
    delete anna;
    delete shovel;

    bob = new Worker("Bob", 1,2,3,5);
    anna = new Worker("Anna", 5,7,3,8);
    Hammer *hammer = new Hammer();
    bob->take_tool(hammer);
    anna->take_tool(hammer);
    bob->remove_tool(hammer);
    delete bob;
    delete anna;
    delete hammer;
}

void    test_inherence() {
    Shovel shovel = Shovel();
    Hammer hammer = Hammer();
    Worker bob = Worker("Bob", 1,2,3,5);
    Worker anna = Worker("Anna", 5,7,3,8);
    
    bob.take_tool(&shovel);
    bob.remove_tool(&shovel);
    bob.take_tool(&shovel);
    anna.take_tool(&shovel);

    bob.take_tool(&hammer);
    anna.take_tool(&hammer);
}

void    test_association() {
    Workshop<Shovel> shovelw = Workshop<Shovel>("Shovel Workshop");
    Workshop<Shovel> craftsmen = Workshop<Shovel>("Craftsmen Workshop");
    Workshop<Hammer> hammerw = Workshop<Hammer>("Hammer Workshop");
    Workshop<Hammer> diy = Workshop<Hammer>("DIY Workshop");
    Worker bob = Worker("Bob", 1,2,3,5);
    Worker john = Worker("John", 4,9,3,4);
    Worker anna = Worker("Anna", 5,7,3,8);
    Worker jen = Worker("Jenn", 3,1,3,10);

    Shovel shovel1 = Shovel();
    Shovel shovel2 = Shovel();
    Hammer hammer1 = Hammer();
    Hammer hammer2 = Hammer();
    
    bob.take_tool(&shovel1);
    anna.take_tool(&hammer1);

    shovelw.register_worker(&bob);
    shovelw.register_worker(&john);
    craftsmen.register_worker(&bob);
    craftsmen.register_worker(&john);

    hammerw.register_worker(&anna);
    hammerw.register_worker(&jen);
    diy.register_worker(&anna);
    diy.register_worker(&jen);

    shovelw.list_workers();
    craftsmen.list_workers();
    hammerw.list_workers();
    diy.list_workers();

    shovelw.execute_workday();
    craftsmen.execute_workday();
    hammerw.execute_workday();
    diy.execute_workday();

    john.take_tool(&shovel2);
    jen.take_tool(&hammer2);

    diy.register_worker(&john);
    diy.register_worker(&jen);
    shovelw.register_worker(&john);
    shovelw.release_worker(&bob);

    shovelw.list_workers();
    craftsmen.list_workers();
    hammerw.list_workers();
    diy.list_workers();

    shovelw.execute_workday();
    craftsmen.execute_workday();
    hammerw.execute_workday();
    diy.execute_workday();

}

void test_general() {
    Hammer *hammer1 = new Hammer();
    Shovel *shovel1 = new Shovel();

    Worker *bob = new Worker("Bob", Position(1,2,3), Statistic(5));
    Worker *anna = new Worker("Anna", Position(3,1,6), Statistic(3));
        
    Workshop<Hammer> *diy = new Workshop<Hammer>("DIY");
    diy->register_worker(anna);

    bob->take_tool(shovel1);
    bob->take_tool(hammer1);
    anna->take_tool(hammer1);
    Workshop<Shovel> *craftsmen = new Workshop<Shovel>("Craftsmen");
    craftsmen->register_worker(bob);
    diy->register_worker(bob);
    diy->register_worker(anna);

    craftsmen->execute_workday();
    diy->execute_workday();

    craftsmen->list_workers();
    diy->list_workers();

    delete hammer1;
    delete shovel1;
    delete bob;
    delete anna;
    delete diy;
    delete craftsmen;
}


int main() {

    try {
        test_composition();
        test_aggregation();
        test_inherence();
        test_association();
        test_general();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
