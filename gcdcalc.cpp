#include<iostream>
using namespace std;

class gcd
{
	int num1,num2,res;
	
	public:
	
	void input()
	{
		do
		{cout<<"\nEnter 2 numbers for gcd: ";
		cin>>num1;
		cin>>num2;
		if(num1<0||num2<0)
		cout<<"\nPlease positive numbers";
		}while(num1<0||num2<0);
		
		int op;
		
		do
		{
			cout<<"\nChoose method to calculate gcd: \n1.Recursion\n2.Iteration\n=> ";
			cin>>op;
			if(op==1)
			{res=gcdrec(num1,num2);
			cout<<"\nthe result is: "<<res;
			}
			else if(op==2)
			{res=gcdit(num1,num2);
			cout<<"\nthe result is: "<<res;
			}
			else
			cout<<"\nInvalid option";
		
		}while(op!=1 && op!=2);
	}

	int gcdit(int num1, int num2)
	{	
		int hcf=num1;
		while(1)
		{
			if(num1%hcf==0 && num2%hcf==0)
			break;
			hcf--;
		}
		return hcf;
	}

	int gcdrec(int a, int b) 
	{ 	 
		if (a == 0)
		   return b;
		if (b == 0)
		   return a;
	  
		if (a == b)
			return a;
	  
		if (a > b)
		return gcdrec(a-b, b);
		return gcdrec(a, b-a);
	} 
};
int main()
{	gcd obj;
	char ans='y';
	cout<<"\n\t\t* Calculate GCD of two numbers *\n";
	do
	{	
		obj.input();
		cout<<"\nCheck for another number? y/n : ";
		cin>>ans;
		
	}while(ans=='y');
	return 0;
}
