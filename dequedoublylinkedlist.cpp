#include<iostream>

using namespace std;

class Node
{
	public:
	int data;
	Node *prev,*next;
};

template <class t>
class dblinkedlist
{
	Node *head,*tail;
	int count;
	
	public:
	dblinkedlist()
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
	
	void insertend(t n)
	{	Node *temp=createNode(n);
		if(head==NULL)												//no node in the list
		{head=temp;
		tail=temp;
		}
		else
		{	
			tail->next=temp;
			temp->prev=tail;
			tail=temp;
		}
		count++;
	}
	
	void insertbeg(t n)
	{
		Node *temp=createNode(n);
		
		if(isempty())												//no node in the list
		{head=temp;
		tail=temp;
		}
		
		else														//if there are one or more elements in the list
		{head->prev=temp;
		temp->next=head;
		
		if(head->next==NULL)										//if there was only one element
		tail=head;
		
		head=temp;
		}
		count++;
	} 
	
	void display()
	{	cout<<" ";
		Node *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
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
			if(head==NULL)												//single node deleted
			tail=NULL;
			delete temp;
			count--;
		}
	}
	
	void deleteend()
	{
		if(isempty())
		{cout<<"\nThere is no node in the list";
		return;
		}
		
		else if(head->next==NULL)						//Single element
		deletebeg();
		
		else 											//more than one element
		{
			tail=tail->prev;
			delete tail->next;
			tail->next=NULL;
			count--;
		}
	}
	
	t displayfront()
	{
		return head->data;
	}
	
	int returnsize()
	{
		return count;
	}
	
	bool isempty()
	{
		if(head==NULL)
		return true;
		return false;
	}
};

int main()
{	
	dblinkedlist <int> list;
	
	int op;
	char cont='y';
	cout<<"\t\t * Linked List *\n";
	while(cont=='y'||cont=='Y')
	{
	cout<<"\n\n\tCurrent Main list: ";
	list.display();
	cout<<endl;
	int data=0;
	
	cout<<"\n choose an option: ";
	cout<<"\n1.Insert at Beginning\n2.Insert at end\n";
	cout<<"\n3.Delete from Beginning\n4.Delete from end\n";
	cout<<"\n5.Display front element \n6.Check empty \n7.Check size\n8.Exit program\n\n=>";
	cin>>op;
	
	switch(op)
	{
		case 1: cout<<"\nEnter data of the new node: ";
				cin>>data;
				list.insertbeg(data);
				break;
				
		case 2: cout<<"\nEnter data of the new node: ";
				cin>>data;
				list.insertend(data);
				break;	
				
		case 3:	list.deletebeg();
				cout<<"\n\nAfter deletion";
				break;
				
		case 4:	list.deleteend();
				cout<<"\n\nAfter deletion";
				break;
		
		case 5: if(list.isempty()==false)
				{cout<<"\nFirst element is: "<<list.displayfront();
				}
				else
				cout<<"\ndeque is empty\n";
				break;	
				
		case 6: if(list.isempty()==false)
				cout<<"\ndeque is filled";
				else
				cout<<"\ndeque is empty";
				break;	
		
		case 7: cout<<"\nSize of Deque is: "<<list.returnsize();
				break;	
	
		
		case 8: exit(0);
		
		default: cout<<"\nIncorrect option chosen";
	}
	
	}

	return 0;
}
	
