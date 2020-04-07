/*
 * 8.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: user
 */

#include <iostream>
using namespace std;
#include <string.h>;
class String
{private:
	char s[50];
public:
	String() {}
	String(char *x) {strcpy(s,x);}
	void input()
	{cout<<"enter a string";
	cin>>s;
	}
	void show()
	{cout<<"\n string"<<s;}
	char * disp()
	{return s;}
	String operator +(String x)
	{
		String t;
		strcpy(t.s,s);
		strcat(t.s,x.s);
		return t;
	}
	void operator +=(String x)
		{
		strcat(s,x.s);
		}
	int operator ==(String x)
		{
		if(stricmp(s,x.s)==0)
				return 1;
		else
			return 0;
	}
	int operator >(String x)
	{
		if(stricmp(s,x.s)>0)
		return 1;
		else
			return 0;
	}
};
int main()
{
	String s1;
	String s2("Udupi");s1.input();
	s1.show();s2.show();
	if (s1==s2)
		cout<<"\n Both strings are equal";
	else
		cout<<"\n Both strings are different";
	if (s1>s2)
		{cout<<endl<<s1.disp()<<"is bigger than"<<s2.disp();}

}
