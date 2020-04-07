/*
 * 7.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: user
 */

#include <iostream>
using namespace std;
class date
{
private:
	int dd,mm,yy;
public:
	date()
	{
		dd=mm=yy=0;
	}
	date(int a,int b,int c)
	{dd=a;mm=b;yy=c;}
	date(int a)
	{
		yy=a/365;
		a=a%365;
		mm=a/30;
		dd=a%30;
	}

void input()
{
	cout<<"\n enter a day";
	cin>>dd;
	cout<<"\n enter month";
	cin>>mm;
	cout<<"\n enter year";
	cin>>yy;
}
void show()
{
	cout<<"\n Date:"<<dd<<"/"<<mm<<"/"<<yy;
}
// d2 += d3
// d2= d2+d3
void operator += ( date x)
{
	dd+=x.dd;
	if(dd>30)
	{
		mm++;
		dd-=30;
	}
	mm+=x.mm;
	if(mm>12)
	{
		yy++;
		mm-=12;
	}
	yy+=x.yy;
}
// d4=d1+d2
// ro co po
date operator + ( date x)
{
	date t;
	t.dd=dd + x.dd;
	if(t.dd>30)
	{
		t.mm++;
		t.dd-=30;
	}
	t.mm+=mm+x.mm;
	if(t.mm>12)
	{
		t.yy++;
		t.mm-=12;
	}
	t.yy+=yy+x.yy;
	return t;
}


};
int main()
{
	date d1;
	date d2(10,10,2017);
	date d3(400);
	d1.input();
	d1.show();
	d2.show();
	d3.show();
	d2+=d3;
	d2.show();
	date d4=d1+d2;
	d4.show();
}
