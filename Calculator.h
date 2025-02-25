#pragma once
#include"Stack.h"
#include<cmath>
#include<string>
using namespace std;
using namespace ArrStack;
class TCalculator
{
	string expr, postfix;
	TStack<char> st_char;
	TStack<double> st_d;
	int prior(char c);
public:
	TCalculator() :st_char(100), st_d(100) {};          //����������� �� ���������
	void SetExpr(string s);                  //�������� ���������
	string GetExpr();                        //�������� ���������(������� ���)
	string GetPostfix();                     //�������� ��������� � ����������� �����
	bool Check();                            //���������
	void ToPostfix();                        //������� � ����������� ����� ������
	double calc();                           //�������, ����������� ���������(1 ������)
	double CalcV2();                         //�������, ����������� ���������(������������ � ��������)
};
int TCalculator::prior(char c)
{
	if(c =='(') return 0;
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/')return 2;
	if (c == '^') return 3;
}
void TCalculator::SetExpr(string s)
{
	expr = s;
}
string TCalculator::GetExpr()
{
	return expr;
}
bool TCalculator::Check()
{
	st_char.Clear();
	for (int i = 0; i < expr.size(); i++)
	{
		if (expr[i] == '(') st_char.Push(expr[i]);
		if (expr[i] == ')')
		{
			if (st_char.IsEmpty()) return false;
			else st_char.Pop();
		}
	}
	return st_char.IsEmpty();
}
void TCalculator::ToPostfix()
{
	string str = "(";
	str += expr;
	str += ")";
	st_char.Clear();
	postfix = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(') st_char.Push(str[i]);
		if (str[i] >= '0' && str[i] <= '9' || str[i] == '.' || str[i] == ',')postfix += str[i];
		if (str[i] == '(' && str[i + 1] == '-')
		{
			postfix += '0';
		}
		if (str[i] == ')')
		{
			char tmp = st_char.Pop();
			while (tmp != '(')
			{
				postfix += tmp;
				tmp = st_char.Pop();
			}
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'|| str[i] == '^')
		{
			postfix += " ";
			char tmp = st_char.Pop();
			while (prior(str[i]) <= prior(tmp))
			{
				postfix += tmp;
				tmp = st_char.Pop();
			}
			st_char.Push(tmp);
			st_char.Push(str[i]);
		}
	}
}
double TCalculator::calc()
{
	st_d.Clear();
	char *tmp;
	double res;
	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			double d = strtod(&postfix[i], &tmp);
			int j = tmp - &postfix[i];
			i += j - 1;
			st_d.Push(d);
		}
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
		{
			double op1 = st_d.Pop();
			double op2 = st_d.Pop();
			switch (postfix[i])
			{
			case '+':
				res = op1 + op2;
				break;
			case  '-':
				res = op2 - op1;
					break;
			case '*':
				res = op1*op2;
				break;
			case '/':
				res = op2 / op1;
				break;
			case '^':
				res = pow(op2, op1);
				break;
			default:
				if (st_char.IsEmpty()) throw - 1;
			}
			st_d.Push(res);
		}
	}
	return st_d.Pop();
}
string TCalculator::GetPostfix()
{
	ToPostfix();
	return postfix;
}
double TCalculator::CalcV2()
{
	string str = "(";
	str += expr;
	str += ")";
	
	st_char.Clear();
	st_d.Clear();
	char* tmp;
	double res;
	for (int i = 0; i < str.size(); i++)
	{

		if (str[i] == '(') st_char.Push(str[i]);
		if (str[i] >= '0' && str[i] <= '9' || str[i] == '.' || str[i] == ',')
		{
				double d = strtod(&str[i], &tmp);
				int j = tmp - &str[i];
				i += j - 1;
				st_d.Push(d);
		}
		if (str[i] == '(' && str[i + 1] == '-')
		{
			int j = i + 1;
			str.insert(j, 1, '0');
				/*double d = strtod(&str[i], &tmp);
				int j = tmp - &str[i];
				//i = i + 2;
				i += j-1 ;
				st_d.Push(-d);*/
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '^')
		{
			char tmp = st_char.Pop();
			while (prior(str[i]) <= prior(tmp))
			{
				char op = tmp;
				tmp = st_char.Pop();
				if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
				{
					double op1 = st_d.Pop();
					double op2 = st_d.Pop();
					switch (op)
					{
					case '+':
						res = op1 + op2;
						break;
					case  '-':
						res = op2 - op1;
						break;
					case '*':
						res = op1 * op2;
						break;
					case '/':
						res = op2 / op1;
						break;
					case '^':
						res = pow(op2, op1);
						break;
					default:
						if (st_char.IsEmpty()) throw - 1;
					}
					st_d.Push(res);
				}
			}
			st_char.Push(tmp);
			st_char.Push(str[i]);
		}
		if (str[i] == ')')
		{
			char op = st_char.Pop();
			while (op != '(')
			{
				if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
				{
					double op1 = st_d.Pop();
					double op2 = st_d.Pop();
					switch (op)
					{
					case '+':
						res = op1 + op2;
						break;
					case  '-':
						res = op2 - op1;
						break;
					case '*':
						res = op1 * op2;
						break;
					case '/':
						res = op2 / op1;
						break;
					case '^':
						res = pow(op2, op1);
						break;
					default:
						if (st_char.IsEmpty()) throw - 1;
					}
					st_d.Push(res);
				}
				op = st_char.Pop();
			}
		}
	}
	//if (!(st_d.IsEmpty()))throw - 1;
	return st_d.Pop();
}//((2+5)*9)/((-1)*9)