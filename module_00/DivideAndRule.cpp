#include <iostream>
#include <vector>
class Bank
{
	// Const-macros
	#define HASHMAP_SIZE 1
		// Error-macros
		#define ERROR_NOT_CORRECT_ID std::cerr << "BANK SYSTEM ERROR: account creation failed because new accounts id is negative" << std::endl;
		#define ERROR_ID_ALREADY_EXISTS std::cerr << "BANK SYSTEM ERROR: account creation failed because new accounts id already exists" << std::endl;
		#define ERROR_ID_NOT_REGISTERED std::cerr << "BANK SYSTEM ERROR: account with id " << id << " doesnt exist" << std::endl;
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
			ERROR_NOT_CORRECT_ID \
			return; \
		} \
		std::vector<Account *>::const_iterator it_begin = this->_clientAccounts.begin(); \
		std::vector<Account *>::const_iterator it_end = this->_clientAccounts.end(); \
		for (std::vector<Account *>::const_iterator account = it_begin; account < it_end; account++) \
			if ((*account)->getId() == id) \
				callback

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

				// General-methods
				void log() { ACCOUNT_LOG }
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
		const std::vector<Account *>& getClientAccounts() { return this->_clientAccounts; }

		// General-methods
			// Accounts-manipulation-methods
				// Create-method
				void createAccount(int id, int value)
				{	
					// Error-check-if-Account-already-exists
					ITER({
						ERROR_ID_ALREADY_EXISTS
						return; 
					})

					// Creating-and-adding-the-new-Account-to-the-bank
					Account *newAccount = new Account(id, value);
					this->_clientAccounts.push_back(newAccount);
					SUCCESS_createAccount
				}
				
				// Delete-method
				void deleteAccount(int id)
				{
					// Finding-the-Account-and-if-not-found-then-error 
					ITER({
						this->_clientAccounts.erase(account);
						SUCCESS_deleteAccount
						return;
					})

					// Account-not-registered
					ERROR_ID_NOT_REGISTERED
				}
				
				// Modify-methods
					// Modify-add-money-method
					void modifyAccount_addMoney(int id, int money_to_add)
					{
						// Finding-the-Account-and-if-not-found-then-error 
						ITER({
							const_cast<int&>((*account)->getValue()) += money_to_add;
							SUCCESS_modifyAccount
							return;
						})

						// Account-not-registered
						ERROR_ID_NOT_REGISTERED
					}

				// Log-method
				void logAccount(int id)
				{
					// Finding-the-Account-and-if-not-found-then-error 
					ITER({
						(*account)->log();
						return;
					})

					// Account-not-registered
					ERROR_ID_NOT_REGISTERED
				}
};

int main()
{
	Bank bank;

	// Account-creation-tests
	std::cout << "---- Account-creation-tests ----" << std::endl;
	bank.createAccount(-2, 100);
	bank.createAccount(0, 100);
	bank.createAccount(0, 100);
	bank.createAccount(2, 100);

	// Account-delete-tests
	std::cout << "---- Account-delete-tests ----" << std::endl;
	bank.deleteAccount(5);
	bank.deleteAccount(0);
	bank.deleteAccount(2);
	bank.deleteAccount(2);

	// Account-modify-tests
	std::cout << "---- Account-modify-tests ----" << std::endl;
	bank.createAccount(0, 100);
	bank.logAccount(0);
	bank.modifyAccount_addMoney(0, 500);
	bank.logAccount(0);

	return (0);
}
