#include<iostream>
using namespace std;

template <class t>
class mydeque 
{	public:
	int front, rear, capacity,count=0;
	int* deque;
	
	mydeque (t c)
	{
		front=-1; 
		rear=-1;
		capacity = c;
		deque = new t[c];
	}
	
	~mydeque () 
	{delete[] deque;
	}
	
	void insertatend(t data) // function to insert an element at the rear of the queue
	{
		if (isfull())
		{cout<<"\nDeque is full";
		return;
		}
		
		else 
		{ 
		deque[rear+1] = data;
		rear++;
		if(rear==0)							//first element added
		front=0;
		count++;
		}
		return;
	}

	void deletebeg() // function to delete an element from the front of the queue
	{
		if (isempty()) 
		return;
		
		else 
		{
			for (int i = 0; i <=rear; i++) 
			deque[i] = deque[i + 1];
			//all elements are copied to their previous element and first element is overwritten
			rear--;
			if(rear==-1)					//last element deleted
			front=-1;
			count--;
		}
		return;
	}

	void display()
	{
		int i;
		if(!isempty())
		{
		for (i = front; i <= rear; i++) 
		{
		cout<<deque[i]<<" ";
		}
		}
		return;
	}


	t dfront()
	{return deque[front];
	}
	
	bool isempty()
	{
		if(rear==-1)
		return true;
		return false;
	}
	
	bool isfull()
	{	if(rear==capacity-1)
		return true;
		return false;
	}
	
	void insertbeg(int n)
	{	
		if(isempty())
		{	front++;
			deque[front]=n;
			rear++;
			count++;
		}
		
		else
		{
			if(!isfull())
			{	
				for(int i=rear;i>=front;i--)						//shifting all elements to one position right
				deque[i+1]=deque[i];
				
				deque[0]=n;
				rear++;
				count++;
			}
			else
			cout<<"\nArray full";
		}
	}
	
	void deleteend()
	{
		if(!isempty())
		{	rear=rear-1;
			if(rear==-1)							//last element deleted
			front=-1;
			count--;
		}
		else
		cout<<"\ndeque is empty";
	}
	
	int returnsize()
	{
		return count;
	}
};

int main()
{	
	cout<<"\n\n\t\t deque as Array";
	int n;
	cout<<"\n\nEnter the number of elements in queue:";
	cin>>n;  
	mydeque  <int> obj(n); 
	char ans='y';
	do
	{	int op;
		int data;
		cout<<endl;
		obj.display();
		cout<<endl;
		cout<<"\n choose an option: ";
		cout<<"\n1.Insert at Beginning\n2.Insert at end";
		cout<<"\n3.Delete from Beginning\n4.Delete from end";
		cout<<"\n5.Display front element \n6.Check empty \n7.Check size\n8.Exit program\n=>";
		cin>>op;
		switch(op)
		{	
			case 1: cout<<"\nEnter data: ";
					cin>>data;
					obj.insertbeg(data);
					break;
				
			case 2: cout<<"\nEnter data: ";
					cin>>data;
					obj.insertatend(data);
					break;	
					
			case 3: if(obj.isempty()==false)
					{cout<<"\nDeleted element is: "<<obj.dfront();
					obj.deletebeg();
					}
					else
					cout<<"\ndeque is empty\n";
					break;	
					
			case 4: obj.deleteend();
					break;		
					
			case 5: if(obj.isempty()==false)
					{cout<<"\nFirst element is: "<<obj.dfront();
					}
					else
					cout<<"\ndeque is empty\n";
					break;		
					
			case 6: if(obj.isempty()==false)
					cout<<"\ndeque is filled";
					else
					cout<<"\ndeque is empty";
					break;
					
			case 7: cout<<"\nSize of Deque is: "<<obj.returnsize();
					break;	
					
			case 8: exit(0);
		}
	}while(ans=='y');
	return 0;
}
