/*
 * 26.cpp
 *
 *  Created on: Apr 22, 2006
 *      Author: user
 */
#include <iostream>
#include <string.h>
using namespace std;
typedef struct node
{
	char no[50];
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
		char n[50];
		cout<<"\n Enter number";
		cin>>n;
		strcpy(temp->no,n);
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
		char n[50],l[50];
		cout<<"\n Enter new value";
		cin>>n;
		cout<<"\n Enter location";
		cin>>l;
		NODE *temp=new NODE;
		strcpy(temp->no,n);
		temp->next=NULL;
		if(strcmp(first->no,l)==0)
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
	NODE *search(char *x)
	{
		NODE *t=first;
		while(t!=NULL)
		{
			if(strcmp(t->next->no,x)==0)
				return t;
			t=t->next;

		}return NULL;
	}
	void deletenode()
	{
		char l[50];
		cout<<"\n Enter location";
		cin>>l;
		if(strcmp(first->no,l)==0)
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

