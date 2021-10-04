#include <iostream>
#include <stdio.h>

using namespace std;

void bubble_sort(int a[], int n){
	for(int i = 1 ; i<=n-1 ; i++){
		for(int j = 0 ; j<(n-i) ; j++){
			if(a[j] > a[j+1]){
				swap(a[j] , a[j+1]);
			}
		}
	}
	return;
}
int main(){
	int a[1000];
	int n;

	cin>>n;
	
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	

	bubble_sort(a, n);

	for(int i = 0 ; i < n ; i++){
		cout<<a[i]<<" ";
	}
	

    return 0;
}
