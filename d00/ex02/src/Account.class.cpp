/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:18:01 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/07 19:45:07 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.class.hpp"

int Account::_nbAccounts = 0;
int Account::_nbCheckAmount = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit):
_accountIndex(this->_nbAccounts),
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
		<< ";amount:" << this->_amount \
		<< ";created" << std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	return;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
		<< ";amount:" << this->_amount \
		<< ";closed" << std::endl;
	Account::_nbAccounts--;
	return;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() \
		<< ";total:" << Account::getTotalAmount() \
		<< ";deposits:" << Account::getNbDeposits() \
		<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
	return;
}

void Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
		<< ";p_amount:" << this->_amount \
		<< ";deposit:" << deposit \
		<< ";amount:" << (this->_amount + deposit) \
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	return;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
		<< ";p_amount:" << this->_amount \
		<< ";withdrawal:";
	if (this->checkAmount() - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		std::cout << withdrawal \
			<< ";amount:" << (this->_amount - withdrawal) \
			<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		this->_amount -= withdrawal;
		return (true);
	}
}

int Account::checkAmount(void) const
{
	Account::_nbCheckAmount++;
	return (this->_amount);
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
		<< ";amount:" << this->_amount \
		<< ";deposits:" << this->_nbDeposits \
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
	return;
}

void Account::_displayTimestamp(void)
{
	time_t t = time(NULL);
	struct tm *now = localtime(&t);

	std::cout << std::setfill('0') \
		<< "[" << (now->tm_year + 1900) \
		<< std::setw(2) << (now->tm_mon + 1) \
		<< std::setw(2) << now->tm_mday << "_" \
		<< std::setw(2) << now->tm_hour \
		<< std::setw(2) << now->tm_min \
		<< std::setw(2) << now->tm_sec << "] ";
	return;
}
