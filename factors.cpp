#include<iostream>
using namespace std;

class factors
{
	int num;
	
	public:
	
	void input()
	{
		do
		{cout<<"\nEnter a number for which factors are to be calculated: ";
		cin>>num;
		if(num<0)
		cout<<"\nPlease enter a positive number";
		}while(num<0);
		
		int op;
		do
		{
			cout<<"\nChoose method to calculate factors: \n1.Recursion\n2.Iteration\n=> ";
			cin>>op;
			if(op==1)
			{factrec(num,1);
			cout<<num;
			}
			
			else if(op==2)
			factit(num);
			
			else
			cout<<"\nInvalid option";
		
		}while(op!=1 && op!=2);
	}
	
	void factit(int num)
	{	cout<<"Factors of "<<num<<" are: ";
		for (int i = 1; i <= num/2; i++)
		{
			if (num % i == 0) 
			cout<<i<<" ";
		}
		cout<<num;			//every number is a factor of itself
	}

	void factrec(int n, int i) 
	{ 
		if (i<=n/2) 
		{ 
			if(n%i == 0)  
			cout << i << " "; 
			factrec(n, i + 1); 
		} 
	}
	
};

int main()
{	factors obj;
	char ans='y';
	cout<<"\n\t\t* Calculating factors of a number\n";
	do
	{	obj.input();
		cout<<"\nCheck for another number? y/n : ";
		cin>>ans;
		
	}while(ans=='y');
	return 0;
}
