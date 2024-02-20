#include<iostream>
using namespace std;

class product
{
	int price;
	string id,name;
	
	public:
	
	void input()
	{
		cout<<"\n Enter name of product: ";
		cin>>name;
		cout<<"\n Enter product ID: ";
		cin>>id;
		cout<<"\n Enter price of product: ";
		cin>>price;
	}
	
	void display()
	{
		cout<<"  "<<id<<"  \t"<<name<<"    \t"<<price<<endl;
	}
	
	void erasedata()
	{
		name="";
		id="";
		price=0;
	}
};


class shopstack
{
	product p[100];									//array of all the products
	int capacity;
	int size[4];									//sizes of each category
	int start[5];									//starting position of each category
	int top[4];										//topmost position of each category
	
	//	here top value of the stack is the topmost empty value
	// 	of the stack where a new element can be added
	
	public:
	
	shopstack()
	{	capacity=100;
		cout<<"\n Total Number of products in shop   = "<<capacity;
		cout<<"\n Total Number of categories in shop = 4";
		int limitsum=0;
		while(1)
		{
		cout<<"\n\n Enter Number of products in each category";
		cout<<"\n Stationery: \t";
		cin>>size[0];
		cout<<" Grocery: \t";
		cin>>size[1];
		cout<<" Cosmetic: \t";
		cin>>size[2];
		cout<<" Medicines: \t";
		cin>>size[3];
		
		limitsum=size[0]+size[1]+size[2]+size[3];
		if(limitsum<=capacity)
		break;
		cout<<"\nSum of all category sizes excedes maximum total number of products(100)!";
		
		}
		
		start[0]=0;				//first stack will start from 0 index
		for(int i=1;i<5;i++)
		start[i]=start[i-1]+size[i-1];		//assigning all the starting positions
					
		for(int i=0;i<4;i++)								//initially all the top positions will be the starting positions
		top[i]=start[i];						
		
	}
	
	void displayall()
	{	cout<<"\n  ___________________________________________________________";
		for( int i=0; i<4; i++ )	
		displaycategory(i);													
		cout<<"  ___________________________________________________________\n";
	}
	
	void displaycategory(int cat)							//function to display all products category wise
	{
		if(cat==0)
		{
			cout<<"\n\n  -Stationery-\n\n";
			if(!isempty(cat))
			{	cout<<"  PID  \tName    \tPrice"<<endl;
				for(int i=start[0];i<top[0];i++)
				{
					p[i].display();
				}
			}
			
		}
		
		if(cat==1)
		{
			cout<<"\n  -Grocery-\n\n";
			
			if(!isempty(cat))
			{cout<<"  PID  \tName    \tPrice"<<endl;
			for(int i=start[1];i<top[1];i++)
			{
				p[i].display();
			}
			}
		}
		
		if(cat==2)
		{
			cout<<"\n  -Cosmetics-\n\n";
			if(!isempty(cat))
			{
			cout<<"  PID  \tName    \tPrice"<<endl;
			for(int i=start[2];i<top[2];i++)
			{
				p[i].display();
			}
			}
		}
		
		if(cat==3)
		{
			cout<<"\n  -Medicine-\n\n";
			if(!isempty(cat))
			{
			cout<<"  PID  \tName    \tPrice"<<endl;
			for(int i=start[3];i<top[3];i++)
			{
				p[i].display();
			}
			}
		}
	}
	
	void push(int cat)
	{
		int position;
		if(!isfull(cat))
		{	position=top[cat];
			p[position].input();									//product added at topmost value
			top[cat]++;
			cout<<"\n Product Added";
		}
		else
		cout<<"\n Category full!";
	}
	
	void pop(int cat)
	{	int position;
		if(!isempty(cat))
		{	top[cat]--;
			position=top[cat];										//topmost product of category deleted
			p[position].erasedata();
			cout<<"\n Product Removed";
		}
		else
		cout<<"\n Category Empty!";
	}
	
	bool isfull(int cat)									//to check if a particular category stack is full
	{	
		if(top[cat]==start[cat+1])
		return true;
		return false;
	}
	
	bool isempty(int cat)									//to check if a particular category stack is empty
	{	
		if(top[cat]==start[cat])
		return true;
		return false;
	}
	
	bool checkvalid(int cat)							//to check if a valid category is chosen
	{
		if(cat>=0&& cat <4)
		return true;
		cout<<"\n Invalid Category chosen";
		return false;
	}
	
};

int main()
{
	cout<<"\n\t\t\t* General Store Software *\n";
	shopstack s;
	int op,cat;
	
	while(1)
	{
		cout<<"\n  Choose an option: \n  1.Add a product\n  2.Remove a product \n  3.Display products of a particular category \n  4.Display all products in shop \n  5.Exit\n  => ";
		cin>>op;
		cout<<"\n  -----------------------------------------------\n";
		switch(op)
		{
			case 1: cout<<"\n  *ADD a product*";
					do{
					cout<<"\n Categories: (1)Stationery (2)Grocery (3)Cosmetics (4)Medicine";
					cout<<"\n Enter catagory number: ";
					cin>>cat;
					cat--;
					}while(!s.checkvalid(cat));
					s.push(cat);
					s.displayall();
					break;
			
			case 2: cout<<"\n  *REMOVE a product*";
					do{
					cout<<"\n Categories: (1)Stationery (2)Grocery (3)Cosmetics (4)Medicine";
					cout<<"\n Enter catagory number: ";
					cin>>cat;
					cat--;
					}while(!s.checkvalid(cat));
					s.pop(cat);
					s.displayall();
					break;
				
			case 3: cout<<"\n  *Display Category*";
					do{
					cout<<"\n Categories: (1)Stationery (2)Grocery (3)Cosmetics (4)Medicine";
					cout<<"\n Enter catagory number: ";
					cin>>cat;
					cat--;
					}while(!s.checkvalid(cat));
					s.displaycategory(cat);
					break;
						
			case 4: cout<<"\n Displaying all products in the shop\n";
					s.displayall();
					break;
					
			case 5: exit(0);
			
			default: cout<<"\nInvalid option chosen";
		
		}
		
		
	}
	
	return 0;
}
