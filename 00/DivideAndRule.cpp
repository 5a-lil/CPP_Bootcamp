#include <iostream>
#include <vector>

class Bank
{
	private:
		// Account class
		class Account
		{
			private:
				// Attributes
				int _id;
				int _value;

			public:
				// Constructors
				Account(int id, int value) : _id(id), _value(value) {}	

				// Operator-overloading
				friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
				{
					p_os << "[" << p_account._id << "] - [" << p_account._value << "]";
					return (p_os);
				}	

				// Getters/Setters
				int& const getId() { return this->_id; }
				int& const getValue() { return this->_value; }
		};
		// Attributes
		int _liquidity;
		std::vector<Account *> _clientAccounts;

	public:
		// Constructors
		Bank() :
			_liquidity(0)
		{

		}

		// Operator-overloading
		friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
		{
			Account test(1,1);
			test.getValue() = 2;
			p_os << "Bank informations : " << std::endl;
			p_os << "Liquidity : " << p_bank._liquidity << std::endl;
			for (auto &clientAccount : p_bank._clientAccounts)
       		p_os << *clientAccount << std::endl;
			return (p_os);
		}

		// Getters/Setters
		const int& getLiquidity() { return this->_liquidity; }
		const int& const getLiquidity() { return this->_liquidity; }
		const std::vector<Account *>& getClientAccounts() { return this->_clientAccounts; }
		const std::vector<Account *>& const getClientAccounts() { return this->_clientAccounts; }
};

int main()
{
	Account accountA = Account();
	accountA.id = 0;
	accountA.value = 100;

	Account accountB = Account();
	accountB.id = 1;
	accountB.value = 100;

	Bank bank = Bank();
	bank.liquidity = 999;
	bank.clientAccounts.push_back(&accountA);
	bank.clientAccounts.push_back(&accountB);

	bank.liquidity -= 200;
	accountA.value += 400;

	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}
