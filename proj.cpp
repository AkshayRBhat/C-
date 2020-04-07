/*
 * proj.cpp
 *
 *  Created on: Apr 13, 2006
 *      Author: user
 */
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
typedef struct slibdetails
	{
	int id;
	char bookname[50];
	char authorname[50];
	int pages;
};

typedef struct node
{
	slibdetails data;
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
		slibdetails s1;
		mf.open("libdata.dat",ios::in|ios::binary);
		first=last=NULL;
		mf.read((char *)&s1,sizeof(slibdetails));
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
				mf.read((char *)&s1,sizeof(slibdetails));
			}
			mf.close();
	}
	void newbook()
	{
		NODE *temp=new NODE;
		slibdetails s1;
		cout<<"\n enter id:";
		cin>>s1.id;
		cout<<"\n enterbook name:";
		cin>>s1.bookname;
		cout<<"\n enter author name:";
		cin>>s1.authorname;
		cout<<"\n enter no. of pages:";
		cin>>s1.pages;
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
			cout<<"\n"<<temp->data.id<<"\t"<<temp->data.bookname<<"\t"<<temp->data.authorname<<"\t"<<temp->data.pages;
			temp=temp->next;
		}
	}

	~linklist()
	{
		fstream mf;
		slibdetails s1;
		mf.open("libdata.dat",ios::out|ios::binary);
		NODE *temp=first;
		while(temp!=NULL)
		{
			s1=temp->data;
			mf.write((char *)&s1,sizeof(slibdetails));
			temp=temp->next;
		}

		mf.close();
	}
void sortbybookname()
{

	NODE *i,*j;
	slibdetails s;
	for(i=first;i!=NULL;i=i->next)
		for(j=i->next;j!=NULL;j=j->next)
			if(stricmp(i->data.bookname,j->data.bookname)>0)
			{
				s=i->data;
				i->data=j->data;
				j->data=s;
			}
}
void sortbypages()
{

	NODE *i,*j;
	slibdetails s;
	for(i=first;i!=NULL;i=i->next)
		for(j=i->next;j!=NULL;j=j->next)
			if(i->data.pages>j->data.pages)
			{
				s=i->data;
				i->data=j->data;
				j->data=s;
			}
}
int searchbook()
	{
		char a[50];
		int v;
		int flag = 0;
		NODE *s;
		cout<<"Enter the bookname to be searched: ";
		cin>>a;
		v = strcmp(a,first->data.bookname);
		if (v == 0)
			{
				cout<<a;
				cout<<"\n "<<first->data.id<<"\t"<<first->data.bookname<<"\t"<<first->data.authorname<<"\t"<<first->data.pages;
				flag=1;
			}
		else
		{
			s=first->next;
			while(s!=NULL)
			{
				if(strcmp(s->data.bookname,a)==0)
				{
					cout<<"\n" <<first->data.id<<"\t"<<s->data.bookname<<"\t"<<first->data.authorname<<"\t"<<s->data.pages;
					flag=1;
					break;
				}
				s=s->next;

			}

			if(s==NULL)
				{
					cout<<"\n"<<a<< " not found!!!";
				}
			}
	return flag;
	}
int searchauthor()
	{
		char a[50];
		int v;
		int flag = 0;
		NODE *s;
		cout<<"Enter the authorname to be searched: ";
		cin>>a;
		v = strcmp(a,first->data.authorname);
		if (v == 0)
			{
				cout<<a;
				cout<<"\n "<<first->data.id<<"t"<<first->data.authorname<<"\t"<<first->data.bookname<<"\t"<<first->data.pages;
				flag=1;
			}
		else
		{
			s=first->next;
			while(s!=NULL)
			{
				if(strcmp(s->data.authorname,a)==0)
				{
					cout<<"\n" <<first->data.id<<"\t"<<s->data.authorname<<"\t"<<first->data.bookname<<"\t"<<s->data.pages;
					flag=1;
					break;
				}
				s=s->next;

			}

			if(s==NULL)
				{
					cout<<"\n"<<a<< " not found!!!";
				}
			}
	return flag;
	}


};
int main()
{
	linklist l1;
	int ch;
	do {
		cout<<"\n 1.Add New Book \n 2.Show \n 3.sort by Book name \n 4.sort by pages \n 5.Search book \n 6.Search author \n Enter your choice";
		cin>>ch;
		switch(ch)
		{
		case 1:
			l1.newbook();
			break;
		case 2:
			l1.show();
			break;
		case 3:
			l1.sortbybookname();
			break;
		case 4:
			l1.sortbypages();
			break;
		case 5:
		   l1.searchbook();
		   break;
		case 6:
			l1.searchauthor();
			break;

		}
	}while(ch!=7);
}



