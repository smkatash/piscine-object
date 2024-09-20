#include "Workshop.hpp"

template<class T>
Workshop<T>::Workshop(std::string title): title(title) {}

template<class T>
Workshop<T>::~Workshop() {}



template<class T>
void    Workshop<T>::register_worker(Worker &worker) {
    if (!this->worker_registered(worker)) {
        T* tool = worker.get_tool<T>();
        if (tool) {
            worker.register_to_workshop(*this);
            this->workers.push_back(&worker);
            std::cout << this->title << " registered " << *worker.get_name() << std::endl;
        } else {
            std::cerr << *worker.get_name() << " does not have a proper tool!\n";
        }
    }
}

template<class T>
void    Workshop<T>::release_worker(Worker &worker) {
    std::list<Worker*>::iterator it;
    for (it = this->workers.begin(); it != this->workers.end(); ++it){
        if ((*it) == &worker) {
            (*it)->leave_workshop(*this);
            std::cout << this->title << " released " << *worker.get_name() << std::endl;
            this->workers.erase(it);
            break;
        }
    }
}

template<class T>
const std::string*    Workshop<T>::get_title() { return &this->title; }

template<class T>
void    Workshop<T>::execute_workday() {
    if (this->workers.size() > 0) {
        std::cout << "Workday has started...\n";
        std::list<Worker*>::iterator it;
        for (it = this->workers.begin(); it != this->workers.end(); ++it){
            T* tool = (*it)->get_tool<T>();
            if (tool) {
                (*it)->work(tool);
            } else {
                std::cerr << *(*it)->get_name() << " has lost the tool!\n";
            }

        }
        return ;
    }
    std::cout << ("No workers in the workshop.\n");
}
