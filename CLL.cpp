#include<iostream>
using namespace std;
class node{ 
    public:
    int data;
    node* next;
};
class cll{ 
    node* head=NULL;
    public:
    void insertAtHead(int val){ 
        node* temp=new node;
        temp->data=val;
        if (head==NULL)
        {
            temp->next=temp;
            head=temp;
            return ;
        }
        node* temp1=head;
        while (temp1->next!=head)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
        temp->next=head;
        head=temp;

    }
    void insertAtTail(int val){ 
        node* temp=new node;
        temp->data=val;
        if (head==NULL)
        {
            insertAtHead(val);
            return ;
        }
        node* temp1=head;
        while (temp1->next!=head)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
        temp->next=head;

    }
    void insertAfter(int key,int val){ 
        if (head==NULL)
        {
            insertAtHead(val);
            return ;
        }
        node* temp=new node;
        temp->data=val;
        node* temp1=head;
        while (temp1->data!=key)
        {
            temp1=temp1->next;
        }
        temp->next=temp1->next;
        temp1->next=temp;
    }
    int size(){ 
        node* temp=new node;
        temp=head;
        int count=0;
        do
        {
            count++;
            temp=temp->next;
        } while (temp!=head);
        return count;
    }
    void deleteFromHead(){ 
        if (head==NULL)
        {
            cout<<"No items to delete"<<endl;
            return ;
        }
        node* temp=head;
        if (temp->next==temp)
        {
            head=NULL;
            delete temp;
            return;
        }
        while (temp->next!=head)
        {
            temp=temp->next;
        }
        node* temp1=head;
        temp->next=head->next;
        head=head->next;
        delete temp1;
    }
    void deleteFromTail(){ 
        if (head==NULL)
        {
            cout<<"No items to delete"<<endl;
            return ;
        }
        node* temp=head;
        if (temp->next==temp)
        {
            head=NULL;
            delete temp;
            return;
        }
        
        while (temp->next->next!=head)
        {
            temp=temp->next;
        }
        node* temp1=temp->next;
        temp->next=head;
        delete temp1;
    }
    void deleteElement(int x){ 
        if (head==NULL)
        {
            cout<<"No items to delete"<<endl;
            return ;
        }
        if (head->data==x)
        {
            deleteFromHead();
            return;
        }
        node* temp=head;
        while (temp->next->data!=x)
        {
            temp=temp->next;
        }
        node* temp1=temp->next;
        temp->next=temp1->next;
        delete temp1;
    }
    node* search(int x){
        node* temp=head;
        while (temp->data!=x)
        {
            temp=temp->next;
        }
        return temp;
    }
    cll operator +(cll const &obj){ 
        cll res;
        res.head=head;
        node* temp=obj.head;
        node* temp1=res.head;
        while (temp1->next!=res.head)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
        while (temp->next!=obj.head)
        {
            temp=temp->next;
        }
        temp->next=res.head;
        return res;
    }
    void display(){ 
        if (head==NULL)
        {
            cout<<"Empty List"<<endl;
            return ;
        }
        node* temp=new node;
        temp=head;
        do
        {
            cout<<temp->data;
            if (temp->next==head)
            {
                cout<<endl; 
                break;
            }
            cout<<"->";
            
            temp=temp->next;
        } while (temp!=head);
    }
};
int main(){
    cll c;
    c.insertAtTail(5);
    c.insertAtTail(7);
    c.insertAtTail(8);
    c.insertAtTail(9);
    c.insertAfter(5,6);
    c.display();
    // c.deleteFromTail();
    // c.display();
    // c.deleteFromHead();
    // c.display();
    // c.deleteElement(7);
    // c.display();
    // node* a=c.search(6);
    // cout<<a->next->data<<endl;
    // cout<<a->data<<endl;
    cll b;
    b.insertAtHead(1);
    b.insertAtHead(2);
    b.insertAtHead(3);
    b.display();
    cll a=b+c;
    a.display();
return 0;
}


CIRCULAR LINKED LIST
