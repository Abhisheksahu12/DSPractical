#include<iostream>
#include<cmath>
#include"bits/stdc++.h"
using namespace std;
template<class T>
class node{
    public:
T data;
node<T>* next;
node<T>* previous;
};
template<class T>
class dll{
node<T>* first=NULL;
node<T>* last=NULL;
public:
void add_to_tail(T x){
    node<T>* temp=new node<T>;
    temp->data=x;
    temp->next=NULL;
    if (first==NULL)
    {
        temp->previous=NULL;
        first=temp;
        last=temp;
        return;
    }
    temp->previous=last;
    last->next=temp;
    last=temp;    
}
void add_to_head(T x){
    node<T>* temp=new node<T>;
    temp->data=x;
    temp->previous=NULL;
    if (first==NULL)
    {
        temp->next=NULL;
        first=temp;
        last=temp;
        return;
    }
    temp->next=first;
    first->previous=temp;
    first=temp;    
}
void add_in_between(T x,T after){
    node<T>* temp1=new node<T>;
    node<T>* temp=first;
    temp1->data=x;
    if (temp==NULL)
    {
        add_to_head(x);
        return;
    }
    else if (after==last->data)
    {
        add_to_tail(x);
        return;
    }
    while (temp->data!=after)
    {
        temp=temp->next;
    }
    temp1->next=temp->next;
    temp->next->previous=temp1;
    temp1->previous=temp;
    temp->next=temp1;       
}
void delete_from_tail(){
    if (first==NULL)
        {
            cout<<"No item to delete"<<endl;
            return;
        }
    node<T>* temp=new node<T>;
    temp=first;
    if (temp->next==NULL)
        {
            first=NULL;
            last=NULL;
            delete temp;
            return;
        }
    temp=last;
    last=temp->previous;
    last->next=NULL;
    temp->previous=NULL;
    delete temp;
}
void delete_from_head(){
    if (first==NULL)
        {
            cout<<"No item to delete"<<endl;
            return;
        }
    node<T>* temp=new node<T>;
    temp=first;
    if (temp->next==NULL)
        {
            first=NULL;
            last=NULL;
            delete temp;
            return;
        }
    first=temp->next;
    first->previous=NULL;
    temp->next=NULL;
    delete temp;
}
void delete_from_between(T x){
    if (first==NULL)
        {
            cout<<"No item to delete"<<endl;
            return;
        }
    node<T>* temp=new node<T>;
    temp=first;
    if (temp->next==NULL && temp->previous==NULL)
    {
        first=NULL;
        last=NULL;
        delete temp;
        return ;
    }
    
    if (temp->data==x)
    {
        first=temp->next;
        first->previous=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }
    while (temp->data!=x)
    {
       temp=temp->next;
    }
    if (temp==last)
    {
        last=temp->previous;
        last->next=NULL;
        delete temp;
        return;
    }
    node<T>* temp1=temp->previous;
    temp1->next=temp->next;
    temp->next->previous=temp1;
    delete temp;
}
void display(){
    if (first==NULL)
        {
            cout<<"Empty list!"<<endl;
            return;
        }
    node<T>* temp=first;
    while (temp!=NULL)
    {
        cout<<temp->data;
        if (temp->next==NULL)
        {
            cout<<endl;
        }
        else{
            cout<<"<->";
        }
        temp=temp->next;
    }
}
int size(){
    node<T>* temp=first;
    int count=0;
    while (temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
int find(T x){
    if (first==NULL)
    {
        return -1;
    }
    node<T>* temp=first;
    if (temp->data==x)
    {
        return 1;
    }
    int count=1;
    while (temp->data!=x )
    {
        temp=temp->next;
        count++;
    }
    return count;
}
void   reverse(){
    node<T>* temp=last;
    while (temp!=NULL)
    {
        cout<<temp->data;
        if (temp->previous==NULL)
        {
            cout<<endl;
        }
        else{
            cout<<"<->";
        }
        temp=temp->previous;
    }
}
dll  operator + (dll const &obj) {
        dll res;
        res.first=first;
        last->next=obj.first;
        obj.first->previous=last;
        res.last=obj.last;
        return res;
}
~dll(){
   node<T>* temp=new node<T>;
   while (first!=NULL)
   {
       temp=first;
       first=first->next;
       delete(temp);
   }
    cout<<"MEMORY FREED!!"<<endl;
}
};
int main(){
// dll<char> list;
// dll list1;

// list.add_to_tail('a');
// list.add_to_head('b');
// list.add_to_head('c');
// list.add_to_head('d');
// list.add_in_between('e','c');
// list.display();
// list.reverse();
// list1.add_to_tail(6);
// list1.add_to_head(7);
// list1.add_to_head(9);
// list1.add_to_head(5);
// list1.add_in_between(18,5);
// list1.display();
// list1.reverse();
// dll list2=list+list1;
// list2.display();
// list2.reverse();
// cout<<list.find(8)<<endl;
// cout<<list.size()<<endl;
// list.delete_from_between(8);
// list.display();
// cout<<list.size()<<endl;
// list.delete_from_between(4);
// list.display();
// cout<<list.size()<<endl;
// list.delete_from_between(1);
// list.display();
// cout<<list.size()<<endl;
// list.delete_from_between(3);
// list.display();
// cout<<list.size()<<endl;
// list.delete_from_between(2);
// cout<<list.size()<<endl;
// list.display();
// cout<<list.size()<<endl;
// list.delete_from_between(2);
// cout<<list.size()<<endl;

// list.delete_from_head();
// list.display();
// list.delete_from_head();
// list.display();
// list.delete_from_head();
// list.display();
// list.delete_from_head();
// list.display();
// list.delete_from_head();
// list.display();
// list.delete_from_head();
// list.delete_from_tail();
// list.display();
// list.delete_from_tail();
// list.display();
// list.delete_from_tail();
// list.display();
// list.delete_from_tail();
// list.display();
// list.delete_from_tail();
// list.display();
// list.delete_from_tail();
dll<int> list;
    cout<<"Created...."<<endl;
    cout<<"Adding to tail 10...."<<endl;
    list.add_to_tail(10);
    list.display();
    cout<<"Adding to tail 20...."<<endl;
    list.add_to_tail(20);
    list.display();
    cout<<"Adding to tail 30...."<<endl;
    list.add_to_tail(30);
    list.display();
    cout<<"Adding to head 50...."<<endl;
    list.add_to_head(50);
    list.display();
    cout<<"Adding 40 after 50 in between..."<<endl;
    list.add_in_between(40,50);
    list.display();
    cout<<"Deleting from head...."<<endl;
    list.delete_from_head();
    list.display();
    cout<<"Deleting 20 from between..."<<endl;
    list.delete_from_between(20);
    list.display();
    cout<<"Searching for 10....."<<endl;
    cout<<"10 Found at index:"<<list.find(10)<<endl;
dll<int> list1;
    cout<<"Created new list...."<<endl;
    cout<<"Adding to tail 70...."<<endl;
    list1.add_to_tail(70);
    list1.display();
    cout<<"Adding to tail 80...."<<endl;
    list1.add_to_tail(80);
    list1.display();
    cout<<"Adding to tail 90...."<<endl;
    list1.add_to_tail(90);
    list1.display();
    dll<int> list3=list+list1;
    cout<<"Concatenating this list with previous one....."<<endl;
    cout<<"Final list :";
    list3.display();
return 0;
}


Doubly linked list
