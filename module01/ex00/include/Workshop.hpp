#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP
#include <list>
#include <exception>
#include <iostream>
#include "Worker.hpp"
#include "Position.hpp"
#include "Statistic.hpp"

class   Worker;

class BaseWorkshop {
	public:
		virtual void    register_worker(Worker &worker) = 0;
        virtual void    release_worker(Worker &worker) = 0;
		virtual 		~BaseWorkshop() {};
};

template<class T>
class Workshop: public BaseWorkshop {
    private:
        std::string title;
        std::list<Worker*> workers;
        bool worker_registered(Worker &worker) {
            std::list<Worker*>::iterator it;
            for (it = this->workers.begin(); it != this->workers.end(); ++it){
                if ((*it) == &worker) {
                    return (true);
                }
            }
            return (false);
        }

    public:
        Workshop(std::string title): title(title) {}
        ~Workshop() {}
        const std::string*    get_title() { return &this->title; }

        void    register_worker(Worker &worker) {
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

        void    release_worker(Worker &worker) {
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
        void    execute_workday() {
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
};

#endif
