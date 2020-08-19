#include "BinaryCalculator.h" // includes the above definition
#include "gtest/gtest.h"

class BinaryCalculatorTestFriend : public ::testing::Test {
public:
  int GetAns(BinaryCalculator &calculator){
    return calculator.ans_;
  }
};

TEST_F(BinaryCalculatorTestFriend, test_calc){
  BinaryCalculator calculator;
  calculator.setArg1(1);
  calculator.setArg2(2);

  // test plus
  calculator.plus();
  ASSERT_EQ(GetAns(calculator), 1+2);
  
  // test minus
  calculator.minus();
  ASSERT_EQ(GetAns(calculator), 1-2);
  
  auto squared = [](auto a, auto b){ return a * a + b * b; };
  calculator.calc(squared);
  ASSERT_EQ(GetAns(calculator), 1*1+2*2);
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
