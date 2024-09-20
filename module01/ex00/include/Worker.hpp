#ifndef WORKER_HPP
#define WORKER_HPP

#include <vector>
#include <exception>
#include <iostream>
#include <iomanip>
#include "Position.hpp"
#include "Statistic.hpp"
#include <list>
#include <set>

class   ATool;

template <class T>
class	Workshop;

class	BaseWorkshop;

class Worker {
    private:
        std::string                 name;
        Position                    coordonnee;
        Statistic                   stat;
        std::set<ATool*>        tools;
        std::list<BaseWorkshop *>     workshops;
        bool tool_exists(ATool& tool);

        template<class T>
        bool    workshop_exists(Workshop<T>& workshop) {
            if (this->workshops.size() > 0) {
                std::list<BaseWorkshop*>::iterator	it;
                for (it = this->workshops.begin(); it != this->workshops.end(); ++it) {
                    if ((*it) == &workshop) {
                        return (true);
                    }
                }
            }
            return (false);
        }
        
        template<class T>
        void	register_to_workshop(Workshop<T>& workshop) {
            if (!this->workshop_exists(workshop)) {
                this->workshops.push_back(&workshop);
                std::cout << this->name << " registered to " << *workshop.get_title() << std::endl;
            }
        }

        template<class T>
        void	leave_workshop(Workshop<T>& workshop) {
            std::list<BaseWorkshop*>::iterator	it;
            for (it = this->workshops.begin(); it != this->workshops.end(); ++it) {
                if ((*it) == &workshop) {
                    this->workshops.erase(it);
                    std::cout << this->name << " left " << *workshop.get_title() << std::endl;
                    break ;
                }
            }
        }

        template<class T>
        T   *get_tool() {
            for (std::set<ATool *>::iterator it = tools.begin(); it != tools.end(); it++) {
                T	*ret = dynamic_cast<T *> (*it);
                if (ret) {
                    return ret;
                }
            }
            return nullptr;
        }

        void    leave_all_workshops();
        void    leave_all_tools();
        void    work(ATool& tool);


        template <class T>
        friend class Workshop;

    public:
		Worker(Position position, Statistic stat);
		Worker(std::string name, Position position, Statistic stat);
		~Worker();
        const std::string*    get_name();
        void	take_tool(ATool& tool);
		void	remove_tool(ATool& tool);
};

#endif
