#include<iostream>

using namespace std;

void bubbleSort(int*,int);
void printArray(int*,int);
int main()
{
    int n,*arr;
    cout<<"Enter the array size: "<<flush;
    cin>>n;
    arr=new int[n];
    cout<<"Enter "<<n<<" integers..."<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The entered array is: "<<endl;
    printArray(arr,n);
    bubbleSort(arr,n);
    cout<<"The array after sorting is: "<<endl;
    printArray(arr,n);
}
void bubbleSort(int *arr,int n)
{
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){ //ascending order
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void printArray(int*arr,int n)
{
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}