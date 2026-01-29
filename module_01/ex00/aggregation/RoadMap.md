Modify the worker class to make it use a shovel with an aggregation relationship if she wants

- [x] Create a structure Shovel, with an attribute numberOfUses.
    - [x] int numberofUses
    - [x] default constructor() numberOfUses = 0
    - [x] use() method
- [x] Modify the class Worker to add a Shovel object, in a way that allows it to be given and taken away.
- [x] Ensure that the Shovel is not deleted in case of deletion of the Worker object.
- [x] Ensure that, if the tool is already given to a worker, giving it to another worker does remove it from the first
- [x] The Shovel must be able to be given to a Worker and then taken away if necessary
- [x] In case of deletion of the Worker, the Shovel must not be destroyed