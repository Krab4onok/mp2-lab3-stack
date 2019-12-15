// mp2-lab3-stek.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"Stack.h"
#include"Calculator.h"
#include<string>
#include<clocale>
using namespace std;
using namespace ArrStack;

int main()
{
	TCalculator c;
	string exp;
	cin >> exp;
	c.SetExpr(exp);
	c.ToPostfix();
	cout << c.GetExpr()<<" "<<" :Expretion"<< endl;
	cout << c.GetPostfix() << " " << " :PostfixExpretion" << endl;
	cout << c.calc()<<" " << " :Solution from calc()" << endl;
	cout<< c.CalcV2()<< " " << " :Solution from CalcV2()" << endl;
	return 0;
}

