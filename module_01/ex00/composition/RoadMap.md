Simple class with two other objects as composition

Theory: composition relationship -> a complex class has simple class objects that are managed only by the composite class

- [x] structure Position
    - [x] int _x, _y, _z

- [x] structure Statistic
    - [x] int _level, _exp attributes
    - [x] constructors: () (int level, int exp)
    - [x] destructor

- [x] class Worker 
    - [x] Position _coordonnee, Statistic _stat
    - [x] constructors
        - [x] ()
        - [x] (Position coordonnee, Statistic stat)
    - [x] destructor