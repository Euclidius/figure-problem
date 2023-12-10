#include <iostream>
#include "figure.h"

int main() {

    Circle c1(4), c2(5);
    c1 = c2;

    std::cout << c1;

    return 0;
}
