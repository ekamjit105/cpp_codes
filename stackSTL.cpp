#include <iostream> 
#include <stack> 
using namespace std;

void showstack(stack <int> s) 
{ 	cout<<endl;
	cout << "\tThe stack is : "; 
	cout<<endl;
    while (!s.empty()) 
    { 
        cout <<endl <<"\t"<< s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 
  
int main () 
{ 
    stack <int> s; 
    cout<<"\n\t\t* STL Stack implementation *\n";
    cout<<"\nPushing 5, 7, 6, 3 to the stack\n";
    s.push(5); 						//implementing push() function
    s.push(7); 
    s.push(6); 
    s.push(3); 
  
    showstack(s); 
  
    cout << "\ns.size() : " << s.size(); 	//implementing size() function
    cout << "\ns.top() : " << s.top(); 		//implementing pop() function
  
  
    cout << "\n\n\ts.pop()\n "; 
    s.pop(); 
    showstack(s); 
	cout << "\ns.size() : " << s.size(); 	
    cout << "\ns.top() : " << s.top();
    
    cout << "\n\ncheck empty s.empty() : "<<s.empty();	//implementing empty() function
    
    cout << "\n\nremoving all elements\n";
    while (!s.empty()) 
    s.pop(); 
    
    cout << "\ncheck empty s.empty() : "<<s.empty();
    return 0; 
} 
