#include <iostream>
using namespace std;




class LSearch
{
	public:
		
		template <typename T>
		void input(T arr[],int n)
		{
			cout<<"Enter the elements one by one \n";
			for (int i = 0; i < n; i++)
			{
			cin>> arr[i];
			}
			cout<<endl;
		}
		
		template <typename T>
        void LinearSearch(T arr[], T value, int n)
        {   int found = 0,i;
            for (i = 0; i < n ; i++)
            {
                if (value == arr[i] )
                {
                    found = 1;
                    break;
                }
            }
            if (found == 1)
            {
                cout<<"Element is present in the array at position   "<<i+1;
            }
            else
            {
                cout<<"Element is not present in the array.";
            }
        }
        
        
};
int  main()
{  
    LSearch lobj;
    cout<<endl<<"enter number of elements";
    int n;
	cin>>n;
    
    int arri[20],numi;
    float arrd[20],numd;
    char arrc[20],numc;
    
    int ch;
    cout<<"Enter the data type of the array 1.integer 2. float 3. char";
    cin>>ch;
    
    if(ch==1)
    lobj.input(arri[],n);
	numi=lobj.inputnum();
    lobj.LinearSearch(arri[], numi, n); 
    
    else if(ch==1)
    lobj.input(arrd[],n); 
	lobj.LinearSearch(arri[], numd, n); 
	 
    else 
    lobj.input(arrc[],n);
	lobj.LinearSearch(arri[], numc, n); 

    return 0;
}
