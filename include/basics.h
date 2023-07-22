#ifndef BASICS_H
#define BASICS_H

namespace types{
    class integer {
        public:
            integer(int n);
            void print();    
        private:
            int x;
    };


}

types::integer::integer(int n) : x(n) {}

#include <iostream>
void types::integer::print() {
    std::cout << x << "\n";
}


#endif