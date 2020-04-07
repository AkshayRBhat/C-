/*
 * 17.cpp
 *
 *  Created on: Apr 8, 2006
 *      Author: user
 */
#include <iostream>
using namespace std;
template <class t>
void input(t *x,int y)
{
	for(int i=0;i<y;i++)
	{
		cout<<"\n enter a number";
		cin>>x[i];
	}
}
template <class t>
void show(t *x,int y)
{
	for(int i=0;i<y;i++)
		cout<<"\n "<<x[i];
}
int main()
{
	int *a,n;
	float *b;
	cout<<"\n enter number of elements";
	cin>>n;
	a=new int[n];
	b=new float[n];
	cout<<"\n integer input";
	input(a,n);
	cout<<"\n float input";
	input(b,n);
	show(a,n);
	show(b,n);
}
