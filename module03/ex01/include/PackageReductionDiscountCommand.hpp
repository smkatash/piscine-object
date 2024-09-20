#ifndef PACKAGE_REDUCTION_DISCOUNT_COMMAND_HPP
#define PACKAGE_REDUCTION_DISCOUNT_COMMAND_HPP
#include "Command.hpp"

class PackageReductionDiscountCommand: public Command {
    public:
        PackageReductionDiscountCommand(int id, const std::string& date, const std::string& client) : Command(id, date, client) {}
		~PackageReductionDiscountCommand() {}
		double	get_total_price() {
			double price = Command::get_total_price();
            if (price >= 150) {
                std::cout << "Applying Package discount!"<< std::endl;
                return price - 10;
            }
            return price;
		}
};

#endif
