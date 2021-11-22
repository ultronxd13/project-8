#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node*next=NULL;
		node(int value)
		{
			data=value;
		}
};
class list{
	node*head;
	public:
		void append(int value)
		{
			if(head==NULL)
			{
				head=new node(value);
			}
			else
			{
				node*temp=head;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=new node(value);
			}
		}
		void insert()
		{
			int pos,elem,i;
			node*temp=head;
			node*newadd;
			cout<<"enter the insert position  ";
			cin>>pos;
			cout<<"enter the number  ";
			cin>>elem;
			for(i=1;i<pos;i++)
			{
				temp=temp->next;
			}
			newadd=new node(elem);
			newadd->next=temp->next;
			temp->next=newadd;
		}
		void dlt()
		{
			node*temp=head;
			int pos,i;
			node*prev=NULL;
			cout<<"enter the position to delete  ";
			cin>>pos;
			for(i=1;i<pos;i++)
			{
				prev=temp;
				temp=temp->next;
				
			}
			if(temp==head)
			{
				head=head->next;
			}
			prev->next=temp->next;
			delete temp;
		}
		void reverse()
		{
			node*temp=head;
			node*prev=NULL;
			node*next=NULL;
			while(temp!=NULL)
			{
				next=temp->next;
				temp->next=prev;
				prev=temp;
				temp=next;
			}
			head=prev;
			
			
		}
	void print(){
			node*temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data;
				temp=temp->next;
			}
		}
		void update(){
			node*temp=head;
			int oldvalue,newvalue;
			cout<<"enter the which value to update  ";
			cin>>oldvalue;
			cout<<"enter the new value to update  ";
				cin>>newvalue;
				while(temp!=NULL&&temp->data!=oldvalue)
				{
					temp=temp->next;
				}
				temp->data=newvalue;
		}
};
int main()
{
list ll;
int length,i,value,choice;
cout<<"enter the length of the list  ";
cin>>length;
cout<<"enter the values of list  ";
for(i=0;i<length;i++)
{
	cin>>value;
	ll.append(value);
	}
		while(choice!=5)
	{
	cout<<"enter the options \n";
	cout<<" 1.insert \n";
	cout<<"2.delete \n";
	cout<<"3.reverse \n";
	cout<<"4.update \n";
	cout<<"5.exit \n";
	cin>>choice;

	
	switch(choice){
		case 1:
			ll.insert();
			ll.print();
			break;
		case 2:
			ll.dlt();
			ll.print();
			break;
		case 3:
			ll.reverse();
			ll.print();
			break;
		case 4:
			ll.update();
			ll.print();
			default :
				cout<<"enter the valid option  ";
	}
}
	return 0;
}
