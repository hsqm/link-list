#include<iostream>
using namespace std;
typedef struct node Node;
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct List{
    Node* head;
    Node* tail;
};


void CreatList(List&ls){
    ls.head=ls.tail=NULL;
}



Node* CreatNode(int value){
    Node* p=new Node;
    if(p==NULL){
        cout<<"Khong du bo nho cap phap"<<endl;
        return NULL;
    }
    p->data=value;
    p->next=NULL;
    p->prev=NULL;
    return p;
}



void AddHead(List&ls,int value){
    Node*p=CreatNode(value);
    if(ls.head==NULL){
        ls.head=ls.tail=p;
    }
    else{
        p->next=ls.head;
        ls.head->prev=p;
        ls.head=p;
    }
}




void AddTail(List&ls,int value){
    Node*p=CreatNode(value);
    if(ls.head==NULL){
        ls.head=ls.tail=p;
    }
    else{
        p->prev=ls.tail;
        ls.tail->next=p;
        ls.tail=p;
    }
}

void AddAfter(List&ls,Node*after,int value){
    Node*p=CreatNode(value);
    if(!after){
        AddHead(ls,value);
    }
    else{
        p->prev=after;
        p->next=after->next;
        after->next=p;
        if(ls.tail!=after) after->next->prev=p;
        else ls.tail=after;
    }

}

void AddBefore(List&ls,Node*before,int value){
    Node*p=CreatNode(value);
    if(!before){
        AddTail(ls,value);
    }
    else{
        p->next=before;
        p->prev=before->prev;
        if(ls.head!=before){
            before->prev->next=p;
        }
        else{
            ls.head=before;
        }
    }
}

void RemoveHead(List&ls){
    if(!ls.head){
        cout<<"List is empty!"<<endl;
    }
    else if(ls.head==ls.tail){
        delete ls.head;
        ls.head=ls.tail=NULL;
    }
    else{
        Node*temp=ls.head;
        ls.head->next->prev=NULL;
        ls.head=ls.head->next;
        delete temp;
    }
}

void RemoveTail(List&ls){
   if (!ls.head)
      cout << "List is empty!" << endl;
   else if (ls.head == ls.tail)
   {
      delete ls.head;
      ls.head = ls.tail = NULL;
   }
   else
   {
      Node* temp = ls.tail;
      ls.tail->prev->next = NULL;
      ls.tail = ls.tail->prev;
      delete temp;
   }
}



void PrintListNext(List ls){
    for(Node*k=ls.head;k!=NULL;k=k->next){
        cout<<k->data<<" ";
    }
    cout<<endl;
}

void PrintListPrev(List ls){
    for(Node*k=ls.tail;k!=NULL;k=k->prev){
        cout<<k->data<<" ";
    }
    cout<<endl;
}

int main(){
    List ls;
    CreatList(ls);
    AddHead(ls,1);
    AddHead(ls,2);
    AddHead(ls,3);
    AddTail(ls,4);
    AddTail(ls,5);
    AddTail(ls,6);
    PrintListNext(ls);
    RemoveHead(ls);
    RemoveTail(ls);
    PrintListPrev(ls);

}
