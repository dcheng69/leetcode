#include <iostream>
#include <vector>
#include <string>
#include "PrintX.h"
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> i_vec{3, 4, 2};
    string name{"vector"};
    Print(name, i_vec);

    return 0;
}
