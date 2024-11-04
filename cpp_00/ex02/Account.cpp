#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

/*
private static fonsiyon ile public static fonsiyon arasıdaki fark nedir ?

*/
//-> static değişkenler nesnelere ait değil sınıfın 
// kendisine ait değişkelerdir
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// static fonksiyonların tanımlamaları
int Account::getNbAccounts( void ) {return _nbAccounts;}

int Account::getTotalAmount( void ) {return _totalAmount ;}

int Account::getNbDeposits( void ) {return _totalNbDeposits;}

int Account::getNbWithdrawals( void ) {return _totalNbWithdrawals;}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts
				<< ";total:"<< _totalAmount 
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl; 
}

// yapıcı ve yıkıcılar 
Account::Account(int inital_deposit)
:_accountIndex(_nbAccounts++),_amount(inital_deposit), 
_nbDeposits(0), _nbWithdrawals(0)
{
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl; 
}

Account::~Account(void)
{
	_displayTimestamp();
	static int i = 8;
	std::cout << "index:" << _nbAccounts - i << ";amount:" << _amount << ";closed" << std::endl;
	i--;
}
/////////////////////////////////////////////////////////
static std::string now(void);

void	Account::_displayTimestamp()
{
	std::cout << now();
}
/*
null ve nulptr arasındaki fark nedir ?
localtime ?
time ?
std::stringstream ?
str(); ?
*/
static std::string now(void)
{
	time_t unix_now = time(NULL);				// şu anki zamanı unix zaman damgası ile alır
	std::tm *l_now = localtime(&unix_now);		// unix zaman damgasını gün ay yıl gibi parçalayıp tm sructında döner

	std::stringstream ss;
	ss	<< "["
		<< (l_now->tm_year + 1900)
		<< std::setfill('0') << std::setw(2) << l_now->tm_mon
		<< std::setfill('0') << std::setw(2) << l_now->tm_mday
		<< "_"
		<< std::setfill('0') << std::setw(2) << l_now->tm_hour
		<< std::setfill('0') << std::setw(2) << l_now->tm_min
		<< std::setfill('0') << std::setw(2) << l_now->tm_sec
		<< "]";
	std::string time = ss.str();
	return (time);
}

void Account::makeDeposit(int deposit)
{
	int p_amount = checkAmount();
	_amount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;

	_displayTimestamp();
	std::cout	<< "index:" <<_accountIndex
				<< ";p_amount:"	<< p_amount
				<< ":deposit:"	<< deposit
				<< ":amount:"	<< _amount
				<< ":nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount = checkAmount();
	
	_displayTimestamp();
	std::cout	<< "index:" <<_accountIndex
				<< ";p_amount:"	<< p_amount
				<< ":withdrawal:";
	if (p_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_totalNbWithdrawals ++;
		_nbWithdrawals ++;

		std::cout	<< withdrawal
					<< ";amount:" << _amount
					<< ";nb_withdrawal:" << _nbWithdrawals
					<< std::endl;
		return (true);
	}
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const 
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}