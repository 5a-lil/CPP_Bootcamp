
#include "DivideAndRule.hpp"

// Exceptions
	// Error-exceptions
	const char* Bank::OutOfRangeIndex::what() const throw ()
	{
		return ("BANK SYSTEM ERROR: invalid index range");
	}

	const char* Bank::NotCorrectId::what() const throw ()
	{
		return ("BANK SYSTEM ERROR: account creation failed because new accounts id is negative");
	}

	const char* Bank::IdAlreadyExists::what() const throw ()
	{
		return ("BANK SYSTEM ERROR: account creation failed because new accounts id already exists");
	}

	const char* Bank::IdNotRegistered::what() const throw ()
	{
		return ("BANK SYSTEM ERROR: account not registered");
	}

	const char* Bank::LoanBankNotEnoughLiquidity::what() const throw ()
	{
		return ("BANK SYSTEM ERROR: not enough bank liquidity to give a loan to account");
	}

	const char* Bank::LoanAccountNotEnoughFunds::what() const throw ()
	{
		return ("BANK SYSTEM ERROR: account doesnt have enough funds");
	}

// Macros
	// Success-macros
	#define SUCCESS_createAccount std::cout << "BANK SYSTEM SUCCESS: account creation with id=" << id << std::endl;
	#define SUCCESS_deleteAccount std::cout << "BANK SYSTEM SUCCESS: account deletion with id=" << id << std::endl;
	#define SUCCESS_modifyAccount std::cout << "BANK SYSTEM SUCCESS: account modification with id=" << id << std::endl;

	// Log-macros
	#define ACCOUNT_LOG std::cout << "BANK SYSTEM LOG ACCOUNT [" << this->_id << "]: funds=" << this->_value << std::endl;

	// Func-macros
	#define ITER(callback) \
		/* Args-error-checks */ \
		if (id < 0) { \
			throw NotCorrectId(); \
			return; \
		} \
		std::vector<Account *>::const_iterator it_begin = this->_clientAccounts.begin(); \
		std::vector<Account *>::const_iterator it_end = this->_clientAccounts.end(); \
		for (std::vector<Account *>::const_iterator account = it_begin; account < it_end; account++) \
			if ((*account)->getId() == id) \
				callback

// Account-class
	// Constructors/Destructor
	Bank::Account::Account(int id, double value) : _id(id), _value(value) {}

	// Getters/Setters
	const int& Bank::Account::getId() { return this->_id; }
	const double& Bank::Account::getValue() { return this->_value; }

	// General-methods
	void Bank::Account::log() { ACCOUNT_LOG }

// Structs
	// []-bank-operator-overloading-find-if-third-argument
	// Constructors/Destructor
	Bank::equalIds::equalIds(int comp): _comp(comp) {}

	// General-methods
	bool Bank::equalIds::operator () (Account *_) { return _->getId() == this->_comp; }
	
// Constructors/Destructor
Bank::Bank() : _liquidity(0) {}

Bank::~Bank() 
{
	std::vector<Account *>::iterator it_begin = this->_clientAccounts.begin();
	std::vector<Account *>::iterator it_end = this->_clientAccounts.end();
	for (std::vector<Account *>::iterator account = it_begin; account < it_end; account++)
		delete *account;
}

// Operator-overloading
Bank::Account*& Bank::operator [] (int id)
{
	std::vector<Account *>::iterator res; 
	res = std::find_if(this->_clientAccounts.begin(), this->_clientAccounts.end(), equalIds(id));
	if (res == this->_clientAccounts.end())
		throw OutOfRangeIndex();
	return *res;
}

// Getters/Setters
const double& Bank::getLiquidity() { return this->_liquidity; }
const std::vector<Bank::Account *>& Bank::getClientAccounts() { return this->_clientAccounts; }

// General-methods
void Bank::logBank() { std::cout << *this << std::endl; }
	// Accounts-manipulation-methods
		// Create-method
		void Bank::createAccount(int id, int value)
		{	
			// Error-check-if-Account-already-exists
			ITER({
				throw IdAlreadyExists();
				return;
			})

			// Creating-and-adding-the-new-Account-to-the-bank
			Account *newAccount = new Account(id, value);
			this->_clientAccounts.push_back(newAccount);
			SUCCESS_createAccount
		}
				
		// Delete-method
		void Bank::deleteAccount(int id)
		{
			// Finding-the-Account-and-if-not-found-then-error 
			ITER({
				delete *account;
				this->_clientAccounts.erase(account);
				SUCCESS_deleteAccount
				return;
			})

			// Account-not-registered
			throw IdNotRegistered();
		}
				
		// Modify-methods
			// Modify-add-money-method
			void Bank::modifyAccount_addMoney(int id, double money_to_add)
			{
				// Finding-the-Account-and-if-not-found-then-error 
				ITER({
					const_cast<double&>((*account)->getValue()) += money_to_add * 0.95;
					this->_liquidity += money_to_add * 0.05;
					SUCCESS_modifyAccount
					return;
				})

				// Account-not-registered
				throw IdNotRegistered();
			}

			void Bank::modifyAccount_removeMoney(int id, double money_to_remove)
			{
				// Finding-the-Account-and-if-not-found-then-error 
				ITER({
					const_cast<double&>((*account)->getValue()) -= money_to_remove;
					SUCCESS_modifyAccount
					return;
				})

				// Account-not-registered
				throw IdNotRegistered();
			}

			void Bank::modifyAccount_giveLoan(int id, double loan_value)
			{
				// Finding-the-Account-and-if-not-found-then-error 
				ITER({
					// Account-funds-and-bank-liquidity-checks
					if (loan_value > this->_liquidity) { throw LoanBankNotEnoughLiquidity(); return; }
					if ((*account)->getValue() < loan_value) { throw LoanAccountNotEnoughFunds(); return; }

					// Changing-values
					const_cast<double&>((*account)->getValue()) += loan_value;
					this->_liquidity -= loan_value;
					SUCCESS_modifyAccount
					return;
				})

				// Account-not-registered
				throw IdNotRegistered();
			}

		// Log-method
		void Bank::logAccount(int id)
		{
			// Finding-the-Account-and-if-not-found-then-error 
			ITER({
				(*account)->log();
				return;
			})

			// Account-not-registered
			throw IdNotRegistered();
		}