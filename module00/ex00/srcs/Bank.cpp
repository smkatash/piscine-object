#include "Bank.hpp"

Bank::Bank(void): _liquidity(1000) {};
Bank::Bank(int liquidity): _liquidity(liquidity) {};
Bank::~Bank(void) {};
Bank::Bank(const Bank &Parent): _liquidity(Parent._liquidity) {};

Account    *Bank::_find_account_by_id(int account_id) {
    std::map<int, Account*>::iterator it = this->_client_accounts.find(account_id);
    if (it != this->_client_accounts.end()) {
        return it->second;
    }
    return nullptr; 
}

Account* Bank::operator[](int account_id) {
        return this->_find_account_by_id(account_id);
}

void    Bank::_add_liquidity(int liquidity) {
    this->_liquidity += liquidity;
}

void    Bank::_reduce_liquidity(int liquidity) {
    this->_liquidity -= liquidity;
}

const int     &Bank::get_liquidity() const {
    return this->_liquidity;
}

void    Bank::set_liquidity(int liquidity) {
    this->_liquidity = liquidity;
}


void    Bank::create_account(int account_id, int value) {
    if (this->_find_account_by_id(account_id) != nullptr) {
        throw BankException("Account already exists with account_id!");
    }
    Account* new_account = new Account(account_id, value);
    this->_client_accounts.insert(std::make_pair(account_id, new_account));
}

void    Bank::modify_account_id_by_id(int account_id, int newId) {
    Account *current_account = this->_find_account_by_id(account_id);
    if (current_account == nullptr) {
        throw BankException("Account not found");
    }
    this->_client_accounts.erase(account_id);
    current_account->set_id(newId);
    this->_client_accounts[newId] = current_account;
}

void    Bank::modify_account_value_by_id(int account_id, int new_value) {
    Account *current_account = this->_find_account_by_id(account_id);
    if (!current_account) {
        throw BankException("Account not found");
    }
    current_account->set_value(new_value);
}

void    Bank::delete_account_by_id(int account_id) {
    Account* account = this->_find_account_by_id(account_id);
    if (account == nullptr) {
        throw BankException("Account with id does not exist!");
    }
    delete account;
    this->_client_accounts.erase(account_id);
}

void        Bank::deposit_to_account(int account_id, int amount) {
    if (amount <= 0) {
        return;
    }
    Account *current_account = this->_find_account_by_id(account_id);
    if (!current_account) {
        throw BankException("Account not found");
    }
    int inflow = amount * 0.05;
    current_account->deposit(amount - inflow);
    this->_add_liquidity(inflow);
}

void        Bank::withdraw_from_account(int account_id, int amount) {
    if (amount <= 0) {
        return;
    }
    Account *current_account = this->_find_account_by_id(account_id);
    if (!current_account) {
        throw BankException("Account not found");
    }
    current_account->withdraw(amount);
}

void        Bank::provide_loan_to_account(int account_id, int amount) {
    if (amount <= 0) {
        return;
    }
    if (this->_liquidity - amount <= 0) {
        throw BankException("Bank has insufficient liquidity for this loan");
    }
    Account *current_account = this->_find_account_by_id(account_id);
    if (!current_account) {
        throw BankException("Account not found");
    }
    this->_reduce_liquidity(current_account->take_loan(amount));
}

void        Bank::repay_loan_from_account(int account_id, int amount) {
    if (amount <= 0) {
        return;
    }
    Account *current_account = this->_find_account_by_id(account_id);
    if (!current_account) {
        throw BankException("Account not found");
    }
    this->_add_liquidity(current_account->repay_loan(amount));
}

const std::map<int, Account *>&  Bank::get_clients() const {
    return this->_client_accounts;
}
