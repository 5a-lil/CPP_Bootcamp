Build a correct bank and accounts system with correct and logic encapsulation

Requirements:
Subject explicit:
- [x] The bank must receive 5% of each money inflow on these client accounts
- [x] The accounts must never have two identical IDs
- [x] The attributes of the structures must not be modifiable from the outside
- [x] The bank must be able to create, delete and modify the accounts of these customers
 - [x] create
 - [x] delete
 - [x] modify
- [x] The bank must be able to give a loan to a customer, within the limits of its funds
- [x] It must be impossible to add money to a client account without going through the bank
- [x] If it makes sense, the creation of a Getter and a Setter is mandatory. Getter(s) by copy will not be accepted
- [x] If it makes sense, the creation of a const Getter is mandatory. const Getter(s) by copy will not be accepted
- [x] You can’t create any other methods than const getters in Account structure
- [x] The Account structure must be internal to the Bank structure.
- [x] The Bank structure must contain an operator[] to get an account by it’s ID, but you aren’t allow to make a while or a for loop to find the account corresponding to such ID
 - [x] Learn functors
- [x] The error management must be done via throw, and the main must handle those
errors

Personal explicit:
- [ ] Make a good main in a different file
- [x] Make the Makefile