
#include <iostream>
using namespace std;
class myclass
{
private:
	int no;
	static int ctr;
public:
	myclass()
	{
		no=0; ctr++;
	}
	myclass(int a)
	{
		no=a; ctr++;
	}
	void input()
	{
		cout<<"\n Enter a number:";
		cin>>no;
	}
	void show()
	{
		cout<<"\n No"<<no;
	}
    static void getcounter()
	{
		cout << "\n Number of objects " << ctr;
	}
};
int myclass::ctr=0;
int main()
{
	myclass::getcounter();
	myclass m1;
	myclass m2(100);
	m1.input();
	m1.show();
	m2.show();
	myclass::getcounter();
	}

