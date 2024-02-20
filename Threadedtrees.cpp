//Ekamjit Singh
//2019CSC1001

#include <iostream>
using namespace std;


class ThreadedNode 
{
	public:
	int data;
	ThreadedNode *left, *right;
	int successor;
	
	ThreadedNode() 
	{
	left = right = NULL;
	}
	ThreadedNode(int e, ThreadedNode *l = NULL, ThreadedNode *r = NULL)	//parametrized constructor
	{
	data = e;
	left = l;
	right = r;
	successor = 0;
	}
};

template <class t>
class ThreadedTree 
{
	public:
	ThreadedNode * root;
	
	ThreadedTree() 
	{
	root = NULL;
	}
	void insert(t);
	void inorder();
	void displaycall();								//Displaying the tree recursively
	void display(ThreadedNode *ptr, int level);
};

template <class t>
void ThreadedTree <t> ::insert(t el) 
{
	ThreadedNode *p = root, *prev = NULL, *newNode;
	newNode = new ThreadedNode(el);
	if (root == NULL)
	{ 	// tree is empty;
		root = newNode;
		return;
	}
	
	while (p != NULL) 
	{ 	// find a place to insert newNode;
		prev = p;
		if (p->data > el) 
		p = p->left;
		else if (p->successor == 0) // go to the right node only if it is a descendant, not a successor;
		p = p->right;
		else break; // don’t follow successor link;
	}
	
	if (prev->data > el)
	{ 	// if newNode is left child of its parent, the parent also becomes its successor;
		prev->left = newNode;
		newNode->successor = 1;
		newNode->right = prev;
	}
	
	else if (prev->successor == 1) 
	{ 	// if newNode is right child of its parent, the parent’s successor also becomes its successor;
		newNode->successor = 1;
		prev->successor = 0;
		newNode->right = prev->right; // make parent’s successor newNode’s successor,
		prev->right = newNode;
	}
	else 
	prev->right = newNode; // otherwise it has no successor;
}

template <class t>
void ThreadedTree <t> ::inorder() 
{
	ThreadedNode *prev, *p = root;
	if (p != NULL) 
	{ 	
		while (p->left) 			// go to the leftmost node;
		p = p->left;
		
		while(p) 
		{
			cout<<" "<<p->data<<" ";
			prev = p;
			p = p->right; 			// go to the right node
			if (p && prev->successor == 0) 
			{ 	// only if it is a descendant
				while (p->left) // go to the leftmost node,
				p = p->left; // otherwise visit the successor
			}
		}
	}
}

	template <class t>
	void ThreadedTree <t> :: displaycall()
	{
	    if(!root)
	    {
			cout<<"The Tree is empty"<<endl;
			return;
		}
		display(root,1);				//to display the tree recursively
	}
	
	template <class t>
	void ThreadedTree <t> :: display(ThreadedNode *ptr, int level)
	{
		int i;
		if (ptr != NULL)
		{	if (ptr->successor == 0)
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
			cout<<ptr->data;
			display(ptr->left, level+1);
		}
	}

int main()
{
	ThreadedTree <int> obj;
	int op;

	int data;
	
	cout<<"\n\t\t* Threaded Tree *";
	
	while(1){
		cout<<endl<<"\nChoose an operation: "<<endl<<endl;

		cout<<"1. Insert a node\n2. Inorder traversal \n3. Exit \n=>";
		cin>>op;
		
		cout<<endl;
		switch(op)
		{
			case 1:	cout<<"Enter the data value: "<<endl;
					cin>>data;
					obj.insert(data);
					
					cout<<endl;
					break;		
			
			case 2:	obj.inorder();
					break;
			
						
			case 3: exit(0);
			
			
			default:	cout<<"Invalid Option! Please choose again"<<endl;
						break; 
			
		}
		cout<<endl;
		obj.displaycall();
		cout<<endl<<endl;
	}
		
	return 0;
}

