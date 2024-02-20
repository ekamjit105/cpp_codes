#include<iostream>
using namespace std;
class binarys
{
  public:
  int data[10],n,key,first,last,middle;
  void getdata();
  void display();
};
void binarys :: getdata()
{
  cout<<"\nEnter the length of the array:";
  cin>>n;
  for(int i=0;i<n;i++)
   {
     cout<<"\nEnter the element at position"<< (i+1)<<" of the array:";
     cin>>data[i];
   }
  cout<<"\nEnter the key to find the element in the array:";
  cin>>key;
}
void binarys :: display()
{
  first=0;
  last=n-1;
  middle=(first+last)/2;
  while(last>=first)
  {
    middle=(first+last)/2;
    if(key>data[middle])
      first=middle+1;
    else if(key<data[middle])
      last=middle-1;
    else
    {
      cout<<"\nKey "<<key<<" found in the given array";
      break;
    }
  }
}

int main()
{
 binarys ob;
 ob.getdata();
 ob.display();
 return 0;
}
