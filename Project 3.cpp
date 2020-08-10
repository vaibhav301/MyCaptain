#include <iostream>

using namespace std;
int main()
{

    int a[4];
    int *p;
    
    cout<<" enter";
    for(int i=0;i<=4;i++)
    {
        
        cin>>a[i];
        p=a;
    }
    cout<<"u entered";
    for(int i=0;i<=4;i++)
       {
           cout<<*p<<endl;
           p++;
          
       }
       
    return 0;
}



