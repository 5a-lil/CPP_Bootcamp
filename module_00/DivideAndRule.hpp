
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <exception>

#pragma once

class Bank
{
	// Exceptions
		// Error-exceptions
		class OutOfRangeIndex : public std::exception
		{
			public:
                const char* what() const throw ();
		};
		class NotCorrectId : public std::exception
		{
			public:
                const char* what() const throw ();
		};
		class IdAlreadyExists : public std::exception
		{
			public:
                const char* what() const throw ();
		};
		class IdNotRegistered : public std::exception
		{
			public:
                const char* what() const throw ();
		};
		class LoanBankNotEnoughLiquidity : public std::exception
		{
			public:
                const char* what() const throw ();
		};
		class LoanAccountNotEnoughFunds : public std::exception
		{
			public:
                const char* what() const throw ();
		};

	private:
		// Account-class
		class Account
		{
			private:
				// Attributes
				int _id;
				double _value;

			public:
				// Constructors/Destructor
				Account(int id, double value);

				// Operator-overloading
				friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
				{
					p_os << "[" << p_account._id << "] - [" << p_account._value << "]";
					return (p_os);
				}

				// Getters/Setters
				const int& getId();
				const double& getValue();

				// General-methods
				void log();
		};
		
		// Structs
			// []-bank-operator-overloading-find-if-third-argument
			struct equalIds
			{
				int _comp;

				// Constructors/Destructor
				equalIds(int comp);

				// General-methods
				bool operator () (Account *_);
			};

		// Attributes
		double _liquidity;
		std::vector<Account *> _clientAccounts;

	public:
		// Constructors/Destructor
		Bank();
		~Bank();

		// Operator-overloading
		friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
		{
			p_os << "Bank informations : " << std::endl;
			p_os << "Liquidity : " << p_bank._liquidity << std::endl;
			for (auto &clientAccount : p_bank._clientAccounts)
       			p_os << *clientAccount << std::endl;
			return (p_os);
		}

		Account*& operator [] (int id);

		// Getters/Setters
		const double& getLiquidity();
		const std::vector<Account *>& getClientAccounts();

		// General-methods
		void logBank();
			// Accounts-manipulation-methods
				// Create-method
				void createAccount(int id, int value);
				
				// Delete-method
				void deleteAccount(int id);
				
				// Modify-methods
					// Modify-add-money-method
					void modifyAccount_addMoney(int id, double money_to_add);

					void modifyAccount_removeMoney(int id, double money_to_remove);

					void modifyAccount_giveLoan(int id, double loan_value);

				// Log-method
				void logAccount(int id);
			
};