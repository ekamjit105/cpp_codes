#include<iostream>
using namespace std;
template <class t>
class mystack
{
	t *arr;
	t size;
	t top;
	
	public:
	
	mystack(int capacity)
	{	top=-1;
		size=capacity;
		arr=new t[size];
	}
	
	void push(t n)
	{	if(!isfull())								//if it is not full
		{
			top++;
			arr[top]=n;
		}
		else
		cout<<"\nThe stack is full";
	}
	
	void pop()
	{	if(!isempty())								//if stack is not empty
		{
			top--;
		}
		else
		cout<<"\nStack is empty";
	}
	
	t peek()
	{
		return arr[top];							//return topmost value
	}
	
	bool isempty()
	{
		if(top==-1)
		return true;
		return false;
	}
	
	bool isfull()
	{
		if(top==size-1)
		return true;
		return false;
	}
	
	void display()
	{	cout<<"\n\tThe stack is\n";
		if(!isempty())
		{for(int i=top;i>=0;i--)								//in a top to bottom manner
			cout<<endl<<"\t"<<arr[i];
		}
	}
	
};

int main()
{
	cout<<"\n\n\t\t Stack as Array";
	int n;
	cout<<"\n\nEnter the number of elements in stack:";
	cin>>n;  
	mystack <int> obj(n); 
	char ans='y';
	do
	{	int op;
		int data;
		cout<<endl;
		obj.display();
		cout<<endl;
		cout<<"\nEnter an option: ";
		cout<<"\n1.Insert element\n2.Delete element\n3.Display first element \n4.Check empty \n5.exit\n=>";
		cin>>op;
		switch(op)
		{		
			case 1: cout<<"\nEnter data: ";
					cin>>data;
					obj.push(data);
					break;	
					
			case 2: if(obj.isempty()==false)
					{cout<<"\nDeleted element is: "<<obj.peek();
					obj.pop();
					}
					else
					cout<<"\nStack is empty\n";
					break;	
					
			case 3: if(obj.isempty()==false)
					{cout<<"\nFirst element is: "<<obj.peek();
					}
					else
					cout<<"\nStack is empty\n";
					break;		
					
			case 4: if(obj.isempty()==false)
					cout<<"\nStack is filled";
					else
					cout<<"\nStack is empty";
					break;
					
			case 5: exit(0);
		}
	}while(ans=='y');
	return 0;
}
	
