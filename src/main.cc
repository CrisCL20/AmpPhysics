/**
 * @brief For testing purposes
 */

#include "vectors.h"
#include <iostream>

using namespace std;
using namespace Vector;

int main() {

    vector<double> r(1.0,2.0);
    vector<double> w(2.5,1.2);

    vector<double> p = r + w;
    double k = r * w;

    p.print();
    r.unitary().print();

    vector<double> x = r * 0.1;
    x.print();

    cout << k << endl;

    return 0;

}