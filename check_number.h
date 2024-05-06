#pragma once
#include <iostream>

inline int check_number( std::string num) {

    for (size_t i = 0; i < num.length(); i++)
    {
        if (!isdigit(num[i]))
            throw std::invalid_argument("You should enter number!");
    } 
    return stoi(num);
}