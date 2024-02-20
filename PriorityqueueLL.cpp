#include<iostream>

using namespace std;

class Node
{
	public:
	int data;
	int pnum;			//priority number
	Node *next;
};

template <class t>
class PqueueLL
{
	Node *head;
	int count=0;
	
	public:
	PqueueLL()
	{
		head=NULL;
		count=0;
	}
	
	Node *createNode(t n, int p)
	{
		Node *temp=new Node;
		temp->data=n;
		temp->pnum=p;
		temp->next=NULL;
		return temp;
	}
	
	void insert(t n, int p)
	{
		Node *temp;
		temp=createNode(n,p);
		
		if(isempty())												//if it is the first element
		{head=temp;}
			
		else if(head->pnum > p)
		{
			temp->next=head;
			head=temp;
		}	
			
		else 
		{	Node *cur=head;
			Node *prev=NULL;
			while(cur!=NULL && cur->pnum < p )
			{
				prev=cur;
				cur=cur->next;
			}
			prev->next=temp;
			temp->next=cur;
		}
		count++;
	}
	
	void display()
	{	cout<<" ";
		Node *temp=head;
		cout<<"\n\tPQueue:\t"; 
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		temp=head;
		cout<<"\n\tPorder:\t"; 
		while(temp!=NULL)
		{
			cout<<temp->pnum<<" ";
			temp=temp->next;
		}
	}
	
	void deletebeg()
	{
		if(isempty())
		{cout<<"\nThere is no node in the list";
		return;
		}
		
		else
		{	Node *temp=head;
			head=head->next;
			delete temp;
			count--;
		}
	}
	
	t min()
	{return head->data;
	}

	bool isempty()
	{
		if(head==NULL)
		return true;
		return false;
	}
};


int main()
{	int ch; 
	int data, priority;
	PqueueLL <int> obj;
	cout<<"\n\t\t* Priority Queue using Linked List *\n";
	while(1)
	{
		cout<<"\nChoose an option: \n1. Insert in Priority queue \n2. Delete from priority queue(min priority number) \n3. Display element with minimum priority number\n4. Exit\n=>";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\nEnter data: ";
					cin>>data;
					cout<<"\nEnter priority value: ";
					cin>>priority;
					obj.insert(data,priority);
					break;
					
			case 2: obj.deletebeg();
					break;
					
			case 3: cout<<"Minimum priority number element : "<<obj.min();
					break;
					
			case 4: exit(0);
			
			default: cout<<"\nInvalid option chosen";
		}
	
		obj.display();
		cout<<endl;
	
	}
	
	
	
	
	return 0;
}
