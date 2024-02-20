//doubly linked list with both head and tail
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
		
		if(head==NULL)												//no node in the list
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
	
	
	void insertpos(t n, int pos)
	{
		Node *temp;
		temp=createNode(n);
		                                    	
		int i=1;												//position counter
		
		if(head==NULL)
		{	if(pos==0)
			{cout<<"\nThis is the first node\n";
			head=temp;
			tail=temp;
			count++;
			}
			else
			{cout<<"The list is empty so the node can be added at 0 index position only"; 
			return;}
		}
		
		else if(pos==0)											//list is not empty and position in 0
		insertbeg(n);
		
		else if(pos==count)										//insert as last element
		insertend(n);
		
		else
		{
			Node *copy=head;
			
			while(copy->next!=NULL && i!=pos)				//till it reaches the required position or the end of list
			{copy=copy->next;
			i++;
			}
			
			if(i==pos)										//position found
			{temp->next=copy->next;
			copy->next=temp;
			temp->prev=copy;
			temp->next->prev=temp;
			count++;
			}
			else
			{cout<<"\nPosition not found!\n";
			}
		}
	}
	
	bool checksorted()
	{	bool sorted=true;
		Node *temp=head;
		
		while(temp->next!=NULL)								
		{
			if(temp->next->data < temp->data)					//to check if the list is sorted in ascending order
			{sorted=false;
			break;}
			temp=temp->next;
		}	
		return sorted;
	}
	
	void insertsorted(t n)
	{
		Node *temp;
		temp=createNode(n);
		
		if(head==NULL)											//empty list
		{
			cout<<"\nThis is the first node\n";
			head=temp;
			tail=temp;
		}
		
		
		else if(head->next==NULL)								//single node
		{	cout<<"\nThere is a single node in the list";
			if(n<head->data)
			{insertbeg(n);
			}
			else
			{insertend(n);
			}
		}
		
		else
		{
			bool sorted=checksorted();							//checks if the list is sorted or not
			if(!sorted)
			cout<<"\n The list is not sorted!\n";
			
			else
			{
				cout<<"\n The list is sorted\n";
				Node *copy=head;
			
				if(copy->data<n)					//when given element is greater than the first element
				{	
					while(copy->next->data<n)		
					{copy=copy->next;				
					
					if(copy->next==NULL)			//if the selected element is the last element in the list
					break;
					}	
					
					if(copy->next!=NULL)			//if we get the required position in between the list and not at the last
					{temp->next=copy->next;
					copy->next=temp;
					temp->prev=copy;
					temp->next->prev=temp;
					}
					
					else 							//bigger than all the elements in the list
					insertend(n);
				
				}
				else  								//when given element is smaller than all the elements
				{insertbeg(n);}
			}
		}
		count++;
	}
	
	
	int listlinears(t n)
	{	int found=0;
		if(head==NULL)
		{	cout<<"There is no node in the list";
			return -1;
		}
		
		else
		{	
			Node *temp=head;
			while(temp!=NULL && temp->data!=n)
			{
				temp=temp->next;
				found++;
			}
			
			if(temp==NULL)
			{cout<<"\nNo such node found!";
			return -1;
			}

			return found; 										//returns position of found element			
		}
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
		if(head==NULL)
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
		if(head==NULL)
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
	
	void deletepos(int n)
	{	
		if(head==NULL)
		{cout<<"\nThere is no node in the list";
		return;
		}
		
		if(n==0)														//first index position
		{deletebeg();
		return;
		}
		
		if(n==count-1)													//last index position
		{deleteend();
		return;}
		
		else
		{	int i=1;
			if(n<count)
			{
			Node *temp=head->next;
			Node *tempprev=head;
			while(temp->next!=NULL && i!=n)
			{
				tempprev=temp;
				temp=temp->next;
				i++;
			}
			
			if(i==n)													//position found
			{tempprev->next=temp->next;
			temp->next->prev=tempprev;
			delete temp;
			count--;
			}
			}
			else
			cout<<"\nElement not found!";								//list exhausted
		}
	}
	
	void deletebydata(t n)
	{	
		if(head==NULL)
		{cout<<"\nThere is no node in the list";
		return;
		}
		
		if(head->data==n)												//first index position
		{deletebeg();
		return;
		}
		
		if(n==tail->data)													//last index position
		{deleteend();
		return;}
		
		else
		{
			Node *temp=head->next;
			Node *tempprev=head;
			while(temp->next!=NULL && temp->data!=n)
			{
				tempprev=temp;
				temp=temp->next;
			}
									
			if(temp->data==n)										//last element to be deleted
			{tempprev->next=temp->next;
			temp->next->prev=tempprev;
			delete temp;
			count--;
			}
			
			else
			cout<<"\nElement not found!";								//list exhausted
		}
		
	}
	
	void reverselist()
	{	
		
		
		Node *p,*c,*n;
		p=NULL;
		c=head;
		tail=head;
		n=NULL;
		
		while(c!=NULL)
		{	n=c->next;
			c->next=p;
			if(p!=NULL)
			p->prev=c;
			p=c;
			c=n;
		}
		head=p;
	}
	
	dblinkedlist operator + (dblinkedlist &l2)
	{	
		dblinkedlist l3;
		Node *temp1,*temp2;

			temp1=head;
			temp2=l2.head;
		
		if(head==NULL)
		{	cout<<"\nNo elements in first list";
			
			//then it would return the second list as the resultant list 
			while(temp2!=NULL)
			{	l3.insertend(temp2->data);
				temp2=temp2->next;
			}
			return l3;
		}
		
		if(l2.head==NULL)
		{	cout<<"\nNo elements in Second list";
			
			//then it would return the first list as the resultant list
			while(temp1!=NULL)
			{	l3.insertend(temp1->data);
				temp1=temp1->next;
			}
			return l3;
		}
		
		if(checksorted()&&l2.checksorted())			//to check if both the lists are sorted		
		{	
			while(temp1!=NULL && temp2!=NULL)
			{	
				
				if(temp1->data < temp2->data)
				{l3.insertend(temp1->data);
				temp1=temp1->next;}
			
				else
				{l3.insertend(temp2->data);
				temp2=temp2->next;}
			}
			
			//now copying the rest of the elements of the list that hasn't been exhausted
			while(temp2!=NULL)
			{	l3.insertend(temp2->data);
				temp2=temp2->next;
			}
			
			while(temp1!=NULL)
			{	l3.insertend(temp1->data);
				temp1=temp1->next;
			}
		}
		else
		{	if(!checksorted())
			cout<<"\nFirst list not sorted";
			else
			cout<<"\nSecond list not sorted";
			return l3;	
		}
	
		return l3;
	}
	
	dblinkedlist listunion (dblinkedlist &l2)
	{	
		dblinkedlist l3;
		Node *temp1,*temp2,*temp3;
		temp1=head;
		temp2=l2.head;
			
		if(head==NULL)
		{	cout<<"\nNo elements in first list";
			
			//then it would return the second list as the resultant list 
			while(temp2!=NULL)
			{	l3.insertend(temp2->data);
				temp2=temp2->next;
			}
		return l3;
		}
		
		if(l2.head==NULL)
		{	cout<<"\nNo elements in Second list";
			
			//then it would return the first list as the resultant list 
			while(temp1!=NULL)
			{	l3.insertend(temp1->data);
				temp1=temp1->next;
			}
		return l3;
		}
		
		//when both the lists are filled
		
		while(temp1!=NULL)					//copied all the elements of the first list to resultant list
		{	l3.insertend(temp1->data);
			temp1=temp1->next;
		}
			
		while(temp2!=NULL)					//searching for same elements in second list
		{	temp3=l3.head;
			int found=0;
			
			while(temp3!=NULL)
			{if(temp2->data==temp3->data)
				{found=1;
				break;}
				temp3=temp3->next;
			}
			if(found==0)
			l3.insertend(temp2->data);
				
			temp2=temp2->next;
		}
			
		return l3;
	}
	
	dblinkedlist listintersection (dblinkedlist &l2)
	{	
		dblinkedlist l3;
		Node *temp1,*temp2;
		temp1=head;
			
		if(head==NULL || l2.head==NULL)
		{cout<<"\nNo elements in first list";
		cout<<"\nResultant list would be empty";
		return l3;
		}
		
		while(temp1!=NULL)
		{	temp2=l2.head;
			while(temp2!=NULL)
			{
				if(temp1->data==temp2->data)
				{l3.insertend(temp1->data);
				break;}
				temp2=temp2->next;
			}
			temp1=temp1->next;
		}
			
		return l3;
	}
	
	dblinkedlist mergeunsorted (dblinkedlist &l2)
	{
		dblinkedlist l3;
		Node *temp1,*temp2;

			temp1=head;
			temp2=l2.head;
		
		if(head==NULL)
		{	cout<<"\nNo elements in first list";
			
			//copying all the elements of second list as the resultant list
			while(temp2!=NULL)
			{	l3.insertend(temp2->data);
				temp2=temp2->next;
			}
			return l3;
		}
		
		if(l2.head==NULL)
		{	cout<<"\nNo elements in Second list";
			
			//copying all the elements of first list as the resultant list
			while(temp1!=NULL)
			{	l3.insertend(temp1->data);
				temp1=temp1->next;
			}
			return l3;
		}
			
			while(temp1!=NULL)								//copying all the elements of first list
			{	l3.insertend(temp1->data);
				temp1=temp1->next;
			}
			while(temp2!=NULL)								//copying all the elements of second list
			{	l3.insertend(temp2->data);
				temp2=temp2->next;
			}
	
		return l3;
	}
	
	void reachmid()
	{	if(head==NULL)
		{cout<<"\nNo element in the list";
		return;}
		
		Node *temp =head;
		Node *temp2=tail;
		while(temp!=temp2 && temp->next!=temp2)
		{temp=temp->next;
		temp2=temp2->prev;
		}
		cout<<"\n The middle element will be : "<<temp->data;
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
	int data=0,position=0;
	
	cout<<"\n choose an option: ";
	cout<<"\n1.Insert at Beginning\n2.Insert at Position\n3.Insert at end\n4.Insert in a sorted list\n5.Search an element\n";
	cout<<"\n6.Delete from Beginning\n7.Delete from end\n8.Delete from position\n9.Delete by element\n";
	cout<<"\n10.Reverse List\n11.Merging two Sorted lists\n12.Merge two unsorted lists\n13.Union of two lists\n14.Intersection of two lists\n15.Reach Middle element without counter\n16.Exit program\n\n=>";
	cin>>op;
	
	switch(op)
	{
		case 1: cout<<"\nEnter data of the new node: ";
				cin>>data;
				list.insertbeg(data);
				break;
			
		case 2: cout<<"\nEnter data of the new node: ";
				cin>>data;
				cout<<"\nEnter Index position of the new node: ";
				cin>>position;
				list.insertpos(data,position);
				break;
				
		case 3: cout<<"\nEnter data of the new node: ";
				cin>>data;
				list.insertend(data);
				break;	
				
		case 4:	cout<<"\nEnter data of the new node: ";
				cin>>data;
				list.insertsorted(data);
				break;
				
		case 5:	list.display();
				cout<<"\nEnter data of the node to be searched: ";
				cin>>data;
				position=list.listlinears(data);
				if(position!=-1)
				cout<<"\nThis node exists at index position "<<position<<" in the list";
				else
				cout<<"\nThis node does not exists";
				break;
				
		case 6:	list.deletebeg();
				cout<<"\n\nAfter deletion";
				break;
				
		case 7:	list.deleteend();
				cout<<"\n\nAfter deletion";
				break;
		
		case 8: cout<<"\nEnter Index position of the node to be deleted: ";
				cin>>position;
				list.deletepos(position);
				cout<<"\n\nAfter deletion";
				break;		
				
		case 9: cout<<"\nEnter data of the new node: ";
				cin>>data;
				list.deletebydata(data);
				cout<<"\nAfter deletion";
				break;	
				
		case 10: cout<<"\n\nBefore reversal";
				 list.display();
				 list.reverselist();
				 cout<<"\nAfter reversal";
				 list.display();
				 break;
			
		case 11: {int n;
				dblinkedlist <int>list2,result ;
				 cout<<"\nEnter the number of elements in second list: ";
				 cin>>n;
				 while(n>0)
				 {	cout<<"\nEnter element to be entered in list 2: ";
					cin>>data;
					list2.insertend(data);
					n--;
				 }
				 cout<<"\nThe first list is: ";
				 list.display();
				 cout<<"\nThe second list is: ";
				 list2.display();
				 result=list+list2;
				 cout<<"\n\nThe resultant list will be: ";
				 result.display();}
				 break;
				 
		case 12: {int n;
				dblinkedlist <int>list2,result ;
				 cout<<"\nEnter the number of elements in second list: ";
				 cin>>n;
				 while(n>0)
				 {	cout<<"\nEnter element to be entered in list 2: ";
					cin>>data;
					list2.insertend(data);
					n--;
				 }
				 cout<<"\nThe first list is: ";
				 list.display();
				 cout<<"\nThe second list is: ";
				 list2.display();
				 result=list.mergeunsorted(list2);
				 cout<<"\n\nThe resultant list will be: ";
				 result.display();}
				 break;
				 
		case 13: {int n;
				dblinkedlist <int>list2,result ;
				 cout<<"\nEnter the number of elements in second list: ";
				 cin>>n;
				 while(n>0)
				 {	cout<<"\nEnter element to be entered in list 2: ";
					cin>>data;
					list2.insertend(data);
					n--;
				 }
				 cout<<"\nThe first list is: ";
				 list.display();
				 cout<<"\nThe second list is: ";
				 list2.display();
				 result=list.listunion(list2);
				 cout<<"\n\nThe resultant list will be: ";
				 result.display();}
				 break;
				 
		case 14: {int n;
				dblinkedlist <int>list2,result ;
				 cout<<"\nEnter the number of elements in second list: ";
				 cin>>n;
				 while(n>0)
				 {	cout<<"\nEnter element to be entered in list 2: ";
					cin>>data;
					list2.insertend(data);
					n--;
				 }
				 cout<<"\nThe first list is: ";
				 list.display();
				 cout<<"\nThe second list is: ";
				 list2.display();
				 result=list.listintersection(list2);
				 cout<<"\n\nThe resultant list will be: ";
				 result.display();}
				 break;

		case 15:list.reachmid();
				break;	
		
		case 16: exit(0);
		
		default: cout<<"\nIncorrect option chosen";
	}
	
	}

	return 0;
}
	
