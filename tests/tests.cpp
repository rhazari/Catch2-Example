/*
 * Framework Set-up
*/

#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif

#include "catch.hpp"

/*
 * Necessary user header files and library includes
*/

#include "BankApp.hpp"
/*
 * Test cases
*/

TEST_CASE("Bank Account app getAmount()") {
	std::vector<double> accounts = {1001, 2002, 3002, 4001};
	BankApp bankApp(accounts);

	REQUIRE(accounts.size() == 4);

	SECTION("Negative index should throw") {
		CHECK_THROWS(bankApp.getAmount(-1));
	}

	SECTION("Index greater than account size should throw") {
		CHECK_THROWS(bankApp.getAmount(4));
	}

	SECTION("Should fetch the amount for account id 1") {
		REQUIRE(bankApp.getAmount(1) == 2002);
	}
}

TEST_CASE("Bank Account app depositAmount()") {
    std::vector<double> accounts = {1001, 2002, 3002, 4001};
    BankApp bankApp(accounts);

	SECTION("Should fetch the amount for account id 1") {
		CHECK_NOTHROW(bankApp.depositAmount(200, 1));
		REQUIRE(bankApp.getAmount(1) == 2202);
	}
}

TEST_CASE("Bank Account app withDrawAmount()") {
    std::vector<double> accounts = {1001, 2002, 3002, 4001};
    BankApp bankApp(accounts);

	SECTION("Should fetch the amount for account id 1") {
		CHECK_NOTHROW(bankApp.withDrawAmount(200, 0));
		REQUIRE(bankApp.getAmount(0) == 801);
	}

	SECTION("Withdraw amount greater than balance") {
		CHECK_THROWS(bankApp.withDrawAmount(2001, 0));
	}
}