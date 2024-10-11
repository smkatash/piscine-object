#pragma once
#include <map>
#include <iomanip> 
#include "Speed.hpp"
#include "Rail.hpp"
#include "Scheduler.hpp"

class Scheduler;

class Train {
    private:
        std::string _name;
        Speed       _speed;
        Scheduler* _scheduler;
    public:
        Train(std::string p_name, float p_maxAccelerationForce, float p_maxBrakeForce);
        ~Train();
        const std::string*   getName();
        void    setScheduler(Scheduler* _scheduler);
        void    estimateTime(std::pair<std::vector<Rail*>, float> route);
        void    run(std::pair<std::vector<Rail*>, float> route, std::map<Rail*, float> events);
};
