#include "BankApp.hpp"

#include <stdexcept>
#include <iostream>

BankApp::BankApp(const std::vector<double>& accounts): _accounts(accounts){}

double BankApp::getAmount(const int& accountId) const{
	if (accountId < 0 || _accounts.size() == 0 || accountId >= static_cast<int>(_accounts.size())){
		throw std::invalid_argument("Index out of bounds");
	}
	return _accounts[accountId];
}

void BankApp::depositAmount(const double& depositAmount, const int& accountId) const {
	if (accountId < 0 || _accounts.size() == 0 || accountId >= static_cast<int>(_accounts.size())){
		throw std::invalid_argument("Index out of bounds");
	}
	_accounts[accountId] += depositAmount;
}

void BankApp::withDrawAmount(const double& withDrawAmount, const int& accountId) const {
	if (accountId < 0 || _accounts.size() == 0 || accountId >= static_cast<int>(_accounts.size())){
		throw std::invalid_argument("Index out of bounds");
	}
	const auto currAmount = _accounts[accountId];
	if(currAmount < withDrawAmount){
		throw std::invalid_argument("WithDraw amount greater than current balance");
	}
	_accounts[accountId] -= withDrawAmount;
}

