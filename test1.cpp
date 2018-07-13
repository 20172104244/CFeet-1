// test1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class CFeet 
{
private:
	int feet;
	int inches;
public:
	void setvalue(int ft, int in);
	void change();
	void display();
	CFeet operator+(CFeet & ojbk);
	CFeet operator-(CFeet & ojbk);
};
void CFeet::setvalue(int ft, int in)
{
	feet = ft;
	inches = in;
}
CFeet CFeet::operator+(CFeet & ojbk)
{
	CFeet temp;
	if (feet >= 0 & ojbk.feet >= 0)
	{
		temp.setvalue(0, (feet * 12 + inches) + (ojbk.feet * 12 + ojbk.inches));
	}
	if(feet <0 & ojbk.feet >= 0)
	{
		temp.setvalue(0, (feet * 12 - inches) + (ojbk.feet * 12 + ojbk.inches));
	}
	if (feet >= 0 & ojbk.feet < 0)
	{
		temp.setvalue(0, (feet * 12 + inches) + (ojbk.feet * 12 - ojbk.inches));
	}
	if (feet < 0 & ojbk.feet < 0)
	{
		temp.setvalue(0, (feet * 12 - inches) + (ojbk.feet * 12 - ojbk.inches));
	}
	return temp;
}
CFeet CFeet::operator-(CFeet & ojbk)
{
	CFeet j;
	if (feet >= 0 & ojbk.feet >= 0)
	{
		j.setvalue(0, (feet * 12 + inches) - (ojbk.feet * 12 + ojbk.inches));
	}
	if (feet >= 0 & ojbk.feet < 0)
	{
		j.setvalue(0, (feet * 12 + inches) - (ojbk.feet * 12 - ojbk.inches));
	}
	if(feet<0 & ojbk.feet >= 0)
	{
		j.setvalue(0, (feet * 12 - inches) - (ojbk.feet * 12 + ojbk.inches));
	}
	if (feet < 0 & ojbk.feet < 0)
	{
		j.setvalue(0, (feet * 12 - inches) - (ojbk.feet * 12 - ojbk.inches));
	}
	return j;
}
void CFeet::change()
{
	if (inches > 0)
	{
		feet = inches / 12;
		inches = inches % 12;
	}
	else
	{
		feet = inches / 12;
		inches = -inches % 12;
	}
}
void CFeet::display()
{
	cout << "feet=" << feet << " inches=" << inches << endl;
}
int main()
{
	CFeet A, B, C,D;
	A.setvalue(0, 4);
	B.setvalue(-1, 2);
	C = A + B;
	D = A - B;
	C.change();
	D.change();
	C.display();
	D.display();
    return 0;
}

