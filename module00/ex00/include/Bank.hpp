#include <iostream>
#include <vector>
#include <map>
#include <exception>
#include "Account.hpp"


class Bank {
	private:
        int _liquidity;
	    std::map<int, Account*> _client_accounts;
        Account*    _find_account_by_id(int id);
        void        _add_liquidity(int liquidity);
        void        _reduce_liquidity(int liquidity);

    public:
		Bank(void);
		Bank(int liquidity);
		Bank(const Bank &Parent);
		~Bank(void);

        const int&  get_liquidity() const;
        const std::map<int, Account *>&  get_clients() const;
        void        set_liquidity(int liquidity);
        void        create_account(int account_id, int value);
        void        delete_account_by_id(int account_id);
        void        modify_account_id_by_id(int account_id, int newId);
        void        modify_account_value_by_id(int account_id, int new_value);

        void        deposit_to_account(int account_id, int amount);
        void        withdraw_from_account(int account_id, int amount);
        void        provide_loan_to_account(int account_id, int amount);
        void        repay_loan_from_account(int account_id, int amount);
        Account*    operator[](int account_id);

	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
	{
		p_os << "Bank informations : " << std::endl;
		p_os << "Liquidity : " << p_bank.get_liquidity() << std::endl;

        std::map<int,Account*> all_clients = p_bank.get_clients();
        std::map<int,Account*>::iterator it;
        for(it = all_clients.begin(); it != all_clients.end();++it) {
            p_os << *it->second << std::endl;
        }
		return (p_os);
	}

};