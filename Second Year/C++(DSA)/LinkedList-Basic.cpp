#include<iostream>
using namespace std;

int count=0;

class Node{
	public:
		int val;
		Node* next;
		
		Node(int v){
			val = v;
			next = NULL;
			count++;
		}
};

class LinkedList{
	private:
		Node* head;
	public:
		LinkedList(){
			head = NULL;
		}
		
		void insertBeg(int data){
			Node* newNode = new Node(data);
			if(head==NULL){
				head = newNode;
				return;
			}
			newNode->next = head;
			head = newNode;
		}
		
		void insertEnd(int data){
    		Node* newNode = new Node(data); 
    		if(head == NULL){ 
        		head = newNode;
        		return;
    		} 
			else{
        		Node* temp = head; 
        		while(temp->next != NULL){
	            	temp = temp->next;
        		}
        		temp->next = newNode; 
    		}
		}
		
		void insertPos(int data, int pos){
    		if(pos < 0 || pos > count){
        		cout << "ERROR! \nPosition out of bound" << endl;
        		return; 
    		}
    		if(pos == 0){
        		insertBeg(data);
        		return;
    		}
    		if(pos == count){
        		insertEnd(data);
        		return;
    		}
    		Node* newNode = new Node(data); 
    		Node* temp = head;
    		for(int i = 0; i < pos - 1; i++){
        		if(temp == NULL) return;
        		temp = temp->next;
    		}
    		newNode->next = temp->next;
    		temp->next = newNode;
		}
			
		void display(){
			Node* tempP;
            tempP = head;
            while(tempP != NULL){
                cout<<tempP->val<<" -> ";
                tempP=tempP->next;
            }
            cout<<"NULL"<<endl;
		}
};

int main(){
	LinkedList ll;
	cout<<"LINKED LIST: ";
	ll.insertEnd(29);
	ll.insertEnd(07);
	ll.insertBeg(2007);
	ll.insertEnd(00);
	ll.insertPos(27, 2);
	ll.display();
	return 0;
}
