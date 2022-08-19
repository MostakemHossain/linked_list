#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *Next;
    // constructors
    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};
struct Test
{
    int pos[1000];
};
void display(Node *n);
void InsertAtHead(Node *&head, int val);
void InsertAtTail(Node *&head, int val);
int countLen(Node *&head);
void InsertAtspecificPosition(Node *&head, int pos, int val);
int Search_A_Value_unique(Node *&head, int key);
void Search_A_Value_Duplicate(Node *&head, int key);
Test Search_A_Value_Duplicate_Return(Node *&head, int key);
void InsertAfterAspecificValue(Node *&head,int searchval,int val);
void DeletionAtHead(Node *&head);
void DeletionAtTail(Node *&head);
void DeletionAt_A_specificposition(Node *&head,int pos);
void DeletionAt_A_specificValue(Node *&head,int val);
Node* Reverse_A_linked_list_Non_recursive(Node *&head);
Node* Reverse_A_linked_list_recursive(Node *&head);











Node* Reverse_A_linked_list_recursive(Node *&head){
    //base call;
    if(head==NULL || head->Next==NULL){
        if(head==NULL){
            cout<<"The linked list is empty "<<endl;
        }
        return head;
    }
    //recursive call
    Node *newHead=Reverse_A_linked_list_recursive(head->Next);
    head->Next->Next=head;
    head->Next=NULL;
    return newHead;
}
Node* Reverse_A_linked_list_Non_recursive(Node *&head){
    Node *prev=NULL;
    Node *current=head;
    if(head==NULL){
        cout<<"The linked list is empty "<<endl;
        return head;
    }
    Node *next=head->Next;
    while(1){
        current->Next=prev;
        prev=current;
        current=next;
        if(current==NULL){
            break;
        }
        next=next->Next;
    }
    return prev;
}
void DeletionAt_A_specificValue(Node *&head,int val){
    //find the position of the value
    int pos;
    pos=Search_A_Value_unique(head,val);
    if(pos==-1){
        cout<<"The value is not found "<<endl;
    }else{
        //delete the node of the position
        DeletionAt_A_specificposition(head,pos);
    }
}
void DeletionAt_A_specificposition(Node *&head,int pos){
    Node *temp=head;
    if(pos<=countLen(head)){
        if(pos==1){
            DeletionAtHead(head);
        }else if(pos==countLen(head)){
            DeletionAtTail(head);
        }else{
            int i=1;
            while(i<pos-1){
                temp=temp->Next;
                i++;
            }
            Node *delNode= temp->Next;
            temp->Next=delNode->Next;
            delete delNode;
        }

    }else{
        //position>countlen
        cout<<"Position out of bound"<<endl;
    }
}
void DeletionAtTail(Node *&head){
    Node *temp=head;
    if(temp!=NULL && temp->Next!=NULL){
        while(temp->Next->Next!=NULL){
            temp=temp->Next;
        }
        Node *delNode=temp->Next;
        temp->Next=NULL;
        delete delNode;

    }else{
        //head is null
        if(head==NULL){
            cout<<"There is  no value in linked list"<<endl;
        }else{
            //head is tail
            DeletionAtHead(head);
        }
    }
}
void DeletionAtHead(Node *&head){
    Node *temp=head;
    if(temp!=NULL){
        head=temp->Next;
        delete temp;
    }else{
        cout<<"There is no Value in linked list "<<endl;
    }
}
void InsertAfterAspecificValue(Node *&head,int searchval,int val){
    //find the position
    int position;
    position=Search_A_Value_unique(head,searchval);
    //insert the value position+1;
    InsertAtspecificPosition(head,position+1,val);
}
Test Search_A_Value_Duplicate_Return(Node *&head, int key)
{
    Test T;
    int k = 1, count = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            T.pos[k++] = count;
        }
        temp = temp->Next;
        count++;
    }
    T.pos[0] = k;
    return T;
}
void Search_A_Value_Duplicate(Node *&head, int key)
{
    int count = 1;
    int flag = 0;
    int k = 1;
    Node *temp = head;
    int size = countLen(head);
    int pos[size + 1];
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            pos[k++] = count;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }
    pos[0] = k;
    if (flag == 0)
    {
        cout << "The Value is not found " << endl;
    }
    else
    {
        for (int i = 1; i < pos[0]; i++)
        {
            cout << pos[i] << endl;
            if (i < pos[0] - 1)
            {
                cout << ",";
            }
        }
    }
    cout << endl;
}
int Search_A_Value_unique(Node *&head, int key)
{
    // case 1;
    if (head == NULL)
    {
        return -1;
    }
    int count = 1;
    Node *temp = head;
    while (temp->value != key)
    {
        if (temp->Next == NULL)
        {
            return -1;
        }
        temp = temp->Next;
        count++;
    }
    return count;
}
void InsertAtspecificPosition(Node *&head, int pos, int val)
{
    int i = 0;
    Node *temp = head;
    while (i < pos - 2)
    {
        temp = temp->Next;
        i++;
    }
    // new Node creation
    Node *newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}
int countLen(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->Next;
        count++;
    }
    return count;
}
void InsertAtHead(Node *&head, int val)
{
    // new Node creation
    Node *newNode = new Node(val);
    // uptade new node to head
    newNode->Next = head;
    // uptade head
    head = newNode;
}
void InsertAtTail(Node *&head, int val)
{
    // new Node creation
    Node *newNode = new Node(val);
    // case1:head is NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}
void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value << " ";
        if (n->Next != NULL)
        {
            cout << " -> ";
        }
        n = n->Next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    cout << "Choice 1:Insert At head " << endl;
    cout << "Choice 2:Insert At Tail " << endl;
    cout << "Choice 3:Insert At specific position " << endl;
    cout << "Choice 4:Search A value Unique " << endl;
    cout << "Choice 5:Search A value Duplicate " << endl;
    cout << "Choice 6:Search A value Duplicate Return " << endl;
    cout << "Choice 7:Insert After a specific Value " << endl;
    cout << "Choice 8:Deletion at head " << endl;
    cout << "Choice 9:Deletion at Tail " << endl;
    cout << "Choice 10:Deletion at a specific position " << endl;
    cout << "Choice 11:Deletion at a specific value " << endl;
    cout << "Choice 12:Reverse a linkedlist(Non_Recursive) " << endl;
    cout << "Choice 13:Reverse a linkedlist(Recursive) " << endl;
    cout << "Choice 0:Exit " << endl;

    int n, choice, position;
    cout << "Enter your choice " << endl;
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter your value " << endl;
            cin >> n;
            InsertAtHead(head, n);
            break;
        case 2:
            cout << "Enter your value " << endl;
            cin >> n;
            InsertAtTail(head, n);
            break;
        case 3:
            cout << "Enter your desire position " << endl;
            cin >> position;
            cout << "Enter your value " << endl;
            cin >> n;
            InsertAtspecificPosition(head, position, n);
            break;
        case 4:

            cout << "Enter the value to search " << endl;
            cin >> n;
            position = Search_A_Value_unique(head, n);
            if (position == -1)
            {
                cout << "The value is not found " << endl;
            }
            else
            {
                cout << "The position of this value " << position << endl;
            }
            break;
        case 5:
            cout << "Enter the value to search " << endl;
            cin >> n;
            Search_A_Value_Duplicate(head, n);
        case 6:
            cout << "Enter the value to search " << endl;
            cin >> n;
            Test T;
            T = Search_A_Value_Duplicate_Return(head, n);
            if (T.pos[0] == 1)
            {
                cout << "The value is not found " << endl;
            }
            else
            {
                for (int i = 1; i < T.pos[0]; i++)
                {
                    cout << T.pos[i];
                    if (i < T.pos[0] - 1)
                    {
                        cout << ",";
                    }
                }
            }
            break;
        case 7:
            cout<<"Enter the value to search "<<endl;
            int search;
            cin>>search;
            cout<<"Enter the value to Insert "<<endl;
            cin>>n;
            InsertAfterAspecificValue(head,search,n);
            break;
        case 8:
            DeletionAtHead(head);
            break;
        case 9:
            DeletionAtTail(head);
            break;
        case 10:
            if(head==NULL){
                cout<<"There is No value in this linked list"<<endl;
            }
            cout<<"Enter your position to delete "<<endl;
            cin>>position;
            DeletionAt_A_specificposition(head,position);
            break;
        case 11:
            cout<<"Enter your value of delete "<<endl;
            cin>>n;
            DeletionAt_A_specificValue(head,n);
            break;
        case 12:
            head=Reverse_A_linked_list_Non_recursive(head);
            break;
        case 13:
            head=Reverse_A_linked_list_recursive(head);
            break;

        }
        cout << "Next choice " << endl;
        cin >> choice;
    }

    cout << "The Linked list is " << endl;
    display(head);
    cout << "The length of the linked list " << countLen(head) << endl;

    /*//naive way
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();

    head->value=1;
    second->value=5;
    third->value=8;
    fourth->value=9;

    head->Next=second;
    second->Next=third;
    third->Next=fourth;
    fourth->Next=NULL;

    display(head);*/
}