#include<iostream>
using namespace std;

template <class t>
class myqueue 
{	public:
	int front, rear, capacity;
	int* queue;
	
	myqueue(t c)
	{
		front=0; 
		rear=0;
		capacity = c;
		queue = new t[c];
	}
	
	~myqueue() 
	{delete[] queue;
	}
	
	void enqueue(t data) // function to insert an element at the rear of the queue
	{
		if (isfull())
		return;
		
		else 
		{ 
		queue[rear] = data;
		rear++;
		}
		return;
	}

	void dequeue() // function to delete an element from the front of the queue
	{
		if (isempty()) 
		return;
		
		else 
		{
			for (int i = 0; i < rear - 1; i++) 
			queue[i] = queue[i + 1];
			//all elements are copied to their previous element and first element is overwritten
			rear--;
		}
		return;
	}

	void display()
	{
		int i;
		for (i = front; i < rear; i++) 
		{
		cout<<queue[i]<<" ";
		}
		return;
	}


	t dfront()
	{return queue[front];
	}
	
	bool isempty()
	{
		if(rear==0)
		{cout<<"\nQueue is empty\n";
		return true;
		}
		return false;
	}
	
	bool isfull()
	{	if(rear==capacity)
		{cout<<"\nQueue is full\n";
		return true;
		}
		return false;
	}
};

int main()
{	
	cout<<"\n\n\t\t Queue as Array";
	int n;
	cout<<"\n\nEnter the number of elements in queue:";
	cin>>n;  
	myqueue <int> obj(n); 
	char ans='y';
	do
	{	int op;
		int data;
		cout<<endl;
		obj.display();
		cout<<endl;
		cout<<"\nEnter an option: ";
		cout<<"\n1.Insert element at the end \n2.Delete element from the beginning\n3.Display first element \n4.Check empty \n5.exit\n=>";
		cin>>op;
		switch(op)
		{		
			case 1: cout<<"\nEnter data: ";
					cin>>data;
					obj.enqueue(data);
					break;	
					
			case 2: if(obj.isempty()==false)
					{cout<<"\nDeleted element is: "<<obj.dfront();
					obj.dequeue();
					}
					else
					cout<<"\nQueue is empty\n";
					break;	
					
			case 3: if(obj.isempty()==false)
					{cout<<"\nFirst element is: "<<obj.dfront();
					}
					else
					cout<<"\nQueue is empty\n";
					break;		
					
			case 4: if(obj.isempty()==false)
					cout<<"\nQueue is filled";
					break;
					
			case 5: exit(0);
		}
	}while(ans=='y');
	return 0;
}
