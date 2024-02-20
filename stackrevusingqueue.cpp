#include<iostream>

using namespace std;


class queueNode
{
	public:
	int data;
	queueNode *next;
};

template <class t>
class myqueue
{
	queueNode *head,*tail;
	int count=0;
	
	public:
	myqueue()
	{
		head=NULL;
		tail=NULL;
		count=0;
	}
	
	queueNode *createNode(t n)
	{
		queueNode *temp=new queueNode;
		temp->data=n;
		temp->next=NULL;
		return temp;
	}
	
	void insertend(t n)
	{
		queueNode *temp;
		temp=createNode(n);
		
		if(isempty())												//if it is the first element
		{head=temp;
		tail=temp;}
		
		else
		{tail->next=temp;
		tail=temp;
		}
		count++;
	}
	
	void display()
	{	cout<<" ";
		queueNode *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	
	t deletebeg()
	{	t deleted=-1;
		if(isempty())
		{cout<<"\nThere is no node in the list";
		
		}
		
		else
		{	queueNode *temp=head;
			deleted=temp->data;
			head=head->next;
			if(head==NULL)												//last node deleted
			tail=NULL;
			delete temp;
			count--;
		}
		return deleted;
	}
	
	t frontdisplay()
	{return head->data;
	}

	bool isempty()
	{
		if(head==NULL)
		return true;
		return false;
	}
};


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
	
	void reversestack()
	{
		myqueue <t> obj;
		t data;
		while(!isempty())
		{data=pop();
		obj.insertend(data);
		}
		
		while(!obj.isempty())
		{data=obj.deletebeg();
		push(data);
		}
			
	}
};


int main()
{	
	mystack <int> obj;
	
	char cont='y';
	cout<<"\t\t * Reverse Stack using Queue *\n";
	while(cont=='y'||cont=='Y')
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
					
			case 3: obj.reversestack();
					break;
					
			case 4: exit(0);
		}
	
	}

	return 0;
}
	
