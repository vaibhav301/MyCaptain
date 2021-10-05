#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

Node *first;

void creat_cc_ll(int A[],int n)
{
   first=new Node;
   first->data=A[0];
   first->next=first;
   Node *current=first;

   for(int i=1;i<n;i++)
   {
       Node *ptr=new Node;
       ptr->data=A[i];
       ptr->next=current->next;

       current->next=ptr;
       current=ptr;
   }

}

void Display(Node *ptr)
{
    do
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;

    } while (ptr!=first);
    
}

void Recursive_Deisplay(Node *ptr)
{
    static int flag=0;
    if(ptr!=first || flag==0)
    {
       flag=1;
       cout<<ptr->data<<"->";
       Recursive_Deisplay(ptr->next);
    }
    flag=0;
}

int find_length()
{
    do
    {
        /* code */
    } while (pla);
    
}

void insert(int d,int pos)
{
    Node *ptr=new Node;
    ptr->data=d;
    
    Node *temp=first;
    
     if(pos==0)
     {
        if(first==NULL)
        {
            first=ptr;
            first->next=first;
        } 
        else
        {   
        while(temp->next!=first)
        {
          temp=temp->next;
        }
         temp->next=ptr;
         ptr->next=first;
         first=ptr;
     }
     }
     else
     {
         for(int i=0;i<pos-1;i++)
         {
             temp=temp->next;
         }
         if(temp!=first)
         {
         ptr->next=temp->next;
         temp->next=ptr;
         }
         else
         {
             cout<<"Invalid Position !!"<<endl;
         }
     }
}

int main()
{
    int A[]={1,2,3,4,5};
    creat_cc_ll(A,sizeof(A)/sizeof(A[0]));   
    Recursive_Deisplay(first);
    cout<<endl;
    insert(0,0);
    cout<<endl;
    Recursive_Deisplay(first);

    insert(6,8);
    cout<<endl;
     Recursive_Deisplay(first);
}
