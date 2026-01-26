Make a Graph class that can place Vector2 objects and display the graph

- [x] Create a contener Vector2
    - [x] two components x and y of type float
    - [x] getters and setters
    - [x] make a compare operator for std::less used by std::map default value for third template parameter
        - [x] "norm" method to get a Vector2 length with the center of the graph as the other point
    - [x] comments
- [x] Create a class Graph
    - [x] attribute size and attribute list of Vector2 for the graph points
    - [x] can place some Vector2 as points
    - [x] once every points added into it, you must output it on screen, via an ascii art
    - [ ] output goes to png file
    - [ ] add a line feature
    - [x] read an input file containing a list of points
    - [ ] comments
- [x] you must be able to explain the decision you made over encapsulation.
- [x] integrate exceptions for constructor and out of bounds errors
- [x] vector2 must contain an attribute representing x and y.
- [x] user must be allow to add a new Vector2 onto the Graph
- [x] user must be able to output the content of the graph onto the console in a graph-like form

Tests:
Graph class:
- constructor negative or out of bounds or > 10 or <= 0 exceptions
- should not be able to change private attr
- test with floats as values
