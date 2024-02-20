#include<iostream>
using namespace std;
int i,j;

template <class t>
class sort
{	
	t a[10];
	int size;
	
	public:
	
	void input()
	{	
		cout<<"enter size of array: ";
		cin>>size;
		cout<<"\n enter array..\n";
		for(i=0;i<size;i++)
		{cin>>a[i];
		}
	}
	
	void display()
	{for(i=0;i<size;i++)
		cout<<a[i]<<" ";
	}
	
	void bubblesort()
	{ 
		for(i=0;i<size-1;i++)
		{	
			for(j=0;j<size-i-1;j++)
			{	
			if(a[j]>a[j+1])
			swap(a[j],a[j+1]); 
			}
		}
	} 
		
	void insertionsort()
	{	 
		for(i=1;i<size;i++)
		{
			t temp=a[i];
			j=i-1;
			while((temp<a[j])&&(j>=0))
			{
				a[j+1]=a[j];
				j--;
			}
			a[j+1]=temp;
		}
	}
	
	void selectionsort()
	{	
		t min;
		int loc;
		for(int i=0;i<size-1;i++)
		{
			min=a[i];
			loc=i;
			for(int j=i+1;j<size;j++)
			{
				if(a[j]<min)
				{
					min=a[j];
					loc=j;
				}
			}
			swap(a[i],a[loc]);
		}
	
	}
};
	template <class t>
	void swap(t a, t b)
	{   
		t temp=a;
		a=b;
		b=temp;
	}
	
	
	int main()
	{
	sort <int> s1;
	sort <float> s2;
	int op,datatype;
	char ans='y';
	
	cout<<" Choose the data type of the array to be sorted: \n(1)Integer\n(2)Float\n=>";
	cin>>datatype;
	
	switch(datatype)
	{
		case 1: 
		{
		while(ans=='y')
		{
		s1.input();
	
		cout<<"\n Enter sorting method:\n(1)bubblesort\n(2)insertionsort\n(3)selectionsort\n=>";
		cin>>op;
			switch(op)
			{
			case 1:
			cout<<"\n before sorting..\n";
			s1.display();
			s1.bubblesort();
			cout<<"\n after sorting with bubblesort..\n";
			s1.display();
			break;
		
			case 2:
			cout<<"\n before sorting..\n";
			s1.display();
			s1.insertionsort();
			cout<<"\n after sorting with insertionsort \n";
			s1.display();
			break;
	
			case 3:
			cout<<"\n before sorting..\n";
			s1.display();
			s1.selectionsort();
			cout<<"\n after sorting with selectionsort\n";
			s1.display();
			break;
			
			default: cout<<"\nInvalid Choice of sorting method";
			}
			
			cout<<"\n Do you want to try another example? y/n : ";
			cin>>ans;
			
		}		//sorting choice while 
		}		//case 1 integer data type
		
		case 2:
		{
		while(ans=='y')
		{
		s2.input();
	
		cout<<"\n Enter sorting method:\n(1)bubblesort\n(2)insertionsort\n(3)selectionsort\n=>";
		cin>>op;
			switch(op)
			{
			case 1:
			cout<<"\n before sorting..\n";
			s2.display();
			s2.bubblesort();
			cout<<"\n after sorting with bubblesort..\n";
			s2.display();
			break;
		
			case 2:
			cout<<"\n before sorting..\n";
			s2.display();
			s2.insertionsort();
			cout<<"\n after sorting with insertionsort \n";
			s2.display();
			break;
	
			case 3:
			cout<<"\n before sorting..\n";
			s2.display();
			s2.selectionsort();
			cout<<"\n after sorting with selectionsort\n";
			s2.display();
			break;
			
			default: cout<<"\nInvalid Choice of sorting method";
			}
	
			cout<<"\n Do you want to try another example? y/n : ";
			cin>>ans;
			
		}		//sorting choice while
		}		//case 2 float data type
		
		default: cout<<"\nInvalid Choice of Data type";
	}
		
return 0;
}
		
