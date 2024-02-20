#include<iostream>
using namespace std;
class represent
{
	int arr[10][10],r,c;		//sparse matrix, no. of rows and columns
	int nonz[3][10],noc=0;		//non-zero 2d array, no. of columns in non-zero representation
	
	public:
	
	represent();
	void inputmatrix();			//input sparse matrix
	void inputnonzero();		//input non-zero form
	void converttonz();			//convert sparse to non-zero form
	void converttomat();		//convert non-zero to sparse matrix
	void displaynz();			//display non-zero form
	void displaymat();			//display matrix
	
};

represent::represent()
{
		for(int i=0;i<3;i++)	
		for(int j=0;j<noc;j++)
		nonz[i][j]=0;
		
		for(int i=0;i<10;i++)	
		for(int j=0;j<=10;j++)
		arr[i][j]=0;
}

void represent::inputmatrix()
{	cout<<"\n Enter the number of rows: ";
	cin>>r;
	cout<<"\n Enter the number of columns: ";
	cin>>c;
	cout<<"\n Enter the matrix..\n";
	
	for(int i=0;i<r;i++)
	{for(int j=0;j<c;j++)
		{	cout<<"\nEnter element ("<<i<<","<<j<<") : ";			//Getting 2d array input
			cin>>arr[i][j];
		}
	}	
	displaymat();
}

void represent::inputnonzero()
{
	cout<<"\n Non zero representation";
	cout<<"\nEnter the elements..\n";
	
	char ans='y';
	noc=0;
	do
	{	
		cout<<"\n Enter Row column value\n";
		cout<<" Row    : ";
		cin>>nonz[0][noc];
		cout<<" Column : ";
		cin>>nonz[1][noc];
		cout<<" Value  : ";
		cin>>nonz[2][noc];
		
		noc++;

		cout<<"\nEnter another element? (y/n) =>";
		cin>>ans;
	}while(ans=='y');
	
	displaynz();
}

void represent::converttonz()
{
	nonz[0][0]=r;
	nonz[1][0]=c;
	nonz[2][0]=0;
	noc=1;						//storing number of rows and columns in first column of non-zero representation
	
	for(int i=0;i<r;i++)
	{for(int j=0;j<c;j++)
		{
			if(arr[i][j]!=0)
			{
			nonz[0][noc]=i;
			nonz[1][noc]=j;
			nonz[2][noc]=arr[i][j];
			noc++;						//if element in sparse matrix is non-zero, store element and location in nonz matrix
			}
		}
	}	
}

void represent::converttomat()
{
	r=nonz[0][0];
	c=nonz[1][0];							//determining number of rows and columns of sparse matri
	
	for(int i=1;i<noc;i++)
	{	int row,column,value;
		
		row = nonz[0][i];
		column = nonz[1][i];
		value = nonz[2][i];
		
		for(int m=0;m<r;m++)
		{for(int n=0;n<c;n++)
			{if(m==row && n==column)
				arr[m][n]=value;
			}
		}
	}
}

void represent::displaynz()
{	cout<<endl<<"\tNon-Zero Representation\n\n";
	for(int i=0;i<3;i++)
	{	
		if(i==0)
		cout<<" Row    | ";
		else if(i==1)
		cout<<" Column | ";
		else 
		cout<<" Value  | ";
		
		for(int j=0;j<noc;j++)
		{
			cout<<nonz[i][j]<<" ";
		}
		cout<<endl;		
	}
}

void represent::displaymat()
{	cout<<"\n\tThe Sparse matrix is\n\n";
	for(int i=0;i<r;i++)
	{	cout<<"\t";
		for(int j=0;j<c;j++)
		{	cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}	
}

int main()
{
	represent mat;
	int op;
	cout<<"\n\t* Matrix Representation *";
	cout<<"\n\n(1)Sparse matrix to Non-Zero form\n(2)Non-zero form to Sparse Matrix";
	cout<<"\n\nENTER AN OPTION (1/2): ";
	cin>>op;
	switch(op)
	{	
		case 1: 	mat.inputmatrix();
					mat.converttonz();
					mat.displaynz();
					break;
	 
		case 2: 	mat.inputnonzero();
					mat.converttomat();
					mat.displaymat();
					break;
					
		default: 	cout<<"\nInvalid option entered";
	}
	return 0;
}
