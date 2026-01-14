#include <iostream>
#include <vector>

class Bank
{
	// Const-macros
	#define ERROR_NOT_CORRECT_ID "BANK SYSTEM ERROR: account creation failed because new accounts id is negative"
	#define ERROR_ID_ALREADY_EXISTS "BANK SYSTEM ERROR: account creation failed because new accounts id already exists"

	private:
		// Account-class
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
				const int& getId() { return this->_id; }
				const int& getValue() { return this->_value; }
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
			p_os << "Bank informations : " << std::endl;
			p_os << "Liquidity : " << p_bank._liquidity << std::endl;
			for (auto &clientAccount : p_bank._clientAccounts)
       		p_os << *clientAccount << std::endl;
			return (p_os);
		}

		// Getters/Setters
		const int& getLiquidity() { return this->_liquidity; }
		const int& getLiquidity() const { return this->_liquidity; }
		const std::vector<Account *>& getClientAccounts() { return this->_clientAccounts; }
		const std::vector<Account *>& getClientAccounts() const { return this->_clientAccounts; }

		// General-methods
		//  Accounts-manipulation-methods
		void createAccount(int id, int value)
		{	
			// Args-error-checks
			if (id < 0) {
				std::cout << ERROR_NOT_CORRECT_ID << std::endl;
				return;
			}

			std::vector<Account *>::iterator it_begin = _clientAccounts.begin();
			std::vector<Account *>::iterator it_end = _clientAccounts.end();
			for (std::vector<Account *>::iterator it = it_begin; it < it_end; it++)
				if ((*it)->getId() == id) {
					std::cout << ERROR_ID_ALREADY_EXISTS << std::endl;
					return;
				}
			Account newAccount(id, value);
			this->_clientAccounts.push_back(&newAccount);
		}
};

int main()
{
	Bank bank;

	// Account-creation-tests
	bank.createAccount(-2, 100);
	bank.createAccount(0, 100);
	bank.createAccount(0, 100);
	bank.createAccount(0, 100);

	return (0);
}
