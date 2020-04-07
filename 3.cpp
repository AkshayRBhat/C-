/*
 * 3.cpp
 *
 *  Created on: May 13, 2006
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
}
