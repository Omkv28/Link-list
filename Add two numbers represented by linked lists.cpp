//Add two numbers represented by linked lists 
#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
	int data;
	Node* next;
	
};
void insert(Node** head,int data)
{
	Node* new_node=new Node;
	new_node->data=data;
	new_node->next= NULL;
	Node* temp=*head;
	if(temp==NULL)
	{
		*head=new_node;
		return;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new_node;
		return;
	}
}
void print(Node* head)
{
	Node* temp=head;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}

void reverse(Node** head)
{
	
	Node* prev=NULL;
	Node* current= *head;
	Node* after= *head;
	while(current!=NULL)
	{
		after=after->next;
		current->next=prev;
		prev=current;
		current=after;
	}
	*head= prev;
	
}

void sum(Node* head,Node* start,Node** q)
{
	int x=0;
	int e=0;
	int w=0;
	
	while(head and start)
	{
		w=head->data+start->data+x;
		x=0;
		if(w>9)
		{
			e=w/10;
			w=w%10;
			x=e;
			
		}
		else
		e=0;
		insert(&(*q),w);
	
		head=head->next;
		
		start=start->next;
		
	}
	while(start)
	{
		
		w=start->data+e;
		if(w>9)
		{
			e=w/10;
			w=w%10;
			x=e;
			
		}
		else
		e=0;
		insert(&(*q),w);
	
		
		
		start=start->next;
	}
	
	while(head)
	{
		
		w=head->data+e;
		if(w>9)
		{
			e=w/10;
			w=w%10;
			x=e;
			
		}
		else
		e=0;
		insert(&(*q),w);
	
		
		
		head=head->next;
	}
	if(e>0)
	{
		
		insert(&(*q),e);
	}
	
	
}

int main()
{
	Node* head=NULL;
	insert(&head,9);
	insert(&head,9);
	insert(&head,9);
	print(head);
	reverse(&head);
	
	Node* start=NULL;
	insert(&start,8);
	insert(&start,4);
	insert(&start,2);
	insert(&start,2);
	insert(&start,9);
	insert(&start,9);
	print(start);
	reverse(&start);
	
	Node* q=NULL;
	sum(head,start,&q);
	reverse(&q);
	print(q);
	
}
