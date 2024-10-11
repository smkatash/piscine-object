#include "TrainDispatcher.hpp"
#include <iostream>
#include <stdexcept>

int main() {
    TrainDispatcher dispatcher;
    try {
        dispatcher.loadNetworkData("input/network.txt");
        dispatcher.loadTrainData("input/trains.txt");
        dispatcher.output();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
