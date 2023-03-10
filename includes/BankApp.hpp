#pragma once

#include <vector>

class BankApp{
    mutable std::vector<double> _accounts;
public:
    BankApp(const std::vector<double>& accounts);

    double getAmount(const int& account_id) const;

    void depositAmount(const double& depositAmount, const int& accountId) const;

    void withDrawAmount(const double& withDrawAmount, const int& accountId) const;
};