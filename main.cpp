#include <iostream>
#include "figure.h"

int main() {

    Circle c1(4), c2(5);
    Figure& f1 = c1;
    Figure& f2 = c2;
    f1 = f2;
    Ellipse e(2, 4);

    std::cout << e;

    return 0;
}
