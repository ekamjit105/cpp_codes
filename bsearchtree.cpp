#include <iostream>
using namespace std;

class node{
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

class bsearchtree{
  node *root;
  int count;
  
  public:
   
   bsearchtree(){
     root=NULL;
     count=0;
   }
   
   node* createnode(int data)
   {
     node* temp=new node(data);
     return temp;
   }
   
   void insertrec(int val)
   {
     recurin(root, val);
   }
   
   void recurin(node* &root, int val)
   {
     if(!root)														
     {	 															//if there isn't any data at the current selected root,
																	//add the data to this root node
       node *newnode=new node(val);									
       root=newnode;
       count++;
       return;
     }
     
     if(val < root->data)											
     {																//if the value is less than root data, left branch is chosen 
																	//root becomes left node
       recurin(root->left, val);
     }
     else
     {
       recurin(root->right, val);									//if the value is greater than root data, right branch is chosen 
																	//root becomes right node
     }
   }
   
   void insertit(int val){
     node* newnode=createnode(val);
     
     if(!root)
     {
       root=newnode;
       count++;
       return;
     }
     
     node *temp = root;
     node *prev = NULL;
     
     while(temp)										
     {
       prev=temp;
       if (val<temp->data)
       {												
          temp = temp->left;
       }
       else
       {												
         temp = temp->right;
       }
     }
     
     if (val < prev->data)								
     {	
       prev->left = newnode;
     }
     
     else
     {	
       prev->right = newnode;
     }
     count++;
   }
   
  bool search(int val)
  {
     node* p=root;
     while (p)
     {
       if (val == p->data)
       {return true;
       }
       else if (val < p->data)
       {p = p->left;
       }
       else
       {p = p->right;
       }
     }
     return false;
   }
   
   void remove(int val)
   {
		node *parent,*current;
		if(!root)
		{
			cout<<"Tree is empty!"<<endl;
			return;
		}
		
		find(val, &parent, &current);
		
		if (current->left==NULL && current->right==NULL)
		{
			if (parent == NULL)
			root=NULL;	
			
			else
			{
				if(current == parent->right)
				parent->right=NULL;	
				
				else
				parent->left=NULL;
				
			}	
		}
   }
   
	void find(int item, node **par, node **loc)
	{
		node *ptr, *ptrsave;
		if (root == NULL)
		{
			*loc = NULL;
			*par = NULL;
			return;
		}
		if (item == root->data)
		{
			*loc = root;
			*par = NULL;
			return;
		}
		if (item < root->data)
			ptr = root->left;
		else
			ptr = root->right;
		ptrsave = root;
		while (ptr != NULL)
		{
			if (item == ptr->data)
			{
				*loc = ptr;
				*par = ptrsave;
				return;
			}
			ptrsave = ptr;
			if (item < ptr->data)
            ptr = ptr->left;
			else
			ptr = ptr->right;
		}
		*loc = NULL;
		*par = ptrsave;
	}
   
   void bfs()
   {
		int l= level(root);											
		for (int i=1; i<=l; i++)
		{
			printlevel(root, i);	
		}
	}
	
	int level(node* leaf)
	{
		if (leaf == NULL)
		{  
			return 0;  
		}
		else
		{  
			int lheight = level(leaf->left);  
			int rheight = level(leaf->right);  
  
			if (lheight > rheight){  
				return(lheight + 1);  
			}
			else{
				return(rheight + 1);  
			}
		}  	
	}
	
	void printlevel(node* root, int level)
	{
		if (root == NULL) 
		return;  
		
		if (level == 1){  
			cout<<root->data<<" ";  
		}
		else if (level > 1)
		{  
			printlevel(root->left, level-1);  
			printlevel(root->right, level-1);  
		}  	
	}
   
	void dfs(int choice)
	{
		if (choice==1)
		inorder(root);
	   
		else if(choice==2)
		preorder(root);
	   
		else if(choice==3)
		postorder(root);
	   
	}
	
	void inorder(node *nodeptr){
		if (root == NULL)
		{
			cout<<"Tree is empty"<<endl;
			return;
		}
		if (nodeptr != NULL)
		{
			inorder(nodeptr->left);
			cout<<nodeptr->data<<"  ";
			inorder(nodeptr->right);
		}
	}
	
	void preorder(node *nodeptr){
		if (root == NULL)
		{
			cout<<"Tree is empty"<<endl;
			return;
		}
		if (nodeptr != NULL)
		{
			cout<<nodeptr->data<<"  ";
			preorder(nodeptr->left);
			preorder(nodeptr->right);
		}
	}
	
	void postorder(node *nodeptr)
	{
		if (root == NULL)
		{
			cout<<"Tree is empty"<<endl;
			return;
		}
		if (nodeptr != NULL)
		{
			postorder(nodeptr->left);
			postorder(nodeptr->right);
			cout<<nodeptr->data<<"  ";
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

		if (ptr != NULL)
		{
			display(ptr->right, level+1);
			cout<<endl;
			
			if (ptr == root)
			{
				cout<<"Root->:  ";
			}	

			cout<<ptr->data;
			display(ptr->left, level+1);
		}
	}
   
	void countl()
	{
		int num = countr(root);
		cout<<"\n leaf nodes : "<<num;
		cout<<"\n non-leaf nodes : "<<count-num<<endl;
	}
	
	int countr(node *p)
	{	int sum=0;
		if(p->left==NULL && p->right==NULL)
		return 1;
		
		else if(p->left==NULL)
		sum=countr(p->right);
		
		else if(p->right==NULL)
		sum=countr(p->left);
		
		else
		sum = countr(p->left) + countr(p->right);
		
		return sum;
	}

	void height()
	{	if(root)
		{int h = hc(root->left,root->right,1);
		cout<<"\n Height of the tree is : "<<h<<endl;
		}
		else
		cout<<"\n Tree empty\n";
	}
	
	int hc(node* pleft, node* pright, int l)
	{	int l1=1,l2=1;
		if(pleft == NULL && pright == NULL)
		return l;
		
		if(pright!=NULL)
		l1 += hc(pright->left,pright->right, l);
		if(pleft!=NULL)
		l2 += hc(pleft->left,pleft->right, l);
		
		if(l1>l2)
		return l1;
		return l2;
	}

	void createm()
	{
		mirror(root);
	}

	void mirror(node* p)  
	{ 
		if (p == NULL)  
			return;  
		else
		{ 
			node* temp; 
			  
			mirror(p->left); 
			mirror(p->right); 
		  
			// swapping the pointers in this node 
			temp= p->left; 
			p->left = p->right; 
			p->right = temp; 
		} 
	}  

	void  predsucc(int key)
	{
		int op;
		do
		{
		cout<<"\n\n  Choose an option: 1. Predecessor 2. Successor ";
		cin>>op;
		
		if(op==1)
		{
			node* pre = NULL;
			findpredec(root, pre, key);
			
			if (pre != NULL)
			cout<<"predecessor is " << pre->data;
			else
			cout<<"No Predecessor";
		}
		
		else if(op==2)
		{
			node *suc = NULL;
			findsucc(root, suc, key);
			
			if (suc != NULL)
			cout<<"successor is : " << suc->data;
			else
			cout<<" No Successor";
		}
		
		else if(op>2)
		cout<<" Invalid option chosen!";
		
		}while(op<2);
	}	
	
	void findpredec(node* root, node*& pre, int key)
	{
		// Base case
		if (root == NULL)  return ;
	 
		// If key is present at root
		if (root->data == key)
		{
			// the maximum value in left subtree is predecessor
			if (root->left != NULL)
			{
				node* tmp = root->left;
				while (tmp->right)
				tmp = tmp->right;
				pre = tmp ;
			}
			return ;
		}
	 
		// If key is smaller than root's key, go to left subtree
		if (root->data > key)
		{
			findpredec(root->left, pre, key) ;
		}
		else 	// go to right subtree
		{
			pre = root ;
			findpredec(root->right, pre, key) ;
		}
	}

	void findsucc(node* root, node*& suc, int key)
	{
		// Base case
		if (root == NULL)  return ;
	 
		// If key is present at root
		if (root->data == key)
		{
			// the minimum value in right subtree is successor
			if (root->right != NULL)
			{
				node* tmp = root->right ;
				while (tmp->left)
					tmp = tmp->left ;
				suc = tmp ;
			}
			return ;
		}
		if (root->data > key)
		{
			suc = root ;
			findsucc(root->left, suc, key) ;
		}
		else 
		{
			findsucc(root->right, suc, key) ;
		}
	}
	
	void  MorrisInorder() 
	{
		node *p = root, *tmp;
		while (p != NULL) 
		{
			if (p->left == NULL) 
			{
				cout<<" "<<p->data<<" ";
			p = p->right;
			}
			
			else 
			{	tmp = p->left;
				while (tmp->right != NULL && tmp->right != p) // go to the rightmost node of the left subtree
				tmp = tmp->right; // or to the temporary parent of p;
			
				if (tmp->right == NULL) 
				{ // if 'true' rightmost node was reached,
				tmp->right = p; //make it a temporary parent of the current root
				p = p->left;
				}
				else 
				{ // else a temporary parent has been found
				
				cout<<" "<<p->data<<" ";
				tmp->right = NULL; // and then cut the right pointer of the current parent
				p = p->right;
				}
			}
		}
	}
};

int main()
{
	bsearchtree obj;
	int op,ch;
	int data;
	char ans='y';
	do{
		cout<<endl<<"Choose an operation: "<<endl<<endl;

		cout<<"1. Insert a node\n2. Search a node.\n3. Breadth First Traversal.";
		cout<<"\n4. Depth First Traversal (using recursion) \n5. Depth First Traversal (using iteration)";
		cout<<"\n6. Count leaf nodes \n7. Caculate tree height \n8. Convert to mirror image \n9. Find predecessor successor \n10. Morris Indorder Traversal \n11. Exit \n=>";
		cin>>op;
		cout<<endl;
		switch(op)
		{
			case 1:	cout<<"Enter the data value: "<<endl;
					cin>>data;
					cout<<"\nChoose method \n1.Iteration\n2.Recursion\n=>";
					cin>>ch;
				
					if(ch==1)
					obj.insertit(data);
					else if(ch==2)
					obj.insertrec(data);
					else
					cout<<"\nInvalid choice";
					cout<<endl;
					break;
		
			case 2:	cout<<"Enter the data to be deleted: "<<endl;
					cin>>data;
					obj.remove(data);
					break;			
			
			case 3:	cout<<"Enter the data to be searched: "<<endl;
					cin>>data;
					bool found; 
					found = obj.search(data);
					if(found)
					cout<<"\nNode found";
					else
					cout<<"\nNode not found";
					break;
			
			case 4:	obj.bfs();
					break;
			
			
			case 5:	cout<<endl<<"Choices available: "<<endl<<endl;
					cout<<"1. Inorder Traversal\n2. Preorder Traversal\n3. Postorder Traversal\n=>"<<endl;
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
					break;
		
			case 6: obj.countl();
					break;
		
			case 7: obj.height();
					break;
			
			case 8: obj.createm();
					break;
			
			case 9: 	cout<<"\nEnter key element : ";
						cin>>data;
						obj.predsucc(data);
						break;
			
			case 10: 	obj.MorrisInorder();
						cout<<endl;
						break;
						
			case 11: exit(0);
			
			default:	cout<<"Invalid Option! Please choose again"<<endl;
						break; 
			
		}

		obj.displaycall();
		cout<<endl<<endl<<"want to continue? y/n";
		cin>>ans;
		
	}while(ans=='y');
		
	return 0;
}
