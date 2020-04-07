/*
 * 22.cpp
 *
 *  Created on: Apr 15, 2006
 *      Author: user
 */
#include <iostream>
#include <fstream>
using namespace std;
class student
{
private:
	int id;
	char sub[50];
	int marks;
public:
	student()
	{id=0;
		marks=0;
	}
	void input()
	{
		cout<<"\n enter id:";
		cin>>id;
		cout<<"\n enter subject:";
		cin>>sub;
		cout<<"\n enter marks:";
		cin>>marks;
	}
	void show()
	{
		cout<<"\n"<<id<<"\t"<<sub<<"\t"<<marks;
	}
};

void entry()
{
	fstream mf;
	student s1;
	mf.open("marks.dat",ios::app|ios::binary);
	s1.input();
	mf.write((char *)&s1,sizeof(student));
	mf.close();
}

void readdata()
{
	fstream mf;
	student s1;
	mf.open("marks.dat",ios::in|ios::binary);
	cout<<"\n id:\t subject\t marks";
		mf.read((char *)&s1,sizeof(student));
			while(!mf.eof())
			{
				s1.show();
				mf.read((char *)&s1,sizeof(student));
			}
			mf.close();
}

int main()
{
	int ch;
	do{
		cout<<"\n 1.marksentry \n 2.showmarks \n 3.quit \n"<<"\n enter your choice";
		cin>>ch;
		switch(ch)
		{
		case 1:
			entry();
			break;
		case 2:
			readdata();
			break;

		}

	}while(ch!=3);

}
