/*

Lab 6: Task 2
*/


#include<iostream>
using namespace std;

struct Node{
    int score;
    string name;
    Node* next;
    Node* prev;
    
    Node(int s, string n){
    score = s;
    name = n;
    next = NULL;
    prev = NULL;
}
};

class DoublyLinkedList{
    Node* head;
public:
	
    DoublyLinkedList(){
    head=NULL;
}

    void insertSorted(int score,string name){
        Node* newNode=new Node(score,name);
        if(!head||head->score>=score){
            newNode->next=head;
            if(head)head->prev=newNode;
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next&&temp->next->score<score)temp=temp->next;
        newNode->next=temp->next;
        if(temp->next)newNode->next->prev=newNode;
        temp->next=newNode;
        newNode->prev=temp;
    }
    
    void deletePlayer(string name){
        Node* temp=head;
        while(temp&&temp->name!=name)temp=temp->next;
        if(!temp)return;
        if(temp->prev)temp->prev->next=temp->next;
        else head=temp->next;
        if(temp->next)temp->next->prev=temp->prev;
        delete temp;
    }
    
    void display(){
        Node* temp=head;
        while(temp){
            cout<<temp->name<<" : "<<temp->score<<endl;
            temp=temp->next;
        }
    }
    
    void displayLowest(){
        if(head)cout<<head->name<<" : "<<head->score<<endl;
    }
    
    void displaySameScore(int score){
        Node* temp=head;
        while(temp){
            if(temp->score==score)cout<<temp->name<<endl;
            temp=temp->next;
        }
    }
    
    void displayBackwardFrom(string name){
        Node* temp=head;
        while(temp&&temp->name!=name)temp=temp->next;
        while(temp){
            cout<<temp->name<<" : "<<temp->score<<endl;
            temp=temp->prev;
        }
    }
};

int main(){
    DoublyLinkedList list;
    
    list.insertSorted(50,"Yasamin");
    list.insertSorted(40,"Sara");
    list.insertSorted(60,"Samira");
    list.insertSorted(45,"Erfan");
    
    cout<<"All Players:"<<endl;
    list.display();
    
    cout<<"\nLowest Score Player:"<<endl;
    list.displayLowest();
    
    cout<<"\nPlayers with score 45:"<<endl;
    list.displaySameScore(45);
    
    cout<<"\nBackward from Erfan:"<<endl;
    list.displayBackwardFrom("Erfan");
    
    cout<<"\nDeleting Sara and displaying updated list:"<<endl;
    list.deletePlayer("Sara");
    list.display();
    
    return 0;
}
