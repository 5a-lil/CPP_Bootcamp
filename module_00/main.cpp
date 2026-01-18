
#include "./DivideAndRule.cpp"

#define DO(callback) \
	try { \
		callback; \
	} catch (std::exception& e) { \
		std::cerr << e.what() << std::endl; \
	} 

int main()
{
	Bank bank;

	// Account-creation-tests
	std::cout << "---- Account-creation-tests ----" << std::endl;
	DO(bank.createAccount(-2, 100))
	DO(bank.createAccount(0, 100))
	DO(bank.createAccount(0, 100))
	DO(bank.createAccount(2, 100))

	// Account-delete-tests
	std::cout << "---- Account-delete-tests ----" << std::endl;
	DO(bank.deleteAccount(5))
	DO(bank.deleteAccount(0))
	DO(bank.deleteAccount(2))
	DO(bank.deleteAccount(2))

	// Account-modify-tests
	std::cout << "---- Account-modify-tests ----" << std::endl;
	DO(bank.createAccount(0, 100))
	DO(bank.logBank())
	DO(bank.modifyAccount_addMoney(0, 5000))
	DO(bank.logBank())
	DO(bank.modifyAccount_giveLoan(0, 250))
	DO(bank.logBank())
	DO(std::cout << *bank[2] << std::endl)
	DO(std::cout << *bank[0] << std::endl)

	return (0);
}
