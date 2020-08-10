# Testing Private members and methods in gtest

[![Build Status](https://travis-ci.com/soblin/gtest-private.svg?branch=master)](https://travis-ci.com/soblin/gtest-private)

## TestFriend class

Declare `TestFriend` class for unit testing.

```
class BinaryCalculator {
public:
  BinaryCalculator() {}
  ~BinaryCalculator() {}
  inline void setArg1(int arg) { arg1_ = arg;}
  inline void setArg2(int arg) { arg2_ = arg;}
  void plus() { ans_ = arg1_ + arg2_; }
  void minus() { ans_ = arg1_ - arg2_; }
  void calc(std::function<int(int, int)> op) { ans_ = op(arg1_, arg2_); }

private:
  int arg1_ = -1;
  int arg2_ = -1;
  int ans_ = -1;

#ifdef UTEST
public:
  friend class BinaryCalculatorTestFriend;
#endif
};
```

## From gtest

Implement the `TestFriend` class and access to private fields.

```
#include "BinaryCalculator.h" // includes the above definition
#include "gtest/gtest.h"

class BinaryCalculatorTestFriend : public ::testing::Test {
public:
  int GetAns(BinaryCalculator &calculator){
    return calculator.ans_;
  }
};
```
