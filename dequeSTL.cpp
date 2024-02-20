#include <iostream> 
#include <deque> 
  
using namespace std; 
  
void display(deque <int> g) 
{ 	cout<<"\n\ndeque: ";
    for (auto i = g.begin(); i != g.end(); ++i) 
        cout << '\t' << *i; 
    cout << '\n'; 
} 
  
int main() 
{ 
    deque <int> dobj; 
    cout<<"\n\t\t * Deque using STL *";
    cout<<"\n\nDisplaying initial deque";
    display(dobj);  
    cout << "push_back(10)"; 		//insert at end
    dobj.push_back(10); 
    cout << "\npush_front(20)"; 	//insert at beginning
    dobj.push_front(20); 
    cout << "\npush_back(30)"; 
    dobj.push_back(30);
    cout << "\npush_front(15)"; 
    dobj.push_front(15); 
    display(dobj); 
  
    cout << "\nsize() : " << dobj.size(); 						//returns size
    cout << "\nmax_size() : " << dobj.max_size(); 				//returns max size
  
    cout << "\nat(2) : " << dobj.at(2); 						//returns element at location
    cout << "\nfront() : " << dobj.front(); 					//returns first element 
    cout << "\nback() : " << dobj.back(); 						//returns last element 
	
    cout << "\n\npop_front()  "; 								//deletes first element
    dobj.pop_front(); 
    display(dobj); 
  
    cout << "\npop_back()  "; 									//deletes last element
    dobj.pop_back(); 
    display(dobj); 
    
    cout<<"\nChecking if deque is empty: ";						//checks empty for deque
	if (dobj.empty() == false)
	cout << "deque is not empty"; 
	else
	cout << "deque is empty";
	
	cout << "\npop_back()  "; 									
    dobj.pop_back(); 
    display(dobj);
  
	cout << "\npop_back()  "; 
    dobj.pop_back(); 
    display(dobj);
    
    cout<<"\nChecking if deque is empty: ";
	if (dobj.empty() == false)
	cout << "deque is not empty"; 
	else
	cout << "deque is empty";
	
    return 0; 
} 
