#include "Bank.hpp"

int main()
{
	Bank bank = Bank();
    try {
        std::cout << "1" << std::endl;
        bank.create_account(5, 200);
        bank.create_account(6, 600);
        bank.create_account(10, 20000);
        std::cout << bank << std::endl;
        
        std::cout << "2" << std::endl;
        bank.modify_account_id_by_id(5,7);
        bank.modify_account_value_by_id(7,1000);
        std::cout << bank << std::endl;
        bank.delete_account_by_id(7);
        std::cout << bank << std::endl;

        std::cout << "3" << std::endl;
        bank.provide_loan_to_account(6, 500);
        bank.provide_loan_to_account(10, 300);
        std::cout << bank << std::endl;
        
        std::cout << "4" << std::endl;
        std::cout << *bank[6] << std::endl;
        std::cout << *bank[10] << std::endl;
        std::cout << std::endl;

        std::cout << "5" << std::endl;
        bank.deposit_to_account(6, 500);
        bank.repay_loan_from_account(6, 500);
        std::cout << bank << std::endl;
        bank.repay_loan_from_account(10, 200);
        std::cout << bank << std::endl;
        bank.provide_loan_to_account(10, 10000);
        std::cout << bank << std::endl;

    
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	return (0);
}
