#include<iostream>
using namespace std;
template <class t>
class doublestack
{
	t *arr;
	t size;
	t top1,top2;
	
	public:
	
	doublestack(int capacity)
	{	
		size=capacity;
		arr=new t[size];
		top1 = -1;
		top2 = size;
		
		for(int i=0;i<size;i++)								//initialising stack array with 0
		arr[i]=0;
	}
	
	void push(int snum, t n)
	{	if(!isfull())
		{
			if(snum==1)										//first stack selected
			{
				top1++;
				arr[top1]=n;
			}
			else 											//second stack selected
			{
				top2--;
				arr[top2]=n;
			}
		}
		else
		cout<<"\nThe stack array is full";
	}
	
	void pop(int snum)
	{	if(!isempty(snum))
		{
			if(snum==1)										//first stack selected
			{arr[top1]=0;
			top1--;
			}
			else 											//second stack selected
			{arr[top2]=0;
			top2++;
			}
			
		}
		else
		cout<<"\nStack is empty";
	}
	
	t peek(int snum)
	{	if(snum==1)
		return arr[top1];									//top of first
		return arr[top2];									//top of second
	}
	
	bool isempty(int snum)
	{
		if(snum==1) 										//first stack selected
		{
			if(top1==-1)
			return true;
			return false;
		}
		
		//else if second stack is chosen
		if(top2==size)
		return true;
		return false;
	}
	
	bool isfull()
	{
		if(top1==top2-1)
		return true;
		return false;
	}
	
	void display()
	{	cout<<"\n\tStack 1: ";									//displaying first stack
		if(!isempty(1))
		{for(int i=0;i<=top1;i++)
			cout<<"  "<<arr[i];
		}
		cout<<"\n\tStack 2: ";									//displaying second stack
		if(!isempty(2))
		{for(int i=size-1;i>=top2;i--)
			cout<<"  "<<arr[i];
		}
		
		cout<<"\n\tComplete Stack Array: ";						//displaying complete stack array
		{for(int i=0;i<size;i++)
		cout<<" "<<arr[i];
		}
		
	}
	
};

int main()
{
	cout<<"\n\n\t\t Stack as Array";
	int n;
	cout<<"\n\nEnter the number of elements in stack:";
	cin>>n;  
	doublestack <int> obj(n); 
	char ans='y';
	do
	{	int op;
		bool check=true;			//to check if a valid option is chosen
		int data, snum;
		cout<<endl;
		obj.display();
		cout<<endl;
		
		cout<<"\nEnter an option: ";
		cout<<"\n1.Insert element\n2.Delete element\n3.Display first element \n4.Check empty \n5.exit\n=>";
		cin>>op;
		
		switch(op)
		{		
			case 1: do
					{cout<<"\nEnter stack number (1/2) : ";
					cin>>snum;
					if(snum==1 || snum==2)
					check=true;
					else
					{	cout<<"\nInvalid option entered!";
						check=false;
					}
					}while(!check);
					
					cout<<"\nEnter data: ";
					cin>>data;
					obj.push(snum,data);
					break;	
					
			case 2: do
					{cout<<"\nEnter stack number (1/2) : ";
					cin>>snum;
					if(snum==1 || snum==2)
					check=true;
					else
					{	cout<<"\nInvalid option entered!";
						check=false;
					}
					}while(!check);
					
					if(obj.isempty(snum)==false)
					{cout<<"\nDeleted element is: "<<obj.peek(snum);
					obj.pop(snum);
					}
					else
					cout<<"\nStack is empty\n";
					break;	
					
			case 3: do
					{cout<<"\nEnter stack number (1/2) : ";
					cin>>snum;
					if(snum==1 || snum==2)
					check=true;
					else
					{	cout<<"\nInvalid option entered!";
						check=false;
					}
					}while(!check);
					
					if(obj.isempty(snum)==false)
					{cout<<"\nTop element is: "<<obj.peek(snum);
					}
					else
					cout<<"\nStack is empty\n";
					break;		
					
			case 4: do
					{cout<<"\nEnter stack number (1/2) : ";
					cin>>snum;
					if(snum==1 || snum==2)
					check=true;
					else
					{	cout<<"\nInvalid option entered!";
						check=false;
					}
					}while(!check);
					
					if(obj.isempty(snum)==false)
					cout<<"\nStack is filled";
					else
					cout<<"\nStack is empty";
					break;
					
			case 5: exit(0);
		}
	}while(ans=='y');
	return 0;
}
	
