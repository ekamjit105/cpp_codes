#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

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
	
	t pop()															//deletion from end dll
	{	t deleted = -1;
		
		if(head==NULL)
		{cout<<"\nThere is no node in the list";
		return deleted;
		}
		
		else if(head->next==NULL)						//Single element
		{	Node *temp=head;
			head=NULL;											//single node deleted
			tail=NULL;
			deleted=temp->data;
			delete temp;
			count--;
		}
		else 											//more than one element
		{
			tail=tail->prev;
			deleted=tail->next->data;
			delete tail->next;
			tail->next=NULL;
			count--;
		}
		
		return deleted;
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

template <class t>
class infixprepostfix
{	
	string infix, ns, prefix; 
	int length;
	int p;										//stores number of paranthesis in infix
	
	public:
	
	void inputinfix()
	{	
		cout<<"\nEnter char array :\n";
		cin>>infix;
		
		length=infix.length();
		cout<<"\nDisplaying char array :";
		for(int i=0;i<length;i++)
		cout<<" "<<infix[i];
		p=countbrackets(infix,length);
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
	
	void topostfix()	
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
				{ 	char c = st.pop();
					ns[j++] = c;
				}
				
				if(st.peek() == '(')
				st.pop(); 
			}
			
			else
			{ //If an operator is scanned
				while(!st.isempty() && prec(infix[i]) <= prec(st.peek()))
				{ 	char c = st.pop();
					ns[j++] = c;
				}
				st.push(infix[i]);
			}
		}
	
		while(!st.isempty())
		{ 	char c = st.pop();
			ns[j++] = c;
		}
		
	}
	
	void toprefix()
	{		
		string arr;
		for(int i=0;i<length;i++)
		arr[i]=infix[i];
		
		reversestr(infix);
		topostfix();
		
		for(int i=0;i<length;i++)
		infix[i]=arr[i];					//saving the original infix expression
	}
	
	void reversestr(string& str) 
	{ 
		int n = str.length(); 
  
		for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
        
        for (int i = 0; i <n; i++) 
		{	if(str[i] == '(')
			str[i] = ')';  
			 
			else if(str[i] == ')') 
			str[i] = '('; 
		}
    }
    
    void evaluatepostfix()
    {
		topostfix();
		displaypostfix();
		
		mystack <int> st;
		for (int i = 0; ns[i]; ++i)  
		{  
        // If the scanned character is an operand push it to the stack. 

			if (isdigit(ns[i]))  
			st.push(ns[i]-'0');										//subtracting the ASCII value of 0 to get the actual integer value
			
		// If the scanned character is an operator, 
		// pop two elements from stack apply the operator
		   
        else
        {  
            int val1 = st.pop();  
            int val2 = st.pop();  
            switch (ns[i])  
            {  
            case '+': 	st.push(val2 + val1);
						break;
						  
            case '-': 	st.push(val2 - val1);
						break;
						  
            case '*': 	st.push(val2 * val1);
						break;
						  
            case '/': 	st.push(val2/val1);
						break;  
            }  
        } 
        
        
		}  
		int res=st.pop();
		cout<<endl<<res; //last element left is the result
	}
	
void evaluateprefix()
 {
		toprefix();
		displayprefix();

		mystack <int> st;
		
		for (int j = 0; j<length-p; j++)  
		{ 
			if (isdigit(ns[j])) 
			st.push(ns[j]-'0'); 							//subtracting the ASCII value of 0 to get the actual integer value
			
			
			else 
			{ 
			// Operator encountered 
            // Pop two elements from Stack and apply operator on them
            
            int val1 = st.pop();
            int val2 = st.pop(); 
            
            switch (ns[j])  
            {  
            case '+': 	st.push(val2 + val1);
						break; 
						 
            case '-': 	st.push(val2 - val1);
						break;  
						
            case '*': 	st.push(val2 * val1);
						break;  
						
            case '/': 	st.push(val2/val1);
						break;  
            } 
			} //else
			} //for
  
		int res=st.pop();
		cout<<endl<<res;			 //last element left is the result
	
}	
	
	void displaypostfix()
	{	cout<<endl<<"Postfix notation will be: ";
		for(int i=0;i<length-p;i++)
		cout<<" "<<ns[i];
		cout<<endl;
	}
	void displayprefix()
	{	cout<<endl<<"Prefix notation will be: ";
		for(int i=length-p;i>=0;i--)
		cout<<" "<<ns[i];
		cout<<endl;
	}
};

int main()
{	
	
	infixprepostfix <char> obj;
	infixprepostfix <int> obj1;
	char ans='y';
	int op,dtype;
	cout<<"\nEnter infix notation operand type: \n1.Digits\n2.Alphabets\n=>"; 
	cin>>dtype;
	
	if(dtype==1)
	{obj1.inputinfix();
	while(ans=='y')
	{	cout<<"\nEnter option:\n1.Convert Infix to Postfix\n2.Convert Infix to Prefix \n3.Evaluate Postfix \n4.Evaluate Prefix \n5.Exit\n=>  ";
		cin>>op;
		switch(op)
		{
			case 1:	obj1.topostfix();
					obj1.displaypostfix();
					break;
					
			case 2:	obj1.toprefix();
					obj1.displayprefix();
					break;	
					
			case 3:	obj1.evaluatepostfix();
					break;
					
			case 4:	obj1.evaluateprefix();
					break;	
						
			case 5: exit(0);
			
			default:cout<<"\nInvalid option chosen!";
		}

	}
		
	}
	else if(dtype==2)
	{
	obj.inputinfix();	
	while(ans=='y')
	{	cout<<"\nEnter option:\n1.Convert Infix to Postfix\n2.Convert Infix to Prefix \n3.Exit\n=>  ";
		cin>>op;
		switch(op)
		{
			case 1:	obj.topostfix();
					obj.displaypostfix();
					break;
					
			case 2:	obj.toprefix();
					obj.displayprefix();
					break;	
					
			case 3: exit(0);
			
			default:cout<<"\nInvalid option chosen!";
		}

	}
	}
	return 0;
}

