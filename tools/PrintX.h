#ifndef PRINTX_H_
#define PRINTX_H_
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

template<typename T>
std::string PrintToString(const std::string name, const T& vec) {
    std::stringstream ss;
    if (vec.size() != 0) {
        ss << name << ":\t";
        for (auto const& n : vec)
            ss << n << ' ';
        ss << std::endl;
    }
    return ss.str();
}

template<typename T>
void Print(const std::string name, const T& vec) {
    std::cout << PrintToString(name, vec);
}

#endif
