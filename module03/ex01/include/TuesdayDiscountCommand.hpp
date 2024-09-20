#ifndef TUESDAY_DISCOUNT_COMMAND_HPP
#define TUESDAY_DISCOUNT_COMMAND_HPP
#include "Command.hpp"

class TuesdayDiscountCommand: public Command {
    public:
		TuesdayDiscountCommand(int id, const std::string& date, const std::string& client) : Command(id, date, client) {}
		~TuesdayDiscountCommand() {}

		double get_total_price() {
			double price = Command::get_total_price();
			if (price > 0) {
				std::cout << "Applying Tuesday discount!"<< std::endl;
				return price * 0.9;
			}
			return price;
		}
};

#endif
