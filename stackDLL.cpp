#include<iostream>

using namespace std;

class Node
{
	public:
	int data;
	Node *prev,*next;
};

template <class t>
class mystack
{
	Node *head,*tail;
	int count;
	
	public:
	mystack()
	{
		head=NULL;
		tail=NULL;
		count=0;
	}
	
	Node *createNode(t n)
	{
		Node *temp=new Node;
		temp->data=n;
		temp->next=NULL;
		temp->prev=NULL;
		return temp;
	}
	
	
	
	void push(t n)
	{
		Node *temp=createNode(n);
		
		temp->next=head;
		
		if(head!=NULL)								//head==NULL if there was a single element in the list
		head->prev = temp;
		
		head=temp;
		
		if(head->next==NULL)						//if this is the first element																											
		tail=temp;
		
		count++;
	} 
	
	t pop()
	{	t deleted=-1;
		if(!isempty())
		{	Node *temp=head;
			deleted=head->data;
			head=head->next;
			if(head==NULL)												//single node deleted
			tail=NULL;
			delete temp;
			count--;
		}
		return deleted;
	}
	
	void display()
	{	cout<<"\n\n";
		Node *temp=head;
		while(temp!=NULL)
		{
			cout<<"\t\t"<<temp->data<<"\n";
			temp=temp->next;
		}
	}
	
	bool isempty()
	{
		if(head==NULL)									//no node
		return true;
		return false;
	}
	
	t peek()
	{
		return head->data;
	}

};


int main()
{	
	mystack <int> obj;
	
	char cont='y';
	cout<<"\t\t * Stack as Double Linked List *\n";
	while(cont=='y'||cont=='Y')
	{
	cout<<"\n\tCurrent Stack: ";
	obj.display();
	
		int op;
		int data;
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
	
	}

	return 0;
}
	
