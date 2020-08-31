#include <iostream>
using namespace std;
	class time
	{
		private:
			int h;
			int m;
			int s;
			int min;
			int sec;
		public:
			void display()
			{
				cout<<"Enter Time:"<<endl;
				cout<<"Hours? ";
				cin>>h;
				cout<<"Minutes? ";
				cin>>m;
				cout<<"Seconds? ";
				cin>>s;
				cout<<"The time is = 0"<<h<<":0"<<m<<":0"<<s<<endl;
				min=m+(h*60);
				sec=s+(min*60);
				cout<<"Time in total seconds: "<<sec<<endl;
			}
		
	};
	int main()
	{
		time obj;
		obj.display();
		return 0;
		
	}
