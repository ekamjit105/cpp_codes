#include<iostream>
using namespace std;

template <class t>	
class polynomial
{
	t arr[20];							//coefficient array
	int degree,size;					//size = degree+1 (size is the number of coefficients)
										//represents size of coefficient array
	char ch;
	
	public: 
	
	polynomial()
	{
		for(int i=0;i<20;i++)
		arr[i]=0;														//initialising array with null values
		ch='a';
	}
	void input()
	{
		cout<<"\nEnter the degree of the equation: ";
		cin>>degree;
		size=degree+1;
		
		cout<<"\nEquation will be of type:  ";
		for(int j=degree;j>0;j--,ch++)
		{cout<<ch<<"x^"<<j<<" + ";										//displaying sample equation
		}
		cout<<ch;
		
		cout<<"\n\nEnter coefficients: \n";
		for(int i=0,ch='a';i<size;i++,ch++)
		{ 
		cout<<(char)ch<<": ";
		cin>>arr[i];
		cout<<endl;
		}
		
		cout<<"\nThe equation entered is: ";
		display();
		cout<<endl;
		reversearray(arr,size);											//reversing the coefficient array for addition
	}
	
	void reversearray(t arr[], int l)
	{	
		t temp;
		for(int i=0;i<l/2;i++)
		{
		  temp=arr[i];
		  arr[i]=arr[l-1-i];
		  arr[l-1-i]=temp;
		}	

	}
	
	int comparesize(polynomial<t>& p);							//function to return larger size out of two arrays
	polynomial<t> add(polynomial<t>& p,int l);					//add function prototype		
	
	void display()
	{	cout<<endl;
		for(int i=0;i<size;i++)
		{cout<<arr[i]<<"x^"<<size-1-i;
		if(i!=size-1)
		cout<<" + ";
		}
	}	
		
};	
	template <class t>
	int polynomial <t> :: comparesize(polynomial<t>& p)
	{
		if(size>=p.size)
		return size;
		else 
		return p.size;													//returns the larger size
	}
		
	
	template <class t>
	polynomial<t> polynomial<t>::add(polynomial<t>& p,int l)
	{	
		polynomial <t>temp;
		temp.size=l;
		for(int i=0;i<l;i++)
		{
			temp.arr[i]=arr[i]+p.arr[i];
		}
		reversearray(temp.arr,l);										//reversing the resulting array after addition 
																		//so that coefficients are displayed orderly
		return temp;
	}
	
int main()
{	
	cout<<" \n\t\tPolynomial Addition Using Template Class\n\n";
	int op;
	cout<<" Choose the data type of the polynomial functions to be added: \n(1)Integer\n(2)Float\n=>";
	cin>>op;
		
		if(op==1)
		{
		polynomial <int> p1,p2,result;
		p1.input();
		p2.input();

		int length;
		length=p1.comparesize(p2);
		result=p1.add(p2,length);
		cout<<"___________________________________________________________";
		cout<<"\n\nThe resulting polynomial after addition is: \n";
		result.display();
		}
		
		else if(op==2)
		{polynomial <float> p1,p2,result;
		p1.input();
		p2.input();

		int length;
		length=p1.comparesize(p2);
		result=p1.add(p2,length);
		cout<<"___________________________________________________________";
		cout<<"\n\nThe resulting polynomial after addition is: \n";
		result.display();
		}
	
		else 
		cout<<"\nInvalid Option Entered!";

	return 0;
}

