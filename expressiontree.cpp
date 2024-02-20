#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;


/* Here, we firstly define a mystack class that acts as a normal stack 
 * and it's node denoted by object of Node class stores integer or char type data. 
 * This stack is used in converting expression from infix to postfix.
*/

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
	
	void push(t n)													//insertion at end dll
	{	
		Node *temp=createNode(n);
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
	
	void pop()															//deletion from end dll
	{	
		if(head==NULL)
		{cout<<"\nThere is no node in the list";
		}
		
		else if(head->next==NULL)						//Single element
		{	Node *temp=head;
			head=NULL;											//single node deleted
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
		return tail->data;
	}
};

/*	Object of class treenode denotes a node 
 *  in the Expression tree and stores char type data (operator or operand).
*/

class treenode
{
	public: 
	char value;
	treenode *left, *right;
	
	treenode()
	{
		left=NULL;
		right=NULL;
	}
	
	treenode(char val)
	{
		value=val;		//stores operator or operand in tree node
		left=NULL;
		right=NULL;
	}
};

/* Here we define another stack class treestack that acts as a stack for 
 * storing pointers to the tree nodes. object of class tsnode denotes a node of the
 * stack treestack and it stores pointer to a node of the binary tree. 
*/ 

class tsnode
{
	public:
	treenode* data;		//stores pointer to a tree node
	tsnode *prev,*next;
};

class treestack
{
	tsnode *head,*tail;
	int count;
	
	public:
	treestack()
	{
		head=NULL;
		tail=NULL;
		count=0;
	}
	
	tsnode *createNode(treenode* n)
	{
		tsnode *temp = new tsnode;
		temp->data = n;
		temp->next=NULL;
		temp->prev=NULL;
		return temp;
	}
	
	void push(treenode* n)													//insertion at end dll
	{	
		tsnode *temp = createNode(n);
		if(head==NULL)														//no node in the list
		{head=temp;
		tail=temp;
		}
		else
		{	
			tail->next = temp;
			temp->prev = tail;
			tail=temp;
		}
		count++;
	} 
	
	void pop()															//deletion from end dll
	{	
		if(head==NULL)
		{cout<<"\nThere is no node in the list";
		}
		
		else if(head->next==NULL)								//Single element
		{	tsnode *temp=head;
			head=NULL;											//single node deleted
			tail=NULL;
			delete temp;
			count--;
		}
		else 													//more than one element
		{
			tail=tail->prev;
			delete tail->next;
			tail->next=NULL;
			count--;
		}
		
	}
	
	void display()
	{	cout<<"\n\n";
		tsnode *temp=head;
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
	
	treenode* peek()
	{
		return tail->data;
	}
};


template <class t>
class expressiontree
{	
	string infix, ns, prefix; 
	int length, postlength;
	int p;										//stores number of paranthesis in infix
	treenode *root;
	int count;
	
	public:
	
	expressiontree()
	{
     root=NULL;
     count=0;
	}
	
	bool isoperator(char c)
	{
		if (c == '+' || c == '-' ||c == '*' || c == '/' ||c == '^')
		return true;
		return false;
	}
	
	void inputinfix()		//function to input infix
	{	
		cout<<"\nEnter infix expression : ";
		cin>>infix;
		
		length=infix.length();
		cout<<"\nDisplaying infix expression :";
		for(int i=0;i<length;i++)
		cout<<" "<<infix[i];
		p=countbrackets(infix,length);
		postlength=length-p;
	}
	
	int prec(char c) //Function to return precedence of operators
	{
		if(c == '^') return 3;
		else if(c == '*' || c == '/') return 2;
		else if(c == '+' || c == '-') return 1;
		else return -1;
	}

	int countbrackets(string s,int len)
	{
		//because the resulting array won't be containing parenthesis
		//so length of resulting array is len-countbrackets
		
		int countbrackets=0;
		for(int i = 0; i < len; i++)
		{ if(s[i] == '(')
			countbrackets+=2;
		}
		return countbrackets;
	}
	
	void topostfix()		//function to convert to postfix
	{	
		mystack <t> st;
		int j = 0;
											
		for(int i = 0; i < length; i++)
		{ 
			if(isalpha(infix[i]) || isdigit(infix[i]))
			{ ns[j++] = infix[i]; }
			
			else if(infix[i] == '(') 
			{ 	st.push('('); 
			}
			
			// If the scanned character is an ‘)’, pop and to output string from the stack until an ‘(‘ is encountered.
			else if(infix[i] == ')') 
			{ 
				while(!st.isempty() && st.peek() != '(')
				{ 	char c = st.peek();
					st.pop();
					ns[j++] = c;
				}
				
				if(st.peek() == '(')
				st.pop(); 
			}
			
			else
			{ //If an operator is scanned
				while(!st.isempty() && prec(infix[i]) <= prec(st.peek()))
				{ 	char c = st.peek();
					st.pop();
					ns[j++] = c;
				}
				st.push(infix[i]);
			}
		}
	
		while(!st.isempty())
		{ 	char c = st.peek();
			st.pop();
			ns[j++] = c;
		}
		
	}
	
	void displaypostfix()
	{	cout<<endl<<"Postfix notation will be: ";
		for(int i=0;i<postlength;i++)
		cout<<" "<<ns[i];
		cout<<endl;
	}
	
	treenode* createtreenode(char n)	//function to create a node in the expression tree
	{
		treenode *temp = new treenode(n);
		return temp;
	}
	
	void convertexptotree()				//function to create expressionn tree
	{	topostfix();					//convert in fix to postfix
		treestack st;
		treenode *temp, *top1, *top2;
		
		for(int i=0;i<postlength;i++)
		{
			if(!isoperator(ns[i]))		//if is operand
			{
				temp = createtreenode(ns[i]);
				st.push(temp);
			}
			
			else
			{	//Operator scanned
				temp = createtreenode(ns[i]);
				
				//popping first two elements
				top1=st.peek();
				st.pop();
				top2=st.peek();
				st.pop();
				
				//assigning first top node to right of operand and 
				//second top node to left of operand 
				temp->right=top1;
				temp->left=top2;
				
				st.push(temp);
			}
		}
		
		temp=st.peek();
		st.pop();
		//last node remaining in the stack is the root of tree
		
		root = temp;
		displaycall();
	}
	
	void dfs(int choice)
	{	convertexptotree();
		cout<<endl<<endl<<"\t";
		if (root == NULL)
		{
			cout<<"Tree is empty"<<endl;
			return;
		}
		
		if (choice==1)
		{cout<<"Preorder : ";
		preorder(root);}

		else if(choice==2)
		{cout<<"Inorder : ";
		inorder(root);}
	   
		else if(choice==3)
		{cout<<"Postorder : ";
		postorder(root);}
	   
	}
	
	void preorder(treenode *nodeptr)
	{	
		if (nodeptr != NULL)
		{
			cout<<nodeptr->value<<"  ";
			preorder(nodeptr->left);
			preorder(nodeptr->right);
		}
	}
	

	void inorder(treenode *nodeptr)
	{

		if (nodeptr != NULL)
		{
			inorder(nodeptr->left);
			cout<<nodeptr->value<<"  ";
			inorder(nodeptr->right);
		}
	}
	
	void postorder(treenode *nodeptr)
	{
		if (nodeptr != NULL)
		{
			postorder(nodeptr->left);
			postorder(nodeptr->right);
			cout<<nodeptr->value<<"  ";
		}
	}
	
	void evaluateexptree()		//function to evaluate expression tree
	{	convertexptotree();
		int result = eval(root);
		cout<<"\n\nThe result after evaluation will be : "<<result<<endl;
	}
	
	int toint(char a)
	{
		return a-48;						//returning integer value from ASCII value of integer
	}
	
	int eval(treenode* cur)
	{
		if (!cur) // empty tree
		return 0;
		
		if (!cur->left && !cur->right) 		// leaf node i.e, an integer
		return toint(cur->value);
		
		int l_val = eval(cur->left); 		// Evaluate left subtree
		int r_val = eval(cur->right); 		// Evaluate right subtree
		
		if (cur->value=='+')				// Check which operator to apply
		return l_val+r_val;
		if (cur->value=='-')
		return l_val-r_val;
		if (cur->value=='*')
		return l_val*r_val;
		if (cur->value=='/')
		return l_val/r_val;
		if (cur->value=='^')
		return pow(l_val,r_val);

	return -1; // invalid operator
	}
	
	
	void displaycall()
	{
	    if(!root)
	    {
			cout<<"The Tree is empty"<<endl;
			return;
		}
		display(root,1);				//to display the tree recursively
	}
	
	void display(treenode *ptr, int level)
	{

		int i;
		if (ptr != NULL)
		{
			display(ptr->right, level+1);
			cout<<endl;
			if (ptr == root)
			{
				cout<<"Root->:  ";
			}					
			else
			{
				for (i = 0;i < level;i++)
				{
					cout<<"       ";					
				}    			
			}
			cout<<ptr->value;
			display(ptr->left, level+1);
		}
	}

};

int main()
{	cout<<"\n\t\tExpression tree\n";
	expressiontree <int> obj;
	char ans='y';
	int op;
	
	obj.inputinfix();
	cout<<endl;
	while(ans=='y')
	{	cout<<"\nEnter option:\n1.Convert Infix to Postfix\n2.Create Expression tree\n3.DFS Tree traversal (recursively)\n4.Evaluate expression tree \n5.Exit\n=>  ";
		cin>>op;
		switch(op)
		{
			case 1:	obj.topostfix();
					obj.displaypostfix();
					break;
			
			case 2:	obj.convertexptotree();
					break;
					
			case 3:	{cout<<endl<<"Choices available: "<<endl<<endl;
					cout<<"\n1. Preorder Traversal\n2. Inorder Traversal\n3. Postorder Traversal\n=>"<<endl;
					int tmethod;
					cin>>tmethod;
					switch(tmethod)
					{
						case 1:	cout<<endl;
								obj.dfs(1);
								cout<<endl;
								break;
								
						case 2:	cout<<endl;
								obj.dfs(2);
								cout<<endl;
								break;
								
						case 3:	cout<<endl;
								obj.dfs(3);
								cout<<endl;
								break;
						default:cout<<"Please enter a valid choice"<<endl;
					}
					}
					break;
			
			case 4:	obj.evaluateexptree();
					break;
					
			case 5: exit(0);
			
			default:cout<<"\nInvalid option chosen!";
		}
	}
return 0;
}
