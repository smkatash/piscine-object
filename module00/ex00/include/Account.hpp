#include <iostream>
#include "BankException.hpp"

class Account
{
	private:
        int _id;
        int _value;
		int	_taken_loan;

    public:
        Account(void);
		Account(int id, int value);
		Account(const Account &Parent);
		~Account(void);

        void	set_value(int value);
        void	set_id(int id);
        const int&		get_value() const;
        const int&		get_id() const;

		void	deposit(int amount);
		void	withdraw(int amount);
		int		take_loan(int amount);
		int		repay_loan(int amount);


	friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
	{
		p_os << "[" << p_account._id << "] - [" << p_account._value << "] - [" << p_account._taken_loan << "]";
		return (p_os);
	}
};