#include<iostream>
using namespace std;

class fibonacci
{
	int num;
	public:
	
	void input()
	{
		do
		{cout<<"\nEnter the number of terms: ";
		cin>>num;
		if(num<0)
		cout<<"\nPlease enter a positive number";
		}while(num<0);
		
		int op;
		
		do
		{
			cout<<"\nChoose method to display fibonacci series: \n1.Recursion\n2.Iteration\n=> ";
			cin>>op;
			if(op==1)
			fiborec(num,0,1);
			
			else if(op==2)
			fiboit(num);
			
			else
			cout<<"\nInvalid option";
		
		}while(op!=1 && op!=2);
		
	}
	
	
	void fiboit(int num)
	{	int num1=0,num2=1,num3;
		cout<<num1<<endl<<num2;	
		for (int i = 2; i < num; i++)
		{
			num3=num2+num1;
			cout<<endl<<num3;
			num1=num2;
			num2=num3;
		}
	}

	void fiborec(int limit, int num1, int num2) 
	{ 	if(limit==0)
		return;
		cout<<num1<<" ";
		limit--;
		fiborec(limit,num2,num1+num2);
		
	} 

};
int main()
{	fibonacci obj;
	char ans='y';
	cout<<"\n\t\t* Fibonacci Serires *\n";
	do
	{	
		obj.input();
		cout<<"\nCheck for another number? y/n : ";
		cin>>ans;
	}while(ans=='y');
	return 0;
}
