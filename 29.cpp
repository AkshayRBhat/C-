/*
 * 29.cpp
 *
 *  Created on: Apr 7, 2006
 *      Author: user
 */
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
typedef struct smarks
{
	int id;
	char sub[50];
	int marks;
};

typedef struct node
{
	smarks data;
	node *next;
}NODE;

class linklist
{
private:
	NODE *first;
	NODE *last;
public:
	linklist()
	{
		fstream mf;
		smarks s1;
		mf.open("marks.dat",ios::in|ios::binary);
		first=last=NULL;
		mf.read((char *)&s1,sizeof(smarks));
			while(!mf.eof())
			{
		NODE *temp=new NODE;
		temp->data=s1;
		temp->next=NULL;
		if(first==NULL)
		{
			first=last=temp;

		}
		else
		{
			last->next=temp;
			last=temp;
		}
				mf.read((char *)&s1,sizeof(smarks));
			}
			mf.close();
	}
	void addnode()
	{
		NODE *temp=new NODE;
		smarks s1;
		cout<<"\n enter id:";
		cin>>s1.id;
		cout<<"\n enter subject:";
		cin>>s1.sub;
		cout<<"\n enter marks:";
		cin>>s1.marks;
		temp->data=s1;
		temp->next=NULL;
		if(first==NULL)
		{
			first=last=temp;

		}
		else
		{
			last->next=temp;
			last=temp;
		}
	}
	void show()
	{
		NODE *temp=first;
		while(temp!=NULL)
		{
			cout<<"\n"<<temp->data.id<<"\t"<<temp->data.sub<<"\t"<<temp->data.marks;
			temp=temp->next;
		}
	}

	~linklist()
	{
		fstream mf;
		smarks s1;
		mf.open("marks.dat",ios::out|ios::binary);
		NODE *temp=first;
		while(temp!=NULL)
		{
			s1=temp->data;
			mf.write((char *)&s1,sizeof(smarks));
			temp=temp->next;
		}

		mf.close();
	}
void sortbysubject()
{

	NODE *i,*j;
	smarks s;
	for(i=first;i!=NULL;i=i->next)
		for(j=i->next;j!=NULL;j=j->next)
			if(stricmp(i->data.sub,j->data.sub)>0)
			{
				s=i->data;
				i->data=j->data;
				j->data=s;
			}
}
void sortbymarks()
{

	NODE *i,*j;
	smarks s;
	for(i=first;i!=NULL;i=i->next)
		for(j=i->next;j!=NULL;j=j->next)
			if(i->data.marks>j->data.marks)
			{
				s=i->data;
				i->data=j->data;
				j->data=s;
			}
}
};
int main()
{
	linklist l1;
	int ch;
	do {
		cout<<"\n 1.New node \n 2.Show \n 3.sort by subject \n 4.sort by marks \n 5.Quit \n Enter your choice";
		cin>>ch;
		switch(ch)
		{
		case 1:
			l1.addnode();
			break;
		case 2:
			l1.show();
			break;
		case 3:
			l1.sortbysubject();
			break;
		case 4:
			l1.sortbymarks();
			break;
		}
	}while(ch!=5);
}


