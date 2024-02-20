#include<iostream>
#include<vector>
using namespace std;
int main()
{	
	/*
	* begin(), end(), rbegin(),rend()
	* size(), capacity(), maxsize(), resize()
	* empty(),
	* front(),back(),at()
	* using pointer 
	* assign(),push_back(),pop_back()
	* insert(), erase(), emplace(), emplace_back()
	* clear()
	* swap()
	
	
	
	
	*/ 
	
	vector <int> g1;
	cout<<"\n\n** Creating new Vector g1 **";
	cout<<"\n\nAssigning values to the elements using push_back()";
	for(int i=1;i<=5;i++)
	g1.push_back(i);
	cout << "\n Vector elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
	cout << *it << " "; 
	cout<<"\nOutput of vector using begin and end\n";
	for(auto i=g1.begin();i!=g1.end();i++)
	cout<<" "<<*i;
	cout<<"\nOutput of vector using rbegin and rend\n";
	for(auto ir=g1.rbegin();ir!=g1.rend();ir++)
	cout<<" "<<*ir;
	
	cout << "\n\nSize : " << g1.size();
	//Returns the number of elements in the vector = 5.
	
	cout << "\nCapacity : " << g1.capacity(); 
	// size of the storage space currently allocated to the vector expressed as number of elements = 8.
	
	cout << "\nMax_Size : " << g1.max_size(); 
	//Returns the maximum number of elements that the vector can hold = 4611686018427387903.
	
	cout<<"\n** Resizing to 4 **";
	g1.resize(4); // resizes the vector size to 4
	cout << "\nSize : " << g1.size()<<endl; // prints the vector size after resize() = 4
	
	cout<<"\nChecking if vector is empty: ";
	if (g1.empty() == false) // checks if the vector is empty or not
	cout << "Vector is not empty"; //gets printed
	else
	cout << "Vector is empty";
	
	cout << "\n\nCurrent vector elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
	cout << *it << " "; //prints 1 2 3 4
	
	cout << "\n\nUsing \n reference operator [g] : g1[2] = " << g1[2];
	cout << "\n at : g1.at(4) = " << g1.at(3); //returns element at index 3
	cout << "\n front() : g1.front() = " << g1.front(); //first element
	cout << "\n back() : g1.back() = " << g1.back(); //last element
	cout << "\n changing 2nd element by using g1[1] = 7";
	g1[1]=7; 
	
	cout<<"\n\n Assigning pointer to the vector";
	int* pos = g1.data(); // pointer to the first element – base address
	cout<< "\n\n *pos points to base address, that is, first element";
	cout<< "\n Displaying *pos = "<<*pos<<". This is the first element.";
	cout<< "\n Displaying *pos+1 = "<<*pos+1 <<". This is the second element.";
	cout<< "\n Current vector elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
	cout << *it << " "; 
	
	cout<<"\n\n Inserting 5 and 3 in the beginning";
	g1.insert(g1.begin(), 5); // inserts 5 at the beginning
	g1.insert(g1.begin(), 3); // inserts 3 at the beginning
	cout<< "\n Current vector elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
	cout << *it << " "; 
	cout << "\n The first element is: " << g1[0];
	
	cout<<"\n\n Removing first element";
	g1.erase(g1.begin()); // removes the first element
	cout<< "\n Current vector elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
	cout << *it << " "; 
	cout << "\n The first element is: " << g1[0];
	
	cout<<"\n\n Inserting 12 and 13 at the end(push_back)";
	g1.push_back(12);
	g1.push_back(13);
	cout<< "\n Current vector elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
	cout << *it << " "; 
	
	cout<<"\n\n Removing first element from the end(pop_back)";
	g1.pop_back();
	cout<< "\n Current vector elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
	cout << *it << " "; 
	
	cout<<"\n\n Using emplace() and emplace_back() to insert 3 and 20 at start and end respectively";   
	g1.emplace(g1.begin(), 3); // extends the container by inserting new element at position
	cout << "\n The first element is: " << g1[0];
	g1.emplace_back(20); // Inserts 20 at the end ;
	cout << "\n The last element is: " << g1[g1.size() - 1];
	cout<< "\n Current vector elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
	cout << *it << " "; 
	
	cout<<"\n\n** Creating new Vector g2 **";
	vector <int> g2;
	if (g2.empty() == false) // checks if the vector is empty or not
	cout << "\nVector is not empty"; //gets printed
	else
	cout << "\nVector is empty";
	cout<<"\n\nNow assigning vector 5 elements with values 10 using assign(5,10)";
	g2.assign(5,10);
	cout << "\nCurrent second vector elements are: ";
	for (auto it = g2.begin(); it != g2.end(); it++)
	cout << *it << " "; 
	
	cout<<"\n\n Swapping the two vectors g1 and g2";
	cout<<"\n Before swapping: \n";
	cout << "\n g1 elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
	cout << *it << " "; 
	cout << "\n g2 elements are: ";
	for (auto it = g2.begin(); it != g2.end(); it++)
	cout << *it << " "; 
	g1.swap(g2);
	cout<<"\n\n After swapping: \n";
	cout << "\n g1 elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
	cout << *it << " "; 
	cout << "\n g2 elements are: ";
	for (auto it = g2.begin(); it != g2.end(); it++)
	cout << *it << " "; 
	
	cout<<"\n\nClearing the first vector(g1)";
	g1.clear();
	if (g1.empty() == false) // checks if the vector is empty or not
	cout << "\nVector is not empty"; //gets printed
	else
	cout << "\nVector is empty";
	cout << "\n Size : " << g1.size()<<endl; 
	cout << "\n First vector elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
	cout << *it << " "; 
	cout << "\n Second vector elements are: ";
	for (auto it = g2.begin(); it != g2.end(); it++)
	cout << *it << " ";  

	
	return 0;
}
	
