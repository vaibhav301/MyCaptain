#include<iostream>
using namespace std;

template<class T>
class tridiagonalmatrix
{
	public:
		tridiagonalmatrix(int theN=10);
		~tridiagonalmatrix(){ delete[] element;}
		T get(int ,int )const;
		void set(int ,int ,const T&);
	private:
		int n;
		T  *element;
};
template<class T>
tridiagonalmatrix<T>::tridiagonalmatrix(int theN)
{
	if(theN<1)
		throw ("Matrix size must be > 0");
	n=theN;
	element=new T [n];
}
template<class T>
T tridiagonalmatrix<T>::get(int i,int j)const
{

if(i<1||j<1||i>n||j>n)
throw "matrixIndexOutOfBound";
switch(i-j)
{
	case 1:return element[i-2];
	       break;
	case 0:return element[n+i-2];
	       break;
	case-1:return element[2*n+i-2];
	        break;
	default: return 0;
}
}


template<class T>
void tridiagonalmatrix<T>::set(int i,int j, const T& value)
{
	if(i<0||j<0||i>n||j>n)
	throw ("Matrix Index out of bounds");

	switch(i-j)
	{
		case 1:
		{
		   element[i-2]=value;
			break;
		}
		case 0:
		{
			element[n+i-2]=value;
			break;
		}
		case -1:
		{
			element[2*n+i-2]=value;
			break;
		}
		default:
		{
			if(value!=0)
			{
				cout<<"Value should be zero"<<endl;
			
			}
			break;
		}
	}
}

int main()
{
	int n;
	cout<<"Enter the order of matrix"<<endl;
	cin>>n;
	int i,j;
	tridiagonalmatrix<int> d (n);
	int **element;
	element=new int*[n];
	for(int i=1;i<=n;i++)
	{
		element[i]=new int[n];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<"element at position ["<<i<<"]["<< j<<"]"<<endl; 
			cin>>element[i][j];
			d.set(i,j,element[i][j]);
		}
	}

cout<<"FORMATION OF TRIDIAGONAL MATRIX : ";
cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<d.get(i,j)<<" ";
		}
		cout<<endl;
	}
}
/*OUTPUT
Enter the order of matrix
3
element at position [1][1]
2
element at position [1][2]
8
element at position [1][3]
9
Value should be zero
element at position [2][1]
8
element at position [2][2]
5
element at position [2][3]
6
element at position [3][1]
7
Value should be zero
element at position [3][2]
4
element at position [3][3]
5
FORMATION OF TRIDIAGONAL MATRIX :
2 8 0
8 5 6
0 4 5

--------------------------------
Process exited after 9.972 seconds with return value 3221226356
Press any key to continue . . .
*/
