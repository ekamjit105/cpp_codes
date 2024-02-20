#include <iostream> 
using namespace std; 

class node
{
  //Object Of This Class Denotes a Node in the Binary Search Tree
  public:
    
  int data;
  node *left, *right;
 
    
  node(int value)
  {
    data=value;
    left=NULL;
    right=NULL;
  }
};

class bstarr
{
  
  int count;
  
  public:
  node *root;

   bstarr()
	{
     root=NULL;
     count=0;
   }

  node* createnode(int data)
  {
     node* temp=new node(data);
     return temp;
  }
   
   void insertrec(int val)	//function to insert array values recursively into BST  
   {
	 //this insertion ensures a value that is already presesnt in the tree is not entered again  
     recurin(root, val);
     count++;
   }

	
	void recurin(node* &p, int val)		
	{
		if(root==NULL)
		{
			node *temp=createnode(val);
			root=temp;
		}
		
		else if(val < p->data)
		{
			if(p->left==NULL)
			p->left=createnode(val);
			else
			recurin(p->left,val);
		}
		
		else if(val > p->data)
		{
			if(p->right==NULL)
			p->right=createnode(val);
			else
			recurin(p->right,val);
		}
		
	}
   void getinorder()
   {
	   inorder(root);
	}
   
	void inorder(node* root) //function for inorder traversal in binary tree
	{ 
		if (root == NULL) 
			return; 
		else { 
			inorder(root->left); 
			cout << root->data << " "; 
			inorder(root->right); 
		} 
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
	
	void display(node *ptr, int level)
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
			cout<<ptr->data;
			display(ptr->left, level+1);
		}
	}
	
};

int main()
{
	bstarr obj;
	int num,arr[10];
	char ch;
	cout<<"\n\t\tRemove duplicates from array using BST\n";
	do
	{
		cout<<"\n Enter the number of elements in array : ";
		cin>>num; 
		cout<<"\n Enter array\n";
	
		for(int i=0;i<num;i++)
		{cout<<"\n Enter element "<<i+1<<" : ";
		cin>>arr[i];}
		
		cout<<"\n Removing duplicates\n\n";
		for(int i=0;i<num;i++)
		{	
			obj.insertrec(arr[i]);
		}
		
		cout<<endl<<"Array is : ";		
		obj.getinorder();
	 
	 cout<<"\n\nTry another example? y/n :";
	 cin>>ch; 
	}while(ch=='y'||ch=='Y');
	
	return 0;
	
}






























/*// C++ Program of above implementation 
#include <iostream> 
using namespace std; 
  
// Struct declaration 
struct Node { 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
  
// Node creation 
struct Node* newNode(int data) 
{ 
    struct Node* nn 
        = new Node; 
    nn->data = data; 
    nn->left = NULL; 
    nn->right = NULL; 
    return nn; 
} 
  
// Function to insert data in BST 
struct Node* insert(struct Node* root, int data) 
{ 
    if (root == NULL) 
        return newNode(data); 
    else { 
        if (data < root->data) 
            root->left = insert(root->left, data); 
        if (data > root->data) 
            root->right = insert(root->right, data); 
        return root; 
    } 
} 
  
// InOrder function to display value of array 
// in sorted order 
void inOrder(struct Node* root) 
{ 
    if (root == NULL) 
        return; 
    else { 
        inOrder(root->left); 
        cout << root->data << " "; 
        inOrder(root->right); 
    } 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 1, 2, 3, 2, 5, 4, 4 }; 
  
    // Finding size of array arr[] 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    struct Node* root = NULL; 
  
    for (int i = 0; i < n; i++) { 
  
        // Insert element of arr[] in BST 
        root = insert(root, arr[i]); 
    } 
  
    // Inorder Traversal to print nodes of Tree 
    inOrder(root); 
    return 0; 
} 
*/


