#ifndef ATOOL_HPP
#define ATOOL_HPP
#include <iostream>

class Worker;

class ATool {
    public:
        virtual ~ATool() {};
        virtual void use() = 0;

    protected:
        int     number_of_uses;
        Worker  *worker;
        void	give_to_worker(Worker* worker);
        void	take_away_from_worker();
        friend class Worker;
};


#endif
