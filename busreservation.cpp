#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

void intro()
{
     system("color 07");
     system("cls");
}

static int p = 0;
class Bus_Reservation
{
  char busn[5];
  char driver[10];
  char arrival[5];
  char depart[5];
  char from[10];
  char to[10];
  char seat[8][4][10];

public:
  void add_bus();
  void reserve_bus();
  void empty();
  void show_bus();
  void is_bus_available();
  void position(int i);
}

bus[10];

void Bus_Reservation::add_bus()
{
  cout<<"Enter bus number: ";
  cin>>bus[p].busn;

  cout<<"Enter Driver's name: ";
  cin>>bus[p].driver;

  cout<<"Arrival time: ";
  cin>>bus[p].arrival;

  cout<<"Departure: ";
  cin>>bus[p].depart;

  cout<<"From: ";
  cin>>bus[p].from;

  cout<<"To: ";
  cin>>bus[p].to;
  
   cout<<"\n Added Successfully....";
 
  bus[p].empty();
  p++;
  
  getch();

}

void Bus_Reservation::reserve_bus()
{
  int seat;
  char number[5];
  top:
  cout<<"Bus number: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
  while(n<=p)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
    }
    else
    {
      if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
        cout<<"Enter passanger's name: ";
        cin>>bus[n].seat[seat/4][(seat%4)-1];
        break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
      }
    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
      goto top;
    }
    cout<<"\n Added Successfully....";
	getch();
  }


void Bus_Reservation::empty()
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[p].seat[i][j], "Empty");
    }
  }
}

void Bus_Reservation::show_bus()
{
  int n;
  char number[5];
  cout<<"Enter bus number: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
  while(n<=p)
  {
  	cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
  	cout<<"Bus no: "<<bus[n].busn
  	<<"\nDriver: "<<bus[n].driver<<"\nArrival time: "
  	<<bus[n].arrival<<"\nDeparture time: "<<bus[n].depart
  	<<"\nFrom: "<<bus[n].from<<"\nTo: "<<
  	bus[n].to<<"\n";
  	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
  	bus[0].position(n);
  
  	int a=1;
  	for (int i=0; i<8; i++)
  	{
    	for(int j=0;j<4;j++)
    	{
      	a++;
      	if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      	cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    	}
  	}
  	break;
  	}
  	if(n>p)
    	cout<<"Enter correct bus no: ";
    	
  	getch();
}

void Bus_Reservation::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
    cout<<"\n\nThere are "<<p<<" seats empty in Bus Number: "<<bus[l].busn;
  }

void Bus_Reservation::is_bus_available()
{
  for(int n=0;n<p;n++)
  {
  		cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    	cout<<"Bus number: "<<bus[n].busn<<"\nDriver: "<<bus[n].driver
    	<<"\nArrival time: "<<bus[n].arrival<<"\nDeparture Time: "
    	<<bus[n].depart<<"\nFrom: "<<bus[n].from<<"\nTo: "
    	<<bus[n].to;
    	cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
  }
getch();
}

int main()
{
system("cls");
int w;
while(1)
{
system("cls");
    intro();

  cout<<"\n";
  cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
  cout<<"\t\t\t1. Add Bus\n\t\t\t"
  <<"2. Reservation\n\t\t\t"
  <<"3. Show Bus\n\t\t\t"
  <<"4. Buses Available \n\t\t\t"
  <<"5. Exit";
  cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
  cout<<"\n\t\t\tEnter your choice:-> ";
  cin>>w;
  switch(w)
  {
    case 1:  bus[p].add_bus();
      break;
    case 2:  bus[p].reserve_bus();
      break;
    case 3:  bus[0].show_bus();
      break;
    case 4:  bus[0].is_bus_available();
      break;
    case 5:  exit(0);
  }
}
return 0;
}
