#include "Worker.hpp"
#include "ATool.hpp"
#include "Workshop.hpp"

Worker::Worker(Position position, Statistic stat): name("Worker"), coordonnee(position), stat(stat) {
    std::cout << name << " is created.\n";
}
Worker::Worker(std::string name, Position position, Statistic stat): name(name), coordonnee(position), stat(stat) {
    std::cout << name << " is created.\n";
}

Worker::~Worker() {
    std::cout << name << " is destroyed.\n";
    this->leave_all_tools();
    this->leave_all_workshops();
}

void    Worker::leave_all_tools() {
    if (this->tools.size() > 0) {
        std::set<ATool*>::iterator	it;
        for (it = this->tools.begin(); it != this->tools.end(); ++it) {
            std::cout << " Here 1\n";
            this->remove_tool(*(*it));
            std::cout << " Here 2\n";
            if (this->tools.size() == 0) {
                break;
            }
            std::cout << " Here 3\n";
        }

    }
}

void    Worker::leave_all_workshops() {
    if (this->workshops.size() > 0) {
        std::list<BaseWorkshop*>::iterator	it;
        std::cout << " Here.\n";
        for (it = this->workshops.begin(); it != this->workshops.end(); ++it) {
            (*it)->release_worker(*this);
            if (this->workshops.size() == 0) {
                break;
            }
        }

    }
}

bool    Worker::tool_exists(ATool& tool) {
    if (this->tools.size() > 0) {
        std::set<ATool*>::iterator	it;
        for (it = this->tools.begin(); it != this->tools.end(); ++it) {
            if ((*it) == &tool) {
                return (true);
            }
        }
    }
    return (false);
}

void    Worker::work(ATool& tool) {
	std::set<ATool*>::iterator	it;
    for (it = this->tools.begin(); it != this->tools.end(); ++it) {
        if ((*it) == &tool) {
            std::cout << this->name << " is starting work...\n";
            (*it)->use();
            break;
        }
    }
}

const std::string*    Worker::get_name() { return &this->name; }

void	Worker::take_tool(ATool& tool) {
    if (!this->tool_exists(tool)) {
	    tool.give_to_worker(this);
        this->tools.insert(&tool);
        std::cout << this->name << " took a tool\n";
    }
}

void	Worker::remove_tool(ATool& tool) {
	std::set<ATool*>::iterator	it;
    for (it = this->tools.begin(); it != this->tools.end(); ++it) {
        if ((*it) == &tool) {
            (*it)->take_away_from_worker();
            this->tools.erase(it);
            std::cout << this->name << " removed a tool\n";
            break;
        }
    }
}
