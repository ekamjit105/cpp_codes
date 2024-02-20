#include<iostream>
using namespace std;

class factorial
{
	int num,res;
	
	public:
	
	void input()
	{
		do
		{cout<<"\nEnter a Number for factorial to be calculated: ";
		cin>>num;
		if(num<0)
		cout<<"\nPlease enter a positive number";
		}while(num<0);
		
		int op;
		do
		{
			cout<<"\nChoose method to calculate factorial: \n1.Recursion\n2.Iteration\n=> ";
			cin>>op;
			if(op==1)
			{res=factrec(num);
			cout<<"\nThe result will be: "<<res;
			}
			else if(op==2)
			{res=factit(num);
			cout<<"\nThe result will be: "<<res;
			}
			else
			cout<<"\nInvalid option";
		
		}while(op!=1 && op!=2);
	}
	
	int factit(int num)
	{	res=1;
		while(num!=0)
		{
			res*=num;
			num--;
		}
		return res;
	}

	int factrec(int num)
	{	res=1;
		if(num==0)
		return 1;
		
		res=num*factrec(num-1);
		return res;
	}
	
};

int main()
{	factorial obj;
	char ans='y';
	cout<<"\n\t\t* Calculate factorial of a number *\n";
	do
	{	obj.input();
		cout<<"\nCheck for another number? y/n : ";
		cin>>ans;
		
	}while(ans=='y');
	return 0;
}
