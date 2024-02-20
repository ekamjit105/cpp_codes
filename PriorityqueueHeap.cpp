//Ekamjit Singh
//2019CSC1001

#include<iostream>
#include<cmath>
using namespace std;

//The binary tree used is implemented using array

class PqueueMinheap
{
	int MAX;			//total number of elements in heap
	int *arr;			//array to store heap elements
	int n;				//number of elements stored
	
	public:
	
	PqueueMinheap()
	{	MAX=15;
		n=0;
		arr = new int[MAX];
	}
	
	void insert(int key)
	{
		arr[n+1]=key;
		int i=n+1;
		
		while(i>1 && arr[i]<arr[i/2])		//up heap bubbling
		{
			swap(arr[i],arr[i/2]);
			i=i/2;
		}
		n++;
	}
	
	void remove()
	{	if(isempty())
		{
			cout<<"\n\n No element in heap";
		}
		int x = arr[1];
		arr[1]=arr[n];
		adjust();						//down heap bubbling
		n--;
		cout<<"\n "<<x<<" is deleted";
	}
	
	void adjust()
	{	int index=1;
		int lefti,righti;
		while(1)	//down-heap bubbling					
		{
			lefti = index*2;
			righti = index*2 + 1;
			
			if(lefti > n)				//left child does not exist
			{
			break;
			}
			if(lefti<n && righti>n) 	//only left child, no right
			{	
				if(arr[index]>arr[lefti])
				swap(arr[index],arr[lefti]);
				break;
			}
			
			if(arr[lefti] < arr[righti])	//left child < right child
			{	
				swap(arr[index],arr[lefti]);
				index=lefti;
				continue;
			}
			
			if(arr[righti] < arr[lefti])	//rigth child < left child
			{	
				swap(arr[index],arr[righti]);
				index=righti;
				continue;
			}
		}
	}
	
	bool isempty()
	{
		if(n==0)
		return true;
		return false;
	}
	
	int retroot()
	{	
		return arr[1];
	}
	
	void display()
	{	
		cout<<"\n\n Heap Array will be : ";
		for(int i=1;i<=n;i++)
		cout<<arr[i]<<" ";
		cout<<endl;
	}
	
	void displayheap()
	{	int level=1;
		cout<<"\n\n The heap will be:\n\n";
		cout<<" level 1 : ";
		for(int i=1;i<=n;i++)
		{	
			cout<<" "<<arr[i];
			if((i+1<=n)&&(i+1)==pow(2,level))
			{	level++;
				cout<<endl;
				cout<<" level "<<level<<" : ";
			}
		}
		
	}
	
	void swap(int &a, int &b)
	{
		int temp=a;
		a=b;
		b=temp;
	} 
};

int main()
{
	cout<<"\n\t\t* Priority Queue using Min-Heap\n";
	int ch,data;
	PqueueMinheap obj;
	while(1)
	{
		cout<<"\n Enter an option:\n1.Insert a key\n2.Delete a key\n3.Display Heap\n4.Exit\n=>";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\n Enter data to be inserted : ";
					cin>>data;
					obj.insert(data);
					break;
			
			case 2: if(!obj.isempty())
					obj.remove();
					else
					cout<<"\n Heap empty!";
					break;
					
			case 3: obj.displayheap();
					break;
					
			case 4: exit(0);
			
			default: cout<<"\n Invalid option chosen";
		}
		obj.display();
	}
	
	return 0;
}








































/*#include<iostream>
#include<vector>

using namespace std;
class CompleteTree 
{ // left-complete tree interface
	private: vector<int> V; // tree contents
	
	public:
	
	typedef typename vector<int>::iterator Position; // a position in the tree
	int size() 
	{ int s=V.size()-1;
		return s;
	//	return V.size() − 1; }
	
	Position left(Position p)
	{ return pos(2*idx(p)); }
	
	Position right(Position p) 
	{ return pos(2*idx(p) + 1); }
	
	Position parent(Position p) 
	{ return pos(idx(p)/2); }
	
	bool hasLeft(Position p)
	{ return 2*idx(p) <= size(); }
	
	bool hasRight(Position p) 
	{ return 2*idx(p) + 1 <= size(); }
	
	bool isRoot( Position p) 
	{ return idx(p) == 1; }
	
	Position root() 
	{ return pos(1); }
	
	Position last() 
	{ return pos(size()); }
	
	void addLast(int e) 
	{ V.push_back(e); }
	
	void removeLast() 
	{ V.pop_back(); }
	
	void swap(Position p, Position q)
	
	Position pos(int i) 
	{ return V.begin() + i; } // map an index to a position
	
	int idx(Position p) 
	{ return p − V.begin(); } // map a position to an index
	
	int elemAtInd(int idx) 
	{ return V.at(idx); }
};

class HeapPriorityQueue 
{
	private:
	CompleteTree T;
	typedef typename VectorCompleteTree::Position Position;
	public:
	
	void insert( int e)
	{
		T.addLast(e); // add e to heap
		
		Position v = T.last(); // e’s position
		
		while (!T.isRoot(v)) 
		{ 	// up-heap bubbling
			Position u = T.parent(v);
			if (T.elemAtIdx(T.idx(u)) < T.elemAtIdx(T.idx(v))) break; // if v in order
			T.swap(v, u); // . . .else swap with parent
			v = u;
		}
	}
	
	int min() 
	{ return (T.elemAtIdx(T.idx(T.root()))); }

	void removeMin() 
	{
		if (T.size() == 1) 
		{ T.removeLast(); } // . . .remove it
		
		else 
		{
			Position u = T.root(); // root position
			
			T.swap(u, T.last()); // swap last with root
			
			T.removeLast(); // . . .and remove last
			
			while (T.hasLeft(u)) 
			{ // down-heap bubbling
			Position v = T.left(u);
			if (T.hasRight(u) && T.elemAtIdx(T.idx(T.right(u)) < T.elemAtIdx(T.idx(v)))
			v = T.right(u); // v is u’s smaller child
			if (T.elemAtIdx(T.idx(v) < T.elemAtIdx(T.idx(u))) {
			T.swap(u, v); // . . .then swap
			u = v;
		}
		else break;
		}
	}

};

int main()
{
	return 0;
}
*/
