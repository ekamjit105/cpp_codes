#include <iostream> 
#include <queue> 
 
using namespace std; 
  
void show(queue <string> names) 
{ 	cout<<"\nQUEUE : ";
    queue <string> temp = names; 
    while (!temp.empty()) 
    { 
        cout<< temp.front()<<"\t"; 
        temp.pop(); 
    } 
    cout<<endl;
} 
  
int main() 
{ 	
	queue <string> names; 
	cout<<"\n\n\t\t Class list using STL Queue";
	char ans='y';
	do
	{	int op;
		string name;
		cout<<"\nEnter an option: ";
		cout<<"\n1.Insert a name (at the end) \n2.Delete a name (from the beginning)\n3.Display first name \n4.Display Last name\n5.Check size \n6.Check empty \n7.Swap two queues \n8.exit\n=>";
		cin>>op;
		switch(op)
		{		
			case 1: cout<<"\nEnter name: ";
					cin>>name;
					names.emplace(name);
					show(names);
					break;	
					
			case 2: if(names.empty()==false)
					{cout<<"\nDeleted name is: "<<names.front()<<endl;;
					names.pop();}
					else
					cout<<"\nQueue is empty\n";
					show(names);
					break;	
					
			case 3: if(names.empty()==false)
					cout<<"\nFirst name is: "<<names.front()<<endl;
					else
					cout<<"\nQueue is empty\n";
					break;		
			
			case 4: if(names.empty()==false)
					cout<<"\nLast name is: "<<names.back()<<endl;
					else
					cout<<"\nQueue is empty\n";
					show(names);
					break;
					
			case 5: cout<<"\nSize: "<<names.size()<<endl;
					show(names);
					break;
					
			case 6: if(names.empty()==true)
					cout<<"\nIt is empty\n";
					else
					cout<<"\nIt is filled\n";
					show(names);
					break;
			
			
			case 7: {queue <string> second;
					int n;
					cout<<"Enter the number of elements in second list: ";
					cin>>n;
					while(n!=0)
					{cout<<"\nEnter name: ";
					cin>>name;
					second.push(name);
					n--;
					}
					cout<<"\nThe second queue is ";
					show(second);
					cout<<"Swapping the queues..\n";
					names.swap(second);
					cout<<"\nFirst queue";
					show(names);
					cout<<"\nSecond queue";
					show(second);}
					break;
					
			case 8: exit(0);
		}
	}while(ans=='y');
  
    return 0; 
} 
