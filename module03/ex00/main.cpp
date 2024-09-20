#include "Car.hpp"


int main() {
    Car bmw;
    try {
        bmw.engine.start();
        bmw.speed.accelerate(30);
        bmw.transmission.shift_gears_up();
        bmw.transmission.shift_gears_up();
        bmw.transmission.shift_gears_up();
        bmw.transmission.shift_gears_down();
        bmw.steering.turn_wheel(30);
        bmw.steering.turn_wheel(20);
        bmw.steering.straighten_wheels();
        bmw.speed.accelerate(60);
        bmw.transmission.reverse();
        bmw.speed.apply_force_on_brakes(10);
        bmw.speed.apply_emergency_brakes();
        bmw.engine.stop();

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
