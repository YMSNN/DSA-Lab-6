/*
lAB 6: Task 1
*/

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    
    Node(int d){
    data=d;
    next=NULL;
    prev=NULL;
}

};

class DoublyLinkedList{
    Node* head;
public:
    DoublyLinkedList() {
    	head = NULL;
	}

    void insertAtEnd(int data){
        Node* newNode=new Node(data);
        if(!head){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next)temp=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
    }

    void deleteAtBeginning(){
        if(!head)return;
        Node* temp=head;
        head=head->next;
        if(head)head->prev=NULL;
        delete temp;
    }
    
    void deleteAfterValue(int value){
        Node* temp=head;
        while(temp&&temp->data!=value)temp=temp->next;
        if(temp&&temp->next){
            Node* delNode=temp->next;
            temp->next=delNode->next;
            if(delNode->next)delNode->next->prev=temp;
            delete delNode;
        }
    }

    void display(){
        Node* temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    DoublyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(45);
    list.insertAtEnd(50);
    
    cout<<"Original List: ";
    list.display();
    
    list.deleteAtBeginning();
    cout<<"After deleting first node: ";
    list.display();
    
    list.deleteAfterValue(45);
    cout<<"After deleting node after 45: ";
    list.display();
    
    return 0;
}

