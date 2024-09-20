#include "PackageReductionDiscountCommand.hpp"
#include "TuesdayDiscountCommand.hpp"


int main() {
    try {
        Command one = Command(1, "20.09.2024", "Sam Smith");
        TuesdayDiscountCommand two = TuesdayDiscountCommand(2, "21.09.2024", "Bob Johnson");
        PackageReductionDiscountCommand three = PackageReductionDiscountCommand(3, "22.09.2024", "Emily Paris");
        one.list_articles();
        two.list_articles();
        three.list_articles();
        std::cout << "Command: " << one.get_id() << ", price: " << one.get_total_price() << std::endl;
        std::cout << "Command: " << two.get_id() << ", price: " << two.get_total_price() << std::endl;
        std::cout << "Command: " << three.get_id() << ", price: " << three.get_total_price() << std::endl;

        one.add_article("T-Shirt Black", 15.9);
        one.add_article("T-Shirt White", 20.9);
        one.add_article("T-Shirt Yellow", 33.9);
        two.add_article("Shirt Black", 15.9);
        two.add_article("Shirt White", 20.9);
        two.add_article("Shirt Yellow", 33.9);
        three.add_article("Dress Black", 15.9);
        three.add_article("Dress White", 200.9);
        three.add_article("Dress Yellow", 33.9);

        one.list_articles();
        two.list_articles();
        three.list_articles();
        std::cout << "Command: " << one.get_id() << ", price: " << one.get_total_price() << std::endl;
        std::cout << "Command: " << two.get_id() << ", price: " << two.get_total_price() << std::endl;
        std::cout << "Command: " << three.get_id() << ", price: " << three.get_total_price() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
