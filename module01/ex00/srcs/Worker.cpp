#include "Worker.hpp"
#include "ATool.hpp"
#include "Workshop.hpp"

Worker::Worker(std::string name,int x, int y, int z, int level): name(name), coordonnee(x, y, z), stat(level) {
    std::cout << name << " is created.\n";
}
Worker::Worker(std::string name, Position position, Statistic stat): name(name), coordonnee(position), stat(stat) {
    std::cout << name << " is created.\n";
}

Worker::~Worker() {
    this->leave_all_tools();
    this->leave_all_workshops();
    std::cout << name << " is destroyed.\n";
}

void    Worker::leave_all_tools() {
    if (this->tools.size() > 0) {
        std::set<ATool*>::iterator	it = this->tools.begin();
        while (it != this->tools.end()) {
            ATool* tool = *it;
            ++it;
            tool->take_away_from_worker();
        }
        this->tools.clear();
    }
}

void    Worker::leave_all_workshops() {
    if (this->workshops.size() > 0) {
        std::list<BaseWorkshop*>::iterator it = this->workshops.begin();
        while (it != this->workshops.end()) {
            BaseWorkshop* workshop = *it;
            ++it;
            workshop->release_worker(this);
        }
        this->workshops.clear();
    }
}



bool    Worker::tool_exists(ATool* tool) {
    if (this->tools.size() > 0) {
        std::set<ATool*>::iterator	it;
        for (it = this->tools.begin(); it != this->tools.end(); ++it) {
            if ((*it) == tool) {
                return (true);
            }
        }
    }
    return (false);
}

void    Worker::work(ATool* tool) {
	std::set<ATool*>::iterator	it;
    for (it = this->tools.begin(); it != this->tools.end(); ++it) {
        if ((*it) == tool) {
            std::cout << this->name << " is starting work...\n";
            (*it)->use();
            break;
        }
    }
}

const std::string&    Worker::get_name() const { return this->name; }

void	Worker::take_tool(ATool* tool) {
    if (!this->tool_exists(tool)) {
	    tool->give_to_worker(this);
        this->tools.insert(tool);
        std::cout << this->name << " took a tool\n";
    }
}

void	Worker::remove_tool(ATool* tool) {
	std::set<ATool*>::iterator	it;
    for (it = this->tools.begin(); it != this->tools.end(); ++it) {
        if ((*it) == tool) {
            (*it)->take_away_from_worker();
            this->tools.erase(it);
            std::cout << this->name << " removed a tool\n";
            break;
        }
    }
}

void	Worker::remove_destroyed_tool(ATool* tool) {
	std::set<ATool*>::iterator	it;
    for (it = this->tools.begin(); it != this->tools.end(); ++it) {
        if ((*it) == tool) {
            this->tools.erase(it);
            std::cout << this->name << " removed a tool\n";
            break;
        }
    }
}

