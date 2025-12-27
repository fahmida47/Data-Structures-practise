#include<bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    node* next;
};
node* root = NULL;

// 1.Insert First
void InsertFirst(int value) 
{
    node* temp = new node();
    temp->data = value;
    temp->next = root;
    root = temp;
}

// 2.Insert Last
void InsertLast(int value) 
{
    node* temp = new node();
    temp->data = value;
    temp->next = NULL;

    if (root == NULL) 
    {
        root = temp;
        return;
    }

    node* curr = root;
    while (curr->next != NULL) 
    {
         curr = curr->next;
    }
    curr->next = temp;
}

// 3.Insert anywhere between 2 node[pos,value]
// Insert After Position 
void InsertAfterPosition(int pos, int value)
    {
    if (pos < 1) 
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1 && root == NULL) 
    {
        InsertFirst(value);
        return;
    }

    node* curr = root;

    for (int i = 1; i < pos && curr != NULL; i++) 
    {
        curr = curr->next;
    }

    if (curr == NULL) 
    {
        cout << "Position exceeds list length\n";
        return;
    }

    node* temp = new node();
    temp->data = value;
    temp->next = curr->next;
    curr->next = temp;
}

// Insert Before Position 
void InsertBeforePosition(int pos, int value) 
{
    if (pos<=1) 
    {
        InsertFirst(value);
        return;
    }
    InsertAfterPosition(pos-1, value);
}

// Insert After Value
void InsertAfterValue(int valueToSearch, int value) 
    {
    node* curr = root;
    while (curr!=NULL && curr->data!=valueToSearch) 
    {
        curr = curr->next;
    }

    if (curr==NULL) 
    {
        cout << "Value"<<valueToSearch<<"not found\n";
        return;
    }

    node* temp = new node();
    temp->data = value;
    temp->next = curr->next;
    curr->next = temp;
}

// Insert Before Value
void InsertBeforeValue(int valueToSearch, int value) 
    {
    if (root == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (root->data == valueToSearch) 
    {
        InsertFirst(value);
        return;
    }

    node* curr = root;
    while (curr->next!=NULL && curr->next->data!=valueToSearch) 
    {
        curr=curr->next;
    }

    if (curr->next == NULL)
    {
        cout << "Value"<<valueToSearch <<"not found\n";
        return;
    }

    node* temp = new node();
    temp->data = value;
    temp->next = curr->next;
    curr->next = temp;
}

// 4.Delete First
    void DeleteFirst()
    {
        if(root!=NULL)
        {
        root=root->next;
        }
    }

// 5.Delete Last
    void DeleteLast()
    {
         node* curr=root;
         node* prev=NULL;
      while(curr->next!=NULL)
      {
          prev=curr;
          curr=curr->next;
      }
      prev->next=NULL;
    }
// 6.Delete anyehere between 2 node[pos,value]
// Delete After Position
 void DeleteAfterPosition(int pos)
    {
        if(pos==1)
        {
            DeleteFirst();
            return;
        }

        node* curr=root;
        for(int i=0;i<pos-1;i++)
        {

            curr=curr->next;

        }
        if(curr->next==NULL)
        {
            DeleteLast();
        }
        curr->next=curr->next->next;
    }

// Delete Before Position
    void DeleteBeforePosition(int pos)
    {
        DeleteAfterPosition(pos-1);
    }
// Delete After Value
    void DeleteAfterValue(int valueToSearch)
    {

        node* curr=root;
        while(curr->data!=valueToSearch)
        {

            curr=curr->next;

        }
        curr->next=curr->next->next;
    }
// Delete Before Value
   void DeleteBeforeValue(int valueToSearch)
{
    if (root==NULL || root->data==valueToSearch) 
    {
        cout << "No node exists before the value or list is empty\n";
        return;
    }

    if (root->next != NULL && root->next->data == valueToSearch) 
    {
        DeleteFirst();
        return;
    }
    node* prev = NULL;
    node* curr = root;
    
    while (curr->next != NULL && curr->next->data != valueToSearch) 
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr->next == NULL) 
    {
        cout << "Value " << valueToSearch << " not found\n";
        return;
    }
    if (prev != NULL) 
    {
        prev->next = curr->next;
    }
}

// 7.Printing 
void Printing() 
{
    node* curr = root;
    while (curr != NULL) 
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// 8.Searching
void Searching(int value)
  {
      node *curr=root;
       int flag=0;
      while(curr!=NULL)
      {
          if(curr->data==value)
          {
              cout<<"Found"<<endl;
              flag=1;
              break;
          }
          curr=curr->next;
      }
      if(flag==0)
      {
            cout<<"Not found"<<endl;
      }
  }

// 9.last_node
void Last_Node()
  {
      node* curr=root;
      while(curr->next!=NULL)
      {
          curr=curr->next;
      }
      cout<<curr->data<<endl;
  }

// 10.Previous last
void Previous_of_Last_Node()
  {
      node* curr=root;
      while(curr->next->next!=NULL)
      {
          curr=curr->next;
      }
      cout<<curr->data<<endl;
  }

// 11.Size
  int size()
    {
        node* curr=root;
        int num=1;
        while(curr->next!=NULL)
        {
            num++;
            curr=curr->next;
        }
    return num;
    }

// 12.Reverse Print
void RevPrint(node* curr)
  {
      if(curr!=NULL)
      {
          RevPrint(curr->next);
          cout<<curr->data<<endl;
      }
  }


int main()
{
// INSERT //
    //Print Insert 1st
    InsertFirst(40);
    InsertFirst(30);
    InsertFirst(20);
    InsertFirst(10);
    //Print Insert last
    InsertLast(50);
    //Print by Position
    InsertAfterPosition(1,15);
    InsertBeforePosition(5,35);
    //Print by value
    InsertAfterValue(20,26);
    InsertBeforeValue(10,5);
    Printing();

// DELETE //
    // Print delete 1st
    DeleteFirst();
    //Print delete last
    DeleteLast();

    DeleteAfterPosition(3);
    DeleteBeforePosition(1);

    DeleteAfterValue(30);
    DeleteBeforeValue(60);
    Printing();

// Searching
    Searching(30);
    Last_Node();
    Previous_of_Last_Node();
    Printing();

// Size
    cout<<size()<<endl;

// Reverse
    RevPrint(root);
}
