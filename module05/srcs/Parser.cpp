#include "Parser.hpp"

void    NetworkParser::parseData(const std::string& filepath) {
    std::ifstream	file(filepath.data());
	std::string		line;

	if (!file.is_open()){
		std::cerr << "Error opening file : " << filepath << std::endl;
		exit(1) ;
	}
	while (getline(file, line)) {
		std::istringstream	iss(line);
		std::string			token;

		iss >> token;
		if (token == NODE){
			iss >> token;
			if (!token.empty()) {
				Scheduler::getInstance()->addNode(new Node(token));
			}
		} else if (token == EVENT) {
			std::string name;
			float	probability, duration;
			iss >> name >> token;
			probability = std::stof(token);
			if (probability <= 0.f) {
				std::cerr << "Event can not happen. Skipping line.\n";
				continue ;
			}

			iss >> token;
			duration = parseDuration(token);
			if (!duration) {
				std::cerr << "Invalid duration. Skipping line.\n";
				continue;
			}
			iss >> token;
			Node* node = Scheduler::getInstance()->getNode(token);
			if (!name.empty() && probability && duration && node) {
				Scheduler::getInstance()->addEvent(new Event(name, probability, duration, node));
			}
		} else if (token == RAIL) {
			std::string	departFrom, arriveAt;
			float	length;
			iss >> departFrom >> arriveAt >> token;
			length = std::stof(token);
			if (!length) {
				std::cerr << "Invalid length. Skipping line.\n";
				continue;
			}
			Node* a = Scheduler::getInstance()->getNode(departFrom);
			Node* b = Scheduler::getInstance()->getNode(arriveAt);
			if (a && b && length) {
				Scheduler::getInstance()->addRail(new Rail(a, b, length));
			}
		} else {
			throw std::runtime_error("Parser: Unknown token");
		}
	}
}

float	NetworkParser::parseDuration(const std::string& token) {
    std::map<char, float> timeUnits;
    timeUnits['m'] = 0.0166667f;
    timeUnits['h'] = 1.0f;
    timeUnits['d'] = 24.0f;    

    for (std::map<char, float>::iterator it = timeUnits.begin(); it != timeUnits.end(); ++it) {
        size_t pos = token.find(it->first);
        if (pos != std::string::npos) {
            try {
                std::string sub = token.substr(0, pos);
                return std::atof(sub.c_str()) * it->second;
            } catch (...) {
                std::cerr << "Error processing token: " << token << std::endl;
            }
        }
    }
    return 0.0f;
}

void    TrainCompositionParser::parseData(const std::string& filepath) {
	std::ifstream	file(filepath.data());
	std::string		line;

	if (!file.is_open()){
		std::cerr << "Error opening file : " << filepath << std::endl;
		exit(1) ;
	}
	while (getline(file, line)) {
		std::istringstream	iss(line);
		std::string			token;
		std::string			trainName;
		float				maxAcceleration, maxBrake;
		iss >> trainName;
		iss >> token;
		maxAcceleration = std::stof(token);
		iss >> token;
		maxBrake = std::stof(token);
		if (!trainName.empty() && maxAcceleration && maxBrake) {
			Train* train = new Train(trainName, maxAcceleration, maxBrake);
			if (train) {
				iss >> token;
				Node* a = Scheduler::getInstance()->getNode(token);
				iss >> token;
				Node* b = Scheduler::getInstance()->getNode(token);
				iss >> token;
				float hour = parseDepartureHour(token);
				if (a && b && hour) {
					Scheduler::getInstance()->addTrain(train);
					Scheduler::getInstance()->addTrainComposition(new TrainComposition(train, a, b, hour));
				}
			}
		}

	}
}

float	TrainCompositionParser::parseDepartureHour(const std::string& token) {
    size_t hPos = token.find('h');
    size_t mPos = token.find('m'); 

    if (hPos != std::string::npos) {
        std::string hoursPart = token.substr(0, hPos);
        float hours = std::atof(hoursPart.c_str());

        if (mPos != std::string::npos && mPos > hPos) {
            std::string minutesPart = token.substr(hPos + 1, mPos - hPos - 1);
            float minutes = std::atof(minutesPart.c_str());
            return hours + (minutes / 60.0f);
        }
        return hours;
    }

    return 0.0f;
}