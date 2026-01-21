#include "Vector2.hpp"

int main()
{
    std::map<Vector2, bool> my_map;
    Vector2 vec(1, 2);
    my_map[vec] = true;
    std::cout << my_map[vec] << std::endl;
    vec.setX(5);
    std::cout << my_map[vec] << std::endl;
}