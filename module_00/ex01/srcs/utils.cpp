#include "./includes.hpp"

size_t count_occurences(std::string& str, char char_to_count)
{
    size_t count = 0;

    std::string::iterator it_begin = str.begin();
    std::string::iterator it_end = str.end();
    for (std::string::iterator it = it_begin; it < it_end; it++)
        if (*it == char_to_count) count++;
    return count;
}