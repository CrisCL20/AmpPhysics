#!/bin/sh

g++ -Wall -Wextra -Werror -Wshadow -pedantic -O2 -I/$(pwd)/include/ --std=c++20 -o engine lib/*.cpp src/main.cc  
