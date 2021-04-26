#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next=NULL;
    Node(int val){
        this->val = val;
    } 
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    int size = 0;
    Node* head;
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node* tmp = head;
        for(int i=0;i<index;i++){
            if(tmp->next==NULL)
                return -1;
            tmp = tmp->next;
        }
        return tmp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* newnd = new Node(val);
        if(size==0)
            head = newnd;
        else{
            Node* tmp = head;
            newnd->next = tmp;
            head = newnd;
        }
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* newnd = new Node(val);
        Node* tmp = head;
        while(tmp->next!=NULL)
            tmp = tmp->next;
        tmp->next = newnd;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>size) return;
        Node* newnd = new Node(val);
        Node* prev;
        Node* tmp = head;
        int i =0;
        while(i++<index-1){
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = newnd;
        newnd->next = tmp;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>size) return;
        Node* tmp = head;
        Node* prev;
        int i =0;
        while(i++<index){
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = (tmp->next!=NULL) ? tmp->next : NULL;
        delete tmp;
        size--;
        
    }
};

void printlinkedlist(Node* n){
    while(n->next!=NULL){
        cout<<n->val;
    }
}

int main() {

    MyLinkedList* obj = new MyLinkedList();
    int param_1 = obj->get(1);
    obj->addAtHead(1);
    printlinkedlist(obj->head);
    obj->addAtTail(3);
    printlinkedlist(obj->head);
    obj->addAtIndex(1,2);
    printlinkedlist(obj->head);
    obj->deleteAtIndex(1);
    printlinkedlist(obj->head);
    delete obj;
    return 0;
}
