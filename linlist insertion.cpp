#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
};
void frontput(Node**head,int Data)
{
    Node* new_node = new Node();
    new_node->data = Data;
    new_node->next = (*head);
    (*head) = new_node;
}
void append(Node *prev_node,int data)
{
    if(prev_node==NULL)
    {
        cout<<"Node can't be null."<<endl;
        return;
    }
    Node* nw = new Node();
    nw->data = data;
    nw->next = prev_node->next;
    prev_node->next = nw;
}
void footput(Node**head_ref,int data)
{
    Node* node = new Node();
    Node* last = *head_ref;
    node->data = data;
    node->next = NULL;
    if(*head_ref==NULL)
    {
        *head_ref = node;
        return;
    }
    while(last->next!= NULL)
    {
        last=last->next;
    }
    last->next = node;
    return;
}
void printlist(Node* node)
{
    while(node!=NULL)
    {
        cout<<node->data<<"         ";
        node=node->next;
    }
}
void delte(Node** head_ref,int value)
{
    Node* temp = *head_ref,*prev;
    if(temp!=NULL && temp->data==value)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL)
    {
        prev = temp;
        temp=temp->next;
        if(temp->data == value)
        {
            prev->next = temp->next;
            free(temp);
            break;
        }

    }
}
int get_count(Node**head_ref)
{
    Node* temp = *head_ref;
    int counnt=0;
    while(temp!=NULL)
    {
        counnt++;
        temp=temp->next;
    }
    return counnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Node *head = NULL;
	frontput(&head,35);
	append(head,656);
	footput(&head,87);
	frontput(&head,911);
	append(head->next,266);
	printlist(head);
	delte(&head,35);
	cout<<endl<<"After deletion"<<endl;
	printlist(head);
	cout<<endl<<"get-count : "<<get_count(&head)<<endl;

}
