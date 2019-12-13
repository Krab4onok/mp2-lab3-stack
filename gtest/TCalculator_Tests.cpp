#include"gtest.h"
#include"../Calculator.h"
TEST(TCalculator, can_create_calculator)
{
	ASSERT_NO_THROW(TCalculator s);
}
TEST(TCalculator, can_set_expression)
{
	TCalculator s;
	string a = "2+2";
	ASSERT_NO_THROW(s.SetExpr(a));
}
TEST(TCalculator, can_get_expression)
{
	TCalculator s;
	string a = "2+2";
	s.SetExpr(a);
	string g = s.GetExpr();
	EXPECT_TRUE(a == g);
}
TEST(TCalculator, can_create_postfix)
{
	TCalculator s;
	string a = "((2+5)*9)/((-1)*9)";
	s.SetExpr(a);
	ASSERT_NO_THROW(s.ToPostfix());
}
TEST(TCalculator, can_get_postfix)
{
	TCalculator s;
	string a = "((2+5)*9)/((-1)*9)";
	s.SetExpr(a);
	s.ToPostfix();
	string g = "2 5+ 9* 0 1- 9*/";
	ASSERT_NO_THROW(s.GetPostfix());
	EXPECT_TRUE(g == s.GetPostfix());
}
TEST(TCalculator, can_multiply)
{
	TCalculator s;
	string a = "3*2";
	s.SetExpr(a);
	double res = s.CalcV2();
	EXPECT_EQ(6, res);
}
TEST(TCalculator, can_divide)
{
	TCalculator s;
	string a = "6/2";
	s.SetExpr(a);
	double res = s.CalcV2();
	EXPECT_EQ(3,res);
}
TEST(TCalculator, can_add)
{
	TCalculator s;
	string a = "2+3";
	s.SetExpr(a);
	double res = s.CalcV2();
	EXPECT_EQ(5, res);
}
TEST(TCalculator, can_subtract)
{
	TCalculator s;
	string a = "3-1";
	s.SetExpr(a);
	double res = s.CalcV2();
	EXPECT_EQ(2, res);
}
TEST(TCalculator, can_rise_in_power)
{
	TCalculator s;
	string a = "3^2";
	s.SetExpr(a);
	double res = s.CalcV2();
	EXPECT_EQ(9, res);
}
TEST(TCalculator, can_solve_expression_with_negative_numbers)
{
	TCalculator s;
	string a = "(-3)*3+5";
	s.SetExpr(a);
	double res = s.CalcV2();
	EXPECT_EQ(-4, res);
}
TEST(TCalculator, can_use_brackets)
{
	TCalculator s;
	string a = "((2*2^3)^2)+5";
	s.SetExpr(a);
	double res = s.CalcV2();
	EXPECT_EQ(261, res);
}
TEST(TCalculator, can_combine_all_operations)
{
	TCalculator s;
	string a = "(((-2)*10)+3^2*9-51)^2/10";
	s.SetExpr(a);
	double res = s.CalcV2();
	EXPECT_EQ(10, res);
}
TEST(TCalculator, can_use_fractions)
{
	TCalculator s;
	string a = "(2.5/0.5)^2";
	s.SetExpr(a);
	double res = s.CalcV2();
	EXPECT_EQ(pow((2.5/ 0.5),2), res);
}
TEST(TCalculator, can_add_and_subtract_fractions)
{
	TCalculator s;
	string a = "2.5+3.6-1.1";
	s.SetExpr(a);
	double res = s.CalcV2();
	EXPECT_EQ(2.5 + 3.6 - 1.1, res);
}
TEST(TCalculator, can_multiply_and_divide_fractions)
{
	TCalculator s;
	string a = "2.5*3.6/1.1";
	s.SetExpr(a);
	double res = s.CalcV2();
	EXPECT_EQ(2.5 * 3.6 / 1.1, res);
}