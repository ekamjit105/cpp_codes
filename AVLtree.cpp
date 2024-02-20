#include<iostream>

using namespace std;

template<typename T>
class Node  
{  
    public: 
    T key;  
    Node<T> *left;  
    Node<T> *right;  
    int height;  
};  

template<typename T>
class AVL
{
	Node<T>* root;
	
	public:
	AVL()
	{
		root=NULL;
	}
	Node<T>* newNode(T key);
	int max(int a, int b);
	int getheight(Node<T> *N);
	Node<T>*rightRotate(Node<T> *y);
	Node<T>*leftRotate(Node<T> *x);
	int getBalance(Node<T>*N);
	Node<T>* insert(Node<T>* node,T key);
	void insertion(T key);
	
	void displaycall();
    void display(Node<T> *ptr, int level);
    
    Node<T>* minValueNode(Node<T>* node);
    Node<T>* deleteNode(Node<T>* root, T key);
    void deletion(T key);
    
    bool search(T val);
};

template<typename T>
Node<T>* AVL<T>::newNode(T key)  
{  
    Node<T>* node = new Node<T>(); 
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; 
    return node;
}  

template<typename T>
int AVL<T>::getheight(Node<T> *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  
 
template<typename T>
int AVL<T>::max(int a, int b)  
{  
    return (a > b)? a : b;  
}  

template<typename T>
Node<T>* AVL<T>::rightRotate(Node<T> *y)  
{  
    Node<T>*x = y->left;  
    Node<T>*T2 = x->right;  
   
    x->right = y;  
    y->left = T2;  
    
    y->height = max(getheight(y->left),getheight(y->right)) + 1;  
    x->height = max(getheight(x->left),getheight(x->right)) + 1;  
    return x;  
}  

template<typename T>
Node<T>* AVL<T>::leftRotate(Node<T> *x)  
{  
    Node<T>*y = x->right;  
    Node<T>*T2 = y->left;  
 
    y->left = x;  
    x->right = T2;  
  
    x->height = max(getheight(x->left),getheight(x->right)) + 1;  
    y->height = max(getheight(y->left),getheight(y->right)) + 1;  
  
    return y;  
}  

template<typename T>
int AVL<T>::getBalance(Node<T>*N)  
{  
    if (N == NULL)  
        return 0;  
    return getheight(N->left) - getheight(N->right);  
}  

template<typename T>
Node<T>* AVL<T>::insert(Node<T>* node, T key)  
{  
    if (node == NULL)  
        return(newNode(key));  
  
    if (key < node->key)  
        node->left = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  
    else 
        return node;  
  
    node->height = 1 + max(getheight(node->left),getheight(node->right));  
    int balance = getBalance(node);  
   
    if (balance > 1 && key < node->left->key)  
        return rightRotate(node);  
    
    if (balance < -1 && key > node->right->key)  
        return leftRotate(node);  
  
    if (balance > 1 && key > node->left->key)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    if (balance < -1 && key < node->right->key)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    return node;  
}  

template<typename T>
void AVL<T>::insertion(T key)
{
	root=insert(root,key);
}

template<typename T>
void AVL<T>::displaycall()
{	
	cout<<"\n\t AVL Tree is\n";
	if(!root){
		cout<<"\n\t No nodes present";
		return;
	}
	display(root,1);
}

template<typename T>
void AVL<T>::display(Node<T> *ptr, int level)
{
	int i;
	if (ptr != NULL){
		display(ptr->right, level+1);
		cout<<endl;
		if (ptr == root){
			cout<<"Root->:  ";
		}	
		else{
			for (i = 0;i < level;i++){
				cout<<"       ";
			}    
		}
		cout<<ptr->key;
		display(ptr->left, level+1);
	}
}

template<typename T>
Node<T>* AVL<T>::minValueNode(Node<T>* node)  
{  
    Node<T>* current = node;  

    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}  

template<typename T>
Node<T>* AVL<T>::deleteNode(Node<T>* root, T key)  
{  
    if (root == NULL)  
        return root;  
  
    if ( key < root->key )  
        root->left = deleteNode(root->left, key);  
 
    else if( key > root->key )  
        root->right = deleteNode(root->right, key);   
    else
    {  
        if( (root->left == NULL) || (root->right == NULL) )  
        {  
            Node<T>*temp = root->left ?  root->left :  root->right;  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else   
            *root = *temp; 
            delete temp; 
        }  
        else
        {  
            Node<T>* temp = minValueNode(root->right);   
            root->key = temp->key;  
   
            root->right = deleteNode(root->right,  
                                     temp->key);  
        }  
    }   
    if (root == NULL)  
    return root;  
  
    root->height = 1 + max(getheight(root->left),getheight(root->right));  
  
    int balance = getBalance(root);  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
    
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
}  

template<typename T>
void AVL<T>::deletion(T key)
{
	root=deleteNode(root,key);
}

template<typename T>
bool AVL<T>::search(T val)
{
    Node<T>* p=root;
    while(p!=NULL) 
    {
        if (val == p->key){
            return true;
        }
        else if (val < p->key){
            p = p->left;
        }
        else{
            p= p->right;
        }
    }
    return false;
}


int main()
{
	AVL<int> obj;
	int ch;
	int data;
	
	cout<<"\n\t* AVL tree *\n";
	
	while(1)
	{
		cout<<"\n Choose an option: ";
		cout<<"\n 1. Insertion of a node";
		cout<<"\n 2. Deletion of a node";
		cout<<"\n 3. Search a node";
		cout<<"\n 4. Exit ";
	
	
		cout<<"\n\n Enter your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1: cout<<"\n Enter the data of a node to be inserted : ";
					cin>>data;
					obj.insertion(data);          
					break;
				
			case 2:	cout<<"\n Enter the data of a node to be deleted : ";
					cin>>data;	
					obj.deletion(data);
					break;	
			
			case 3:	cout<<"\n Enter the data to be searched : ";
					cin>>data;
					if(obj.search(data)==true)
					cout<<"\n Node present in the tree ";
					
					else
					cout<<"\n Node not present in the tree";
			
					break;
		    
		    
			
			case 4: exit(0);
			
			default:cout<<"\n Invalid option chosen!";
					
			
		}
		
	obj.displaycall();
	cout<<endl;
	}
			

	return 0;
}


