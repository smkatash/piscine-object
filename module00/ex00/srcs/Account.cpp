#include "Account.hpp"

Account::Account(void): _id(-1), _value(0) {};
Account::Account(int id, int value): _id(id), _value(value) {};
Account::~Account(void) {};
Account::Account(const Account &Parent): _id(Parent._id), _value(Parent._value) {};

const int&     Account::get_id() const {
    return this->_id;
}

const int&     Account::get_value() const {
    return this->_value;
}

void    Account::set_id(int id) {
    this->_id = id;
}

void    Account::set_value(int value) {
    this->_value = value;
}

void    Account::deposit(int amount) {
    if (!amount) {
        throw BankException("Invalid deposit amount");
    }
    this->_value += amount;
}

void    Account::withdraw(int amount) {
    if (this->_value - amount < 0) {
        throw BankException("Insufficient funds or invalid withdrawal amount");
    }
    this->_value -= amount;
}

int    Account::take_loan(int amount) {
    this->_value += amount;
    this->_taken_loan += amount;
    return amount;
}

int    Account::repay_loan(int amount) {
    if (this->_value - amount < 0) {
        throw BankException("Insufficient funds");
    }
    this->_value -= amount;
    if (this->_taken_loan < amount) {
        throw BankException("Invalid loan repayment");
    }
    this->_taken_loan -= amount;
    return amount;
}
