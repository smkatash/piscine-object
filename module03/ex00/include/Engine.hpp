#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <iostream>

class Engine {
    private:
        bool    _on;
    public:
        Engine(): _on(false) {}
        ~Engine() {}
        void    start() {
            if (!this->_on) {
                this->_on = true;
                std::cout << "Starting engine.\n";
            }
        }
        void    stop() {
            if (this->_on) {
                this->_on = false;
                std::cout << "Stopping engine.\n";
            }
        }
};  

#endif
