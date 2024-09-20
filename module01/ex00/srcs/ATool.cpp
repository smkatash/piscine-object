#include "ATool.hpp"
#include "Worker.hpp"

void	ATool::give_to_worker(Worker* worker) {
	if (this->worker != nullptr) {
        this->worker->remove_tool(*this);
    }
	this->worker = worker;
}

void	ATool::take_away_from_worker() {
    this->worker = nullptr;
}
