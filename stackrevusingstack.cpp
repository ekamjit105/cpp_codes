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
	
	void reversestack(mystack s)
	{	t data,temp;
		int size=count;
		for(int j=0;j<size;j++)
		{
			data=pop();
			temp=data;
			for(int i=0;i<size-1-j;i++)
			{	
				data=pop();
				s.push(data);
			}

			push(temp);
			while(!s.isempty())
			push(s.pop());
		}	
	}
};


int main()
{	
	mystack <int> obj;
	
	char cont='y';
	cout<<"\t\t * Reverse Stack using Stack *\n";
	while(cont=='y')
	{
	cout<<"\n\tCurrent Stack: ";
	obj.display();
	
		int op;
		int data;
		cout<<"\nEnter an option: ";
		cout<<"\n1.Insert element\n2.Delete element\n3.Reverse Stack \n4.exit\n=>";
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
					
			case 3: {mystack <int> obj2;
					obj.reversestack(obj2);
					}
					break;
					
			case 4: exit(0);
		}
	
	}

	return 0;
}
	
