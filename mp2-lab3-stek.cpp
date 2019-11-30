// mp2-lab3-stek.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"Stack.h"
#include"Calculator.h"
#include<string>
using namespace std;

int main()
{
	TCalculator c;
	string exp;
	cin >> exp;
	c.SetExpr(exp);
	c.ToPostfix();
	cout << c.GetExpr() << endl;
	cout << c.GetPostfix() << endl;
	cout << c.calc();
	return 0;
}

