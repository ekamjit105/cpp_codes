#include<iostream>

using namespace std;

class Node
{
	public:
	int row,column,value;
	Node *next;
};

template <class t>
class sparselist
{
	Node *head;
	t arr[10][10];
	
	public:
	int count=0;										//to count nodes
	int nr, nc;											//number of rows and columns of matrix								
	sparselist()
	{
		head=NULL;
		count=0;
		
		for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		arr[i][j]=0;	
	}
	
	Node *createNode(int r,int c, t v)
	{
		Node *temp=new Node;
		temp->row=r;
		temp->column=c;
		temp->value=v;
		temp->next=NULL;
		return temp;
	}
	
	void displaylist()
	{	
		cout<<"\n\nCurrent List\n";
		Node *temp=head;
		
		cout<<"\nRows:    ";										//to display all the row values
		while (temp!=NULL)
		{
			cout<<temp->row<<" ";
			temp=temp->next;
		}
		
		temp=head;
		cout<<"\nColumns: ";										//to display all the column values
		while (temp!=NULL)
		{
			cout<<temp->column<<" ";
			temp=temp->next;
		}
		
		temp=head;
		cout<<"\nValues:  ";										//to display all the node data values
		while (temp!=NULL)
		{
			cout<<temp->value<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	
	//LIST OPERATIONS
	
	void Inputlist()
	{	int r,c;
		t v;
		cout<<"\nEnter row: ";
		cin>>r;
		cout<<"\nEnter column: ";
		cin>>c;
		
		if(count==0)
		{
		cout<<"\nThis column will denote the number of rows and column of sparse matrix";
		v=0;
		//first column of the linked list contains number of rows and columns of the matrix
		}
		
		else
		{	do
			{cout<<"\nEnter value: ";
			cin>>v;
			if(v==0)
			cout<<"\nPlease enter a non-zero value!";
			}while(v==0);
		}
		insertend(r,c,v);
		displaylist();
		converttomatrix();
	}
	
	void insertend(int r,int c, t v )
	{
		Node *temp;
		temp=createNode(r,c,v);
		
		if(head==NULL)												
		head=temp;
		
		else
		{	Node *copy=head;
			while(copy->next!=NULL)
			{copy=copy->next;
			}
		copy->next=temp;
		}
		
		count++;
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
			delete temp;
			count--;
		}

	}
	
	void deletebydata(t n)
	{	
		if(head==NULL)
		{cout<<"\nThere is no node in the list";
		return;
		}
		
		if(head->value==n)												//first node to be deleted
		{deletebeg();
		return;
		}
		
		else
		{
			Node *temp=head->next;
			Node *prev=head;
			while(temp->next!=NULL && temp->value!=n)
			{
				prev=temp;
				temp=temp->next;
			}
			
			if(temp->value==n)
			{prev->next=temp->next;
			delete temp;}
			
			else
			cout<<"\nElement not found!";
		}
		
	}
	
	void converttomatrix()
	{	
		Node *temp=head;
		if(temp!=NULL)
		{
		nr=temp->row;
		nc=temp->column;
		//first column of the linked list contains number of rows and columns of the matrix
														
		temp=temp->next;
			while(temp!=NULL)
			{	
				arr[temp->row][temp->column]=temp->value;
				temp=temp->next;
			}
		}
		else
		cout<<"\nThere are no nodes in the list!";
		displaymatrix();
	}
	
	//MATRIX OPERATIONS
	
	void displaymatrix()
	{	cout<<"\nDisplaying the matrix\n";
		for(int i=0;i<nr;i++)
		{cout<<endl;
		for(int j=0;j<nc;j++)
		cout<<" "<<arr[i][j];
		} 
		cout<<endl;
	}
	
	void Inputmatrix()
	{
		if(count==0)													
		{cout<<"\nEnter the number of Rows: ";
		cin>>nr;
		cout<<"\nEnter the number of Columns: ";
		cin>>nc;
		insertend(nr,nc,0);
		//first column of the linked list contains number of rows and columns of the matrix
		}
	
		else
		{
		int r,c;
		t v;
		cout<<"\nFor the new element\nenter row:";
		cin>>r;
		cout<<"\nenter column: ";
		cin>>c;
		do
		{	cout<<"\nenter value: ";
			cin>>v;
			if(v==0)
			cout<<"\nPlease enter a non-zero value!";						//matrix already initialised with zero values
		}while(v==0);
		
		arr[r][c]=v;
		insertend(r,c,v);
		}
	
	displaymatrix();
	displaylist();	
	}
	
	void deletematelement()
	{	int r,c;
		t v;
		bool deleted=false;
	
		
	
		Node *temp=head;										//starting with the second node
		if(temp!=NULL)
		{	temp=temp->next;
			if(temp!=NULL)
			{	
				cout<<"\nEnter the row value of the element to be deleted: ";
				cin>>r;
				cout<<"\nEnter the column value of the element to be deleted: ";
				cin>>c;
				
				while(temp!=NULL)
				{	if(temp->row==r && temp->column==c)
					{v=temp->value;
					arr[r][c]=0;
					deleted=true;
					break;
					}
				temp=temp->next;
				}
			if(deleted)
			deletebydata(v);
			}
			else
			{cout<<"\nMatrix is empty!\n";
			displaymatrix();
			return;}
		}
		else
		{cout<<"\nLinked List and Matrix both are empty!\n";
		return;}
		
		displaymatrix();
		displaylist();	
	}
};

int main()
{	
	sparselist <int> obj;
	int op;
	char cont='y';
	int choice;
	cout<<"\n\t\t * Linked List and Sparse Matrix conversions*\n";
	cout<<"\nEnter a choice:\n1.Sparse Matrix to Linked List\n2.Linked list to Sparse Matrix\n=>";
	cin>>choice;
	
	if(choice==1)
	{
	cout<<"\n - Sparse Matrix to Linked List conversion -\n";
	
	while(cont=='y'||cont=='Y')
	{
		cout<<"\n Choose an option: ";
		cout<<"\n1.Input an element \n2.Delete an element from the Matrix\n3.Exit\n=>";
		cin>>op;

		switch(op)
		{
		case 1: obj.Inputmatrix();
				break;
				
		case 2: obj.deletematelement();
				break;
		
		case 3: exit(0);
		}
	}//while
	}//if	
	
	
	else if(choice==2)
	{	cout<<"\n - Linked List to Sparse Matrix conversion -\n";
		while(cont=='y'||cont=='Y')
		{
		cout<<"\n choose an option: ";
		cout<<"\n1.Enter an element in the list \n2.Delete an element from the list\n3.Exit\n=>";
		cin>>op;
		switch(op)
		{
		case 1: obj.Inputlist();
				break;
				
		case 2: int v;
				do
				{cout<<"\nEnter value: ";
				cin>>v;
				if(v==0)
				cout<<"\nPlease enter a non-zero value!";
				}while(v==0);
				obj.deletebydata(v);
				obj.displaylist();
				obj.converttomatrix();
				break;
		
		case 3: exit(0);
		}//switch
		}//while
	}
	
	else cout<<"\nInvalid option entered!";
	return 0;
}
	
