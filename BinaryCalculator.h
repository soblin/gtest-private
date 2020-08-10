#include <functional>

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
