/*
 * 25.cpp
 *
 *  Created on: Apr 22, 2006
 *      Author: user
 */
#include <iostream>
#include <string.h>
using namespace std;
typedef struct node
{
	int no;
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
		first=last=NULL;
	}
	void addnode()
	{
		NODE *temp=new NODE;
		int n;
		cout<<"\n Enter number";
		cin>>n;
		temp->no=n;
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
			cout<<"\n"<<temp->no;
			temp=temp->next;
		}
	}
	void insertnode()
	{
		int n,l;
		cout<<"\n Enter new value";
		cin>>n;
		cout<<"\n Enter location";
		cin>>l;
		NODE *temp=new NODE;
		temp->no=n;
		temp->next=NULL;
		if(first->no==l)
		{
			temp->next=first;
			first=temp;
		}
		else
		{
			NODE *s=search(l);
			if(s==NULL)
			{
				cout<<"\n "<<l<<"not found";
			}
			else
			{
				temp->next=s->next;
				s->next=temp;
			}
		}
	}
	NODE *search(int x)
	{
		NODE *t=first;
		while(t!=NULL)
		{
			if(t->next->no==x)
				return t;
			t=t->next;

		}return NULL;
	}
	void deletenode()
	{
		int l;
		cout<<"\n Enter location";
		cin>>l;
		if(first->no==l)
		{
			NODE *temp=first;
			first=first->next;
			delete temp;
		}
		else
		{
			NODE *s=search(l);
			if(s==NULL)
				cout<<"\n not found";
			else
			{
				NODE *temp=s->next;
				s->next=temp->next;
				delete temp;
			}
		}
	}
};
int main()
{
	linklist l1;
	int ch;
	do {
		cout<<"\n 1.New node \n 2.Show \n 3.Insert \n 4.Delete \n 5.Quit \n Enter your choice";
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
					l1.insertnode();
					break;
		case 4:
					l1.deletenode();
					break;
		}
	}while(ch!=5);
}
