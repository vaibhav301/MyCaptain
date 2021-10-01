//Merge Sort 
#include<iostream>
using namespace std;
void copy(int *arr, int temp[], int n)
{
	for(int l=0; l<n; l++)
	arr[l]=temp[l];
}

void mergeSort(int arr[], int first, int last){
	//Base Case 
	if(first>=last)
	return;
	//Recursive Case
	int mid =(first+last)/2;
	mergeSort(arr, first, mid);
	mergeSort(arr, mid+1, last);
	//Merging
	int i=first; int j=mid+1; int k=first; 
	int temp[100];
	while(i<=mid and j<=last){
		if(arr[i]<=arr[j])
		{ temp[k]=arr[i]; i++; k++;}
		else
		{ temp[k]=arr[j]; j++; k++;}
	}
	while(i<=mid)
	temp[k++]=arr[i++];
	while(j<=last)
	temp[k++]=arr[j++];
	
	//Copy elements into main Array
	copy(arr, temp, last+1);
}

int main(){
	int n; cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	cin>>arr[i];
	mergeSort(arr, 0, n-1);
	for(int i=0; i<n; i++)
	cout<<arr[i]<<" ";
}
