#!/bin/sh

wFlags="-Wall -Wextra -Werror -Wshadow -pedantic"
CC="g++"
INCLUDE="$(pwd)/include"
LIB="$(pwd)/lib/*.cpp"
LINK="$(pwd)/lib"
CSTD="--std=c++20"

echo =========================

echo ACTIVATED FLAGS: $wFlags
echo INCLUDE PATH: $INCLUDE
echo LIB PATH: $LINK
echo C++ STD: $CSTD

echo =========================

$CC $wFlags -O2 -I/$INCLUDE $CSTD -o engine $LIB src/main.cpp -L$LINK -lSDL2
