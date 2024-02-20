#include<iostream>
using namespace std;

class Node
{
	public:
	float data;
	Node *next,*prev;
};

template <class t>
class polynomial
{
	Node *head,*tail;
	int count;
	
	public:
	polynomial()
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
	
	void insert(t n)
	{
		Node *temp=createNode(n);
		
		if(isempty())												//if it is the first element
		{head=temp;
		tail=temp;}
		
		else
		{tail->next=temp;
		temp->prev=tail;
		tail=temp;
		}
		count++;
	}
	
	void deleteend()
	{
		if(isempty())
		{cout<<"\nThere is no node in the list";
		return;
		}
		
		else if(head->next==NULL)						//Single element
		{	Node *temp=head;
			head=NULL;							
			tail=NULL;
			delete temp;
			count--;
		}
		else 											//more than one element
		{
			tail=tail->prev;
			delete tail->next;
			tail->next=NULL;
			count--;
		}
	}
	
	void updatepos(int n,t val)
	{	
		if(n>=count)
		{cout<<"\nInvalid Position Entered!";
		return;}
		
		if(head==NULL)
		{cout<<"\nThere is no node in the list";
		return;
		}
		
		else
		{	int index=0;
			Node *temp=head;
			
			while(index!=n)
			{	index++;
				temp=temp->next;
			}
			temp->data=val;
		}
	}
	void display()
	{	if(!isempty())
		{
		int i=count-1;
		Node *temp=tail;
		while(temp!=head)
		{	cout<<temp->data<<"x^"<<i<<" + ";
			temp=temp->prev;
			i--;
		}
		cout<<temp->data<<"x^"<<i;
		cout<<endl;
		}
	}
	
	void add(polynomial p)
	{
		polynomial <float> result;
		
		float data;
		Node *temp1=head, *temp2=p.head;
		
		while(temp1!=NULL && temp2!=NULL)
		{	data = temp1->data + temp2->data;
			result.insert(data);
			temp1=temp1->next;
			temp2=temp2->next;
		}
		
		if(temp1==NULL)
		{while(temp2!=NULL)
			{
				result.insert(temp2->data);
				temp2=temp2->next;
			}
		}
		
		if(temp2==NULL)
		{while(temp1!=NULL)
			{
				result.insert(temp1->data);
				temp1=temp1->next;
			}
		}
		cout<<"\n\nThe resultant polynomial will be: ";
		result.display();
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
	polynomial <float> obj1,obj2,result;
	float data;
	int pos, op;
	char ans='y';
	cout<<"\n\n\t\t* POLYNOMIAL ADDITION USING LINKED LIST *";

	while(ans=='y')
	{	
		cout<<"\n\n  *Updating First Polynomial*\n\nChoose an option: \n1.Enter a new element / increase degree of polynomial\n2.Delete last element(highest degree) \n3.Update coefficient \n4.First complete. Update second polynomial\n=> ";
		cin>>op;
		switch(op)
		{
			case 1: cout<<"\nEnter data: ";
					cin>>data;
					obj1.insert(data);
					break;
				
			case 2: /*cout<<"\nEnter index position / degree of variable: ";
					cin>>pos;
					obj1.deletepos(pos);*/
					obj1.deleteend();
					break;
					
			case 3: cout<<"\nEnter index position / degree of variable: ";
					cin>>pos;
					cout<<"\nEnter data: ";
					cin>>data;
					obj1.updatepos(pos,data);
					break;
							
			case 4: ans='n';
		}
		cout<<"\nThe first polynomial is  :  ";
		obj1.display();
		cout<<"The second polynomial is :  ";
		obj2.display();
		
	}
	ans='y';
	cout<<"\n\n\t\tNow enter the second polynomial";
	while(ans=='y')
	{
		cout<<"\n\n  *Updating Second Polynomial*\n\nChoose an option: \n1.Enter a new element / increase degree of polynomial\n2.Delete last element(highest degree) \n3.Update coefficient \n4.Perform polynomial addition\n=> ";
		cin>>op;
		switch(op)
		{
			case 1: cout<<"\nEnter data: ";
					cin>>data;
					obj2.insert(data);
					break;
				
			case 2: obj2.deleteend();
					break;
					
			case 3: cout<<"\nEnter index position / degree of variable: ";
					cin>>pos;
					cout<<"\nEnter data: ";
					cin>>data;
					obj2.updatepos(pos,data);
					break;
							
			case 4: ans='n';
		}
		
		cout<<"\nThe first polynomial is  :  ";
		obj1.display();
		cout<<"The second polynomial is :  ";
		obj2.display();
	}
	
	cout<<"\n\nAdding Both the polynomials";
	obj1.add(obj2);
	return 0;
}
