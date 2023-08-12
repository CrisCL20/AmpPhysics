#!/bin/sh

wFlags="-Wall -Wextra -Werror -Wshadow -pedantic"

g++ $wFlags -O2 -I/$(pwd)/include/ --std=c++20 -o engine lib/*.cpp src/main.cpp -L$(pwd)/lib -lSDL2
