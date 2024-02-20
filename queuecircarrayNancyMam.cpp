#include<iostream>
using namespace std;
template <class t>
class circqueue 
{	public:
	int f, r, max, count;
	int* queue;
	
	circqueue(t c)
	{
		f=-1; 
		r=-1;
		max = c;
		queue = new t[max];
		count=0;
	}
	
	~circqueue() 
	{delete[] queue;
	}
	
	void qinsert(t data) // function to insert an element at the rear of the queue
	{	
		if((r+1)%max!=f)
		{	
			r=(r+1)%max;
			queue[r]=data;
			if(f==-1)
			f=(f+1)%max;
		}
		else
		cout<<"\nqueue is full";
	}

	void qdelete() // function to delete an element from the front of the queue
	{	
		if(f!=-1)
		{cout<<endl<<queue[f]<<" being deleted";
			if(f!=r)
			f=(f+1)%max;
			else
			{f=-1;
			r=-1;}
		}
		else
		cout<<"\nQueue Empty";
	}	

	void display()
	{	cout<<endl;
		
		int cn=f;
		if(f!=-1)
		{	while(cn!=r)
			{cout<<queue[cn]<<" ";
			cn=(cn+1)%max;
			}
			cout<<queue[cn];
		}
		
		else
		cout<<"\nQueue Empty";
	}

	t dfront()
	{return queue[f];
	}
	
	bool isempty()
	{	if(f==-1)
		{cout<<"\nQueue is empty\n";
		return true;
		}
		return false;
	}
	
	bool isfull()
	{	if((r+1)%max==f)
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
		
		cout<<endl;
		cout<<"\nEnter an option: ";
		cout<<"\n1.Insert element at the end \n2.Delete element from the beginning\n3.Display first element \n4.Check empty \n5.exit\n=>";
		cin>>op;
		switch(op)
		{		
			case 1: cout<<"\nEnter data: ";
					cin>>data;
					obj.qinsert(data);
					break;	
					
			case 2: obj.qdelete();
					break;	
					
			case 3: cout<<"\nFirst element is: "<<obj.dfront();
					break;		
					
			case 4: if(obj.isempty())
					cout<<"\nQueue is empty\n";
					else
					cout<<"\nQueue is not empty\n";
					break;
					
			case 5: exit(0);
		}
		
		obj.display();
		
	}while(ans=='y');
	return 0;
}

