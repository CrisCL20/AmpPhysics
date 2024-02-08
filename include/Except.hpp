#pragma once
#include <stdexcept>

class Except : public std::length_error
{
public:
  Except(const char* err) : std::length_error(err) {}
};
