Create a Tool abstract class and two derived classes, Hammer and Shovel

- [ ] Worker class
    - [ ] not use Shovel but has Tools
    - [ ] multiple tools, be able to return them
- [x] Create an abstract class Tool.
    - [x] protected int numberOfUses
    - [x] pure virtual method use()
- [x] Make the class Shovel inherit from Tool.
- [x] Create a class Hammer that inherits from Tool.
- [ ] Ensure that tools can be given to a Worker and taken away.
- [ ] Ensure that, if the tool is already given to a worker, giving it to another worker
does remove it from the first