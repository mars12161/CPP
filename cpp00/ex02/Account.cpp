/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:26:31 by mschaub           #+#    #+#             */
/*   Updated: 2023/03/08 20:40:43 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void    Account::_displayTimestamp() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 80, "[%Y%m%d_%H%M%S] ", timeinfo);
    std::string str(buffer);
    std::cout << str;
}

Account::Account(int initial_deposit) {
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
    this->_accountIndex = Account::_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account() {
    Account::_nbAccounts--;
    Account::_totalAmount -= this->_amount;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int Account::getNbAccounts() {
    return (Account::_nbAccounts);
}

int Account::getTotalAmount() {
    return (Account::_totalAmount);
}

int Account::getNbDeposits() {
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals() {
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void    Account::makeDeposit(int deposit) {
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    this->_amount += deposit;
    this->_nbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

int Account::checkAmount() const {
    return (this->_amount);
}

void   Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "p_amount:" << _amount << ";" << "withdrawal" << std::flush;
	if (withdrawal > checkAmount())
	{
		std::cout << "not enough money" << std::endl;
		return false;
	}
	std::cout << withdrawal << ";" << std::flush;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	std::cout << "amount:" << _amount << ";" << "nb_deposit:" << _nbDeposits << std::endl;
	return true;
}