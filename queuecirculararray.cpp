//this answer does not have (r+1)%max approach, 
//that one is saved in ds programs file named circular queue nancy mam
#include<iostream>
using namespace std;

template <class t>
class circqueue 
{	public:
	int front, rear, capacity;
	int* queue;
	
	circqueue(t c)
	{
		front=-1; 
		rear=-1;
		capacity = c;
		queue = new t[c];
	}
	
	~circqueue() 
	{delete[] queue;
	}
	
	void enqueue(t data) 				// function to insert an element at the rear of the queue
	{	if (!isfull())					// if there is space in the queue
		{	
			rear++;
			
			if(rear==capacity)			// if previously added element was at the last position, next would be added at first position 
			rear=0;
			
			queue[rear] = data;
			
			if(front==-1)				// first element was being inserted
			front++;
		}
		return;
	}

	t dequeue() // function to delete an element from the front of the queue
	{	
		if(!isempty())
		{t temp = queue[front];
		
		if(front==rear)													//single element left
		{front=-1;
		rear=-1;}
		else
		front++;
		
		if(front==capacity)												//if front reaches end, next front will be first element
		front=0;

		return temp;
		}
		else
		cout<<"\nqueue is empty";
		return -1;
	}	
	
	void display()
	{
		if(rear==-1)
		{
			cout<<"\nqueue is empty";
			return;
		}
		
		cout<<"\nElements in circular queue are: ";
		if(rear>=front)
		{
			for(int i=front; i<=rear;i++)
			cout<<queue[i]<<" ";
		}
		
		else
		{
			for(int i=front; i<capacity;i++)
			cout<<queue[i]<<" ";
			
			for(int i=0; i<=rear;i++)
			cout<<queue[i]<<" ";
		}
	}

	t dfront()
	{return queue[front];
	}
	
	bool isempty()
	{
		if(rear==-1)
		{cout<<"\nQueue is empty\n";
		return true;
		}
		return false;
	}
	
	bool isfull()
	{	
		if((rear==capacity-1 && front==0)||(rear==front-1))
		{cout<<"\nQueue is full\n";
		return true;
		}
		return false;
	}
};

int main()
{	
	cout<<"\n\n\t\t Queue as Circular Array";
	int n;
	cout<<"\n\nEnter the number of elements in queue:";
	cin>>n;  
	circqueue <int> obj(n); 
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
					{cout<<"\nDeleted element is: "<<obj.dequeue();
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
