#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node *next;
};

class cqsll
{
	node *head, *tail;
	public:
	cqsll()
	{
		head=NULL;
		tail=NULL;
	}
	node * createnode(int d)
	{
		node *temp=new node;
		temp->data=d;
		temp->next=NULL;
		return temp;
	}
	void insertend(int d)
	{
		node *temp=createnode(d);
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			temp->next=head;
			tail=temp;
		}
	}
	
	void deletebeg()
	{
		if(head!=NULL)
		{	node *temp = head;
			if(head==tail)
			{	
				head=NULL;
				tail=NULL;
				delete temp;
			}
			else
			{
				head=head->next;
				tail->next=head;	//new head
				delete temp;
			}
			
		}
		else
		cout<<"\nLL empty\n";
	}
	
	void deleteend()
	{
		if(head!=NULL)
		{
			node *temp = head;
			
			if(head==tail)
			{head=NULL;
			tail=NULL;
			delete temp;
			}
			else
			{
				while(temp->next!=tail)
				temp=temp->next;
				
				if(temp==head)
				temp->next=NULL;
				else
				temp->next=head;
				
				delete tail;
				tail=temp;
			}
		}
		else
		cout<<"\nLL empty\n";
	}
	
	void display()
	{
		if(head!=NULL)
		{
			node *temp=head;
			if(head==tail)
			cout<<head->data;
			
			else
			{
				do
				{
					cout<<temp->data;
					temp=temp->next;
				}while(temp!=head);
			}
		}
		else
		cout<<"\nLL empty\n";
	}
	
};	

int main()
{	cqsll obj;
	while(1)
	{	int op,data;
		cout<<"\nChoose option : 1. insert at end 2.delete from beg 3.delete from end\n=>";
		cin>>op;
		if(op==1)
		{cout<<"\nenter data : ";
		cin>>data;
		obj.insertend(data);
		}
		if(op==2)
		obj.deletebeg();
		if(op==3)
		obj.deleteend();
		
		obj.display();
	}
	return 0;
}
