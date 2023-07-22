#include "basics.h"
#include <iostream>

using namespace std;

types::integer::integer(int x) : x(x) {}
void types::integer::print() {
    cout << x << "\n";
}
