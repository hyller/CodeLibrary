// function_object.h
// Unary predicate to identify negative values
#pragma once
#include <functional>

template <class T> class is_negative: public std::unary_function<T, bool>
{
  public:
  result_type operator()(T& value)
  {
    return value<0;
  }
};
