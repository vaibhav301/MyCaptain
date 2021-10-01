#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int a[1000];
	int n;
	int key;

	cin>>n;

	int s = 0;
	int e = n-1;

	for(int i=0 ; i<n ; i++){
		cin>>a[i];
	}

	cin>>key;
	int flag = 0;
	while(s <= e){
		int m = (s+e)/2;
		if(a[m] == key){
			cout<<key<<" found at "<<m<<" index.";
			flag = 1;
			break;
		}
		if(key < a[m] ){
			e = m-1;
		}
		if(key > a[m]){
			s = m+1;
		}
	}
	if(flag != 1){
		cout<<key<<" is not in the array.";
	}
    return 0;
}
