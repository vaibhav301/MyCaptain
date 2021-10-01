#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(){
	int a[1000];
	int n;
	int max_sum = 0;
	int current_sum = 0;

	cin>>n;
	int left = 0;
	int right = n;
	
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	
	for(int i=0 ; i<n ; i++){
		for(int j=i; j<n ; j++){
			current_sum = 0;
			for(int k=i ; k<j ; k++){
				current_sum += a[k];
			}
			if(current_sum > max_sum){
				max_sum = current_sum;
				left = i;
				right = j;
			}
		}
	}
	cout<<max_sum<<endl;
	for(int k=left ; k<right ; k++){
		cout<<a[k]<<" ";
	}
    return 0;
}
