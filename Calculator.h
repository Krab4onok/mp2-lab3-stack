#pragma once
#include"Stack.h"
#include<cmath>
#include<string>
using namespace std;
class TCalculator
{
	string expr, postfix;
	TStack<char> st_char;
	int prior(char c);
public:
	TCalculator() :st_char(100) {};          //конструктор по умолчанию
	void SetExpr(string s);                  //записать выражение
	string GetExpr();                        //получить выражение
	bool Check();                            //проверить
};
int TCalculator::prior(char c)
{
	if(c =='(') return 0;
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/')return 2;
	if (c == '^') return 2;
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