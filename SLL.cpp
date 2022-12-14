#include<iostream>
#include<cmath>
#include"bits/stdc++.h"
using namespace std;
template<class T>
class node{
    public:
    T data;
    node<T>* next;
};
template<class T>
class sll{
    node<T> *first=NULL;
    node<T> *last=NULL;
    public:
    void add_to_tail(T x){
        node<T>* temp=new node<T>;
        temp->data=x;
        if (first==NULL)
        {
            first=temp;
            last=temp;
            return;
        }
        last->next=temp;
        last=temp;
        temp->next=NULL;

    }
    void   add_to_head(T x){
        node<T>* temp=new node<T>;
        temp->data=x;
        
        if (first==NULL)
        {
            first=temp;
            last=temp;
            return;
        }
        temp->next=first;
        first=temp;

    }
    void   add_in_between(T x,T after){
        node<T>* temp1=new node<T>;
        temp1->data=x;
        if (first==NULL)
        {
            first=temp1;
            last=temp1;
            return;
        }
        node<T>* temp=first;
        while (temp->data!=after)
        {
            temp=temp->next;
        }
        
        if (temp==last)
        {
            last->next=temp1;
            temp1->next=NULL;
            last=temp1;
        }
        else{
            temp1->next=temp->next;
            temp->next=temp1;
        }
    }
    void   delete_from_head(){
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
        delete temp;
    }
    void   delete_from_tail(){
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
        
        while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        last=temp;
        temp=temp->next;
        last->next=NULL;
        delete temp;
    }
    void   delete_from_between(T x){
        if (first==NULL)
        {
            cout<<"No item to delete"<<endl;
            return;
        }
        node<T>* temp=first;
        if (temp->data==x)
        {
            first=temp->next;
            delete temp;
            return;
        }
        
        while (temp->next->data!=x)
        {
            temp=temp->next;
            if (temp==last)
            {
                delete_from_tail();
                break;
                return;
            }
        }
        if (temp==first)
        {
            delete_from_head();
        }
        else{
            node<T>* temp1=temp->next;
            temp->next=temp->next->next;
            delete temp1;
        }
    }
    int   size(){
        node<T>* temp=first;
        int count=0;
        while (temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    int   find(int x){
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
        while (temp->data!=x)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }
    void   display(){
        if (first==NULL)
        {
            cout<<"Empty list!"<<endl;
            return;
        }
        node<T>* temp=first;
        while (temp!=NULL)
        {
            cout<<temp->data;
            if(temp->next==NULL){
                cout<<endl;
            }
            else{
                cout<<"->";
            }
            temp=temp->next;
        }
    }
    void   reverse(){
        node<T>* temp=last;
        node<T>* temp1=first;
        //more code to come
        while (temp!=NULL)
        {
            if (temp==first)
            {
                temp->next=NULL;
                temp=last;
                last=first;
                first=temp;
                break;
            }
        while (temp1->next!=temp)
        {
            temp1=temp1->next;
        }
        temp->next=temp1;
        temp=temp1;
        temp1=first;
        }
    }
    sll  operator + (sll const &obj) {
         sll res;
         res.first=first;
         node<T>* temp=first;
         last->next=obj.first;
         res.last=obj.last;
        //  res.real = real + obj.real;
        //  res.imag = imag + obj.imag;

         return res;
    }
    ~sll(){
        while (first!=NULL)
        {
            node<T>* temp=first;
            first=first->next;
            delete temp;
        }
        last=NULL;
        cout<<"Destructor called"<<endl;
    }

};
int main(){
// sll li;
// sll li1;
// li.add_to_tail(5);
// li.add_to_tail(6);
// li.add_to_tail(7);
// li.display();
// // li.add_in_between(11,8);
// li1.add_to_head(8);
// li1.add_to_head(9);
// li1.add_to_head(10);
// li1.display();
// sll li2=li1+li;
// li2.display();
// // li.delete_from_between(10);
// // li.delete_from_head();
// // li.delete_from_tail();

// // cout<<"10 found at position:"<<li.find(10)<<endl;
// // cout<<"9 found at position:"<<li.find(9)<<endl;
// // cout<<"8 found at position:"<<li.find(8)<<endl;
// // cout<<"11 found at position:"<<li.find(11)<<endl;
// // cout<<"5 found at position:"<<li.find(5)<<endl;
// // cout<<"6 found at position:"<<li.find(6)<<endl;
// // cout<<"7 found at position:"<<li.find(7)<<endl;

// // li.display();
// // li.reverse();
// // li.display();
// // cout<<li.size()<<endl;
// char x;
// int count;
// cin>>count;
// sll<char> list;
// list.add_to_tail('a');
// list.add_to_head('b');
// list.add_to_head('c');
// list.add_to_head('d');
// list.add_in_between('e','c');
// list.display();
// list.reverse();
// for (int i = 0; i < count; i++)
// {
//     cin>>x;
//     list.add_to_tail(x);
// }
// list.display();
// list.reverse();
// list.display();
sll<int> list;
    cout<<"Created...."<<endl;
    cout<<"Adding to tail 1...."<<endl;
    list.add_to_tail(1);
    list.display();
    cout<<"Adding to tail 2...."<<endl;
    list.add_to_tail(2);
    list.display();
    cout<<"Adding to tail 3...."<<endl;
    list.add_to_tail(3);
    list.display();
    cout<<"Adding to head 5...."<<endl;
    list.add_to_head(5);
    list.display();
    cout<<"Adding 4 after 5 in between..."<<endl;
    list.add_in_between(4,5);
    list.display();
    cout<<"Deleting from head...."<<endl;
    list.delete_from_head();
    list.display();
    cout<<"Deleting 1 from between..."<<endl;
    list.delete_from_between(2);
    list.display();
    cout<<"Searching for 1....."<<endl;
    cout<<"1 Found at index:"<<list.find(1)<<endl;
sll<int> list1;
    cout<<"Created new list...."<<endl;
    cout<<"Adding to tail 7...."<<endl;
    list1.add_to_tail(7);
    list1.display();
    cout<<"Adding to tail 8...."<<endl;
    list1.add_to_tail(8);
    list1.display();
    cout<<"Adding to tail 9...."<<endl;
    list1.add_to_tail(9);
    list1.display();
    sll<int> list3=list+list1;
    cout<<"Concatenating this list with previous one....."<<endl;
    cout<<"Final list :";
    list3.display();
return 0;
}


singly linked list
